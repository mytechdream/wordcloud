#pragma once
class UF//���鼯
{
private:
	int count;//��ʾ��¼��ͨ����
	int* parent;
	int* size;
public:
	void union_tree(int p, int q);
	bool connected(int p, int q);//�ж��Ƿ�����
	int count_num();//������ͨ�����ĸ���
	int find(int x);//���Ҹ��ڵ�
	UF(int n)
	{
		this->count = n;
		parent = new int[n];//���츸����
		size = new int[n];
		for (int i = 0; i < n; i++)//���캯��,��ÿ���ڵ�ĸ��ڵ�Ϊ�Լ�
		{
			parent[i] = i;
			size[i] = 1;
		}
	}
};


void UF::union_tree(int p, int q)
{
	int rootP = find(p);//����p��ĸ��ڵ�
	int rootQ = find(q);//����q�ĸ��ڵ�
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
		x = parent[x];//�����˵���
	}
	return x;
}

