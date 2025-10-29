#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./ substitution key\n");
        return 1;
    }
    string key = argv[1];

    if (!is_valid_key(key))
    {
        printf("Key must contain26 unique alphabetic characters.\n");
        return 1;
    }
    string plaintext =
    get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            int index;
            if (isupper(c))
            {
                index = c - 'A';
                printf("%c", toupper(key[index]));
            }
            else
            {
                index = c - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
        return 0;
    }
        bool is_valid_key(string key)
        {
        if (strlen(key) != 26)
        {
        return false;
        }
        bool seen[26] = {false};
        for (int i = 0; i < 26; i++)
        {
        if (!isalpha(key[i]))
        {
        return false;
        }
        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
        return false;
        }
        seen[index] = true;
        }
        return true;
        }
