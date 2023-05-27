#include<iostream>
using namespace std;
int main()
{
	int a[100][100] = { 0 };
	int row, col,n;
	cin >> row >> col>>n;
	int r, c,re;
	for (int j = 0; j < n; j++)
	{
		cin >> r >> c >> re;
		a[r][c] = re;
	}
	for (int i = 0; i < row;i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}

}