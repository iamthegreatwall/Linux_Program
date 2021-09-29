#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    printf("HOME: %s\n",getenv("HOME"));
    //printf("PATH: %s\n",getenv("PATH"));
    printf("LOGNAME: %s\n",getenv("LOGNAME"));
    printf("PWD: %s\n",getenv("PWD"));
    printf("LANG: %s\n",getenv("LANG"));
    return 0;
}