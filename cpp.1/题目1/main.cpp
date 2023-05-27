//#include<iostream>
//#include<string>
//using namespace std;
//string  fun(string a)
//{
//	string b;
//	for (int i = 0; i < a.size(); i++)
//	{
//		if (a[i] >= 'A' && a[i] <= 'Z')
//		{
//			b += a[i]-'A'+'a';
//		}
//		else
//		{
//			b += a[i];
//		}
//	}
//	return b;
//}
//int main()
//{
//	string te;
//	getline(cin,te);
//	int num, num1;
//	cin >> num >> num1;
//	string pa;
//	string  a[100];
//	int m = 0;
//	getline(cin, pa);
//	for (int i = 0; i < num1; i++)
//	{
//		getline(cin, pa);
//		if (num == 0)
//		{
//			string B = fun(pa);
//			te = fun(te);
//			if (B.find(te) != -1)
//			{
//				cout << pa << endl;
//			}
//		}
//		else
//		{
//			
//			if (pa.find(te) != -1)
//			{
//				cout << pa << endl;
//
//			}	
//		}
//	
//	}
//	
//}
#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
struct Dis
{
    string path;
    int value;
    bool visit;
    Dis()
    {
        path = "";
        value = 0;
        visit = false;
    }
};
class Dijkstra
{
private:
    int vexnum;
    int edge;
    int arc[101][101];
    Dis dis[101];

public:
    Dijkstra(int _vexn, int _edge);
    //bool check();
    void createG();
    void show();
    void getDist(int begin);
    string d2string(int n);
    void showPath(int begin);
};
Dijkstra::Dijkstra(int _vexn, int _edge)
{
    vexnum = _vexn;
    edge = _edge;
    int i, j;
    for (i = 0; i < vexnum; i++)
    {
        for (j = 0; j < vexnum; j++)
        {
            arc[i][j] = INT_MAX;
        }
    }
}
void Dijkstra::createG()
{
    int start, end, weight;
    int k = 0;
    while (k < edge)
    {
        cin >> start >> end >> weight;
        arc[start - 1][end - 1] = weight;
        k++;
    }
}
void Dijkstra::show()
{
    int row, col;
    row = 0;
    col = 0;
    while (row != vexnum)
    {
        col = 0;
        while (col != vexnum)
        {
            if (arc[row][col] == INT_MAX)
            {
                cout << "∞ "
                    << " ";
       
            }
            else
            {
                cout << arc[row][col] << " "; 
            }
            col++;
        }
        cout << endl;
        row++;
    }
}
string Dijkstra::d2string(int n)
{
    char str1[10], str2[10];
    int i = 0, j = 0;
    while (n > 0)
    {
        str1[i++] = n % 10 + 48;
        n = n / 10;
    }
    str1[i] = '\0';
    i--;
    while (i >= 0)
    {
        str2[j++] = str1[i--];
    }
   
    str2[j] = '\0';
    return str2;
}
void Dijkstra::getDist(int begin)
{
    int i;
    for (i = 0; i < vexnum; i++)
    {
        dis[i].path = "V" + d2string(begin) + "->V" + d2string(i + 1);
        dis[i].value = arc[begin - 1][i];
    }
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;
    int count = 1;
    while (count <vexnum)
    {
        count++;
        int min = INT_MAX;
        int t = 0;
        for (i = 0; i < vexnum; i++)
        {
            if (!dis[i].visit && dis[i].value < min)
            {
                min = dis[i].value;
                t = i;
            }
        }
        dis[t].visit = true;
        for (i = 0; i < vexnum; i++)
        {
            if (!dis[i].visit && arc[t][i] != INT_MAX && (dis[t].value + arc[t][i] )< dis[i].value)
            {
                dis[i].value = dis[t].value + arc[t][i];
                dis[i].path = dis[t].path + "->V" + d2string(i + 1);
            }
        }
    }
}
void Dijkstra::showPath(int begin)
{
    for (int i = 0; i < vexnum; i++)
    {
        cout << dis[i].path << ":" << dis[i].value << endl;
    }
}
int main(int argc, char** argv)
{
    freopen("C:\\Users\\syk\\Desktop\\8.txt", "r", stdin);
  //绝对路径，注意\要用转意运算符
    int n, v;
    cin >> n >> v;
    Dijkstra D(n, v);
    D.createG();
    D.show();
    D.getDist(1);
    D.showPath(1);
    return 0;
}


