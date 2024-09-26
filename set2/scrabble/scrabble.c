#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int PLAYERS = 2;

    string words[PLAYERS];
    int scores[PLAYERS];
    int score;

    for (int i = 0; i < PLAYERS; i++)
    {
        score = 0;
        words[i] = get_string("Player %i: ", i + 1);

        for (int j = 0; j < strlen(words[i]); j++)
        {
            if (toupper(words[i][j]) >= 'A' && toupper(words[i][j]) <= 'Z')
            {
                score += POINTS[toupper(words[i][j]) - 'A'];
            }
        }
        scores[i] = score;
    }

    if (scores[0] > scores[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (scores[0] < scores[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
