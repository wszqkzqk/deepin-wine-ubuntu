#!/bin/bash
cd `dirname $0`; pwd
sudo apt update
echo '即将开始安装...'
sudo dpkg -i *.deb
echo '安装完成，正在自动安装依赖...'
sudo apt install -f


