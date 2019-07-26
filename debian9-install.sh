#!/bin/bash

##debian9-install.sh

cd `dirname $0`; pwd

echo '准备添加32位支持'
sudo dpkg --add-architecture i386
echo '添加成功，准备刷新apt缓存信息...'
sudo apt update
echo '即将开始安装...'

## （1）防止 依赖报错：（见本文附录1）
sudo apt-get install liblcms2-2:i386 libldap-2.4-2:i386   libmpg123-0:i386   libopenal1:i386   libpcap0.8:i386   libudev1:i386  libusb-1.0-0:i386   libxml2:i386   ocl-icd-libopencl1:i386  libxcursor1:i386  libxrandr2:i386  libxinerama1:i386  libxcomposite1:i386  libglu1-mesa:i386  libosmesa6:i386  libxslt1.1:i386  libgnutls30:i386  libv4l-0:i386  libcups2:i386 libtiff5:i386  libodbc1:i386 libjpeg-turbo8|libjpeg-turbo8:i386  -y

#sudo dpkg -i debian-special-pkgs/1.1-libjpeg-turbo8_2.0.1-0ubuntu2_i386.deb

## （2）防止错误提示缺少依赖：deepin-wine32-preloader_2.18-12:i386 
dpkg-deb --build deepin-wine32-preloader_2.18-12_i386
sudo dpkg -i *.deb

## （3）防止错误提示：deepin-wine_2.18-12_all与以安装的***_2.18-12:i386 版本不兼容。
## 注意，本deepin-wine_2.18-12_i386目录是从deepin-wine_2.18-12_all 复制并修改了部分文件架构从all改成i386，以和其他i386的deb包兼容。
dpkg-deb --build  debian-special-pkgs/deepin-wine_2.18-12_i386
sudo dpkg -i debian-special-pkgs/deepin-wine_2.18-12_i386.deb


## 这里由于debian 没有那么智能判断缺少的i386依赖，所以上面（1）里面  apt-get install xxx 命令主动安装多个相关的i386的软件包。
## 剩下的只作为补充遗漏：
echo '安装完成，正在自动安装依赖...'
sudo apt install -f

echo '如果以上没提示错误，说明安装成功。您还可以执行./install-taobao.qianniu.sh 命令以安装 千牛客户端软件'

######  附录1
######可能出现的报错内容：
##依赖: liblcms2-2:i386 (>= 2.2+git20110628) 
##依赖: libldap-2.4-2:i386 (>= 2.4.7) 
##依赖: libmpg123-0:i386 (>= 1.13.7) 
##依赖: libopenal1:i386 (>= 1.14) 
##依赖: libpcap0.8:i386 (>= 0.9.8) 
##依赖: libudev1:i386 (>= 183) 
##依赖: libusb-1.0-0:i386 (>= 2:1.0.16) 
##依赖: libxml2:i386 (>= 2.9.0) 
##依赖: ocl-icd-libopencl1:i386  或
        ##libopencl1:i386
##依赖: ocl-icd-libopencl1:i386 (>= 1.0)  或
        ##libopencl-1.1-1:i386
##依赖: libxcursor1:i386 
##依赖: libxrandr2:i386 
##依赖: libxinerama1:i386 
##依赖: libxcomposite1:i386 
##依赖: libglu1-mesa:i386 
##依赖: libosmesa6:i386 
##依赖: libxslt1.1:i386 
##依赖: libgnutls30:i386 
##依赖: libv4l-0:i386 
##依赖: libcups2:i386 
##依赖: libjpeg-turbo8:i386 但无法安装它
##依赖: libtiff5:i386 
##依赖: libodbc1:i386 
