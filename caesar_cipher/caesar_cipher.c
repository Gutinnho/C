#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

int validating_args(int argc, char *argv[]);
char *encryptor(char *plain_text, int key);

int main(int argc, char *argv[])
{
	int key = validating_args(argc, argv);
	if (key == -1)
	{
		return 1;
	}

	printf("Plain Text: ");

	char *plain_text = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read = getline(&plain_text, &buffer_size, stdin);

	if (characters_read == -1)
	{
		printf("Error reading input.\n");
		free(plain_text);
		return 1;
	}

	plain_text[strcspn(plain_text, "\n")] = '\0';
	char *cipher_text = encryptor(plain_text, key);

	printf("ciphertext: %s\n", cipher_text);

	free(plain_text);

	return 0;
}

char *encryptor(char *plain_text, int key)
{
	int text_length = strlen(plain_text);

	for (int i = 0; i < text_length; i++)
	{
		if (isalpha(plain_text[i]))
		{
			if (isupper(plain_text[i]))
			{
				plain_text[i] = ((plain_text[i] - 'A' + key) + 26) % 26 + 'A';
			}
			if (islower(plain_text[i]))
			{
				plain_text[i] = ((plain_text[i] - 'a' + key) + 26) % 26 + 'a';
			}
		}
	}

	return plain_text;
}

int validating_args(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error! Expected 1 argument but %i received\n", argc - 1);
		printf("Use: ./caesar key\n");
		return -1;
	}

	char *endptr;
	long long_key = strtol(argv[1], &endptr, 10);

	if (*endptr != '\0' || (long_key == 0 && argv[1][0] != '0'))
	{
		printf("Error! Expected integer\n");
		printf("Use: ./caesar key\n");
		return -1;
	}

	long max_number = (1L << 31) - 1;
	if (long_key > max_number || long_key < INT_MIN || long_key > INT_MAX)
	{
		printf("Error! Number out of range, the parameter must be between %d and %ld\n", INT_MIN, max_number);
		return -1;
	}

	if (long_key == 0)
	{
		printf("Error! The key cannot be zero\n");
		printf("Use: ./caesar key\n");
		return -1;
	}

	return (int)long_key;
}