#!/bin/bash

## 从深度在线镜像仓库拉取千牛安装包，安装到系统
cd `dirname $0`; pwd

mkdir -p debian-special-pkgs

wget -O debian-special-pkgs/deepin.com.taobao.aliclient.qianniu_6.06.02Ndeepin2_i386.deb https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.taobao.aliclient.qianniu/deepin.com.taobao.aliclient.qianniu_6.06.02Ndeepin2_i386.deb 

echo '开始安装千牛，请注意查看是否有提示错误...'

sudo dpkg -i deepin.com.taobao.aliclient.qianniu_6.06.02Ndeepin2_i386.deb 

echo '千牛安装结束，请打开普通用户的命令行，以普通用户权限，命令方式启动千牛工作台 /opt/deepinwine/apps/Deepin-QianNiu/run.sh（或通过debian的系统菜单里找到 千牛工作台 运行） 。千牛初次启动有点慢，请耐心等待1分钟左右。以后再启动会比较快'
