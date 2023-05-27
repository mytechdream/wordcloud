#pragma once
class UF//并查集
{
private:
	int count;//表示记录连通分量
	int* parent;
	int* size;
public:
	void union_tree(int p, int q);
	bool connected(int p, int q);//判断是否相连
	int count_num();//返回连通分量的个数
	int find(int x);//查找父节点
	UF(int n)
	{
		this->count = n;
		parent = new int[n];//创造父数组
		size = new int[n];
		for (int i = 0; i < n; i++)//构造函数,让每个节点的父节点为自己
		{
			parent[i] = i;
			size[i] = 1;
		}
	}
};


void UF::union_tree(int p, int q)
{
	int rootP = find(p);//查找p点的父节点
	int rootQ = find(q);//查找q的父节点
	if (rootP == rootQ)
		return;
	if (size[rootP] > size[rootQ])
	{
		parent[rootQ] = rootP;
		size[rootP] += size[rootQ];
	}
	else
	{
		parent[rootP] = rootQ;
		size[rootQ] += size[rootP];
	}
	parent[rootP] = rootQ;
	count--;

}
bool UF::connected(int p, int q)
{
	int rootP = find(p);
	int rootQ = find(q);
	return rootP == rootQ;
}
int UF::count_num()
{
	return count;
}


int UF::find(int x)
{
	while (parent[x] != x)
	{
		x = parent[x];//利用了迭代
	}
	return x;
}

