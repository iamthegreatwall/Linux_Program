#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
    char buf[30];
    int n; 
    int fd = -1;
    if((fd=open("file1.txt",O_RDWR))<0)
    {
        printf("open fail");
        exit(EXIT_FAILURE);
    }
    while((n=read(fd,buf,30))>0)
    {
        if(write(STDOUT_FILENO,buf,n)!=n)
        {
            printf("write error");
            exit(EXIT_FAILURE);
        }
    }
    if(n<0)
    {
        printf("read error");
        exit(EXIT_FAILURE);
    }
    return 0;
}