#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *shell = getenv("MYSHELL");
    if (shell)
        printf("%s is in %x\n", shell, (unsigned int)shell);
}