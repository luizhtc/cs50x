#include <cs50.h>
#include <stdio.h>

int get_digits(long number);
bool validate_digits(long number, int n_digits);
long positive_exponential(long base, long exponent);

int main(void)
{
    long number = get_long("Number: ");
    int n_digits = get_digits(number);

    if (n_digits == 15 &&
        (number / positive_exponential(10, n_digits - 2) == 34 ||
         number / positive_exponential(10, n_digits - 2) == 37) &&
        validate_digits(number, n_digits))
    {
        printf("AMEX\n");
    }
    else if (n_digits == 16 &&
             ((number / positive_exponential(10, n_digits - 2) > 50) &&
              (number / positive_exponential(10, n_digits - 2) < 56)) &&
             validate_digits(number, n_digits))
    {
        printf("MASTERCARD\n");
    }
    else if (n_digits == 16)
    {
        if (number / positive_exponential(10, n_digits - 1) == 4 &&
            validate_digits(number, n_digits))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (n_digits == 13)
    {
        if (number / positive_exponential(10, n_digits - 1) == 4 &&
            validate_digits(number, n_digits))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long positive_exponential(long base, long exponent)
{
    long result = base;
    for (int i = 1; i < exponent; i++)
    {
        result = result * base;
    }
    return result;
}

int get_digits(long number)
{
    int n_digits = 0;
    while (number != 0)
    {
        number = number / 10;
        n_digits++;
    }
    return n_digits;
}

bool validate_digits(long number, int n_digits)
{
    int odd_sum = 0;
    int even_sum = 0;
    for (int i = 1; i <= n_digits; i++)
    {
        int digit = number % 10;

        if (i % 2 == 0)
        {
            if (digit >= 5)
            {
                even_sum = even_sum + ((digit * 2) % 10);
                digit = (digit * 2) / 10;
                even_sum = even_sum + digit;
            }
            else
            {
                even_sum = even_sum + (digit * 2);
            }
        }
        else
        {
            odd_sum = odd_sum + digit;
        }

        number = number / 10;
    }

    if ((even_sum + odd_sum) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
