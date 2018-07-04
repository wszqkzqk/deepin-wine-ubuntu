#!/bin/bash

# $1 key value
# $2 process name , default QQ|TIM
# $3 control mode , default ctrl+alt
#    0   no control key
#    1   shift+
#    2   ctrl+
#    3   alt+
#    4   ctrl+alt+
#    5   ctrl+shift+
#    6   alt+shift+

get_bottle_path_by_process_id()
{
    PID_LIST="$1"
    PREFIX_LIST=""

    for pid_var in $PID_LIST ; do
        WINE_PREFIX=$(xargs -0 printf '%s\n' < /proc/$pid_var/environ | grep WINEPREFIX)
        WINE_PREFIX=${WINE_PREFIX##*=}
        #echo "found $pid_var : $WINE_PREFIX"
        for path in $(echo -e $PREFIX_LIST) ; do
            if [[ $path == "$WINE_PREFIX" ]]; then
                WINE_PREFIX=""
            fi
        done
        PREFIX_LIST+="\n$WINE_PREFIX"
    done
    echo -e $PREFIX_LIST | grep $HOME
}

get_bottle_path_by_process_name()
{
    PID_LIST=$(ps -ef | grep -E -i "c:.*${1}|d:.*${1}|e:.*${1}|f:.*${1}" | grep -v grep | awk '{print $2}')
    get_bottle_path_by_process_id "$PID_LIST"
}

send_to_process()
{
    if [ -z "$2" ]; then
        return 0
    fi

    for path in $(get_bottle_path_by_process_name $2); do
        if [[ $path == *"deepinwine"* ]]; then
            echo "send ${path##*/} deepinwine"
            env WINEPREFIX="$path" deepin-wine "/opt/deepinwine/tools/sendkeys.exe" $1 $3
        elif [[ $path == *"cxoffice"* ]]; then
            echo "send ${path##*/} cxoffice"
            /opt/cxoffice/bin/wine --bottle=${path##*/} "/opt/deepinwine/tools/sendkeys.exe" $1 $3
        else
            echo "unkown ${path}"
            env WINEPREFIX="$path" wine "/opt/deepinwine/tools/sendkeys.exe" $1 $3
        fi
    done
}

if [ -z "$1" ]; then
    echo "Please input a key [a-zA-Z]"
    exit 0
fi

if [ -n "$2" ]; then
    send_to_process $1 $2 $3
else
    send_to_process $1 "QQ|TIM"
fi
