#ifndef _MYTREE_STRUCTOR_
#define _MYTREE_STRUCTOR_

#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};
//////////////////////////////////////////////////
typedef struct mynode
{
	struct mynode *leftChild;
	struct mynode *rightChild;
	char data;
}BiTreeNode, *BiTree;

void testmytree();
#endif

