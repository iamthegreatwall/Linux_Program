#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
void myExit1();
void myExit2();
int main()
{
    if((atexit(myExit1))!=0)
    {
        printf("can't register myExit1");
        exit(EXIT_FAILURE);
    }
    if((atexit(myExit1))!=0)
    {
        printf("can't register myExit1");
        exit(EXIT_FAILURE);
    }
    if((atexit(myExit2))!=0)
    {
        printf("can't register myExit2");
        exit(EXIT_FAILURE);
    }
    printf("main is done\n");
    return 0;
}
void myExit1()
{
    printf("first myExit\n");
}

void myExit2()
{
    printf("second myExit\n");
}