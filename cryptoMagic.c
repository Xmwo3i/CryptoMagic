#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character
int encryptChar(int ch) {
    if (ch == '\t') {
        // Replace <tab> with TT
        return 'T' << 8 | 'T';
    } else if (ch != '\n' && ch != '\r') {
        int outChar = ch - 16;
        if (outChar < 32) {
            outChar = (outChar - 32) + 144;
        }
        return outChar;
    }
    return ch; // Don't encrypt newlines
}

// Function to decrypt a pair of characters
int decryptPair(int ch1, int ch2) {
    if (ch1 == 'T' && ch2 == 'T') {
        return '\t';
    } else {
        int outChar = (ch1 * 16) + ch2 + 16;
        if (outChar > 127) {
            outChar = (outChar - 144) + 32;
        }
        return outChar;
    }
}

// Function to process input and output files
void processFile(const char *inputFileName, const char *outputFileName, int encrypt) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: Unable to open input or output file.\n");
        exit(1);
    }

    int ch, prevCh = 0;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (encrypt) {
            int encryptedChar = encryptChar(ch);
            fprintf(outputFile, "%02X", encryptedChar);
        } else {
            int hexValue;
            if (prevCh != 0) {
                sscanf(&prevCh, "%02X", &hexValue);
                int decryptedChar = decryptPair(hexValue, ch);
                fputc(decryptedChar, outputFile);
                prevCh = 0;
            } else {
                prevCh = ch;
            }
        }
    }

    if (prevCh != 0) {
        int hexValue;
        sscanf(&prevCh, "%02X", &hexValue);
        fputc(hexValue, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: cryptoMagic [-E/-D] inputFilename\n");
        return 1;
    }

    int encrypt = 1;
    char *inputFileName = argv[argc - 1];
    char *outputFileName;

    if (argc == 2) {
        outputFileName = malloc(strlen(inputFileName) + 5);
        strcpy(outputFileName, inputFileName);
        strcat(outputFileName, ".crp");
    } else {
        if (strcmp(argv[1], "-E") == 0) {
            outputFileName = malloc(strlen(inputFileName) + 5);
            strcpy(outputFileName, inputFileName);
            strcat(outputFileName, ".crp");
        } else if (strcmp(argv[1], "-D") == 0) {
            int len = strlen(inputFileName);
            if (len > 4 && strcmp(inputFileName + len - 4, ".crp") == 0) {
                outputFileName = malloc(len - 3);
                strncpy(outputFileName, inputFileName, len - 4);
                outputFileName[len - 4] = '\0';
            } else {
                printf("Error: Invalid input file format for decryption.\n");
                return 1;
            }
            encrypt = 0;
        } else {
            printf("Usage: cryptoMagic [-E/-D] inputFilename\n");
            return 1;
        }
    }

    processFile(inputFileName, outputFileName, encrypt);

    printf("File %s has been processed and saved as %s\n", inputFileName, outputFileName);

    free(outputFileName);

    return 0;
}







