#!/bin/bash
echo '正在准备卸载...'
sudo apt-get purge `dpkg --get-selections | grep deepin | grep wine | awk '{print $1}'`
sudo apt remove --purge udis86
# sudo apt autoremove
echo '卸载完成...'
echo -e "如果您不是双显卡用户的话，请手动执行： sudo apt autoremove 来清除不必要的依赖。\n如果您是双显卡用户的话，请勿在您不清楚的情况下执行该条命令，可能导致显卡驱动的丢失！"
