[Back](../README.md)

This code is the decryptor. The decryptor has two usage modes, one using brute force and the other using a key.

Since the Caesar cipher has a limited number of possibilities (25), it is possible to easily decrypt it using brute force.

## Execution

To run the code, use:

``` bash
./decryptor [b/bruteforce/k/key]
```

`b` or `bruteforce`: To decrypt using brute force.

`k` or `key`: To decrypt using a key.

## Code Structure

The structure of the decryptor is as follows:

### `main`

The `main` coordinates the program's execution, calling auxiliary functions based on the arguments provided on the command line.

**Parameters:**
: `argc`: Number of arguments on the command line.
: `argv`: Array of strings containing the command line arguments.

**Return:**
: If everything goes as expected, returns 0.
: If any error occurs during execution, returns 1.

### Auxiliary Functions

**Summary**
: [validate_args](#validate_args)
: [get_cripted_text](#get_cripted_text)
: [get_valid_key](#get_valid_key)
: [decryptor_without_key](#decryptor_without_key)
: [decryptor_with_key](#decryptor_with_key)

### `validate_args`

Function to validate command line arguments.

**Parameters:**
: `argc`: Number of arguments on the command line.
: `argv`: Array of strings containing the command line arguments.

**Return:**
: If the argument is "b" or "bruteforce", returns `1`.
: If the argument is "k" or "key", returns `2`.
: If there is an error in the arguments, returns `-1`.

### `get_cripted_text`

Function to obtain a line of encrypted text from standard input (stdin).

This function uses the `getline` function to read a line from standard input and returns a pointer to the read string. The function dynamically allocates memory to store the read line. Be sure to free this memory using the `free` function when it is no longer needed.

**Return:**
: A pointer to the string containing the read encrypted text.
: In case of error in reading or memory allocation, returns `NULL`.

### `get_valid_key`

Function to obtain a valid key from the user.

This function prompts the user to enter a key as input. If the entered value is outside the representable range of an `int` type, the function recursively calls itself until a valid value is entered.

**Return:**
: An integer value representing the valid key entered by the user.

### `decryptor_without_key`

Function to decrypt text without the provided key.

This function attempts to decrypt the provided text for all possible keys (from 1 to 25) and prints the results to standard output.

**Parameters:**
: `plain_text`: The string containing the text to be decrypted.

### `decryptor_with_key`

Function to decrypt text with a specific key.

This function decrypts the provided text using a specific key and prints the decrypted text to standard output.

**Parameters:**
: `plain_text`: The string containing the text to be decrypted.
: `key`: The key to be used to decrypt the text.

## Compilation

If you, for any reason, wish to compile, you can use the following command:

```bash
gcc -g caesar_decryptor.c -o decryptor
```

> :warning: **Important!**
>
> You need to have GCC (GNU Compiler Collection) installed.
