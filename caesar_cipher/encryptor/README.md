[Back](../README.md)

This code is the encryptor. The encryptor encrypts the provided text according to the also provided key.

## Execution

To execute the encryptor, use:

``` bash
./encryptor
```

## Code Structure

The structure of the encryptor is as follows:

### `main`

The `main` function coordinates the program's execution, calling auxiliary functions as needed.

**Return:**
: If everything goes as expected, it returns 0.
: If an error occurs during execution, it returns 1.

### Auxiliary Functions

1. [get_plain_text](#get_plain_text)
2. [get_valid_key](#get_valid_key)
3. [encryptor](#encryptor)

### `get_plain_text`

Function to obtain a line of text to be encrypted from standard input (stdin).

This function uses the `getline` function to read a line from standard input and returns a pointer to the read string. The function dynamically allocates memory to store the read line. Ensure to free this memory using the `free` function when it is no longer needed.

**Return:**
: A pointer to the string containing the read plaintext.
: In case of an error in reading or memory allocation, it returns `NULL`.

### `get_valid_key`

Function to obtain a valid key from the user.

This function prompts the user to enter a key as input. If the entered value is outside the range representable by an `int` type, the function calls itself recursively until a valid value is entered.

**Return:**
: An integer value representing the valid key entered by the user.

### `encryptor`

Function to encrypt a text with a specific key.

This function encrypts the provided text using a specific key and prints the encrypted text to standard output.

**Parameters:**
: `plain_text`: The string containing the text to be encrypted.
: `key`: The key to be used to encrypt the text.

## Compilation

If you, for any reason, wish to compile, you can use the following command:

```bash
gcc -g caesar_encryptor.c -o encryptor
```

> :warning: **Important!**
>
> You need to have GCC (GNU Compiler Collection) installed.
