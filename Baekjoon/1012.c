#include <stdio.h>
#include <string.h>

int ground [50][50], m, n;


int dfs(int x, int y)
{
	ground[x][y] = 0;
	
	if (x+1 < m && ground[x+1][y] == 1)
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
	return 0;
}

int main()
{
	int T, k, x, y, cnt;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		memset(ground, 0, sizeof(ground));
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d %d", &x, &y);
			ground[x][y] = 1;
		}
		
		cnt = 0;
		for (int a = 0; a < m; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (ground[a][b] == 1)
				{
					dfs(a, b);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
