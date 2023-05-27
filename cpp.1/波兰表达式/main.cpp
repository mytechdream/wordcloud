#include<iostream>
#include<stack>
using namespace std;
int main()
{

	stack<char> stk;
	string m;
	cin >> m;
	string s;

	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] != '.')
		{
			s += m[i];
		}
	}

	char a, b;
	int sum;
	int len = s.size();
	for (int i = 0; i < len-1; i++)
	{
		if (s[i] >= '0' &&s[i] <= '9')
		{
			stk.push(s[i]);

		}
		if (s[i] == '-')
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			sum = (b - '0') - (a - '0');
			stk.push(sum + '0');

		}
		if (s[i] == '+')
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			sum = (b - '0') +(a - '0');
			stk.push(sum + '0');
		}
		if (s[i] == '*')
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			sum = (b - '0') *(a - '0');
			stk.push(sum + '0');
		}

	}
	cout << (stk.top()-'0');


}
