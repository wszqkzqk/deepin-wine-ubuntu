#!/bin/bash -e

TMP_DIR="$(mktemp -d)"
RELEASE_ASSERTS_URL="$(wget -qO- -T10 --tries=10 --retry-connrefused https://api.github.com/repos/wszqkzqk/deepin-wine-ubuntu/releases/latest | grep browser_download_url | cut -d '"' -f 4)"

echo "开始下载deepin-wine安装包: ${RELEASE_ASSERTS_URL}, 请稍后..."
cd "${TMP_DIR}"
wget -c -T10 --tries=10 --show-progress -qO- "${RELEASE_ASSERTS_URL}" | tar zxf -

echo "正在安装, 请稍后(需要sudo提权)"
sudo dpkg --add-architecture i386
sudo apt update && sudo apt install -y "${TMP_DIR}"/*.deb

echo "安装完毕
您可以访问: https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/
下载您需要的deepin wine container"
