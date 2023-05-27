#include<iostream>
using namespace std;
void dfs(int x, int sum);
const int N = 5010;
int a[N];
int b[N];
int res = 0;
int n;
int c[50100][11];
int k = 0;
int main()
{
	cin >> n;
	dfs(1, 0);
	cout << res<<endl;
	for (int i = 0; i < res; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;

	}
}
void dfs(int x, int sum)
{
	if (sum > n) return;

	if (x > 10)
	{
		if (sum == n)
		{
			for (int j = 1; j <= 10; j++)
			{
				c[k][j - 1] = a[j];

			}
			k++;
			res++;
		}
		return;

	}
	for (int i = 1; i <= 3; i++)
	{
		a[x] = i;
		dfs(x + 1, sum + i);
		a[x] = 0;
	}
}