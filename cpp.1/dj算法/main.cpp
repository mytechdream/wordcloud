#include<iostream>
#include<stack>
#include<stdio.h>
#include<cstring>
using namespace std;
#define MAX 1000
#define INF 0x3f3f3f3f
int dist[MAX],path[MAX];//dist�洢��С���룬//path��¼���·��
struct MGraph
{
	int edges[MAX][MAX];
    int e,v;//e�ߣ�v����

}G;//��ͼ
void init()
{
	memset(G.edges, INF, sizeof(G.edges));//��ÿһ���߱����鸳Ϊ��
	for (int i = 1; i <=G.v; i++)
	{
		G.edges[i][i] = 0;//ʹ��ÿһ������������������Ϊ0
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
				printf("�� ");

			}
			else {
				printf("%2d", G.edges[i][j]);
			}
		}
		printf("\n");
	}
}
void Dijkstra(MGraph g, int u)//u����ʼ��
{
	int U[MAX]={0}, int mmin;//�ֱ�����Ѿ��������ĵ㡢�ݵ�ǰ��ʼ������ĵ�ľ���
	memset(path, -1, sizeof(path));
	for (int i = 1; i <=g.v; i++)
	{
		dist[i] = g.edges[u][i];
		if (g.edges[u][i] < INF)
		{
			path[i] = u;//i�ڵ�ĸ��׽ڵ�Ϊu;
		}
	}
	dist[u] = 0;

}