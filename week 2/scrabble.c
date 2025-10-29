#include<stdio.h>
#include<ctype.h>
#include<string.h>

int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

int compute_score(char word[])
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            int letter_index = toupper(word[i]) - 'A';
            score +=
            POINTS[letter_index];
        }
    }
    return score;
}
int main()
{
    char word1[100], word2[100];

    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    int score1 =
    compute_score(word1);
    int score2 =
    compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins with %d points!\n", score1);
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins with %d points!\n", score2);
    }
    else
    {
        printf("It's a tie! Both scored %d points. \n", score1);
    }
    return 0;
}
