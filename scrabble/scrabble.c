#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

char *get_string(char *text);
int calculate_word_points(char *word);
int calculate_letter_points(char letter);

int main(void)
{
	char *player1Word = get_string("Player 1: ");
	char *player2Word = get_string("Player 2: ");

	int player1Score = calculate_word_points(player1Word);
	int player2Score = calculate_word_points(player2Word);

	printf("Player 1's score: %d\n", player1Score);
	printf("Player 2's score: %d\n", player2Score);

	printf("%s\n", (player1Score > player2Score) ? "Player 1 wins!" : (player1Score < player2Score) ? "Player 2 wins!"
																																																	: "Tie!");

	free(player1Word);
	free(player2Word);

	return 0;
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

int calculate_word_points(char *word)
{
	int wordLength = strlen(word);
	int score = 0;

	for (int i = 0; i < wordLength; i++)
	{
		score += calculate_letter_points(word[i]);
	}

	return score;
}

int calculate_letter_points(char letter)
{
	if (isupper(letter))
	{
		return points[letter - 'A'];
	}
	else if (islower(letter))
	{
		return points[letter - 'a'];
	}
	else
	{
		return 0;
	}
}
