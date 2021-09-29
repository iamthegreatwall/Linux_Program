#include<stdio.h>
#include<fcntl.h>
int main()
{
    int flag = 0;
    if((flag=creat("createfile.txt",O_CREAT))==-1)
    {
        printf("创建文件失败");
    }
    else
    {
        printf("创建文件成功");
    }
    return 0;
}