#include <string.h> 

extern "C"
{
	__declspec(dllexport) char* encrypt(char* rawText, int key)
	{
		for (int i = 0; i < strlen(rawText); i++)
		{
			rawText[i] += key;
		}
		return rawText;
	}

	__declspec(dllexport) char* decrypt(char* encryptedText, int key)
	{
		for (int i = 0; i < strlen(encryptedText); i++)
		{
			encryptedText[i] -= key;
		}
		return encryptedText;
	}
}