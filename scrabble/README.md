# Scrabble Score Calculator

This program calculates the Scrabble scores for two players based on the words they input. It assigns point values to each letter according to the standard Scrabble rules and then calculates the total score for each word. In the end, it displays the winner in the standard output.

## Execution

To execute the scrabble, use:

``` bash
./scrabble
```

## Code Structure

### `main`

The `main` function coordinates the execution of the program. It takes input from both players, calculates their scores, and determines the winner.

### Functions

1. [get_string](#get_string)
2. [calculate_word_points](#calculate_word_points)
3. [calculate_letter_points](#calculate_letter_points)

### `get_string`

This function reads a string from the user, dynamically allocating memory as needed to store the input.

**Parameters:**
: `text`: The prompt displayed to the user.

**Return:**
: A dynamically allocated string containing the user input.

### `calculate_word_points`

Calculates the Scrabble score for a word by summing the values returned by the `calculate_letter_points` function for each letter in the word.

**Parameters:**
: `word`: The word for which to calculate the score.

**Return:**
: The total Scrabble score for the word.

### `calculate_letter_points`

Calculates the point for each letter in the Scrabble game based on its position in the alphabet compared to the index in the array `int points[]`.

**Parameters:**
: `letter`: The letter for which to calculate the point value.

**Return:**
: The Scrabble point value of the letter.

## Compilation

If you, for any reason, wish to compile, you can use the following command:

```bash
gcc -g scrabble.c -o scrabble
```

> :warning: **Important!**
>
> You need to have GCC (GNU Compiler Collection) installed.
