#include "stdio.h"
#include <malloc.h>
#include <string.h>

void main ()
{
    char *hello = "Hello world";
    char *buffer;
    buffer = (char*)malloc(strlen(hello) * sizeof(char));

    strcpy(buffer, hello);
    strcpy(buffer, "Hello world");

    printf ("GitHub test %s",buffer);
    scanf("%s", buffer);

    free(buffer);
}