#include<iostream>
using namespace std;
const int MaxSize = 10;
template <class DataType>
class MGraph;
template <class DataType>
void print(MGraph<DataType>& t);
template <class DataType>
class MGraph
{
	//直接在类内部声明定义函数不报错

	friend void print<DataType>(MGraph<DataType>& t);
public:
	MGraph(DataType a[], int n, int e);

private :
	DataType vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum, arcNum;
};
template<class DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	vertexNum = n; arcNum = e;
	int i,j;
	for (i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (i = 0; i < vertexNum; i++)
	{
		for (j = 0; j < vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	for (int k = 0; k < arcNum; k++)
	{
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}	

	

}

template <class DataType>
void print<DataType>(MGraph<DataType>& t)
{
	int i, j;
	for (i = 0; i < t.vertexNum; i++)
	{
		for (j = 0; j < t.vertexNum; j++)
		{
			cout << t.arc[i][j];
		}
		cout << endl;
	}
}

int main()
{

	/*int matrix[4][4] = {0};
	matrix[0][1] = 1;
	matrix[0][3] = 1;
	matrix[1][0] = 1;
	matrix[1][2] = 1;
	matrix[1][3] = 1;
	matrix[2][1] = 1;
	matrix[3][0] = 1;
	matrix[3][1] = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrix[i][j];

		}
		cout << endl;
	}*/
	int   a[5] = {1,2,3,4,5};
	MGraph<int > m(a, 5, 6);
	print(m);

}