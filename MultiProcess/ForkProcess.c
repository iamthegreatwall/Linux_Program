#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int globvar=6;
char buf[] = "a write to stdout\n";
int main(void)
{
    int var=88;
    pid_t pid;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
    {
        printf("write error\n");
        exit(EXIT_FAILURE);
    }
    printf("父进程：pid=%ld\n",(long)getpid());
    printf("before fork\n");
    /*
        fork对于子进程返回0，对于·父进程返回子进程的ID（大于0），小于0则创建失败
        子进程和父进程继续执行fork调用之后的指令。
        子进程获得父进程数据空间、堆和栈的副本。不共享存储空间部分，共享正文段
    */
    pid = fork();
    if(pid<0)
    {
        
        printf("fork error");
    }
    else if(pid==0)
    {
        //当前为子进程
        printf("子进程：pid=%ld\n",(long)getpid());    
        globvar++;
        var++;
    }
    else
    {
        //当前为父进程
        printf("父进程：pid=%ld\n",(long)getpid());
        sleep(2);
    }
    printf("pid=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
    exit(0);
}