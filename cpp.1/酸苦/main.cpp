#include<iostream>
using namespace std;
const int N = 210;
int num[N];
void dfs(int x, int sum);
int res=210;
int n,b;
bool num1[N];
int main()
{
	int  a, i;
	cin >> n >> a >> b;
	for (i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	dfs(a, 0);
	if (res == 210)
	{
		cout << -1;
	} 
	else
	{
		cout << res;
	}

}
void dfs(int x, int sum)
{
	if (x == b)
	{
		res = min(res, sum);
		return;
	}
	if (x<0 || x>n)return;
	if (sum >= res)return;
	if (x + num[x] <= n&&!num1[x+num[x]])
	{
		num1[x + num[x]] = true;
		dfs(x + num[x], sum + 1);
		num1[x + num[x]] = false;
	}

	if (x -num[x] >= 0&& !num1[x -num[x]])
	{
		num1[x - num[x]] = true;
		dfs(x -num[x], sum + 1);
		num1[x - num[x]] = false;

	}



}