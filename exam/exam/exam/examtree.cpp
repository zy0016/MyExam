#include "stdafx.h"
#include "mytree.h"
#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int max(int a, int b)
{
	return a < b ? b : a;
}

void preOrder(TreeNode* root, vector<int>& res) {
	if (root == nullptr) 
		return;
	res.push_back(root->val);
	preOrder(root->left, res);
	preOrder(root->right, res);
}

void inOrder(TreeNode* root, vector<int>& res) {
	if (root == nullptr) 
		return;
	inOrder(root->left, res);
	res.push_back(root->val);
	inOrder(root->right, res);
}

void postOrder(TreeNode* root, vector<int>& res) {
	if (root == nullptr) 
		return;
	postOrder(root->left, res);
	postOrder(root->right, res);
	res.push_back(root->val);
}

vector<int> preOrder(TreeNode* root) {
	vector<int> res;
	if (root == nullptr) 
		return res;

	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur || !st.empty()) {
		while (cur) {
			res.push_back(cur->val);
			st.push(cur);
			cur = cur->left;
		}
		if (!st.empty()) {
			cur = st.top();
			st.pop();
			cur = cur->right;
		}
	}
	return res;
}

vector<int> inOrder(TreeNode* root) {
	vector<int> res;
	if (root == nullptr) 
		return res;

	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur || !st.empty()) 
	{
		while (cur) 
		{
			st.push(cur);
			cur = cur->left;
		}
		if (!st.empty()) 
		{
			cur = st.top();
			st.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}
	}
	return res;
}

vector<int> postOrder(TreeNode* root) 
{
	vector<int> res;
	if (root == nullptr) 
		return res;

	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur) 
	{
		st.push(cur);
		cur = cur->left;
	}

	TreeNode* lastVisited = nullptr;
	while (!st.empty()) 
	{
		cur = st.top();
		st.pop();
		if (cur->right == nullptr || cur->right == lastVisited) 
		{
			res.push_back(cur->val);
			lastVisited = cur;
		}
		else {
			st.push(cur);
			cur = cur->right;
			while (cur) {
				st.push(cur);
				cur = cur->left;
			}
		}
	}
	return res;
}

vector<int> levelOrder(TreeNode* root) {
	vector<int> res;
	if (root == nullptr) return res;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		size_t n = q.size();
		for (size_t i = 0; i<n; i++) {
			TreeNode* cur = q.back();
			q.pop();
			res.push_back(cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
	return res;
}
/////////////////////////////////////////////////////////////////////
void createBiTree(BiTree &T)
{
	char c;
	cin >> c;
	if ('#' == c)
	{
		T = NULL;
	}
	else
	{
		T = new BiTreeNode;
		T->data = c;
		createBiTree(T->leftChild);
		createBiTree(T->rightChild);
	}
}
// 用递归方法求树的高度
int Depth(BiTree T)
{
	if (NULL == T)
		return 0;

	int leftDepth = Depth(T->leftChild);
	int rightDepth = Depth(T->rightChild);

	return 1 + max(leftDepth, rightDepth);
}

void PrintNodeAtLevel(BiTree T, int level)
{
	// 空树或层级不合理
	if (NULL == T || level < 1)
		return;

	if (1 == level)
	{
		cout << T->data << "  ";
		return;
	}
	// 左子树的 level - 1 级
	PrintNodeAtLevel(T->leftChild, level - 1);

	// 右子树的 level - 1 级
	PrintNodeAtLevel(T->rightChild, level - 1);
}

void traverseMiddle(BiTree tree)
{
	if (!tree)
		return;
	traverseMiddle(tree->leftChild);
	cout << tree->data << " ";
	traverseMiddle(tree->rightChild);
}
void traversePre(BiTree tree)
{
	if (!tree)
		return;
	cout << tree->data << " ";
	traversePre(tree->leftChild);
	traversePre(tree->rightChild);
}
void traversePost(BiTree tree)
{
	if (!tree)
		return;
	traversePost(tree->leftChild);
	traversePost(tree->rightChild);
	cout << tree->data << " ";
}
void destroytree(BiTree T)
{
	if (T)
	{
		destroytree(T->leftChild);
		destroytree(T->rightChild);
		delete T;
		T = NULL;
	}
}
void LevelTraverse(BiTree T)
{
	if (NULL == T)
		return;

	int depth = Depth(T);
	int i;
	for (i = 1; i <= depth; i++)
	{
		PrintNodeAtLevel(T, i);
		cout << endl;
	}
}

void testmytree()
{
	cout << "\n===========================testmytree===========================" << endl;
	BiTree T;
	createBiTree(T);//2 3 4 # # 5 # 6 # # 7 # #

	cout << "level browser:" << endl;
	LevelTraverse(T);

	cout << "middle browers:";
	traverseMiddle(T);
	cout << endl;
	
	cout << "pre browers:";
	traversePre(T);
	cout << endl;

	cout << "post browers:";
	traversePost(T);
	cout << endl;

	cout << "destroy tree:" << endl;
	destroytree(T);
	cout << endl;
}


