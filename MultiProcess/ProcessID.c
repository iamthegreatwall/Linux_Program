#include<stdio.h>
#include<unistd.h>
int main(void)
{
    printf("pid: %d\n",getpid());
    /*
    printf("parent pid: %d\n",getppid());
    printf("uid: %d\n",getuid());
    printf("effective uid: %d\n",geteuid());
    printf("gid: %d\n",getgid());
    printf("effective gid: %d\n",getegid());
    */
    return 0;
}