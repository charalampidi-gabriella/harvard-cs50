#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDigits(long long number)
{
    int count = 0;
    do
    {
        number /= 10;
        count++;
    }
        while (number != 0);
    return count;
}

int LuhnAlg(long long number)
{

    // convert number to string
    char str[256];
    sprintf(str, "%lld", number);

    // array to store digits
    int digitsToDouble[numDigits(number) / 2];

    // iterate string and store integers to double in the array
    for (int i = 0, j = numDigits(number) - 2; i < numDigits(number) / 2 && j >= 0; i++, j--)
    {
        digitsToDouble[i] = 2 * (str[j] - '0');
        j--;
    }

    // adds DIGITS of products
    int sumDoubled = 0;
    int d1 = 0;
    int n = 0;
    for (int i = 0; i < numDigits(number) / 2; i++)
    {

        while (digitsToDouble[i] > 0)
        {
            d1 = digitsToDouble[i] % 10;
            sumDoubled += d1;
            digitsToDouble[i] = digitsToDouble[i] / 10;
        }
    }

    int j = numDigits(number) - 1; // starts from the last digit of the number
    int sum = 0;
    while (j >= 0)
    {
        sum += str[j] - '0';
        j -= 2;
    }
    return (sum + sumDoubled);
}

bool valid(int total)
{

    int lastDigit = total % 10;
    if (lastDigit == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void final(long long number)
{
    long long temp = number;

    // gets 2 first digits
    while (temp >= 100)
    {
        temp = temp / 10;
    }

    long long temp2 = number; // for visa

    // gets 2 first digits
    while (temp2 >= 10)
    {
        temp2 = temp2 / 10;
    }

    if (temp == 34 || temp == 37)
    {
        printf("AMEX\n");
    }
    else if (temp == 51 || temp == 52 || temp == 53 || temp == 54 || temp == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (temp2 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{

    long long num = get_long_long("Number: ");
    if (numDigits(num) == 13 || numDigits(num) == 15 || numDigits(num) == 16)
    {
        if (valid(LuhnAlg(num)))
        {
            final(num);
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
