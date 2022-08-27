#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string strCc;
    long constCc;
    long cC;
    int res;
    int lastDigit;

    // Input for CC number.
    do
    {
        strCc = get_string("Card number.: ");
        constCc = atol(strCc);
    }
    while (constCc < 0);

    // 1st Luhn's step.
    cC = constCc / 10;
    while (cC > 0)
    {
        int digit = cC % 10;
        int product = digit * 2;
        res = res + (product % 10) + (product / 10);
        cC /= 100;
    }

    // 2nd Luhn's step.
    cC = constCc;
    while (cC > 0)
    {
        int digit = cC % 10;
        res = res + digit;
        cC /= 100;
    }

    // 3th Luhn's step - Chack if last number == 0.
    lastDigit = res % 10;
    if (lastDigit)
    {
        printf("INVALID\n");
    }

    // CC number checking.
    else if (strlen(strCc) < 13 || strlen(strCc) > 16)
    {
        printf("INVALID\n");
    }

    //Identify CC flag.
    // AMEX | 15 Digits | 34 or 37.
    else if (strCc[0] == 51 && (strCc[1] == 52 || strCc[1] == 55))
    {
        printf("AMEX\n");
    }

    // MASTERCARD | 16 Digits | 51 to 55.
    else if (strCc[0] == 53 && (strCc[1] >= 49 && strCc[1] <= 53))
    {
        printf("MASTERCARD\n");
    }

    // VISA | 13 to 16 Digits | 4.
    else if (strCc[0] == 52)
    {
        printf("VISA\n");
    }

    //For every other.
    else
    {
        printf("INVALID\n");
    }
}