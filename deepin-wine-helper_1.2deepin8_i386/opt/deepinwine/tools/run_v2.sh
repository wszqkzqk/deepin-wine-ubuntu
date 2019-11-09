#!/bin/bash

#   Copyright (C) 2016 Deepin, Inc.
#
#   Author:     Li LongYu <lilongyu@linuxdeepin.com>
#               Peng Hao <penghao@linuxdeepin.com>

WINEPREFIX="$HOME/.deepinwine/@public_bottle_name@"
APPDIR="/opt/deepinwine/apps/@public_bottle_name@"
APPVER="@deb_version_string@"
APPTAR="files.7z"
BOTTLENAME=""
WINE_CMD="deepin-wine"

LOG_FILE=$0

init_log_file()
{
    if [ ! -d "$DEBUG_LOG" ];then
        return
    fi

    LOG_DIR=$(realpath $DEBUG_LOG)
    if [ -d "$LOG_DIR" ];then
        LOG_FILE="${LOG_DIR}/${LOG_FILE##*/}.log"
        echo "" > "$LOG_FILE"
        debug_log "LOG_FILE=$LOG_FILE"
    fi
}

debug_log_to_file()
{
    if [ -d "$DEBUG_LOG" ];then
        echo -e "${1}" >> "$LOG_FILE"
    fi
}

debug_log()
{
    echo "${1}"
}

init_log_file

_SetRegistryValue()
{
    env WINEPREFIX="$WINEPREFIX" $WINE_CMD reg ADD "$1" /v "$2" /t $3 /d "$4" /f
}

_DeleteRegistry()
{
    env WINEPREFIX="$WINEPREFIX" $WINE_CMD reg DELETE "$1" /f &> /dev/null
}

_SetOverride()
{
    _SetRegistryValue 'HKCU\Software\Wine\DllOverrides' "$2" REG_SZ "$1"
}

_DisableAliUpdate()
{
    if [ -f "${WINEPREFIX}/.disable" ];then
        return
    fi
    debug_log "Disable AliUpdate"
    touch ${WINEPREFIX}/.disable

    /opt/deepinwine/tools/kill.sh AliWorkbench block
    VERSIONS=$(ls ${WINEPREFIX}'/drive_c/Program Files/AliWorkbench' | grep -E '*.*.*N')
    VERSIONS=$(echo $VERSIONS | awk '{print $2}')
    debug_log $VERSIONS

    if [ -n "$VERSIONS" ];then
        debug_log "Remove bottle"
        rm -rf "$WINEPREFIX"
        /opt/deepinwine/apps/Deepin-QianNiu/run.sh -c
    fi

    _SetOverride "" "AliUpdate"
}

HelpApp()
{
	echo " Extra Commands:"
	echo " -r/--reset     Reset app to fix errors"
	echo " -e/--remove    Remove deployed app files"
	echo " -h/--help      Show program help info"
}
FixLink()
{
    if [ -d ${WINEPREFIX} ]; then
        CUR_DIR=$PWD
        cd "${WINEPREFIX}/dosdevices"
        rm c: z: y:
        ln -s -f ../drive_c c:
        ln -s -f / z:
        ln -s -f $HOME y:
        cd $CUR_DIR
        ls -l "${WINEPREFIX}/dosdevices"
    fi
}
urldecode() { : "${*//+/ }"; echo -e "${_//%/\\x}"; }

