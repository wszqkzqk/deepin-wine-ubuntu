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
        strDate=$(date)
        echo -e "${strDate}:${1}" >> "$LOG_FILE"
    fi
}

debug_log()
{
    strDate=$(date)
    echo "${strDate}:${1}"
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
        rm c: z:
        ln -s -f ../drive_c c:
        ln -s -f / z:
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

CallYMDY()
{
    SERVER_BOTTLE=$(get_bottle_path_by_process_name sqlservr.exe | grep $WINEPREFIX)
    if [ -z "$SERVER_BOTTLE" ]; then
        debug_log "Starting SQL Server ..."
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Microsoft SQL Server\\MSSQL\\Binn\\sqlservr.exe" -s MSSQLSERVER &
    else
        debug_log "SQL Server is running in $SERVER_BOTTLE"
    fi

    if [ "autostart" == "$1" ]; then
        debug_log "Auto start SQL Server"
    elif [ "tongji" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\旗帜软件\\党内信息管理系统(统计版)\\CReport.exe" &
    elif [ "createdb" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\旗帜软件\\党内信息管理系统(统计版)\\数据库安装\\SetupDb.exe" &
    elif [ "servermanger" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Microsoft SQL Server\\80\\Tools\\Binn\\sqlmangr.exe" /n &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\旗帜软件\\党内信息管理系统(统计版)\\QZCPMIS.exe" &
    fi
}
CallYMGWY()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD uninstaller --list
    elif [ "tongji" == "$1" ]; then
        firefox "http://127.0.0.1:64022/hzbtj" &
    else
        firefox "http://127.0.0.1:64022/hzb" &
    fi
}
CallATM()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        if [ ! -f "$WINEPREFIX/drive_c/Program Files/TradeManager/AliIM.exe" ]; then
            env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\deepin\\AliIM2015_ATM.exe"
        fi
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\TradeManager\\AliIM.exe" &
    fi
}
CallMaxthon2()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Maxthon2\\Maxthon.exe" &
    fi
}
CallQIANNIU()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        _DisableAliUpdate
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\AliWorkbench\\AliWorkbench.exe" &
    fi
}
CallYMPOPS()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\全国持久性有机污染物统计年报信息管理系统(2017)\\POPs.exe" &
    fi
}
CallYMRLZY()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\人力资源社会保障统计报表系统SMIS2012\\bin\\Omni.exe" &
    fi
}
CallYMDATJ()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        if [ ! -f "$WINEPREFIX/drive_c/Program Files/JoinCheer/全国档案事业统计年报信息管理系统/ReportE.exe" ]; then
            env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\deepin\\install\\setup.exe"
        fi

        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\JoinCheer\\全国档案事业统计年报信息管理系统\\ReportE.exe" &
    fi
}
CallYMWZXX()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\全国政府网站信息报送客户端\\UFReader.exe" &
    fi
}
CallRTX2015()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        cd "$WINEPREFIX/drive_c/Program Files/Tencent/RTXC"
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\RTXC\\RTX.exe" &
    fi
}
CallYMRDWS()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\饮用水水源环境基础信息采集系统\\RDWS.exe"  &
    fi
}
CallQQGame()
{
    debug_log "run $1"
    /opt/deepinwine/tools/kill.sh QQMicroGameBox block
    env WINEPREFIX="$WINEPREFIX" /opt/deepinwine/tools/QQGameRunner $1 &
}
CallWXWork()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        /opt/deepinwine/tools/kill.sh WXWork.exe block

        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\WXWork\\WXWork.exe" &
    fi
}
CallRTX2009()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        cd "$WINEPREFIX/drive_c/Program Files/Tencent/RTXC"
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\RTXC\\RTX.exe" &
    fi
}
CallIrfanView()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        OPEN_FILE=$(uridecode $1)
        if [ -f "$OPEN_FILE" ]; then
            OPEN_FILE=$(realpath "$OPEN_FILE")
            OPEN_FILE="z:$OPEN_FILE"
            debug_log "fond file $OPEN_FILE"
            OPEN_FILE=$(echo $OPEN_FILE | sed -e 's/\//\\\\/g')
        fi

        echo "file path: $OPEN_FILE"
        if [ -n "$OPEN_FILE" ]; then
            env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\IrfanView\\i_view32.exe" "$OPEN_FILE" &
        else
            env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\IrfanView\\i_view32.exe" &
        fi
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

    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else 
        #Support use native file dialog
        export ATTACH_FILE_DIALOG=1

        #Auto kill block process
        /opt/deepinwine/tools/kill.sh QQ.exe block

        debug_log "start running..."
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\QQ\\Bin\\QQ.exe" &
    fi
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

    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else 
        #Auto kill block process
        /opt/deepinwine/tools/kill.sh TIM.exe block

        #Support use native file dialog
        export ATTACH_FILE_DIALOG=1

        debug_log "start running..."
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\TIM\\Bin\\TIM.exe" &

        #disable Tencent MiniBrowser
        _DeleteRegistry "HKCU\\Software\\Tencent\\MiniBrowser"
    fi
}
fun1(){
    xwininfo -root -children | grep -E -i "WeChat.exe.*Wine.*60x60"
}
CallWeChat()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        debug_log "Disable auto update"
        _DeleteRegistry "HKCU\\Software\\Tencent\\WeChat" "UpdateFailCnt"
        _DeleteRegistry "HKCU\\Software\\Tencent\\WeChat" "NeedUpdateType"
        rm "${WINEPREFIX}/drive_c/users/${USER}/Application Data/Tencent/WeChat/All Users/config/configEx.ini"

        export DISABLE_RENDER_CLIPBOARD=1
        export ATTACH_FILE_DIALOG=1
        debug_log "start running..."
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\WeChat\\WeChat.exe" &
    fi
}
CallFoobar2000()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\foobar2000\\foobar2000.exe" &
    fi
}
Call7zip()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\7-Zip\\7zFM.exe" &
    fi
}
Callgtjafuyi()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\GTJA\\RichEZ\\TdxW.exe" &
    fi
}
CallAAAlog()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\AAALOGO\\alogo.exe" &
    fi
}
CallWinRAR()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\WinRAR\\WinRAR.exe" &
    fi
}
Call360Zip()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\360\\360zip\\360zip.exe" &
    fi
}
CallJCJCJSC()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\金长江网上交易\\金长江网上交易财智版\\tdxw.exe" &
    fi
}
CallQQEIM()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\QQEIM\\Bin\\QQEIM.exe" &
    fi
}
CallMTXX()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Meitu\\XiuXiu\\XiuXiu.exe " &
    fi
}
CallDecryptDoc()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\DecryptDoc.exe " &
    fi
}
CallYNote()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Youdao\\YoudaoNote\\YoudaoNote.exe " &
    fi
}
CallQQCRM()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Tencent\\BizQQ\\Bin\\QQCRM.exe" &
    fi
}
CallPRCReader()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Founder\\Apabi Reader 4.0\\ApaReader.exe" &
    fi
}
CallMiniCADSee()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\CAD迷你看图\\DWGView.exe" &
    fi
}
CallCMBChina()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        /opt/deepinwine/tools/kill.sh PersonalBankPortal.exe block
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\windows\\system32\\PersonalBankPortal.exe" &
    fi
}
CallWangWang()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        xdg-mime default deepin.com.taobao.wangwang.desktop x-scheme-handler/aliim
        chmod 700 "$WINEPREFIX/drive_c/Program Files/AliWangWang/9.12.03C/wwbizsrv.exe"
        chmod 700 "$WINEPREFIX/drive_c/Program Files/Alibaba/wwbizsrv/wwbizsrv.exe"
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\AliWangWang\\9.12.03C\\WWCmd.exe" "$1" &
    fi
}
CallEM263()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\263\\263 Enterprise Messenger\\263em.exe " &
    fi
}
CallThunderSpeed()
{
    if [ "autostart" == "$1" ]; then
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD /opt/deepinwine/tools/startbottle.exe &
    else
        /opt/deepinwine/tools/kill.sh Thunder.exe block
        env WINEPREFIX="$WINEPREFIX" $WINE_CMD "c:\\Program Files\\Thunder Network\\Thunder\\Program\\Thunder.exe" &
    fi
}
CallApp()
{
    FixLink
    debug_log "CallApp $BOTTLENAME $1 $2"
    case $BOTTLENAME in
        "Deepin-WangWang")
            CallWangWang "$1" "$2"
            ;;
        "Deepin-ThunderSpeed")
            CallThunderSpeed "$1" "$2"
            ;;
        "Deepin-EM263")
            CallEM263 "$1" "$2"
            ;;
        "Deepin-MTXX")
            CallMTXX "$1" "$2"
            ;;
        "Deepin-PRCReader")
            CallPRCReader "$1" "$2"
            ;;
        "Deepin-MiniCADSee")
            CallMiniCADSee "$1" "$2"
            ;;
        "Deepin-CMBChina")
            CallCMBChina "$1" "$2"
            ;;
        "Deepin-DecryptDoc")
            CallDecryptDoc "$1" "$2"
            ;;
        "Deepin-YNote")
            CallYNote "$1" "$2"
            ;;
        "Deepin-Maxthon")
            CallMaxthon2 "$1" "$2"
            ;;
        "Deepin-Foobar2000")
            CallFoobar2000 "$1" "$2"
            ;;
        "Deepin-QQCRM")
            CallQQCRM "$1" "$2"
            ;;
        "Deepin-QQEIM")
            CallQQEIM "$1" "$2"
            ;;
        "com.95579.cjsc")
            CallJCJCJSC "$1" "$2"
            ;;
        "Deepin-360YaSuo")
            Call360Zip "$1" "$2"
            ;;
        "Deepin-WinRAR")
            CallWinRAR "$1" "$2"
            ;;
        "Deepin-AAAlog")
            CallAAAlog "$1" "$2"
            ;;
        "com.gtja.fuyi")
            Callgtjafuyi "$1" "$2"
            ;;
        "Deepin-7zip")
            Call7zip "$1" "$2"
            ;;
        "Deepin-QQ")
            CallQQ "$1" "$2"
            ;;
        "Deepin-TIM")
            CallTIM "$1" "$2"
            ;;
        "Deepin-RTX2015")
            CallRTX2015 "$1" "$2"
            ;;
        "Deepin-RTX2009")
            CallRTX2009 "$1" "$2"
            ;;
        "Deepin-IrfanView")
            CallIrfanView "$1" "$2"
            ;;
        "Deepin-YMRDWS")
            CallYMRDWS "$1" "$2"
            ;;
        "Deepin-WeChat")
            CallWeChat "$1" "$2"
            ;;
        "Deepin-wangzhanxinxi")
            CallYMWZXX "$1" "$2"
            ;;
        "Deepin-dangantongji")
            CallYMDATJ "$1" "$2"
            ;;
        "Deepin-renliziyuan")
            CallYMRLZY "$1" "$2"
            ;;
        "Deepin-YMPOPS")
            CallYMPOPS "$1" "$2"
            ;;
        "Deepin-YMDY")
            CallYMDY "$1" "$2"
            ;;
        "Deepin-YMGWY")
            CallYMGWY "$1" "$2"
            ;;
        "Deepin-QQHlddz")
            CallQQGame 363 "$1" "$2"
            ;;
        "Deepin-QQHlmj")
            CallQQGame 1101070761 "$1" "$2"
            ;;
        "Deepin-QQWzry")
            CallQQGame 1106084547 "$1" "$2"
            ;;
        "Deepin-QQMnsj")
            CallQQGame 1105856612 "$1" "$2"
            ;;
        "Deepin-QQBydr")
            CallQQGame 1104632801 "$1" "$2"
            ;;
        "Deepin-QQJlhmjq")
            CallQQGame 1105370739 "$1" "$2"
            ;;
        "Deepin-QQXwsd")
            CallQQGame 1101328322 "$1" "$2"
            ;;
        "Deepin-QQDldl")
            CallQQGame 1105208044 "$1" "$2"
            ;;
        "Deepin-QQSszb")
            CallQQGame 1105640244 "$1" "$2"
            ;;
        "Deepin-QQCszj")
            CallQQGame 1105974527 "$1" "$2"
            ;;
        "Deepin-WXWork")
            CallWXWork "$1" "$2"
            ;;
        "Deepin-QianNiu")
            CallQIANNIU "$1" "$2"
            ;;
        "Deepin-ATM")
            CallATM "$1" "$2"
            ;;
        *)
            debug_log "unkown bottle $BOTTLENAME"
            ;;
    esac
}
ExtractApp()
{
	mkdir -p "$1"
	7z x "$APPDIR/$APPTAR" -o"$1"
	mv "$1/drive_c/users/@current_user@" "$1/drive_c/users/$USER"
	sed -i "s#@current_user@#$USER#" $1/*.reg
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
    CallApp "$1" "$2"
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

if [ -z $1 ] || [ -z $2 ]; then
    debug_log "Invalid params"
    exit 0
fi

BOTTLENAME="$1"
WINEPREFIX="$HOME/.deepinwine/$1"
APPDIR="/opt/deepinwine/apps/$1"
APPVER="$2"

debug_log "Run $1 $2"

if [ -z "$3" ]; then
	RunApp
	exit 0
fi
case $3 in
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
		RunApp "$4" "$5"
		;;
	"-h" | "--help")
		HelpApp
		;;
	*)
		echo "Invalid option: $3"
		echo "Use -h|--help to get help"
		exit 1
		;;
esac
exit 0
