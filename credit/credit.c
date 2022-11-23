#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_card(void);
int get_length(long card);
bool check(long card, int digits);
int get_type(long card, int digits);
void verify(bool checksum, int digits, int first_digits);

int main(void)
{
    // Prompt the user for a credit card number
    long card = get_card();

    // Get card length
    int digits = get_length(card);

    // Calculate checksum
    bool checksum = check(card, digits);

    // Get card brand by the starting digits
    int first_digits = get_type(card, digits);

    // Verify card. Print brand if valid
    verify(checksum, digits, first_digits);
}

long get_card(void)
{
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 1);
    return card;
}

int get_length(long card)
{
    long card_digits = card;
    int digits;
    for (digits = 1; digits <= 16; digits++)
    {
        card_digits = card_digits / 10;
        if (card_digits < 1)
        {
            break;
        }
    }
    return digits;
}

bool check(long card, int digits)
{
    // Luhn's algorithm
    long int_part, divisor, first;
    double dec_part;
    double cc_dec = (double)card;
    int result, second;

    // Retrieve card's every other digit and multiply it by 2
    // Start with the second-to-last digit
    // Add the products' digits
    for (divisor = 100; divisor <= pow(10, digits); divisor = divisor * 100)
    {
        int_part = (long)(cc_dec / divisor);
        dec_part = (cc_dec / divisor) - int_part;
        if (dec_part < 0.0996)
        {
            first = 0;
        }
        else
        {
            first = card % divisor;
            while (first >= 10)
            {
                first = first / 10;
            }
        }
        first = first * 2;
        if (first > 9)
        {
            second = first % 10;
            first = first / 10;
            result = result + first + second;
        }
        else
        {
            result = result + first;
        }
    }

    // Get the card's remaining digits, add them, and add the sum to the former sum
    for (divisor = 10; divisor <= pow(10, digits); divisor = divisor * 100)
    {
        int_part = (long)(cc_dec / divisor);
        dec_part = (cc_dec / divisor) - int_part;
        if (dec_part < 0.0996)
        {
            first = 0;
        }
        else
        {
            first = card % divisor;
            while (first >= 10)
            {
                first = first / 10;
            }
        }
        result = result + first;
    }
    // If the sum's last digit is 0, the card's number satisfies the checksum
    bool checksum;
    if (result % 10 == 0)
    {
        checksum = true;
    }
    else
    {
        checksum = false;
    }
    return checksum;
}

int get_type(long card, int digits)
{
    int first_digits = card / (pow(10, digits - 2));
    return first_digits;
}

void verify(bool checksum, int digits, int first_digits)
{
    if ((first_digits == 34 | first_digits == 37) & checksum & (digits == 15))
    {
        printf("AMEX\n");
    }
    else if ((first_digits == 51 | first_digits == 52 | first_digits == 53 | first_digits == 54 | first_digits == 55) &
             checksum & (digits == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((first_digits / 10 == 4) & checksum & ((digits == 13 | digits == 16)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}