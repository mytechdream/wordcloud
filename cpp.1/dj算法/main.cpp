#include<iostream>
#include<stack>
#include<stdio.h>
#include<cstring>
using namespace std;
#define MAX 1000
#define INF 0x3f3f3f3f
int dist[MAX],path[MAX];//dist存储最小距离，//path记录最短路径
struct MGraph
{
	int edges[MAX][MAX];
    int e,v;//e边，v顶点

}G;//建图
void init()
{
	memset(G.edges, INF, sizeof(G.edges));//给每一个边表数组赋为零
	for (int i = 1; i <=G.v; i++)
	{
		G.edges[i][i] = 0;//使得每一个顶点与自身相连的为0
	}
}
void print_MG()
{
	for (int i = 1; i <= G.v; i++)
	{
		for (int j = 1; j <= G.v; j++)
		{
			if (G.edges[i][j] == INF)
			{
				printf("∞ ");

			}
			else {
				printf("%2d", G.edges[i][j]);
			}
		}
		printf("\n");
	}
}
void Dijkstra(MGraph g, int u)//u是起始点
{
	int U[MAX]={0}, int mmin;//分别遍历已经遍历过的点、据当前起始点最近的点的距离
	memset(path, -1, sizeof(path));
	for (int i = 1; i <=g.v; i++)
	{
		dist[i] = g.edges[u][i];
		if (g.edges[u][i] < INF)
		{
			path[i] = u;//i节点的父亲节点为u;
		}
	}
	dist[u] = 0;

}