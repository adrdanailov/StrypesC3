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
#include <string.h>


void SPRINTF(char* szBuffer, char* szPattern, char** args);
void SPRINTF_UC(char* szBuffer, char* szPattern, char** args);
void SPRINTF_BF(char* szBuffer, char* szPattern, char** args);

int main(void)
{
    const char* args[ ] = { "Arg1", "Arg2" };
    char result[100];
	char result_BF[111];
	char result_UC[100];
	SPRINTF_UC(result_UC, "This function takes %s and %s as arguments\n", args);
	printf("UC_RESULT: %s", result_UC);
  	SPRINTF_BF(result_BF, "This function takes %s and %s as arguments\n", args);
	printf("BF_RESULT: %s", result_BF);
    SPRINTF(result, "This function takes %s and %s as arguments\n", args);
	printf("\nRESULT: %s", result);
    return EXIT_SUCCESS;
}


void SPRINTF_UC(char* szBuffer, char* szPattern, char** args) // UC - upper case :)
{
    sprintf(szBuffer, szPattern, args[0], args[1]); //insert Jackie Chan "Mind Blown" meme here :)
}


void SPRINTF(char* szBuffer, char* szPattern, char** args) //strtok() and strcat() vertion
{
	char s[3] = "%";	//special char %
	char* tok = malloc(strlen(szPattern)*sizeof(char));	//initializing tok to be the same size as szPattern
	tok = strcpy(tok, szPattern);
	int i = 0;  // % instance counter
	tok = strtok(tok, s);
	szBuffer = strcat(szBuffer, tok);
	do
	{
		tok = strtok(NULL, s); //when NULL keeps pointing to the previous address TOK
		if (tok == NULL) // second check needed cuz tok[] is used
			break;
		if (tok[0]=='s')
		{
			if(args[i] != NULL)  //checking for arguments count to be as count of %
			{
				szBuffer = strcat(szBuffer, args[i++]);
				szBuffer = strcat(szBuffer, (tok+1));
			}else
			{
				fprintf(stderr, "Argmunet missing for %%s !");
				break;
			}
		}
		else
			szBuffer = strcat(szBuffer, strcat(tok, "%"));
	}while (tok != NULL);
	free(tok);
}

void SPRINTF_BF(char* szBuffer, char* szPattern, char** args) //BF - Brute Force index by index
{
	unsigned size = strlen(szPattern) + 1;
	unsigned max_size = size;
	unsigned k = 0;
	while(args[k])
		max_size += strlen(args[k++]);
	char temp[max_size];
	unsigned arg_counter = 0;
	unsigned p_index = 0;
	for(unsigned i = 0; i < size; i++)
	{
		if (szPattern[i] == '%' && szPattern[i+1] == 's')
		{
			if ((k--))
			{
				for(unsigned j = 0; j < strlen(args[arg_counter]); j++)
					temp[j + i + p_index] = args[arg_counter][j];
				p_index += (strlen(args[arg_counter]));
				arg_counter++;

			}else
			{
				fprintf(stderr, "Argmunet missing for %%s !");
				break;
			}
			i++; //skiping 's'
			p_index-=2;
		}else
		{
			temp[i + p_index] = szPattern[i];
		}
	}
	strcpy(szBuffer, temp);
}
