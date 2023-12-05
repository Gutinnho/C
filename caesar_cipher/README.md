# Caesar Cipher

This is a simple C program that implements the **Caesar cipher** to encrypt text. The basic idea of the Caesar Cipher is to shift each letter of the alphabet by a fixed number of positions. The alphabet is considered circular, so after the letter Z, the next character would be the letter A.

The cipher can be represented by the following mathematical formula:

> **E(x) = (x + n) mod 26**

And to decrypt the message, the inverse process is applied:

> **D(x) = (x − n) mod 26**

The Caesar cipher is a very simple form of encryption and is easily broken by brute force methods since there are only 25 possible shifts.That's why it's not a good option for real-world problems, only for entertainment and educational purposes.

## Programs

[Encryptor](./encryptor/README.md)

[Decryptor](./decryptor/README.md)

## License

This code is distributed under the **MIT License**.
