#!/bin/bash

APPS="Deepin-QQ Deepin-QQLigth"
WINE_CMD="deepin-wine"
RE_TAG="Source Han Sans SC Regular"
WINE_PREFIX=""

_SetRegistryValue()
{
    env WINEPREFIX="$WINE_PREFIX" $WINE_CMD reg ADD "$1" /v "$2" /t $3 /d "$4"
}

_DeleteRegistryValue()
{
    env WINEPREFIX="$WINE_PREFIX" $WINE_CMD reg DELETE "$1" /v "$2"
}

_SetFontReplacements()
{
    echo "$1 -> $2"
#    _DeleteRegistryValue 'HKCU\Software\Wine\\Fonts\Replacements' "$1"
    _SetRegistryValue 'HKCU\Software\Wine\\Fonts\Replacements' "$1" REG_SZ "$2"
}

if [ -z "$1" ]; then
    echo "No font name"
    exit 0
fi

if [ -n "$2" ]; then
    RE_TAG="$2"
fi

for name in ${APPS}; do
    WINE_PREFIX="$HOME/.deepinwine/$name"
    echo $WINE_PREFIX
    if [ -d "$WINE_PREFIX" ]; then
        _SetFontReplacements "$1" "$RE_TAG"
    fi
done
