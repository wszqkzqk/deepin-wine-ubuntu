#!/bin/bash

#   Copyright (C) 2016 Deepin, Inc.
#
#   Author:     Peng Hao <penghao@linuxdeepin.com>
#   Maintainer: Peng Hao <penghao@linuxdeepin.com>

BASE_DIR="$HOME/.deepinwine/Deepin-QQ"
WINE_CMD="deepin-wine"

_SetRegistryValue()
{
    env WINEPREFIX="$BASE_DIR" $WINE_CMD reg ADD "$1" /v "$2" /t $3 /d "$4" /f
}

_SetOverride()
{
    _SetRegistryValue 'HKCU\Software\Wine\DllOverrides' "$2" REG_SZ "$1"
}

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Please input two args, first is dpi, second is bottle name"
    exit 0
fi

if (("$1" < 96)) || (($1 > 400)) ; then
    echo "Invaild dpi vaule, min 96 max 400"
    exit 0
fi

BASE_DIR="$HOME/.deepinwine/$2"
RUN_CMD="/opt/deepinwine/apps/$2/run.sh"

if [ ! -f "$RUN_CMD" ]; then
    echo "Invaild bottle name, $2 is not exist"
    exit 0
fi

/opt/deepinwine/tools/kill.sh $2
$RUN_CMD -c

_SetRegistryValue 'HKCU\Control Panel\Desktop' LogPixels REG_DWORD $1

$RUN_CMD
exit 0
