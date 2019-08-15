#!/bin/bash -e

TMP_DIR="$(mktemp -d)"
RELEASE_ASSERTS_URL="$(wget -qO- -T10 --tries=10 --retry-connrefused https://api.github.com/repos/wszqkzqk/deepin-wine-ubuntu/releases/latest | grep browser_download_url | cut -d '"' -f 4)"

echo "开始下载deepin-wine安装包: ${RELEASE_ASSERTS_URL}, 请稍候..."
wget -c -T10 --tries=10 --show-progress -qO- "${RELEASE_ASSERTS_URL}" | tar zxf - -C "${TMP_DIR}"

echo "正在安装, 请稍后(需要sudo提权)"
sudo dpkg --add-architecture i386
sudo apt update && sudo apt install -y "${TMP_DIR}"/*.deb

rm -fr "${TMP_DIR}"

if [ "x${XDG_CURRENT_DESKTOP}" = "xKDE" ]; then
    echo "==========================================================================="
    echo "检测到KDE环境，将安装gnome-settings-daemon并下载gsd-xsettings.sh配置"
    sudo apt install -y gnome-settings-daemon
    mkdir -p "${HOME}/.config/autostart-scripts/"
    wget -T10 --tries=10 --show-progress -q -O "${HOME}/.config/autostart-scripts/gsd-xsettings.sh" https://raw.githubusercontent.com/wszqkzqk/deepin-wine-ubuntu/master/gsd-xsettings.sh
    chmod 755 "${HOME}/.config/autostart-scripts/gsd-xsettings.sh"
    echo "==========================================================================="
fi

echo "安装完毕,您可以访问: https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/,下载您需要的deepin wine container"
