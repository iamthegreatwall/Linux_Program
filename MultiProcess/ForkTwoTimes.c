#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{
    /*
    一个进程fork衣蛾子进程，但不要他等待子进程种植，也不希望子进程处于
    僵死状态直到父进程终止，可以通过调用fork两次来实现
    */
    pid_t pid;
    printf("父进程：pid=%ld\n",(long)getpid());
    if((pid=fork())<0)
    {
        printf("fork error");
        exit(EXIT_FAILURE);
    }
    else if(pid==0)
    {
        //fork one more tiomes
        if((pid=fork())<0)
        {
            printf("child process fork error");
            exit(EXIT_FAILURE);
        }
        else if(pid>0)
        {
            printf("第一代子进程：pid=%ld\n",(long)getpid());
            exit(EXIT_SUCCESS);/*first child*/
        }
        printf("第一代子进程：pid=%ld\n",(long)getpid());
        printf("第二代子进程：pid=%ld\n",(long)getpid());
        printf("第二代子进程（未睡眠前）：ppid=%ld\n",(long)getppid());
        sleep(2);
        printf("second child,parent pid=%ld\n",(long)getppid());
    }
    if(waitpid(pid,NULL,0)!=pid)
    {
        printf("waitpid error");
        exit(EXIT_FAILURE);
    }
    eixt(0);
}