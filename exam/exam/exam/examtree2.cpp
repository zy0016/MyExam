#include "stdafx.h"
#include "mytree2.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
#include <fstream>
#include <functional>
#include <ctime>
#include <typeinfo>
#include <cstdlib>
#include <set>
#include <deque>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <bitset>
#include <sstream>
#include <bitset>
using namespace std;

template <typename T>
class binaryTreeNode {
public:
	T element;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;

	binaryTreeNode() { leftChild = NULL; rightChild = NULL; }
};
template <typename T>
class binaryTree {
private:
	binaryTreeNode<T>* mRoot;//树根


	int getSize(binaryTreeNode<T>*);
	int getHeight(binaryTreeNode<T>*);

	void preOrder(binaryTreeNode<T>*);
	void inOrder(binaryTreeNode<T>*);
	void postOrder(binaryTreeNode<T>*);
	void distroy(binaryTreeNode<T>*&);
	binaryTreeNode<T>* AddNode(const T& key, int direction, binaryTreeNode<T>*& root);

public:
	binaryTree();
	virtual ~binaryTree();
	binaryTreeNode<T>* Create();//递归的创建二叉树的节点
	void AddNode(const T& key, int direction);

	int getSize();//递归得到树的节点数目
	int getHeight();//递归得到树的高度

					//递归遍历
	void preOrder();//前序遍历
	void inOrder();//中序遍历
	void postOrder();//后序遍历

					 //删除二叉树
	void distroy();

};
template <typename T>
binaryTreeNode<T>* binaryTree<T>::AddNode(const T& key, int direction, binaryTreeNode<T>*& root)
{
	if (direction == 0)//左孩子
	{
		if (root->leftChild == NULL) {//找到对应的叶节点插入
			root->leftChild = new binaryTreeNode<T>(key);
		}
		else {
			root->leftChild = AddNode(key, direction, root->leftChild);
		}
	}

	else//右孩子
	{
		if (root->rightChild == NULL) {//找到相应的叶节点插入
			root->rightChild = new binaryTreeNode<T>(key);
		}
		else {
			root->rightChild = AddNode(key, direction, root->rightChild);
		}
	}

	return root;
}

template <typename T>
void binaryTree<T>::AddNode(const T& key, int direction)
{
	AddNode(key, direction, mRoot);
}

template <typename T>
binaryTreeNode<T>* binaryTree<T>::Create() {

	binaryTreeNode<T>* current = NULL;

	T val;

	cin >> val;//输入键值

	if (val == -1)//标识当前子树为空，转向下一节点
	{
		return NULL;
	}

	else {//递归的创建左右子树
		current = new binaryTreeNode<T>;
		current->element = val;
		current->leftChild = Create();
		current->rightChild = Create();
		return current;
	}
}
/*二叉树的销毁操作：后序遍历删除

1）不能使用该声明：void distroy(binaryTreeNode<T>* pNode);该声明会创建一个局部的临时对象来保存传递的指针
虽然实参指针和局部指针都执行同一块堆空间，delete局部指针也会删除二叉树结构所占用的堆内存
但是实参指针将出现无所指的状态，出现不可预料的错误
因此传递的是指针的引用，这样才能将实参指针置空。

2）使用递归方法释放节点

*/

template <typename T>
void binaryTree<T>::distroy(binaryTreeNode<T>*& pNode)
{
	if (pNode)
	{
		distroy(pNode->leftChild);
		distroy(pNode->rightChild);
		delete pNode;
		pNode = NULL;
	}
}
template <typename T>
void binaryTree<T>::distroy()
{
	distroy(mRoot);
}
template <typename T>
int binaryTree<T>::getHeight()
{
	return getHeight(mRoot);
}
/*
获取当前节点的深度
递归的方法首先要设置截止条件，在进行递归操作。
0.约束条件：节点为空
1.递归左子树,每次递归加1
2.递归右子树，每次递归加1
3.比较左右子树深度，更深的子树+1即为当前节点深度。
*/

template <typename T>
int binaryTree<T>::getHeight(binaryTreeNode<T>* node)
{
	if (node == NULL)
		return 0;
	else {
		int depL = getHeight(node->leftChild);
		int depR = getHeight(node->rightChild);
		return (depL > depR) ? depL + 1 : depR + 1;
	}

}

template <typename T>
void binaryTree<T>::preOrder()
{
	cout << "preOrder:";
	preOrder(mRoot);
	cout << endl;
}

/*
前序遍历：
1.由于是递归实现，所以要设置截止条件：当前节点为空
2.先访问父节点，再访问左节点，最后访问右孩子

*/
template <typename T>
void binaryTree<T>::preOrder(binaryTreeNode<T>* node)
{
	if (node == NULL)
		return;
	else {
		cout << node->element << ' ';
		preOrder(node->leftChild);
		preOrder(node->rightChild);
	}
}

void testmytree2()
{
	cout << "\n===========================testmytree2===========================" << endl;
}