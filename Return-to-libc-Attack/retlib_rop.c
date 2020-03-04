#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char *str)
{
    char buffer[12];
    unsigned int *framep;
    asm("movl %%ebp, %0"
        : "=r"(framep));
    printf("Address of buffer[] : 0x%.8x\n", (unsigned)buffer);
    printf("Frame Pointer value : 0x%.8x\n", (unsigned)framep);

    strcpy(buffer, str);
    return 1;
}

void bar()
{
    static int i = 0;
    printf("The function bar() is invoked %d times!\n", ++i);
}

void baz(int x)
{
    printf("The value of baz()'s argument: 0x%.8x\n", x);
}

int main(int argc, char **argv)
{
    char str[2000];
    FILE *badfile;

    char *shell = (char *)getenv("MYSHELL");
    if (shell)
    {
        printf("%s is in 0x%.8x\n", shell, (unsigned)&shell);
    }
    badfile = fopen("badfile","r");
    fread(str,sizeof(char),2000,badfile);
    foo(str);
    printf("Returned Properly\n");
    return 1;
}