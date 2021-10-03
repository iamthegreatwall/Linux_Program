#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        printf("fork error");
        exit(EXIT_FAILURE);
    }
    else if(pid==0)
    {
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
    }
    exit(0);
}

static void charatatime(char * str)
{
    char *ptr;
    int c;
    setbuf(stdout,NULL);//关闭缓冲
    for(ptr=str;(c=*ptr++)!=00;)
        putc(c,stdout);
}