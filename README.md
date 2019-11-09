# Deepin wine for Ubuntu and Debian

## 一、项目介绍

> Deepin-wine 环境的 Ubuntu/Debian 移植版 

> 使用deepin原版二进制文件，解决依赖问题

> 仅供个人研究学习使用

> 刚刚适配debian，可能在安装或运行上还存在问题,欢迎反馈！

## 二、软件架构

软件架构说明

### （1）安装教程

#### 在线安装(目前尚有bug)

直接使用在线安装脚本，安装最新的Release版本:

```bash
wget -qO- https://raw.githubusercontent.com/wszqkzqk/deepin-wine-ubuntu/master/online_install.sh | bash -e
```

#### 本地安装(Ubuntu/Debian通用)

* 克隆 (`git clone https://github.com/wszqkzqk/deepin-wine-ubuntu.git`) 或[下载](https://github.com/wszqkzqk/deepin-wine-ubuntu/archive/master.zip)到本地。
* 在中国推荐用下面的地址，速度更快： (`git clone https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu.git`) 
* 当然也可以选择下载releases：[Github](https://github.com/wszqkzqk/deepin-wine-ubuntu/releases) 或者
[Gitee](https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu/releases)

* 解压后切换到解压文件目录，在终端中运行（授予可执行权限后）： `./install.sh` 

    KDE或其他按照普通安装方式安装后运行出现X错误的桌面环境执行 `./KDE-install.sh`  ）。


### （2）使用说明

下载并安装所需要的deepin-wine容器 *（建议在终端下使用dpkg -i安装容器，否则容易误报依赖错误）*

可使用deepin发布的最新版容器安装包：

1. [QQ](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im/)
2. [TIM](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.office/)
3. [QQ轻聊版](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im.light/)
4. [微信](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.wechat/) 如果出现依赖错误，请下载[这个版本](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb)
5. [Foxmail](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.foxmail/)
6. [百度网盘](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.baidu.pan/)
7. [360压缩](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.cn.360.yasuo/)
8. [WinRAR](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.cn.com.winrar/)
9. [迅雷极速版](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.thunderspeed/)
10. [千牛卖家工作台](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.taobao.aliclient.qianniu/)

其它deepin-wine容器：[阿里云镜像下载](https://mirrors.aliyun.com/deepin/pool/non-free/d/)

#### 若版本不兼容，可选择下载安装以下旧版包文件：

1. [QQ](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.qq.im_9.1.8deepin0_i386.deb)
2. [TIM](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.qq.office_2.0.0deepin4_i386.deb)
3. [QQ轻聊版](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.qq.im.light_7.9.14308deepin8_i386.deb)
4. [微信](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb)
5. [Foxmail](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.foxmail_7.2deepin3_i386.deb)
6. [百度网盘](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.baidu.pan_5.7.3deepin0_i386.deb)
7. [360压缩](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.cn.360.yasuo_4.0.0.1060deepin3_i386.deb)
8. [WinRAR](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.cn.com.winrar_5.3.0deepin2_i386.deb)
9. [迅雷极速版](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.thunderspeed_7.10.35.366deepin18_i386.deb)


注意：**1.目前基本适配最新版KDE，但测试可能不足(已测试可用：最新版KDE neon、Kubuntu 18.04/18.0.1/18.0.2)，欢迎大家测试反馈（建议将KDE升级到最新版）**
     **2.部分桌面环境无法正常使用视频通话功能！**

### （3）关于托盘

Ubuntu 18.04 下（Gnome 桌面）：

安装 Gnome Shell 插件：[TopIcons Plus](https://extensions.gnome.org/extension/1031/topicons/)

### （4）TIM 的可选操作--Flash 的安装方法
*本操作无必要性
1. 下载需要的 install_flash_player_ppapi.exe 
2. 将下载的安装文件放入 ~/.deepinwine/Deepin-TIM/drive_c 下，即 TIM 所在 Wine C 盘根目录
3. 打开一个 Terminal ，执行：
```
WINEPREFIX=~/.deepinwine/Deepin-TIM deepin-wine "c:\\install_flash_player_ppapi.exe"
```
然后按提示进行安装、重启 TIM 即可。

### （5）手动更改配置（winecfg）
执行 `WINEPREFIX=~/.deepinwine/容器名称 deepin-wine winecfg` 即可，也可以用此方法来调整缩放问题

### （6）解决系统非中文语言环境时软件无法设置为中文
在/opt/deepinwine/tools/run.sh 中将 WINE_CMD 那一行修改为 WINE_CMD="LC_ALL=zh_CN.UTF-8 deepin-wine"

### （7）卸载方法

* 执行uninstall.sh即可

### （8）微信更新问题
* 如果出现微信提示跟新问题执行这一条语句即可
```
 wget -qO- https://deepin-wine.i-m.dev/setup.sh | sudo sh
```

### （7）最近问题
部分环境出现deepin最新容器无法安装的问题，主要是因为这套软件包为了保证兼容性，保持了较旧的软件包版本，使得某些deepin新打包的容器无法正常获得依赖关系，可以到[这里下载兼容包](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu)

另外，希望大家遇到问题时，先检测自己的deepin-wine环境是否升级到了最新版。

## 三、参与贡献

* 1. Fork 本项目
* 2. 新建 Feat_xxx 分支
* 3. 提交代码
* 4. 新建 Pull Request
* 5. 捐赠：
1. [捐赠开发者](https://bbs.deepin.org/forum.php?mod=viewthread&tid=40784&extra=page%3D1)

2. 捐赠打包者（这个其实不需要，我的贡献并不多，支持deepin就好了，不过有人在问，我就加上吧）
![](https://raw.githubusercontent.com/wszqkzqk/deepin-wine-ubuntu/master/donate.jpg)
![](https://!raw.githubusercontent.com/wszqkzqk/deepin-wine-ubuntu/master/donate.png)

欢迎大家积极反馈！

    *本软件最近更新可能有点缓慢
