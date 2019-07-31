#/bin/bash
# Author：IITII
echo "如果您想完全卸载 deep-wine 和 32位软件包 并且 移除 32位 支持的话，"
echo "如果您已知可能发生的后果的话，"
echo "输入 1 继续，输入 0 退出："
read i
if [ $i -eq 1 ]; then
    echo "移除32位软件包..."
    sudo apt-get remove --purge $(dpkg --get-selections | grep i386 | awk '{print $1}')
    echo "移除 32位 支持..."
    sudo dpkg --remove-architecture i386
elif [ $i -eq 0 ]; then
    echo "操作取消..."
    exit 0
else
    echo "请输入正确的数字!!"
    exit 1
fi
