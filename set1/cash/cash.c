#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int coins = 0;
    int change = get_int("Change owed: ");
    while (change < 0)
    {
        change = get_int("Change owed: ");
    }

    while (change >= 25)
    {
        change = change - 25;
        coins++;
    }

    while (change >= 10)
    {
        change = change - 10;
        coins++;
    }

    while (change >= 5)
    {
        change = change - 5;
        coins++;
    }

    while (change >= 1)
    {
        change = change - 1;
        coins++;
    }
    printf("%i\n", coins);
}
