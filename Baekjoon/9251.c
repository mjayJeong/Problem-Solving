#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    char word1[1002], word2[1002];
    scanf("%s", word1);
    scanf("%s", word2);
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    int table[length1+1][length2+1];

    for (int i = 0; i <= length1; i++)
    {
        table[i][0] = 0;
    }
    for (int j = 0; j <= length2; j++)
    {
        table[0][j] = 0;
    }

    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (word1[i-1] == word2[j-1]) 
            {
                table[i][j] = table[i-1][j-1] + 1;
            } else {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    printf("%d", table[length1][length2]);

    return 0;
}
