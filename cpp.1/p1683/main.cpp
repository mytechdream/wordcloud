#include<iostream>
using namespace std;
void dfs(int col,int row,int sum);
int sum = 1;
const int N = 30;	
int H, W;
char ro[N][N];
int col, row;
int main()
{

	cin >> H >> W;
	int j, i;
	
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			cin >> ro[i][j];
			if (ro[i][j] == '#')
			{
				col = i;
				row = j;
			}
		}
	}
	dfs(col,row,sum);
	
	cout << sum;
}
void dfs(int col,int row,int sum)
{
	if (col<0||col>H-1||row<0||row>W-1||ro[col][row] == '#')
	{
       return;
	}
	dfs(col - 1, row, sum + 1);
	dfs(col, row + 1, sum + 1);
	dfs(col + 1, row, sum + 1);
	dfs(col, row - 1, sum + 1);
}