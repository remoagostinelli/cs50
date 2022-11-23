#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char abc[26] = "abcdefghijklmnopqrstuvwxyz";
char ciphertext[10000];

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // User inputs key as an argument
        string key = argv[1];
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int i = 0; i < strlen(key); i++)
        {
            key[i] = tolower(key[i]);
            if (!isalpha(key[i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }

        // Check for repeated characters
        for (int i = 0; i < strlen(key); i++)
        {
            for (int j = i + 1; j < strlen(key); j++)
            {
                if (key[i] == key[j])
                {
                    printf("Key must not contain repetead characters.\n");
                    return 1;
                }
            }
        }

        // Prompt the user for text to cipher
        string plaintext = get_string("plaintext: ");

        // Cipher the input
        for (int i = 0; i < strlen(plaintext); i++)
        {
            char character = plaintext[i];
            char cipher;
            if (isalpha(character))
            {
                // Find the character's position
                for (int j = 0; j < strlen(abc); j++)
                {
                    char c = abc[j];
                    // Convert
                    if (c == character)
                    {
                        cipher = key[j];
                        ciphertext[i] = cipher;
                        break;
                    }
                    else if (toupper(c) == character)
                    {
                        cipher = toupper(key[j]);
                        ciphertext[i] = cipher;
                        break;
                    }
                }
            }
            else
            {
                ciphertext[i] = character;
                continue;
            }
        }
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}