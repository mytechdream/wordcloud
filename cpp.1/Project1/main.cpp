#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 10000;
void next(string pp);
void kmp(string ss, string pp);
vector<int> n(maxn);
int main()
{
	string s;
	string p;
	cin >> s >> p;
	next(p);
	kmp(s, p);


}
void next(string pp)
{
	int len = pp.size();
	n[0] = -1;
	int k = -1, j = 0;
	while (j < len - 1)
	{
		if (k == -1 || pp[j] == pp[k])
		{

			++j;
			++k;
			n[j] = k;

		}
		else
		{
			k = n[k];
		}
	}
}
void kmp(string ss, string pp)
{
    int slen = ss.size(), plen = pp.size();
    int i = 0, j = 0;
    while (i < slen && j < plen)
    {
        if (j == -1 || ss[i] == pp[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = n[j];
        }
    }
    if (j == plen)
    {
        cout << "YES"<<endl;
        for (int i = 0; i < pp.size(); i++)
        {
            cout << n[i] << " " ;
        }
    }
    else
    {
        cout << "NO" << endl;
        for (int i = 0; i < pp.size(); i++)
        {
            cout << n[i] << " " ;
        }
    }
}