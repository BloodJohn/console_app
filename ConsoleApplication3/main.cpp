#include "stdio.h"
#include <malloc.h>
#include <string.h>

void main ()
{
    //change by BloodJohn at work

    char *hello = "Hello world";
    char *buffer;
    buffer = (char*)malloc(strlen(hello) * sizeof(char));

    strcpy(buffer, hello);
    strcpy(buffer, "Hello world");

    printf ("GitHub test %s",buffer);
    scanf("%s", buffer);
	//some comment from home
	//two second comment
    free(buffer);
}