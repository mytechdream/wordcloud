#include<iostream>
#include<cstdio>
#include<cstring>	
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
struct edge {
	int start;
	int end;
	int w;
	edge() {}
	edge(int s, int e, int _w) { start = s, end = e; w = _w; }
	bool operator <(const edge& e)const
	{

		return e.w < w;
	}
};

int f[101] = { 0 };
int s[101] = { 0 };
int find(int x)
{
	if (x == f[x])return x;
	return f[x] = find(f[x]);
}
bool isDif(int start, int end)
{
	int p1 = find(start);
	int p2 = find(end);
	if (p1 == p2)
	{
		return false;
		if (s[p1] >= s[p2])
		{
			f[p2] = p1;
			s[p1]++;
		}

	}
	return true;
}
int main()
{

	freopen("data.txt", "r", stdin);
	int n, v;
	cin >> n, v;
	priority_queue<edge> q;
	vector<edge> TE;

	int i, j, t;
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
		for (j = 1; j <= n; j++)
		{
			cin >> t;
			if (t != 0 && t != 1000)
			{

				q.push(edge(i, j, t));
			}


		}

	}
	while (TE.size() != n - 1)
	{
		edge e = q.top();
		q.pop();
		int start = e.start;
		int end = e.end;
		if (isDif(start, end))
		{
			TE.push_back(e);
		}

	}
	for (i = 1; i < n; i++)
	{
		cout << TE[i - 1].start << " " << TE[i - 1].end << endl;
	}
}
