# CryptoMagic - Text File Encryption/Decryption Utility

cryptoMagic is a command-line utility that allows you to encrypt and decrypt text files using a custom encryption scheme. This README file provides an overview of the program's input and output.

## Table of Contents
- [Introduction](#cryptoMagic---text-file-encryptiondecryption-utility)
- [Input](#input)
- [Output](#output)

## Introduction

cryptoMagic is designed to provide a simple and secure way to protect your text data by encrypting it and decrypting it when needed. It operates on text files, and the encryption scheme includes special handling for tab characters (<tab>) and the preservation of carriage returns (<CR>).

## Input

The input for the cryptoMagic program includes:

1. **Command-Line Arguments**: You can run the program using the following command-line arguments:
   - `-E`: Encrypts a text file.
   - `-D`: Decrypts an encrypted file.
   - `inputFilename`: The name of the input text file that you want to encrypt or decrypt.

2. **Input Text File**: The text file you want to process (encrypt or decrypt) should contain the text you wish to protect. The file may have any file extension, including none.

## Output

The output of the cryptoMagic program is based on the operation being performed:

### Encryption Output

When you use the `-E` switch to encrypt a text file, the program will create an encrypted file with the same base filename and a `.crp` file extension. For example, if the input file is `myFile.txt`, the encrypted output file will be `myFile.crp`. The content of the output file will be the encrypted version of the original text, including any preserved carriage returns (<CR>).

### Decryption Output

When you use the `-D` switch to decrypt an encrypted file, the program will create a decrypted file with the same base filename and a `.txt` file extension. For example, if the input file is `myFile.crp`, the decrypted output file will be `myFile.txt`. The content of the output file will be the decrypted version of the original text, preserving carriage returns (<CR>).

**Note**: The carriage return characters (<CR>) are preserved in both the encryption and decryption processes. If the input file contains carriage returns, they will be retained in the output file as well.

The cryptoMagic program is designed to handle text files with lines of up to 120 characters in length and will process one line at a time, ensuring the confidentiality and integrity of your text data.
