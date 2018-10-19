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

node **findNode(node *root, int key);
bool remove_if(node **head, int key);
node * AddNode(int value , node *a);
void AddNode(int value, node **a);
void DeleteAllNodes(node *s);
node* DeleteNodeByValue(node *head, int value);
node* DeleteNodeById(node *head, unsigned int id);
void ShowNode(node *s);
node * reverse( node *n);
node *merge_1(node *a,node *b);
node *merge_2(node *a,node *b);
node *merge_3(node *a,node *b);

void LinkAction();
#endif /*_LINK_STRUCTOR_*/