#ifndef _LINK_STRUCTOR_
#define _LINK_STRUCTOR_

#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

struct node_ 
{
    int val ;
    struct node_ *next;
};
typedef struct node_ node;

struct charnode_ 
{
    char val ;
    struct charnode_ *next;
};
typedef struct charnode_ charnode;
struct pnode_ 
{
    int* val ;
    struct pnode_ *next;
};
typedef struct pnode_ pnode;
struct cnode_
{
	char* val;
	struct cnode_ *next;
};
typedef struct cnode_ cnode;

pnode * AddNode(int* value ,int len, pnode *a);
cnode * AddNode(char* value, int len, cnode *a);
bool FindNode(cnode *s, const char *str);
void DeleteAllNodes(cnode *s);

charnode * pushNode(char value , charnode *a);
charnode * popupNode(charnode *a,char *c);
int getTopNode(charnode *a,char *c);
void releaseNode(charnode *a);
int getNodeCount(charnode *s);
int getNodeCharAll(charnode *s,char *buf,unsigned int buflen);

node **findNode(node *root, int key);
bool remove_if(node **head, int key);
node * AddNode(int value , node *a);
void AddNode(int value, node **a);
void DeleteAllNodes(node *s);
node* DeleteNodeByValue(node *head, int value);
node* DeleteNodeById(node *head, unsigned int id);
void ShowNode(node *s);
node * reverse( node *n);
node * reverse( node *n,int k);
node *merge_1(node *a,node *b);
node *merge_2(node *a,node *b);
node *merge_3(node *a,node *b);
int GetLinkLength(node *s);
void LinkAction();
#endif /*_LINK_STRUCTOR_*/