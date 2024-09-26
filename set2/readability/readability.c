#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string user_input = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0; i <= strlen(user_input); i++)
    {
        // Letters
        if (toupper(user_input[i]) >= 'A' && toupper(user_input[i]) <= 'Z')
        {
            letters += 1;
        }

        // Words
        if (user_input[i] == ' ' || user_input[i] == '\0')
        {
            words += 1;
        }

        // Sentences
        if (user_input[i] == '.' || user_input[i] == '!' || user_input[i] == '?')
        {
            sentences += 1;
        }
    }

    // Calculating L and S
    float L = ((float) letters / (float) words) * 100.0;
    float S = ((float) sentences / (float) words) * 100.0;

    // Index calculation '0.0588 * L - 0.296 * S - 15.8'
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // Rounding index to INT so we can use a complete grade
    int int_index = round(index);

    if (int_index <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (int_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", int_index);
    }
}
