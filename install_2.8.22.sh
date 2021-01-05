#!/bin/bash
mkdir ./deepintemp
cd ./deepintemp
wget -O 1.1udis86_1.72-2_i386.deb https://community-packages.deepin.com/deepin/pool/non-free/u/udis86/udis86_1.72-2_i386.deb
wget -O 1.2deepin-fonts-wine_2.18-22~rc0_all.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-fonts-wine_2.18-22~rc0_all.deb
wget -O 2.1deepin-libwine_2.18-22~rc0_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-libwine_2.18-22~rc0_i386.deb
wget -O 2.2deepin-libwine-dbg_2.18-22~rc0_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-libwine-dbg_2.18-22~rc0_i386.deb
wget -O 2.3deepin-libwine-dev_2.18-22~rc0_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-libwine-dev_2.18-22~rc0_i386.deb
wget -O 3.1deepin-wine32_2.18-22~rc0_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-wine32_2.18-22~rc0_i386.deb
wget -O 3.2deepin-wine32-preloader_2.18-22~rc0_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-wine32-preloader_2.18-22~rc0_i386.deb
wget -O 3.3deepin-wine32-tools_2.18-22~rc0_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-wine32-tools_2.18-22~rc0_i386.deb
wget -O 4deepin-wine_2.18-22~rc0_all.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-wine_2.18-22~rc0_all.deb
wget -O 5deepin-wine-binfmt_2.18-22~rc0_all.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine/deepin-wine-binfmt_2.18-22~rc0_all.deb
wget -O 6.1deepin-wine-plugin_1.0deepin2_amd64.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine-plugin/deepin-wine-plugin_1.0deepin2_amd64.deb
wget -O 6.2deepin-wine-plugin-virtual_1.0deepin3_all.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine-plugin-virtual/deepin-wine-plugin-virtual_1.0deepin3_all.deb
wget -O 7deepin-wine-helper_1.2deepin8_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine-helper/deepin-wine-helper_1.2deepin8_i386.deb
wget -O 8deepin-wine-uninstaller_0.1deepin2_i386.deb http://packages.deepin.com/deepin/pool/non-free/d/deepin-wine-uninstaller/deepin-wine-uninstaller_0.1deepin2_i386.deb
wget http://ftp.debian.org/debian/pool/main/libj/libjpeg-turbo/libjpeg62-turbo_1.5.1-2_amd64.deb
wget http://ftp.debian.org/debian/pool/main/libj/libjpeg-turbo/libjpeg62-turbo_1.5.1-2_i386.deb

echo '准备添加32位支持'
sudo dpkg --add-architecture i386
echo '添加成功，准备刷新apt缓存信息...'
sudo apt update
echo '即将开始安装...'
sudo dpkg -i *.deb
echo '安装完成，正在自动安装依赖...'
sudo apt install -fy

rm -vfr ./deepintemp
