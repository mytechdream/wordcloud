#include <iostream>
using namespace std;
void dfs(int x,int start);
const int N = 100;
int a[N];
bool b[N];
int m, n;
int main()
{
	cin >> m >> n;
	dfs(1,1);

}
void dfs(int x,int start)
{
	if (x > n)
	{
		for (int j = 1; j <= n; j++)
		{
			
			cout << a[j]<<" ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= m; i++)
	{
		if (b[i] == false)
		{
			b[i] = true;
			a[x] = i;
			dfs(x + 1,start+1);
			b[i] = false;

		}
	}
}