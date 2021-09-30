#include<stdio.h>
#include<unistd.h>
int globvar = 6;
int main(void)
{
    int var=88;
    pid_t pid;
        printf("before fork\n");
    /*
        vFork用于创建一个新进程，但是他并不将父进程的地址空间完全复制到子进程中，
        在子进程调用exec或exit之前，他在父进程的地址空间中运行，因此可以修改父进程中的数据
        另外，vFork会保证子进程先运行，在调用exec或exit之后父进程才有可能被调度（可能发生死锁）
    */
    pid = fork();
    if((pid = vfork())<0)
    {
        
        printf("vfork error");
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