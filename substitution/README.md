# Substitution Cipher

This program implements a substitution cipher, where each letter in the alphabet is replaced with another letter based on a provided key.

## Execution

To execute the program, use:

```bash
./substitution cipher
```

Here, "cipher" represents a 26-character key, each character being a unique letter of the alphabet.

## Code Structure

The program consists of the following components:

### `main`

This function serves as the entry point for the program. It validates command line arguments, obtains plain text input from the user, performs substitution using a provided cipher, and then prints the substituted text.

**Parameters:**
: `argc`: The number of command line arguments.
: `argv`: An array of strings representing the command line arguments.

**Return:**
: If everything goes as expected, it returns `EXIT_SUCCESS`.
: If there is an error during execution, it returns `EXIT_FAILURE`.

### Functions

### `validate_arguments`

This function checks the number and format of command line arguments to ensure they meet the expected requirements for the program. It performs the following checks:

1. Verifies that the correct number of arguments is provided (2).
2. Checks if the provided cipher string has the correct length (26).
3. Ensures that the cipher string contains only alphabetical letters.
4. Checks for duplicate characters in the cipher string.

If any of these checks fail, the function prints an error message to the standard error stream and exits the program with a failure status.

**Parameters:**
: `argc`: The number of command line arguments.
: `argv`: An array of strings representing the command line arguments.

### `get_string`

This function reads a string from the user, dynamically allocating memory as needed to store the input.

**Parameters:**
: `text`: The prompt displayed to the user.

**Return:**
: A dynamically allocated string containing the user input.

### `substitutor`

This function takes a substitution cipher and a plain text as input and substitutes each character in the plain text with its corresponding character from the cipher.

The substitution is case-sensitive, and the original case of each character is preserved.

**Parameters:**
: `argv`: An array of strings representing the command line arguments.
: `plain_text`: A string containing the plain text to be substituted.

**Return:**
: A pointer to the modified plain text string after substitution.

## License

This code is distributed under the **MIT License**.
