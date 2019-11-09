#!/bin/bash

#$1 link path
#$2 real path
Update_link()
{
    if [ -f "$1" ];then
        echo "$1 is a file"
        rm "$1"
    fi

    if [ -L "$1" ];then
        real_path=$(realpath $1)
        echo "${1} is a symlink, $real_path"
        if [ "$2" = "$real_path" ];then
            echo "not need create"
            return
        fi
        rm "$1"
    fi

    link_dir=$(dirname "$1")
    mkdir -p "$link_dir"
    echo "link $1 to $2"
    ln -s "$2" "$1"
}

map_lp()
{
    ls /dev/lp* |\
    while read line; do
        Update_link "${HOME}/.deepinwine/lp0" "$line"
        return
    done
}

map_serial()
{
    i=0
    COMS=("COM1" "COM2" "COM3" "COM4")
    dmesg | grep -E "0000:01.*tty" | awk '{print $4}'|\
    while read line;do
	ttypath=$(echo "/dev/$line")
	compath=$(echo "${HOME}/.deepinwine/${COMS[i]}")
	let "i++"
	Update_link "$compath" "$ttypath"
    done
}

map_lp
map_serial
