/*  Name: William Kreiser
    Date: 11 July 18
    Lab4A: Basic I/O Pt1
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char inputChar;
    printf("Please enter a character: \n");
    inputChar = getchar();
    putchar(inputChar +1);
    printf("\n");
    
    return 0;
}