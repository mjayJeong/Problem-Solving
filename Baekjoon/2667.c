#include <stdio.h>
#include <stdlib.h>

int n, cnt = 0;
int ground[26][26];
int count[500];

void dfs(int x, int y)
{
    ground[x][y] = 0;
    count[cnt]++;

    if (x+1 < n && ground[x+1][y] == 1)
	{
		dfs(x+1, y);
	}
	if (x-1 >= 0 && ground[x-1][y] == 1)
	{
		dfs(x-1, y);
	}
	if (y+1 < n && ground[x][y+1] == 1)
	{
		dfs(x, y+1);
	}
	if (y-1 >= 0 && ground[x][y-1] == 1)
	{
		dfs(x, y-1);
	}
	return count;
}

int compare(const void *a, const void *b)    
{
    int num1 = *(int *)a;    
    int num2 = *(int *)b;    

    if (num1 < num2)    
        return -1;    
    
    if (num1 > num2)   
        return 1;     
    
    return 0;   
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &ground[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ground[i][j] == 1)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    qsort(count, cnt, sizeof(int), compare);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d\n", count[i]);
    }

    return 0;
}
