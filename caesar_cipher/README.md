# Caesar Cipher Encryptor

This is a simple C program that implements the **Caesar cipher** to encrypt text. The basic idea of the Caesar Cipher is to shift each letter of the alphabet by a fixed number of positions. The alphabet is considered circular, so after the letter Z, the next character would be the letter A.

The cipher can be represented by the following mathematical formula:

> **E(x) = (x + n) mod 26**

And to decrypt the message, the inverse process is applied:

> **D(x) = (x − n) mod 26**

The Caesar cipher is a very simple form of encryption and is easily broken by brute force methods since there are only 25 possible shifts.That's why it's not a good option for real-world problems, only for entertainment and educational purposes.

## Execution

To run the program, use:

``` bash
./caesar_cipher key
```

Replace the key with the desired encryption key.

## Code Structure

The **`main`** starts by validating the arguments received during the program execution through the **`validating_args`** function.

The **`validating_args`** function validates if:

* It has 2 arguments
* The key is a integer
* The key is not greater than interger size
* The key is not 0

Finally, it returns the key as an integer. After that, the **`main`** prompts the user for the text to be encrypted. The text is dynamically allocated in memory.

The **`encryptor`** function encrypts the text based on the key, with validation for **uppercase** and **lowercase** letters. In the end, the **`encryptor`** function returns the encrypted text.

So, the **`main`** displays the encrypted text. In the end, the dynamically allocated memory for the text is freed using **`free(plain_text)`** to prevent memory leaks.

## License

This code is distributed under the **MIT License**.
