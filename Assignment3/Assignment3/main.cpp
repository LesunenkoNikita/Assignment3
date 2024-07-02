#include <Windows.h>
#include <iostream>
#include "caesar.cpp"
using namespace std;

int main(void)
{
	typedef char* (*encrypt_ptr_t)(char*, int);
	typedef char* (*decrypt_ptr_t)(char*, int);
	HINSTANCE handle = LoadLibrary(TEXT("caesar.dll"));
	if
		(handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		cout << "Lib not found" << endl;
		return 1;
	}
	encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
	if (encrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}
	decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
	if (decrypt_ptr == nullptr)
	{
		cout << "Function not found" << endl;
		return 1;
	}
	printf("All available commands:\n\
	1 - To ecnrypt a message\n\
	2 - To decrypt a message\n\
	3 - To exit\n\
		");
	while (1)
	{
		printf("Enter the command: ");
		char input[16];
		fgets(input, 16, stdin);
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "1") == 0)
		{
			printf("Enter the text you want to encrypt: ");
			char text[256];
			fgets(text, 256, stdin);
			text[strcspn(text, "\n")] = '\0';
			printf("Enter the key you want to encrypt the text with: ");
			char key_input[16];
			fgets(key_input, 16, stdin);
			key_input[strcspn(key_input, "\n")] = '\0';
			int key = atoi(input);
			printf(encrypt(text, key));
			printf('\n');
			continue;
		}
		else if (strcmp(input, "2") == 0)
		{
			printf("Enter the text you want to decrypt: ");
			char text[256];
			fgets(text, 256, stdin);
			text[strcspn(text, "\n")] = '\0';
			printf("Enter the key you want to decrypt the text with: ");
			char key_input[16];
			fgets(key_input, 16, stdin);
			key_input[strcspn(key_input, "\n")] = '\0';
			int key = atoi(input);
			printf(decrypt(text, key));
			printf('\n');
			continue;
		}
		else
		{
			break;
		}
	}
	FreeLibrary(handle);
	return 0;
}