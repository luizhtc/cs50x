#include <cs50.h>
#include <stdio.h>

void print_row(int height, int length);

int main(void)
{
    int height = get_int("Height: ");
    while (height <= 0)
    {
        height = get_int("Height: ");
    }

    for (int i = 1; i <= height; i++)
    {
        print_row(height, i);
    }
}

void print_row(int height, int length)
{
    // First pyramid
    for (int i = 0; i < height - length; i++)
    {
        printf(" ");
    }

    for (int j = 0; j < length; j++)
    {
        printf("#");
    }

    printf("  ");

    // Second pyramid
    for (int i = 0; i < length; i++)
    {
        printf("#");
    }

    printf("\n");
}
