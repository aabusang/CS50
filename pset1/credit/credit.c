#include <stdio.h>
#include <cs50.h>

//A program to check the brand and validity of a credit card
bool checksum(long ccn);
void printBrand(long ccn);

int main(void)
{
    long creditCardNunmber = get_long("Number: ");
    if (checksum(creditCardNunmber))
    {
        printBrand(creditCardNunmber);
    }
    else
    {
        printf("INVALID\n");
        // return 1;
    }
}

// int ccnLen(long ccn)
// {
//     int len = 0;
//     for (int i = 0; i != '\0'; i++)
//     {
//         len++;
//     }
//     return len;
// }
bool checksum(long ccn)
{
    int i, digit, sum = 0;
    for (i = 0; ccn > 0; ccn /= 10, i++)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            digit = (ccn % 10) * 2;
            sum += (digit / 10) + (digit % 10); //if digit = 12, / 10 = 1 & % 10 = 2
        }
    }
    // int len = ccnLen(ccn);
    if ((sum % 10 == 0) && (i == 13 || i == 15 || i == 16))
        return true;
    else
        return false;
}

void printBrand(long ccn)
{
    if( (ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13) )
        printf("AMEX\n");
    else if (ccn >= 51e14 && ccn < 56e14)
        printf("MASTERCARD\n");
    else if ( (ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15) )
        printf("VISA\n");
    else
        printf("INVALID\n");
}