uridecode()
{
    local path=$(urldecode "$1")
    path=${path/file:\/\//}
    echo $path
}

UnixUriToDosPath()
{
    OPEN_FILE=$(uridecode "$1")
    if [ -f "$OPEN_FILE" ]; then
        OPEN_FILE=$(realpath "$OPEN_FILE")
        OPEN_FILE="z:$OPEN_FILE"
        debug_log "fond file $OPEN_FILE"
        OPEN_FILE=$(echo $OPEN_FILE | sed -e 's/\//\\\\/g')
    fi
    echo "OPEN_FILE"
}

get_bottle_path_by_process_id()
{
    PID_LIST="$1"
    PREFIX_LIST=""

    for pid_var in $PID_LIST ; do
        WINE_PREFIX=$(xargs -0 printf '%s\n' < /proc/$pid_var/environ | grep WINEPREFIX)
        WINE_PREFIX=${WINE_PREFIX##*=}
        for path in $(echo -e $PREFIX_LIST) ; do
            if [[ $path == "$WINE_PREFIX" ]]; then
                WINE_PREFIX=""
            fi
        done
        if [ -d "$WINE_PREFIX" ]; then
            debug_log_to_file "found $pid_var : $WINE_PREFIX"
            PREFIX_LIST+="\n$WINE_PREFIX"
        fi
    done
    echo -e $PREFIX_LIST | grep $HOME
}

get_bottle_path_by_process_name()
{
    PID_LIST=$(ps -ef | grep -E -i "c:.*${1}" | grep -v grep | awk '{print $2}')
    debug_log_to_file "get pid list: $PID_LIST"
    get_bottle_path_by_process_id "$PID_LIST"
}

#arg 1: windows process file path
#arg 2-*: windows process args
CallProcess()
{
    #get file full path
    path="$1"
    path=$(echo ${path/c:/${WINEPREFIX}/drive_c})
    path=$(echo ${path//\\/\/})

    #kill bloack process
    name="${path##*/}"
    /opt/deepinwine/tools/kill.sh "$name" block

    #change current dir to excute path
    path=$(dirname "$path")
    cd "$path"
    pwd

    debug_log "Starting process $* ..."

    env WINEPREFIX="$WINEPREFIX" $WINE_CMD "$@" &
}

AutoStartBottle()
{
    debug_log "Auto start $WINEPREFIX"
    env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
}

#arg 1: startserver just start server, or process file path
#arg 2-*: windows process args
CallYMDY()
{
    SERVER_BOTTLE=$(get_bottle_path_by_process_name sqlservr.exe | grep $WINEPREFIX)
    if [ -z "$SERVER_BOTTLE" ]; then
        debug_log "Starting SQL Server ..."
        CallProcess "c:\\Program Files\\Microsoft SQL Server\\MSSQL\\Binn\\sqlservr.exe" -s MSSQLSERVER
    else
        debug_log "SQL Server is running in $SERVER_BOTTLE"
    fi

    if [ "startserver" == "$1" ]; then
        debug_log "Auto start SQL Server"
    else
        CallProcess "$@"
    fi
}

CallYMGWY()
{
    if [ "tongji" == "$1" ]; then
        firefox "http://127.0.0.1:64022/hzbtj" &
    else
        firefox "http://127.0.0.1:64022/hzb" &
    fi
}

CallATM()
{
    if [ ! -f "$WINEPREFIX/drive_c/Program Files/TradeManager/AliIM.exe" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\deepin\\AliIM2015_ATM.exe"
    fi
    CallProcess "$@"
}

CallQIANNIU()
{
    _DisableAliUpdate
    CallProcess "$@"
}

CallYMDATJ()
{
    if [ ! -f "$WINEPREFIX/drive_c/Program Files/JoinCheer/全国档案事业统计年报信息管理系统/ReportE.exe" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\deepin\\install\\setup.exe"
    fi

    CallProcess "$@"
}

CallQQGame()
{
    debug_log "run $1"
    /opt/deepinwine/tools/kill.sh QQMicroGameBox block
    env WINEPREFIX="$WINEPREFIX" /opt/deepinwine/tools/QQGameRunner $1 &
}

CallIrfanView()
{
    OPEN_FILE="$(UnixUriToDosPath "$2")"
    debug_log "file path: $OPEN_FILE"

    if [ -n "$OPEN_FILE" ]; then
        CallProcess "$1" "$OPEN_FILE"
    else
        CallProcess "$1"
    fi
}

CallQQ()
{
    if [ ! -f "$WINEPREFIX/../.QQ_run" ]; then
        debug_log "first run time"
        /opt/deepinwine/tools/add_hotkeys
        /opt/deepinwine/tools/fontconfig
        touch "$WINEPREFIX/../.QQ_run"
    fi

    #Support use native file dialog
    export ATTACH_FILE_DIALOG=1

    CallProcess "$@"
}

CallTIM()
{
    if [ ! -f "$WINEPREFIX/../.QQ_run" ]; then
        debug_log "first run time"
        /opt/deepinwine/tools/add_hotkeys
        /opt/deepinwine/tools/fontconfig
        # If the bottle not exists, run reg may cost lots of times
        # So create the bottle befor run reg
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD uninstaller --list
        touch $WINEPREFIX/../.QQ_run
    fi

    #Support use native file dialog
    export ATTACH_FILE_DIALOG=1

    CallProcess "$@"

    #disable Tencent MiniBrowser
    _DeleteRegistry "HKCU\\Software\\Tencent\\MiniBrowser"
}

CallWeChat()
{
    debug_log "Disable auto update"
    _DeleteRegistry "HKCU\\Software\\Tencent\\WeChat" "UpdateFailCnt"
    _DeleteRegistry "HKCU\\Software\\Tencent\\WeChat" "NeedUpdateType"
    rm "${WINEPREFIX}/drive_c/users/${USER}/Application Data/Tencent/WeChat/All Users/config/configEx.ini"

    export DISABLE_RENDER_CLIPBOARD=1
    export ATTACH_FILE_DIALOG=1
    CallProcess "$@"
}

CallWangWang()
{
    xdg-mime default deepin.com.taobao.wangwang.desktop x-scheme-handler/aliim
    chmod 700 "$WINEPREFIX/drive_c/Program Files/AliWangWang/9.12.03C/wwbizsrv.exe"
    chmod 700 "$WINEPREFIX/drive_c/Program Files/Alibaba/wwbizsrv/wwbizsrv.exe"
    CallProcess "$@"
}

#arg 1: exec file path
#arg 2: autostart ,or exec arg 1
#arg 3: exec arg 2
CallApp()
{
    FixLink
    debug_log "CallApp $BOTTLENAME $*"
    if [ "autostart" == "$2" ];then
        AutoStartBottle
        return
    fi

    case $BOTTLENAME in
        "Deepin-WangWang")
            CallWangWang "$@"
            ;;
        "Deepin-QQ")
            CallQQ "$@"
            ;;
        "Deepin-TIM")
            CallTIM "$@"
            ;;
        "Deepin-IrfanView")
            CallIrfanView "$@"
            ;;
        "Deepin-dangantongji")
            CallYMDATJ "$@"
            ;;
        "Deepin-YMDY")
            CallYMDY "$@"
            ;;
        "Deepin-YMGWY")
            CallYMGWY "$@"
            ;;
        "Deepin-QQGame"*)
            CallQQGame "$@"
            ;;
        "Deepin-QianNiu")
            CallQIANNIU "$@"
            ;;
        "Deepin-ATM")
            CallATM "$@"
            ;;
        "Deepin-WeChat")
            CallWeChat "$@"
            ;;
        *)
            CallProcess "$@"
            ;;
    esac
}
ExtractApp()
{
	mkdir -p "$1"
	7z x "$APPDIR/$APPTAR" -o"$1"
	mv "$1/drive_c/users/@current_user@" "$1/drive_c/users/$USER"
	sed -i "s#@current_user@#$USER#" $1/*.reg
    FixLink
}
DeployApp()
{
	ExtractApp "$WINEPREFIX"
	echo "$APPVER" > "$WINEPREFIX/PACKAGE_VERSION"
}
RemoveApp()
{
	rm -rf "$WINEPREFIX"
}
ResetApp()
{
	debug_log "Reset $PACKAGENAME....."
	read -p "*	Are you sure?(Y/N)" ANSWER
	if [ "$ANSWER" = "Y" -o "$ANSWER" = "y" -o -z "$ANSWER" ]; then
		EvacuateApp
		DeployApp
		CallApp
	fi
}
UpdateApp()
{
	if [ -f "$WINEPREFIX/PACKAGE_VERSION" ] && [ "$(cat "$WINEPREFIX/PACKAGE_VERSION")" = "$APPVER" ]; then
		return
	fi
	if [ -d "${WINEPREFIX}.tmpdir" ]; then
		rm -rf "${WINEPREFIX}.tmpdir"
	fi

    case $BOTTLENAME in
        "Deepin-Intelligent" | "Deepin-QQ" | "Deepin-TIM" | "Deepin-WeChat")
            rm -rf "$WINEPREFIX"
            DeployApp
            return
            ;;
    esac

	ExtractApp "${WINEPREFIX}.tmpdir"
	/opt/deepinwine/tools/updater -s "${WINEPREFIX}.tmpdir" -c "${WINEPREFIX}" -v
	rm -rf "${WINEPREFIX}.tmpdir"
	echo "$APPVER" > "$WINEPREFIX/PACKAGE_VERSION"
}
RunApp()
{
    progpid=$(ps -ef | grep "zenity --progress --title=${BOTTLENAME}" | grep -v grep)
    debug_log "run ${BOTTLENAME} progress pid $progpid"
    if [ -n "$progpid" ]; then
        debug_log "$BOTTLENAME is running"
        exit 0
    fi
 	if [ -d "$WINEPREFIX" ]; then
        UpdateApp | progressbar "$BOTTLENAME" "更新$BOTTLENAME中..."
 	else
        DeployApp | progressbar $BOTTLENAME "初始化$BOTTLENAME中..."
 	fi
    CallApp "$@"
}

CreateBottle()
{
    if [ -d "$WINEPREFIX" ]; then
        UpdateApp
    else
        DeployApp
    fi
}

# Check if some visual feedback is possible
if command -v zenity >/dev/null 2>&1; then
	progressbar()
	{
		WINDOWID="" zenity --progress --title="$1" --text="$2" --pulsate --width=400 --auto-close --no-cancel ||
		WINDOWID="" zenity --progress --title="$1" --text="$2" --pulsate --width=400 --auto-close
	}

else
	progressbar()
	{
		cat -
	}
fi

if [ -z $1 ] || [ -z $2 ] || [ -z "$3" ]; then
    debug_log "Invalid params"
    exit 0
fi

BOTTLENAME="$1"
WINEPREFIX="$HOME/.deepinwine/$1"
APPDIR="/opt/deepinwine/apps/$1"
APPVER="$2"

debug_log "Run $*"

if [ -z "$4" ]; then
	RunApp "$3"
	exit 0
fi
case $4 in
	"-r" | "--reset")
		ResetApp
		;;
	"-c" | "--create")
		CreateBottle
		;;
	"-e" | "--remove")
		RemoveApp
		;;
	"-u" | "--uri")
		RunApp "$3" "$5" "$6"
		;;
	"-h" | "--help")
		HelpApp
		;;
	*)
		echo "Invalid option: $4"
		echo "Use -h|--help to get help"
		exit 1
		;;
esac
exit 0
