#!/bin/bash

BOTTLE_NAME="Deepin-QQ"
DEBUG_MSG="+pid,+tid,+timestamp"

find_exec_path()
{
    RUN_SHELL=$HOME/.deepinwine/$1/drive_c/deepin/EnvInit.sh
    if [ -e "$RUN_SHELL" ]; then
        APP_PATH=$(cat $RUN_SHELL | grep "env WINEPREFIX=\"\$BASE_DIR\" \$WINE_CMD" | grep "\&" | grep -E "c:|C:" | cut -d "\"" -f4)
        echo $1=$APP_PATH
    fi
}

show_all_apps()
{
    APP_LIST="$(ls $HOME/.deepinwine)"
    for name in $APP_LIST; do
        find_exec_path $name
    done
    exit
}

#show_all_apps

if [ -n "$1" ]; then
    BOTTLE_NAME="$1"
fi

if [ -n "$2" ]; then
    DEBUG_MSG="$2"
fi

mkdir $HOME/log &> /dev/null

export  DEBUG_LOG="$HOME/log"

dpkg -l | grep "Deepin Wine" > $HOME/log/${BOTTLE_NAME}.log
dpkg -l deepin-libwine >> $HOME/log/${BOTTLE_NAME}.log
ps -ef | grep -i c: >> $HOME/log/${BOTTLE_NAME}.log

if [ -z "$3" ]; then
    WINEDEBUG=${DEBUG_MSG} /opt/deepinwine/apps/${BOTTLE_NAME}/run.sh &>> $HOME/log/${BOTTLE_NAME}.log &
else
    WINEDEBUG=${DEBUG_MSG} /opt/deepinwine/apps/${BOTTLE_NAME}/run.sh -u "$3" &>> $HOME/log/${BOTTLE_NAME}.log &
fi
dde-file-manager $HOME/log &> /dev/null &
