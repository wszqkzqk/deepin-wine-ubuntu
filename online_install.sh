#!/bin/bash -e

TMP_DIR="$(mktemp -d)"
DOWNLOAD_URL_PREFIX="https://github.com/wszqkzqk/deepin-wine-ubuntu/blob/master"

echo "开始下载deepin-wine安装包, 请稍后..."
wget -P "${TMP_DIR}" --content-disposition -c -T10 --tries=10 -q --show-progress "${DOWNLOAD_URL_PREFIX}"/{1.1udis86_1.72-2_i386.deb,1.2deepin-fonts-wine_2.18-12_all.deb,2.1deepin-libwine_2.18-12_i386.deb,2.2deepin-libwine-dbg_2.18-12_i386.deb,2.3deepin-libwine-dev_2.18-12_i386.deb,3.1deepin-wine32_2.18-12_i386.deb,3.2deepin-wine32-preloader_2.18-12_i386.deb,3.3deepin-wine32-tools_2.18-12_i386.deb,4deepin-wine_2.18-12_all.deb,5deepin-wine-binfmt_2.18-12_all.deb,6.1deepin-wine-plugin_1.0deepin2_amd64.deb,6.2deepin-wine-plugin-virtual_1.0deepin1_all.deb,7deepin-wine-helper_1.1deepin12_i386.deb,8deepin-wine-uninstaller_0.1deepin2_i386.deb}"?raw=true"

echo "正在安装, 请稍后"
sudo dpkg --add-architecture i386
sudo apt update && sudo apt install -y "${TMP_DIR}"/*.deb

echo "安装完毕
您可以访问: https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/
下载您需要的deepin wine container"
