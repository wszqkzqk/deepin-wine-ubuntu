#!/bin/bash

APP_NAME="QQ"
LOG_FILE=$0

init_log_file()
{
    if [ -d "$DEBUG_LOG" ];then
        LOG_DIR=$(realpath $DEBUG_LOG)
        if [ -d "$LOG_DIR" ];then
            LOG_FILE="${LOG_DIR}/${LOG_FILE##*/}.log"
            echo "" > "$LOG_FILE"
            debug_log "LOG_FILE=$LOG_FILE"
        fi
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

get_pid_by_process_name()
{
    ps -ef | grep -E -i "c:.*${1}|d:.*${1}|e:.*${1}|f:.*${1}" | grep -v grep | awk '{print $2}'
}

get_bottle_path_by_process_name()
{
    PID_LIST=$(get_pid_by_process_name $1)
    debug_log_to_file "get pid list: $PID_LIST"
    get_bottle_path_by_process_id "$PID_LIST"
}

get_bottle_path()
{
    if [ -z "$1" ];then
        return 0
    fi

    if [ -f "$1/user.reg" ]; then
        echo "$1"
        return 0
    fi

    if [ -f "$HOME/.deepinwine/$1/user.reg" ]; then
        echo "$HOME/.deepinwine/$1"
        return 0
    fi
    get_bottle_path_by_process_name "$1"
}

kill_app()
{
    debug_log "try to kill $1"
    for path in $(get_bottle_path $1); do
        if [[ $path == *"deepinwine"* ]]; then
            debug_log "kill $path deepinwine"
            env WINEPREFIX="$path" /usr/lib/i386-linux-gnu/deepin-wine/wineserver -k
        elif [[ $path == *"cxoffice"* ]]; then
            debug_log "kill $path cxoffice"
            env WINEPREFIX="$path" /opt/cxoffice/bin/wineserver -k
        else
            debug_log "unkown ${path}"
            env WINEPREFIX="$path" /usr/lib/i386-linux-gnu/deepin-wine/wineserver -k
        fi
    done
}

get_tray_window()
{
    /opt/deepinwine/tools/get_tray_window | grep window_id: | awk -F: '{print $2}'
}

get_stacking_window()
{
    xprop -root _NET_CLIENT_LIST_STACKING | awk -F# '{print $2}' | sed -e 's/, / /g'
}

get_window_pid()
{
    for winid in $(echo "$1" | sed -e 's/ /\n/g') ;
    do
        xprop -id $winid _NET_WM_PID | awk -F= '{print $2}'
    done
}

get_window_bottle()
{
    debug_log_to_file "get_window_bottle $1"
    PID_LIST=$(get_window_pid "$1")
    debug_log_to_file "get_window_bottle pid list: $PID_LIST"
    get_bottle_path_by_process_id "$PID_LIST"
}

get_active_bottles()
{
    TRAYWINDOWS=$(get_tray_window)
    STACKINGWINDOWS=$(get_stacking_window)
    debug_log_to_file "tray window id: $TRAYWINDOWS"
    debug_log_to_file "stacking window id: $STACKINGWINDOWS"
    PID_LIST="$TRAYWINDOWS"
    for pid in $STACKINGWINDOWS; do
        if [[ $pid != *"$PID_LIST"* ]];then
            PID_LIST+=" $pid"
        fi
    done
    get_window_bottle "$PID_LIST"
}

kill_exit_block_app()
{
    if [ -z "$(get_pid_by_process_name service)" ];then
        debug_log "No wine process found"
        return
    fi
    TAGBOTTLE=$(get_bottle_path_by_process_name $1)
    debug_log "tag bottle: $TAGBOTTLE"
    ACTIVEBOTTLES=$(get_active_bottles)
    debug_log "active bottles: $ACTIVEBOTTLES"

    if [[ "$ACTIVEBOTTLES" != *"$TAGBOTTLE"* ]]; then
         kill_app "$TAGBOTTLE"
    fi
}

#get_active_bottles
#exit

debug_log "kill $1 $2"

if [ -n "$1" ]; then
    APP_NAME="$1"
fi

if [ "$2" = "block" ]; then
    kill_exit_block_app $APP_NAME $3
else
    kill_app $APP_NAME
fi
