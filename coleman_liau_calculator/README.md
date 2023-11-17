# Coleman-Liau Index Calculator

This is a code used to calculate the **Coleman-Liau index**.

The Coleman-Liau formula is a mathematical formula used to calculate the readability index of an English text. This index is a measure of the text's readability based on the average number of letters per 100 words and the average number of sentences per 100 words. The formula is given by:

> **index = 0.0588 × average letters per 100 words − 0.296 × average sentences per 100 words − 15.8**

## Code Structure

The **`main`** starts by asking the user for a text, then reads the text from input (terminated by EOF or a new line) and dynamically allocates this input.

The **`index_calculation`** function calculates the Coleman-Liau index using the results from the functions: letter_counter, word_counter, and sentence_counter.

**`letter_counter`:** Counts the number of letters in a string, ignoring spaces and other non-alphabetic characters.

**`word_counter`:** Counts the number of words in a string, assuming words are separated by spaces.

**`sentence_counter`:** Counts the number of sentences in a string, using delimiters like a period, exclamation point, and question mark.

Finally, the **`index_calculation`** returns the result of the calculation, rounded to the nearest integer.

Within the **`main`**, the index is displayed to the user.

In the end, the dynamically allocated memory for the input string is freed using **`free(input)`** to prevent memory leaks.

## License

This code is distributed under the **MIT License**.
