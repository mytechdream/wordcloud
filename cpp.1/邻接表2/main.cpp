//#include <iostream>
//using namespace std;
//struct ArcNode {
//	int adjvex;
//	ArcNode* next;
//    //边表类
//};
//template <class DataType>
//struct VertexNode
//{
//	DataType vertex;
//	ArcNode* firstedge;
//    //顶点表
//};
//const int MaxSize = 10;    //图的最大顶点数
//template <class DataType>
//class ALGraph
//{
//public:
//    ALGraph(DataType a[], int n, int e);//构造函数
//    ~ALGraph()
//    {
//
//    };
//private:
//    VertexNode<DataType> adjlist[MaxSize];//顶点数组
//    int vertexNum, arcNum;
//};
//template <class DataType>
//ALGraph<DataType> ::ALGraph(DataType a[], int n, int e)
//{
//    vertexNum = n; arcNum = e;
//    int i, j, k;
//
//    for (i = 0; i < vertexNum; i++)
//    {                                             //输入顶点信息，初始化顶点表
//        adjlist[i].vertex = a[i];
//        adjlist[i].firstedge = NULL;
//    }
//    for (k = 0; k < arcNum; k++) //输入边的信息存储在边表中
//    {
//        cin >> i >> j;
//       auto s = new ArcNode; s->adjvex = j;
//        s->next = adjlist[i].firstedge;
//        adjlist[i].firstedge = s;
//    }
//    for (i = 0; i < vertexNum; i++)
//    {
//        cout << i<<" ";
//        while (adjlist[i].firstedge != NULL)
//        {
//            cout << adjlist[i].firstedge->adjvex<<" ";
//            adjlist[i].firstedge = adjlist[i].firstedge->next;
//        }
//        cout << endl;
//    }
//}
//int main()
//{
//    int b[5] = { 1,2,3,4,5 };
//    ALGraph<int> M(b,5,6);
//
//
//}
//
#include <iostream>
using namespace std;
struct arc
{
	int arcdata;
	arc* next;
};
struct ver
{
	int ad;
	arc* node;
};
const int  MaxSize = 10;
template<class DataType>
class Mgra
{
public:
	Mgra(DataType a[], int n, int m);
private:
	int vernum, arcnum;
	ver vertexnum[MaxSize];
};
template <class DataType>
Mgra<DataType>::Mgra(DataType a[], int n, int m)
{
	vernum = n; arcnum = m;
	ver vertexnumtemp[MaxSize];
	int i, j, k;
	for (i = 0; i < vernum; i++)
	{
		vertexnum[i].ad = a[i];
		vertexnum[i].node= NULL;
	}
	
	for (k= 0; k< arcnum; k++)
	{
		cin >> i >> j;
		arc* s = new arc;
		s->arcdata = j;
	    s->next=vertexnum[i].node;//头插法较好
		vertexnum[i].node = s;	
		
	
	}
	for (i = 0; i < vernum; i++)
	{
		cout << a[i]<< " ";
		while (vertexnum[i].node != nullptr)
		{
			cout << vertexnum[i].node->arcdata << " ";
			vertexnum[i].node = vertexnum[i].node->next;
		}
		cout << endl;
	}
}
int main()
{
	int a[5] = { 1,2,3,4,5 };
	Mgra <int> M(a, 5, 6);


}