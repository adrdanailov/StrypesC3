/*
Strypes C3 cource - Homework 6-7 
Problem 9
Write simple “sprintf” function. The prototype of the function is "void SPRINTF(char* szBuffer, char* 
szPattern, char** args);” The “szBuffer” is the resulting string, “szPattern” is the format control. If and 
only if “%s” appears in the format string “szPattern”, it is replaced with the corresponding next argument 
from the “args”. 
Example: 
const char* args[ ] = { “Arg1”, “Arg2” }; 
SPRINTF(szBuffer, “This function takes %s and %s as arguments\n”, args ); , 
Should print: This function takes Arg1 and Arg2 as arguments\n”
*/

#include <stdio.h>
#include <stdlib.h>

void SPRINTF(char* szBuffer, char* szPattern, char** args);

int main(void)
{   
    const char* args[ ] = { "Arg1", "Arg2" }; 
    char result[100];
    SPRINTF(result, "This function takes %s and %s as arguments\n", args);
    printf("%s", result);
    return EXIT_SUCCESS;
}

void SPRINTF(char* szBuffer, char* szPattern, char** args)
{
    sprintf(szBuffer, szPattern, args[0], args[1]); //insert Jackie Chan "Mind Blown" meme here :) 
}
