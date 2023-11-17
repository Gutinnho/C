#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int letter_counter(char *string, int length_string);
int word_counter(char *string, int length_string);
int sentence_counter(char *string, int length_string);
int index_calculation(char *string, int length_string);

int main(void)
{
	size_t buffer_size = 100;

	char *input = (char *)malloc(buffer_size * sizeof(char));

	if (input == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("Enter the text: ");

	int c;
	size_t index = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		input[index++] = c;

		if (index == buffer_size - 1)
		{
			buffer_size *= 2;
			input = (char *)realloc(input, buffer_size * sizeof(char));

			if (input == NULL)
			{
				printf("Memory reallocation failed.\n");
				return 1;
			}
		}
	}

	input[index] = '\0';

	int length_string = strlen(input);
	int result = index_calculation(input, length_string);

	printf("Index: %i\n", result);

	// Free dynamically allocated memory
	free(input);

	return 0;
}

int letter_counter(char *string, int length_string)
{
	int count = 0;

	for (int i = 0; i < length_string; i++)
	{
		if (isalpha(string[i]))
		{
			count++;
		}
	}

	return count;
}

int word_counter(char *string, int length_string)
{
	int count = 0;
	bool ends_with_space = isspace(string[length_string - 1]);

	for (int i = 0; i < length_string; i++)
	{
		if (isspace(string[i]))
		{
			count++;
		}
	}

	if (!ends_with_space)
	{
		count++;
	}

	return count;
}

int sentence_counter(char *string, int length_string)
{
	int count = 0;

	const char *delimiters = ".?!";

	for (int i = 0; i < length_string; i++)
	{
		if (strchr(delimiters, string[i]) != NULL)
		{
			count++;
		}
	}

	return count;
}

int index_calculation(char *string, int length_string)
{
	int number_of_letters = letter_counter(string, length_string);
	int number_of_words = word_counter(string, length_string);
	int number_of_sentences = sentence_counter(string, length_string);

	float average_letter_count = ((float)number_of_letters / (float)number_of_words) * 100;
	float average_sentence_count = ((float)number_of_sentences / (float)number_of_words) * 100;

	float index = 0.0588 * average_letter_count - 0.296 * average_sentence_count - 15.8;
	int int_index = roundf(index);

	return int_index;
}