//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//const int MAXN = 100; // ��󶥵���
//const int INF = 0x3f3f3f3f; // ���������
//
//struct EdgeNode { // �߱���
//    int to; // �ڽӵ���
//    int weight; // ��Ȩֵ
//    int next; // ��һ���ڽӵ��λ��
//};
//
//struct VertexNode { // �������
//    int data; // ��������
//    int first; // �ö���ĵ�һ���ڽӵ��λ��
//};
//
//class Graph {
//private:
//    VertexNode vertex[MAXN]; // �����
//    EdgeNode edge[MAXN * MAXN]; // �߱�ÿ��������� MAXN ���ڽӵ㣩
//    bool visited[MAXN]; // ��Ǹ��������Ƿ��Ѿ�����
//    int edge_num, vertex_num; // �����Ͷ�����
//public:
//    Graph() {
//        memset(visited, false, sizeof(visited)); // �� visited �����ʼ��Ϊ false
//        edge_num = 0;
//        vertex_num = 0;
//    }
//    void add_edge(int u, int v, int w) { // ���һ����
//        edge[edge_num].to = v;
//        edge[edge_num].weight = w;
//        edge[edge_num].next = vertex[u].first;
//        vertex[u].first = edge_num++;
//    }
//    void bfs(int u) { // �����������
//        queue<int> q;
//        visited[u] = true;
//        q.push(u);
//        while (!q.empty()) {
//            int cur = q.front();
//            q.pop();
//            cout << cur << " "; // ��������ʵĶ���
//            for (int i = vertex[cur].first; i != -1; i = edge[i].next) { // ���������ڽӵ�
//                int v = edge[i].to;
//                if (!visited[v]) {
//                    visited[v] = true;
//                    q.push(v);
//                }
//            }
//        }
//    }
//};
//
//int main() {
//    Graph g;
//    // ���������
//    g.add_edge(1, 2, 3);
//    g.add_edge(1, 3, 2);
//    g.add_edge(1, 4, 5);
//    g.add_edge(2, 4, 4);
//    g.add_edge(2, 5, 4);
//    g.add_edge(3, 4, 2);
//    g.add_edge(4, 5, 3);
//    g.bfs(1); // �Ӷ���1��ʼ���й����������
//    return 0;
//}
#include<iostream>
using namespace std;
const int maxn = 1005;//�������ֵ
int n, m, cnt;//n���㣬m����
struct Edge
{
    int to, w, next;//�յ㣬��Ȩ��ͬ������һ���ߵı��
}edge[maxn];//�����
int head[maxn];//head[i],��ʾ��iΪ���ĵ�һ�����ڱ߼������λ�ã���ţ�
void init()//��ʼ��
{
    for (int i = 0; i <= n; i++) head[i] = -1;
    cnt = 0;
}
void add_edge(int u, int v, int w)//�ӱߣ�u��㣬v�յ㣬w��Ȩ
{
    edge[cnt].to = v; //�յ�
    edge[cnt].w = w; //Ȩֵ
    edge[cnt].next = head[u];//��uΪ�����һ���ߵı�ţ�Ҳ����������������ͬ����һ���ߵı��
    head[u] = cnt++;//������uΪ�����һ���ߵı��
}
int main()
{
    cin >> n >> m;//n,m��ȫ�ֱ���
    //n���㡣m����
    int u, v, w;
    init();//��ʼ��
    for (int i = 1; i <= m; i++)//����m����
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);//�ӱ�
        /*
        ��˫���
        add_edge(u, v, w);
        add_edge(v, u, w);
        */
    }
    for (int i = 1; i <= n; i++)//n�����
    {
        cout << i << endl;
        for (int j = head[i]; j != -1; j = edge[j].next)//������iΪ���ı�
        {
            cout << i << " " << edge[j].to << " " << edge[j].w << endl;
        }
        cout << endl;
    }
    return 0;
}
/*
5 7
1 2 1
2 3 2
3 4 3
1 3 4
4 1 5
1 5 6
4 5 7
*/