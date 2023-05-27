#include<iostream>
#include<queue>
using namespace std;
struct Tree
{
	char  data;
	Tree* lchild;
	Tree* rchild;
};
Tree* create_binary();
void  order(Tree* root);
int main()
{
	Tree* root = create_binary();
	order(root);
}
Tree* create_binary()
{
	Tree* root;
	char da;
	cin >> da;
	if (da == '#')
	{
		return nullptr;
	}
	else
	{
		root = new Tree;
		if (root == nullptr)
		{
			cout << "Ê§°Ü" << endl;
			return NULL;
		}
		root->data = da;

	}
	root->lchild=create_binary();
	root->rchild=create_binary();
	return root;

}
void order(Tree* root)
{
	queue<Tree *> temp;
	if (root == nullptr)
	{
		return;
	}
	temp.push(root);
	
	while (!temp.empty())
	{
		Tree* node = temp.front();
		cout << node->data;
		temp.pop();
		if (node->lchild != nullptr)
		{
			temp.push(node->lchild);
		}
		if (node->rchild != nullptr)
		{
			temp.push(node->rchild);
		}
	}
}