#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char *string;

int validating_args(int argc, string argv[]);
string encryptor(string plain_text, int key);

int main(int argc, string argv[])
{
	int key = validating_args(argc, argv);
	if (key == -1)
	{
		return 1;
	}

	char plain_text[100];
	printf("Plain Text: ");

	fgets(plain_text, sizeof(plain_text), stdin);
	plain_text[strcspn(plain_text, "\n")] = '\0';

	string cipher_text = encryptor(plain_text, key);

	printf("ciphertext: %s\n", cipher_text);

	return 0;
}

string encryptor(string plain_text, int key)
{
	int text_length = strlen(plain_text);

	for (int i = 0; i < text_length; i++)
	{
		if (isalpha(plain_text[i]))
		{
			if (isupper(plain_text[i]))
			{
				plain_text[i] = (plain_text[i] - 'A' + (key)) % 26 + 'A';
			}
			if (islower(plain_text[i]))
			{
				plain_text[i] = (plain_text[i] - 'a' + (key)) % 26 + 'a';
			}
		}
	}

	return plain_text;
}

int validating_args(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Error! Expected 1 argument but %i received\n", argc - 1);
		printf("Use: ./caesar key\n");
		return -1;
	}

	char *argv_char = argv[1];
	for (int i = 0; argv_char[i] != '\0'; i++)
	{
		if (!isdigit(argv_char[i]))
		{
			printf("Error! Expected only positive integers as arguments\n");
			printf("Use: ./caesar key\n");
			return -1;
		}
	}

	long long_key = atoll(argv[1]);
	long max_number = pow(2, 31) - 1;
	if (long_key > max_number)
	{
		printf("Error! Number too large, the parameter cannot be greater than %ld\n", max_number);
		return -1;
	}

	if (long_key == 0)
	{
		printf("Error! Expected only positive integers as arguments\n");
		printf("Use: ./caesar key\n");
		return -1;
	}

	int int_key = (int)lround(long_key);
	return int_key;
}
