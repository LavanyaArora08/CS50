#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n;
    n = get_long("Enter the credit card number: ");
    long b = n;
    int count = 0;
    int sum1 = 0, sum2 = 0, i = 0;
    while (n > 0)
    {
        int d = n % 10;
        if (i % 2 == 0)
        {
            sum2 += d;
        }
        else
        {
            int temp = d * 2;
            while (temp > 0)
            {
                sum1 += temp % 10;
                temp /= 10;
            }
        }
        count++;
        n /= 10;
        i++;
    }
    int sum = sum1 + sum2;
    int flag = 0;

    if (sum % 10 == 0)
    {
        flag = 1;
    }
    if (flag == 1)
    {
        if (count == 15)
        {
            if (b / (long)pow(10, 13) == 34 || b / (long)pow(10, 13) == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                flag = 0;
            }
        }
        else if (count == 13)
        {
            if (b / (long)pow(10, 12) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                flag = 0;
            }
        }
        else if (count == 16)
        {
            if (b / (long)pow(10, 14) >= 51 && b / (long)pow(10, 14) <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (b / (long)pow(10, 15) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                flag = 0;
            }
        }
        else
        {
            flag=0;
        }
    }
    if (flag == 0)
    {
        printf("INVALID\n");ls
        
    }
}
