#include <iostream>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int i = 0, j = -1;
	int next[100];
	next[0] = -1;
	while (i <a.size() - 1)
	{
		if (j == -1 || a[i] == a[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	for (int k = 0; k < a.size(); k++)
	{
		cout << next[k]<<" ";

	}
}