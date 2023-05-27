//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//#include<vector>
//#include<iostream>
//using namespace std;
//int edges[550][550];  // ������еıߣ����� edges[i][j] �����i��j�ľ���
//int dist[550];  // ��¼��ǰ���е㵽���ľ���
//int visited[550];  // ��ǵ�ǰ�ĵ��Ƿ��߳�
//int pre[550];
// vector<int> get_path(int n) {
//vector<int> path;
//if (dist[n] == 0x3f3f3f3f) return path;
//path.push_back(n);
//while (n != 1) {
//    n = pre[n]; // ���յ㷴��Ѱ��·��
//    path.push_back(n);
//}
//reverse(path.begin(), path.end()); // ��ת·����ʹ�����㿪ʼ
//return path;
//}
//void  dijkstra(int n, int m)
//{
//    for (int i = 1; i <= n; i++) {  // ÿ��ѭ�������޳���1���㣬�����Ҫforѭ������n�Ρ�
//        int index = -1;  // index����ǰδ�����ʵľ���ԭ������ĵ�
//        dist[1] = 0; // ԭ�㵽ԭ��ľ���Ϊ0���������Ҫ����������forѭ�����е�dist����0x3f3f3f3f,�޷��ҳ�index��
//        for (int j = 1; j <= n; j++) { // find the index of min distance 
//            if (!visited[j] && (index == -1 || dist[j] < dist[index])) { // ��ǰ�ĵ�û�б��߳������ҵ�ǰ��ľ����index��ľ���С�������index��index == -1��ʾ��δ��ʼ�ҵ�dist����Сֵ�����dist[1]���롣
//                index = j;
//            }
//        }
//
//        visited[index] = 1;  //�ҵ���ǰ����ԭ����Сֵ�ĵ㣬��ѵ���б���߳���
//        for (int j = 1; j <= n; j++) {
//            if (dist[index] + edges[index][j] < dist[j]) { //index������������������е㡣
//                dist[j] = dist[index] + edges[index][j];
//                 pre[j] = index;
//            }
//        }
//    } 
//
//    if (dist[n] == 0x3f3f3f3f) {  //���û�е�n���·�����򷵻�-1
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
//        scanf("%d %d %d", &start, &end, &d);//ÿ��������������
//        edges[start][end] = edges[start][end] > d ? d : edges[start][end];  //��Ϊ��Ŀ�����д����رߣ����ԣ�ÿ��ȡ��Сֵ��
//    }
//
//    memset(dist, 0x3f, sizeof(dist));  // ��ʼ��ÿ��dist��ֵΪ0x3f3f3f3f�� memset�ǰ����ֽ������õģ�ÿ���ֽ�Ϊ0x3f, int�ĸ��ֽڣ������ 0x3f3f3f3f.
//    memset(visited, 0, sizeof(visited)); // ��ʼ�����еĵ㶼û�б��߳���
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
////vector<PII> g[MAXN]; // �ڽӱ��ͼ
////int d[MAXN]; // �Ӷ���1�����������̾���
////int pre[MAXN]; // �洢·��
////
////void dijkstra(int n) {
////    priority_queue<PII, vector<PII>, greater<PII>> q; // С����
////    memset(d, 0x3f, sizeof(d));
////    d[1] = 0; // 1 ���������Ϊ0
////    q.push(make_pair(0, 1)); // ��ʼ״̬���
////    while (!q.empty()) {
////        int u = q.top().second;
////        int w = q.top().first;
////        q.pop();
////        if (w > d[u]) continue; // ��ǰ·���������·��������
////        for (auto x : g[u]) {
////            int v = x.first, c = x.second;
////            if (d[v] > d[u] + c) { // �ɳڲ���
////                d[v] = d[u] + c; // ����·������
////                pre[v] = u; // ����·��     
////                q.push(make_pair(d[v], v)); // �� v ��ӣ�������
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
////        n = pre[n]; // ���յ㷴��Ѱ��·��
////        path.push_back(n);
////    }
////    reverse(path.begin(), path.end()); // ��ת·����ʹ�����㿪ʼ
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
////        g[v].push_back(make_pair(u, w)); // ����ͼ��Ҫ˫����
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
int dist[MAX], path[MAX];//������̾����·��
struct MGraph
{
    int edges[MAX][MAX];//�ڽӾ��󣬼�¼��������֮��ľ��룬Ҳ����Ȩֵ
    int e, n;//�����Ͷ�����
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
                printf("�� ");
            else
                printf("%2d ", G.edges[i][j]);
        }
        printf("\n");
    }
}
void Dijkstra(MGraph g, int u)
{
    int U[MAX], mmin;//�ֱ��ʾ�Ѿ��������ĵ㡢�൱ǰ��ʼ������ĵ�ľ���
    //�Ը�������г�ʼ��
    memset(U, 0, sizeof(U));
    memset(path, -1, sizeof(path));
    //me(dist,INF);
    for (int i = 0; i < g.n; i++)
    {
        dist[i] = g.edges[u][i];
        if (g.edges[u][i] < INF)
            path[i] = u;
    }
    dist[u] = 0;//������ľ���
    for (int i = 0; i < g.n; i++) //���Դ�㵽n�������̾���
    {
        mmin = INF;
        U[u] = 1;//��ѡ�����µ���ʼ�����U������
        for (int j = 0; j < g.n; j++)
            //���if�ж϶���u�ļ����Ƿ�����ͨ������j�ĸ��̵�·����������֣���ı�ԭ��·�����䳤�ȣ�����ʲô������
        {
            if (!U[j] && dist[u] + g.edges[u][j] < dist[j])
            {
                dist[j] = dist[u] + g.edges[u][j];//����·������
                path[j] = u;//���µ�����j��·��
            }
        }
        for (int j = 0; j < g.n; j++)
            //���ѭ��ÿ�δ�ʣ�ඥ����ѡ��һ�����㣬ͨ����������·����ͨ������ʣ�ඥ���·�����ǳ�����̵�
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
        printf("%d-->%d=��", u, x);//û��·��
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
    scanf("%d%d", &G.e, &G.n);//��������Ͷ�����
    init();
    for (int i = 0; i < G.e; i++)
    {
        scanf("%d%d%d", &v1, &v2, &w);
        G.edges[v1][v2] = w;
        G.edges[v2][v1] = w;
    }
    printf_MG();//����ڽӾ���
    int u;
    scanf("%d", &u);//����Դ��
    Dijkstra(G, u);
    for (int i = 0; i < G.n; i++)//���Դ�㵽ÿ��������·���Լ�·����·
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

