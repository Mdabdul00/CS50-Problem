#include<stdio.h>
#include<cs50.h>

int get_length(long num)

{
    int length = 0;
    while (num > 0)
    {
        num /= 10;
        length++;
    }
    return length;
}
bool check_luhn(long number)
{
    int sum = 0;
    int pos = 0;

    while (number > 0)
    {
        int digit = number % 10;
        if (pos % 2 == 1)

        {
            digit *=2;
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }

        sum += digit;
        number /= 10;
        pos++;

    }

    return (sum % 10 == 0);
}
int main(void)
{
    long card = get_long("number :");

    int len = get_length(card);

    if (!check_luhn(card))


     {
        printf("INVALID\n");
            return 0;
    }
      long start = card;
      while (start >= 100)

      {
      start /= 10;
      }

      if ((start == 34 || start == 37) && len == 15)
    {
      printf ("AMEX\n");

      }
      else if (start >= 51 && start <= 55 && len == 16)
      {
      printf("MASTERCARD\n");
      }
      else if (start / 10 == 4 && (len ==13 || len == 16))
      {
      printf("VISA\n");
        }
        else
         {
        printf("INVALID\n");

            return 0;
    }

}
