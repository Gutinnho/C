#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

int validate_args(int argc, char *argv[]);
char *get_cripted_text(void);
int get_valid_key(void);
void decryptor_without_key(char *plain_text);
void decryptor_with_key(char *plain_text, int key);

int main(int argc, char *argv[])
{
	int validate_args_return = validate_args(argc, argv);
	if (validate_args_return == -1)
	{
		return 1;
	}

	printf("Cripted text: ");

	char *cripted_text = get_cripted_text();
	if (cripted_text == NULL)
	{
		return 1;
	}

	printf("\n");

	switch (validate_args_return)
	{
	case 1:
		decryptor_without_key(cripted_text);

		break;
	case 2:
		int key = get_valid_key();
		decryptor_with_key(cripted_text, key);

		break;
	default:
		printf("Internal Error!\n");
		return 1;
	}

	free(cripted_text);

	return 0;
}

int validate_args(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error! Expected 1 argument but %i received\n", argc - 1);
		printf("Use: ./decryptor [b/bruteforce/k/key]\n");
		return -1;
	}

	char lowercaseArg[20];
	strcpy(lowercaseArg, argv[1]);
	for (int i = 0; i < strlen(lowercaseArg); i++)
	{
		lowercaseArg[i] = tolower(lowercaseArg[i]);
	}

	if (strcmp(lowercaseArg, "b") == 0 || strcmp(lowercaseArg, "bruteforce") == 0)
	{
		return 1;
	}
	else if (strcmp(lowercaseArg, "k") == 0 || strcmp(lowercaseArg, "key") == 0)
	{
		return 2;
	}
	else
	{
		printf("Error! Invalid argument\n");
		printf("Use: ./decryptor [b/bruteforce/k/key]\n");
		return -1;
	}
}

char *get_cripted_text(void)
{
	char *cripted_text = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read = getline(&cripted_text, &buffer_size, stdin);

	if (characters_read == -1)
	{
		printf("Error reading input\n");
		free(cripted_text);
		return NULL;
	}

	cripted_text[strcspn(cripted_text, "\n")] = '\0';

	return cripted_text;
}

int get_valid_key(void)
{
	long long_input;

	printf("Key: ");
	scanf("%li", &long_input);

	if (long_input < INT_MIN || long_input > INT_MAX)
	{
		get_valid_key();
	}

	return (int)long_input;
}

void decryptor_without_key(char *plain_text)
{
	int text_length = strlen(plain_text);
	char temp[text_length + 1];

	for (int key = 1; key <= 25; ++key)
	{
		strcpy(temp, plain_text);

		for (int i = 0; i < text_length; i++)
		{
			if (isalpha(plain_text[i]))
			{
				if (isupper(plain_text[i]))
				{
					temp[i] = ((plain_text[i] - 'A' + key) + 26) % 26 + 'A';
				}
				else if (islower(plain_text[i]))
				{
					temp[i] = ((plain_text[i] - 'a' + key) + 26) % 26 + 'a';
				}
			}
		}
		printf("->%i (<-%i) | %s\n", key, 25 - (key - 1), temp);
	}
}

void decryptor_with_key(char *plain_text, int key)
{
	int text_length = strlen(plain_text);

	for (int i = 0; i < text_length; i++)
	{
		if (isalpha(plain_text[i]))
		{
			if (isupper(plain_text[i]))
			{
				plain_text[i] = ((plain_text[i] - 'A' - key) + 26) % 26 + 'A';
			}
			else if (islower(plain_text[i]))
			{
				plain_text[i] = ((plain_text[i] - 'a' - key) + 26) % 26 + 'a';
			}
		}
	}

	printf("Decrypted text: %s", plain_text);
}
