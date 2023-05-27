//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//const int MAXN = 100; // 最大顶点数
//const int INF = 0x3f3f3f3f; // 定义无穷大
//
//struct EdgeNode { // 边表结点
//    int to; // 邻接点编号
//    int weight; // 边权值
//    int next; // 下一个邻接点的位置
//};
//
//struct VertexNode { // 顶点表结点
//    int data; // 顶点数据
//    int first; // 该顶点的第一个邻接点的位置
//};
//
//class Graph {
//private:
//    VertexNode vertex[MAXN]; // 顶点表
//    EdgeNode edge[MAXN * MAXN]; // 边表（每个点最多有 MAXN 个邻接点）
//    bool visited[MAXN]; // 标记各个顶点是否已经访问
//    int edge_num, vertex_num; // 边数和顶点数
//public:
//    Graph() {
//        memset(visited, false, sizeof(visited)); // 将 visited 数组初始化为 false
//        edge_num = 0;
//        vertex_num = 0;
//    }
//    void add_edge(int u, int v, int w) { // 添加一条边
//        edge[edge_num].to = v;
//        edge[edge_num].weight = w;
//        edge[edge_num].next = vertex[u].first;
//        vertex[u].first = edge_num++;
//    }
//    void bfs(int u) { // 广度优先搜索
//        queue<int> q;
//        visited[u] = true;
//        q.push(u);
//        while (!q.empty()) {
//            int cur = q.front();
//            q.pop();
//            cout << cur << " "; // 输出被访问的顶点
//            for (int i = vertex[cur].first; i != -1; i = edge[i].next) { // 遍历所有邻接点
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
//    // 添加七条边
//    g.add_edge(1, 2, 3);
//    g.add_edge(1, 3, 2);
//    g.add_edge(1, 4, 5);
//    g.add_edge(2, 4, 4);
//    g.add_edge(2, 5, 4);
//    g.add_edge(3, 4, 2);
//    g.add_edge(4, 5, 3);
//    g.bfs(1); // 从顶点1开始进行广度优先搜索
//    return 0;
//}
#include<iostream>
using namespace std;
const int maxn = 1005;//点数最大值
int n, m, cnt;//n个点，m条边
struct Edge
{
    int to, w, next;//终点，边权，同起点的上一条边的编号
}edge[maxn];//顶点表
int head[maxn];//head[i],表示以i为起点的第一条边在边集数组的位置（编号）
void init()//初始化
{
    for (int i = 0; i <= n; i++) head[i] = -1;
    cnt = 0;
}
void add_edge(int u, int v, int w)//加边，u起点，v终点，w边权
{
    edge[cnt].to = v; //终点
    edge[cnt].w = w; //权值
    edge[cnt].next = head[u];//以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
    head[u] = cnt++;//更新以u为起点上一条边的编号
}
int main()
{
    cin >> n >> m;//n,m是全局变量
    //n，点。m，边
    int u, v, w;
    init();//初始化
    for (int i = 1; i <= m; i++)//输入m条边
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);//加边
        /*
        加双向边
        add_edge(u, v, w);
        add_edge(v, u, w);
        */
    }
    for (int i = 1; i <= n; i++)//n个起点
    {
        cout << i << endl;
        for (int j = head[i]; j != -1; j = edge[j].next)//遍历以i为起点的边
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