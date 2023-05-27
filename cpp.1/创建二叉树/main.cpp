#include<iostream>
using namespace std;
struct Tree
{
	int data;
	Tree* lchild;
	Tree* rchild;

};
Tree* create();
int main()
{
	Tree* root = create();
}
Tree* create()
{
	Tree* root;
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		return NULL;
	}
	else
	{   
		
	    root = new Tree;
		
	}
	if (ch >= '0' && ch <= '9')
		{
			

			root->data = ch - '0';
		}
	root->lchild = create();
	root->rchild = create();
	return root;
}