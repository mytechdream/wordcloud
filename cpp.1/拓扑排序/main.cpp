//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//// 用邻接表存储图
//vector<int> graph[10001];
//// 存储每个顶点的入度
//int indegree[10001] = { 0 };
//// 拓扑排序函数
//bool topological_sort(int n) {
//    queue<int> q;
//    // 将所有入度为0的顶点入队
//    for (int i = 1; i <= n; i++) {
//        if (indegree[i] == 0) {
//            q.push(i);
//        }
//    }
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        cout << u << " ";
//
//        // 将所有u可达的顶点的入度减1
//        for (int i = 0; i < graph[u].size(); i++) {
//            int v = graph[u][i];
//            indegree[v]--;
//            if (indegree[v] == 0) {
//                q.push(v);
//            }
//        }
//    }
//
//    // 判断是否存在环
//    for (int i = 1; i <= n; i++) {
//        if (indegree[i] != 0) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    // 读入图的边并构建邻接表
//    for (int i = 0; i < m; i++) {
//        int u, v;
//        cin >> u >> v;
//        graph[u].push_back(v);
//        indegree[v]++;
//    }
//
//    if (!topological_sort(n)) {
//        cout << "The graph contains a cycle!" << endl;
//    }
//    return 0;
//}
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<iomanip>
using namespace std;
#define MAV 10;
#define MAXE 200;
struct edgeNode {
	int adjvex;
	int weight;
	edgeNode* next;
};
struct vextexNode {
	int in;
	int data;

};