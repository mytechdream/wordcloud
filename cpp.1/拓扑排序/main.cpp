//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//// ���ڽӱ�洢ͼ
//vector<int> graph[10001];
//// �洢ÿ����������
//int indegree[10001] = { 0 };
//// ����������
//bool topological_sort(int n) {
//    queue<int> q;
//    // ���������Ϊ0�Ķ������
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
//        // ������u�ɴ�Ķ������ȼ�1
//        for (int i = 0; i < graph[u].size(); i++) {
//            int v = graph[u][i];
//            indegree[v]--;
//            if (indegree[v] == 0) {
//                q.push(v);
//            }
//        }
//    }
//
//    // �ж��Ƿ���ڻ�
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
//    // ����ͼ�ı߲������ڽӱ�
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