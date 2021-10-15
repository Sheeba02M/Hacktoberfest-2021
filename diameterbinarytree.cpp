#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};
int calcheight(node* root)
{
	if(root==NULL)
		return -1;
	int lh=calcheight(root->left);
	int rh=calcheight(root->right);
	return max(lh,rh)+1;
}
int calcdiameter(node* root)
{
	if(root==NULL)
		return -1;
	int leftheight=calcheight(root->left);
	int rightheight=calcheight(root->right);
	int cd=(leftheight+rightheight+1);
	int ld=calcdiameter(root->left);
	int rd=calcdiameter(root->right);
	return max(leftheight+rightheight+1,max(ld,rd));
}
int main()
{
	struct node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
cout<<"diameter of tree"<<calcdiameter(root)<<endl;
}
