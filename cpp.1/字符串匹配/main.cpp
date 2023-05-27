#include<iostream>
using namespace std;
const int N = 100;
int pmt[N];
int pmt1[N];
void next(string s);
void next1(string s);
int main()
{
	
	string txt;
	string pa;
	cin  >> txt>>pa;
	next(pa);
	int i = 0, j = 0;
	int len1 = txt.size();
	int len2 = pa.size();

	while (i < len1 && j < len2)

	{
		
		if (j==-1||txt[i]== pa[j])
		{

			++i;
			++j;
		}
		else
		{
			j = pmt[j];
		}
	}
	if (j == pa.size())
	{
		cout << "YES"<<endl;
	}
	else
	{
		cout <<"NO" << endl;
	}
	for (int i = 0; i < len2; i++)
	{
		cout << pmt[i] << " ";
	}
}
void next(string s)
{
	pmt[0] = -1;
	int j = -1, i = 0;
	while (i < s.size() - 1)
	{
		if (j == -1 || s[i] == s[j])
		{
			i++;
			j++;
			pmt[i] = j;
		}
		else
		{
			j = pmt[j];
		}

	}
}

void next1(string s)
{
	int j = 0, i = 1;
	pmt1[0] = 0;
	for (i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = pmt1[j - 1];
		}
		if (s[i] == s[j])
		{
			j++;
		}
		pmt1[i] = j;
	}
}