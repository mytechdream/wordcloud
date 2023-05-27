#include<iostream>
using namespace std;
void dfs(int x);
const int N = 100;
int a[N];
bool b[N];
int n;
int main()
{
	cin >> n;
	dfs(1);
}
void dfs(int x)
{
	if (x > n)
	{
		for (int j = 1; j <= n; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (b[i] == false)//b[i]与b[x]可以好好思考
		{
			b[i] = true;
			a[x] = i;
			dfs(x + 1);
			b[i] = false;

		}

	}

}
