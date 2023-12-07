#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void validate_arguments(int argc, char *argv_string);
char *get_string(char *text);
char *substitutor(char *scrambled_alphabet, char *plain_text);

int main(int argc, char *argv[])
{
	char *argv_string = argv[1];
	validate_arguments(argc, argv_string);

	char *plain_text = get_string("Text: ");
	if (!plain_text)
		return EXIT_FAILURE;

	char *text = substitutor(argv_string, plain_text);
	printf("Substituted text: %s\n", text);

	free(plain_text);

	return EXIT_SUCCESS;
}

void validate_arguments(int argc, char *argv_string)
{
	if (argc != 2)
	{
		fprintf(stderr, "Error! Expected 1 argument but received %i\n", argc - 1);
		fprintf(stderr, "Usage: ./substitution cipher\n");
		exit(EXIT_FAILURE);
	}

	int argv_length = strlen(argv_string);

	if (argv_length != 26)
	{
		fprintf(stderr, "Error! Expected a string of 26 characters, but received a string of %i characters\n", argv_length);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; argv_string[i] != '\0'; i++)
	{
		if (!isalpha(argv_string[i]))
		{
			fprintf(stderr, "Error! Expected only alphabetical letters\n");
			exit(EXIT_FAILURE);
		}
	}

	bool characters[26] = {false};

	for (int i = 0; argv_string[i] != '\0'; i++)
	{
		char c = tolower(argv_string[i]);
		int index = c - 'a';

		if (characters[index])
		{
			fprintf(stderr, "Error! Duplicate characters found in the cipher\n");
			exit(EXIT_FAILURE);
		}
		characters[index] = true;
	}
}

char *get_string(char *text)
{
	int size_buffer = 10;
	int size = 0;

	char *string = malloc(sizeof(char) * 100);
	if (!string)
	{
		fprintf(stderr, "Memory not enough\n");
		exit(EXIT_FAILURE);
	}

	printf("%s", text);

	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		string[size++] = (char)c;

		if (size == size_buffer - 1)
		{
			size_buffer *= 2;
			string = realloc(string, sizeof(char) * size_buffer);

			if (string == NULL)
			{
				fprintf(stderr, "Memory not enough\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	string[size] = '\0';

	if (size == 0 && c == EOF)
	{
		free(string);
		return NULL;
	}

	return string;
}

char *substitutor(char *scrambled_alphabet, char *plain_text)
{
	int plain_text_length = strlen(plain_text);

	for (int i = 0; i < plain_text_length; i++)
	{
		char original_char = plain_text[i];

		if (isupper(plain_text[i]))
		{
			int index = plain_text[i] - 'A';
			plain_text[i] = scrambled_alphabet[index];
		}
		else if (islower(plain_text[i]))
		{
			int index = plain_text[i] - 'a';
			plain_text[i] = scrambled_alphabet[index];
		}

		if (isupper(original_char))
		{
			plain_text[i] = toupper(plain_text[i]);
		}
		else if (islower(original_char))
		{
			plain_text[i] = tolower(plain_text[i]);
		}
	}

	return plain_text;
}
