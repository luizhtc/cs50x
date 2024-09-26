#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_invalid(int argc, string key);
char encipher(char plain_char, string key);

int main(int argc, string argv[])
{
    // Validate
    string key = argv[1];
    if (is_invalid(argc, key))
    {
        return 1;
    }

    // Ask user for plaintext
    string plain = get_string("plaintext: ");

    // Encipher
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        printf("%c", encipher(plain[i], key));
        if (i == strlen(plain) - 1)
        {
            printf("\n");
        }
    }
}

bool is_invalid(int argc, string key)
{
    if (argc != 2) // Error = 1 if arguments are wrong
    {
        printf("Usage: ./substitution key\n");
        return true;
    }
    else if (strlen(key) != 26) // Error = 1 for invalid keys
    {
        printf("Key must contain 26 characters.\n");
        return true;
    }
    else
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (isalpha(key[i]) == 0) // Break loop if a character is not alphabetical
            {
                printf("Key must contain only alphabetical characters.\n");
                return true;
            }

            for (int j = 0; j < strlen(key); j++)
            {
                if (j == i) // Ignore if comparing the same value
                {
                    continue;
                }

                if (toupper(key[i]) == toupper(key[j])) // Validate only different characters
                {
                    printf("Key must not contain similar characters.\n");
                    return true;
                }
            }
        }
    }

    return false; // Return false if passed all tests
}

char encipher(char plain_char, string key)
{
    if (isalpha(plain_char))
    {
        if (isupper(plain_char))
        {
            return toupper(key[plain_char - 'A']);
        }
        else
        {
            return tolower(key[toupper(plain_char) - 'A']);
        }
    }
    else
    {
        return plain_char;
    }
}
