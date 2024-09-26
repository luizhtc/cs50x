#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_digits(string value_to_check[]);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Error = 1 if arguments are wrong
    if (argc != 2 || check_digits(argv) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converting string key to int
    string plain = get_string("plaintext: ");
    int key = atoi(argv[1]);

    // Finally, encrypting
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        printf("%c", rotate(plain[i], key));
        if (i == strlen(plain) - 1)
        {
            printf("\n");
        }
    }
}

bool check_digits(string value_to_check[])
{
    // Check if every character is a digit
    for (int i = 0; i < strlen(value_to_check[1]); i++)
    {
        int digit = value_to_check[1][i] - '0';
        if (digit < 0 || digit > 9)
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int key)
{
    // Converting char to int
    int c_new;
    if (isupper(c))
    {
        c_new = c - 'A';
    }
    else if (islower(c))
    {
        c_new = c - 'a';
    }
    else
    {
        // Returns the same character if not a letter
        return c;
    }

    int new_position = (c_new + key) % 26;

    char upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    if (isupper(c))
    {
        return upper[new_position];
    }
    else
    {
        return lower[new_position];
    }
}
