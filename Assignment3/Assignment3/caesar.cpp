#include <string.h> 

char* encrypt(char* rawText, int key)
{
	for (int i = 0; i < strlen(rawText); i++)
	{
		rawText[i] += key;
	}
	return rawText;
}