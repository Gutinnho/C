#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

char *get_plain_text(void);
int get_valid_key(void);
void encryptor(char *plain_text, int key);

int main(void)
{
	printf("Plain text: ");

	char *plain_text = get_plain_text();
	if (plain_text == NULL)
	{
		return 1;
	}

	int key = get_valid_key();
	printf("\n");
	encryptor(plain_text, key);

	free(plain_text);

	return 0;
}

char *get_plain_text(void)
{
	char *plain_text = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read = getline(&plain_text, &buffer_size, stdin);

	if (characters_read == -1)
	{
		printf("Error reading input\n");
		free(plain_text);
		return NULL;
	}

	plain_text[strcspn(plain_text, "\n")] = '\0';

	return plain_text;
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

void encryptor(char *plain_text, int key)
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

	printf("Encrypted text: %s\n", plain_text);
}
