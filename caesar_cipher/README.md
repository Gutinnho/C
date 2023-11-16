# Code Documentation

This is a simple C program that implements the Caesar cipher to encrypt text.

## Execution

To run the program, use:

```bash
./caesar key
```

Replace the key with the desired encryption key.

## Code Structure

The code consists of two main blocks:

**`int validating_args(int argc, string argv[])`:** Function to validate command-line arguments.

**`string encryptor(string plain_text, int key)`:** Function responsible for encrypting the text using the Caesar cipher.

## Operation

Firstly, the key is validated to ensure it is a positive number.

The program prompts the user to enter the text to be encrypted.

The encryptor function is used to encrypt the text according to the key, using the Caesar cipher.

The encrypted text is displayed on the standard output.

### Additional Notes

**Size Limitation:** The program supports up to 100 characters for the input text. This value can be adjusted as needed.

**Key Validation:** The key is validated to ensure it is a positive number and does not exceed the limit defined by pow(2, 31) - 1.

## License
This code is distributed under the MIT License.