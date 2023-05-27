//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//#include<vector>
//#include<iostream>
//using namespace std;
//int edges[550][550];  // 存放所有的边，例如 edges[i][j] 代表从i到j的距离
//int dist[550];  // 记录当前所有点到起点的距离
//int visited[550];  // 标记当前的点是否被踢出
//int pre[550];
// vector<int> get_path(int n) {
//vector<int> path;
//if (dist[n] == 0x3f3f3f3f) return path;
//path.push_back(n);
//while (n != 1) {
//    n = pre[n]; // 从终点反向寻找路径
//    path.push_back(n);
//}
//reverse(path.begin(), path.end()); // 反转路径，使其从起点开始
//return path;
//}
//void  dijkstra(int n, int m)
//{
//    for (int i = 1; i <= n; i++) {  // 每次循环都会剔除掉1个点，因此需要for循环遍历n次。
//        int index = -1;  // index代表当前未被访问的距离原点最近的点
//        dist[1] = 0; // 原点到原点的距离为0，这个很重要，否则下面for循环所有的dist都是0x3f3f3f3f,无法找出index。
//        for (int j = 1; j <= n; j++) { // find the index of min distance 
//            if (!visited[j] && (index == -1 || dist[j] < dist[index])) { // 当前的点没有被踢出，并且当前点的距离比index点的距离小，则更新index。index == -1表示还未开始找到dist中最小值，则把dist[1]加入。
//                index = j;
//            }
//        }
//
//        visited[index] = 1;  //找到当前距离原点最小值的点，则把点进行标记踢出。
//        for (int j = 1; j <= n; j++) {
//            if (dist[index] + edges[index][j] < dist[j]) { //index点更新与它相连的所有点。
//                dist[j] = dist[index] + edges[index][j];
//                 pre[j] = index;
//            }
//        }
//    } 
//
//    if (dist[n] == 0x3f3f3f3f) {  //如果没有到n点的路径，则返回-1
//        printf("-1");
//    }
//    else
//    {
//        for (int i = 1; i <= n; i++)
//        {
//            printf("%d ", dist[i]);
//
//        }
//    }
//  
//}
//
//int main()
//{
//    memset(edges, 0x3f, sizeof(edges));
//    int n, m;
//
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < m; i++) {
//        int start, end, d;
//        scanf("%d %d %d", &start, &end, &d);//每次输入三个数字
//        edges[start][end] = edges[start][end] > d ? d : edges[start][end];  //因为题目输入中存在重边，所以，每次取最小值。
//    }
//
//    memset(dist, 0x3f, sizeof(dist));  // 初始化每个dist的值为0x3f3f3f3f， memset是按照字节来设置的，每个字节为0x3f, int四个字节，因此是 0x3f3f3f3f.
//    memset(visited, 0, sizeof(visited)); // 初始化所有的点都没有被踢出。
//    dijkstra(n, m);
//     vector<int> path = get_path(n);
//if (path.empty()) cout << -1 << endl;
//else {
//    for (int x : path) cout << x << ' ';
//    cout << endl;
//}
//    return 0;
//}
////#include<iostream>
////#include<queue>
////#include<algorithm>
////#include<cstring>
////
////using namespace std;
////
////const int INF = 1e9;
////const int MAXN = 1e5 + 5;
////
////typedef pair<int, int> PII;
////vector<PII> g[MAXN]; // 邻接表存图
////int d[MAXN]; // 从顶点1到各顶点的最短距离
////int pre[MAXN]; // 存储路径
////
////void dijkstra(int n) {
////    priority_queue<PII, vector<PII>, greater<PII>> q; // 小根堆
////    memset(d, 0x3f, sizeof(d));
////    d[1] = 0; // 1 到自身距离为0
////    q.push(make_pair(0, 1)); // 初始状态入队
////    while (!q.empty()) {
////        int u = q.top().second;
////        int w = q.top().first;
////        q.pop();
////        if (w > d[u]) continue; // 当前路径不是最短路径，抛弃
////        for (auto x : g[u]) {
////            int v = x.first, c = x.second;
////            if (d[v] > d[u] + c) { // 松弛操作
////                d[v] = d[u] + c; // 更新路径长度
////                pre[v] = u; // 更新路径     
////                q.push(make_pair(d[v], v)); // 将 v 入队，待更新
////            }
////        }
////    }
////}
////
////vector<int> get_path(int n) {
////    vector<int> path;
////    if (d[n] == INF) return path;
////    path.push_back(n);
////    while (n != 1) {
////        n = pre[n]; // 从终点反向寻找路径
////        path.push_back(n);
////    }
////    reverse(path.begin(), path.end()); // 反转路径，使其从起点开始
////    return path;
////}
////
////int main() {
////    int n, m;
////    cin >> n >> m;
////    for (int i = 1; i <= m; i++) {
////        int u, v, w;
////        cin >> u >> v >> w;
////        g[u].push_back(make_pair(v, w));
////        g[v].push_back(make_pair(u, w)); // 无向图需要双向存边
////    }
////    dijkstra(n);
////    vector<int> path = get_path(n);
////    if (path.empty()) cout << -1 << endl;
////    else {
////        for (int x : path) cout << x << ' ';
////        cout << endl;
////    }
////    return 0;
////}
#include <iostream>
#include <string.h>
#include <stack>
#include<stdio.h>
using namespace std;
#define MAX 100
#define INF 0x3f3f3f3f
#define me(a,b) memset(a,b,sizeof(b))
int dist[MAX], path[MAX];//储存最短距离和路径
struct MGraph
{
    int edges[MAX][MAX];//邻接矩阵，记录的是两点之间的距离，也就是权值
    int e, n;//边数和顶点数
} G;
void init()
{
    memset(G.edges, INF, sizeof(G.edges));
    //me(G.edges,(INF));
    for (int i = 1; i <=G.n; i++)
        G.edges[i][i] = 0;
}
void printf_MG()
{
    for (int i = 1; i <=G.n; i++)
    {
        for (int j = 1; j <=G.n; j++)
        {
            if (G.edges[i][j] == INF)
                printf("∞ ");
            else
                printf("%2d ", G.edges[i][j]);
        }
        printf("\n");
    }
}
void Dijkstra(MGraph g, int u)
{
    int U[MAX], mmin;//分别表示已经遍历过的点、距当前起始点最近的点的距离
    //对各数组进行初始化
    memset(U, 0, sizeof(U));
    memset(path, -1, sizeof(path));
    //me(dist,INF);
    for (int i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[u][i];
        if (g.edges[u][i] < INF)
            path[i] = u;
    }
    dist[u] = 0;//到本身的距离
    for (int i = 0; i < g.n; i++) //求出源点到n个点的最短距离
    {
        mmin = INF;
        U[u] = 1;//将选出的新的起始点放入U数组中
        for (int j = 0; j < g.n; j++)
            //这个if判断顶点u的加入是否会出现通往顶点j的更短的路径，如果出现，则改变原来路径及其长度，否则什么都不做
        {
            if (!U[j] && dist[u] + g.edges[u][j] < dist[j])
            {
                dist[j] = dist[u] + g.edges[u][j];//更新路径长度
                path[j] = u;//更新到顶点j的路径
            }
        }
        for (int j = 0; j < g.n; j++)
            //这个循环每次从剩余顶点中选出一个顶点，通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的
        {
            if (U[j] == 0 && dist[j] < mmin)
            {
                u = j;
                mmin = dist[j];
            }
        }
    }
}
void printf_path(int u, int x)
{
    int a[MAX], cou = 0, ex = x;
    if (u == x)
        printf("%d-->%d=0", u, x);
    else if (path[x] == -1)
        printf("%d-->%d=∞", u, x);//没有路径
    else
    {
        while (x != u)
        {
            a[cou++] = x;
            x = path[x];
        }
        a[cou] = x;
        for (int i = cou; i > 0; i--)
            printf("%d-->", a[i]);
        printf("%d=%d", a[0], dist[ex]);
    }
    printf("\n");
}
int main()
{
    int v1, v2, w;
    scanf("%d%d", &G.e, &G.n);//输入边数和顶点数
    init();
    for (int i = 0; i < G.e; i++)
    {
        scanf("%d%d%d", &v1, &v2, &w);
        G.edges[v1][v2] = w;
        G.edges[v2][v1] = w;
    }
    printf_MG();//输出邻接矩阵
    int u;
    scanf("%d", &u);//输入源点
    Dijkstra(G, u);
    for (int i = 0; i < G.n; i++)//输出源点到每个点的最短路径以及路径长路
        printf_path(u, i);
    return 0;
}
/*
13 10
0 1 10
0 2 15
1 3 20
1 4 5
2 5 8
2 6 6
3 7 7
4 5 10
4 7 3
4 8 4
5 6 9
5 8 3
6 8 12
*/

