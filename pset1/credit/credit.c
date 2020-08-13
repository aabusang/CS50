#include <stdio.h>
#include <cs50.h>

bool checksum(long ccn);
void printBrand(long ccn);

int main(void)
{
    long credCardN = get_long("Number: ");
    // if card length is not 13 or 15 or 16
    // printf("INVALID");
    // Or
    // if it does not pass the checksum
    // printf("INVALID");
    if (checksum(credCardN))
        printBrand(credCardN);
    else
        printf("INVALID\n");
}

bool checksum(long ccn)
{

}