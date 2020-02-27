#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *shell = getenv("MYSHELL");
    if (shell)
        printf("%x\n", (unsigned int)shell);
}