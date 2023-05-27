#include <iostream>
using namespace std;
void dfs(int x,int num);
//int col(int x);

int a[10010] = { 6,2,5,5,4,5,6,3,7,6};
int n;
int arr[4];
int res = 0;
int main()
{
	cin >> n;
	n = n - 4;
    for (int i = 10; i < 1000; i++)
{
	a[i] = a[i % 10] + a[i / 10];
}
	dfs(1, 0);
	cout << res;

} 
//int col(int i)
//{
//	if (i < 10)
//	{
//		return a[i];
//	}
//	else
//	{
//		int num = 0;
//		while (i != 0)
//		{
//			num = num + a[i % 10];
//			i = i / 10;
//		}
//		return num;
//	}
//}
void dfs(int x, int sum)
{
	if (sum > n)
	{
		return;
	}
	if (x > 3)
	{
		if (arr[1] + arr[2] == arr[3] && sum == n)
		{
			res++;
		}
		return;
	}
	for (int i = 0; i <=1000; i++)
	{
		arr[x] = i;
		dfs(x + 1, sum + a[i]);

		arr[x] = 0;
	}

}