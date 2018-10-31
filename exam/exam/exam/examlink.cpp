#include "stdafx.h"
#include "linkstructor.h"
#include <iostream>
using namespace std;

node **findNode(node *root, int key)
{
    node **prev = &root->next;
    node *t = *prev;
    while (t != NULL && t->val != key)
    {
        prev = &t->next;
        t = *prev;
    }
    return prev;
}
bool remove_if(node **head, int key)
{
    for (node ** curr = head; *curr;)
    {
        node *entry = *curr;
        if (key == entry->val)
        {
            *curr = entry->next;
            free(entry);
            return true;
        }
        else
        {
            curr = &entry->next;
        }
    }
    return false;
}
void AddNode(int value, node **a)
{
    node *p = NULL;
    node *pNext = *a;

    p = (node*)malloc(sizeof(node));
    p->val = value;
    p->next = NULL;
    if (*a == NULL)
    {
        *a = p;
        return;
    }
    while (pNext->next != NULL)
    {
        pNext = pNext->next;
    }
    pNext->next = p;
}
node * AddNode(int value , node *a)
{
    node *p = NULL;
    node *pNext = a;

    p = (node*)malloc(sizeof(node));
    p->val = value;
    p->next = NULL;
    if (a == NULL)
    {
        return p;
    }
    while (pNext->next != NULL)
    {
        pNext = pNext->next;
    }
    ////////
    //for (pNext = a; pNext->next != NULL ; pNext = pNext->next);
    ////////
    pNext->next = p;
    return a;
}

node *merge_1(node *a,node *b)
{
    node *h = a, *p, *q;
    while (b)
    {
        for (p = h; p && p->val < b->val; q = p, p = p->next)
            ;

        if (p == h)
        {
            h = b;
        }
        else
        {
            q->next = b;
        }
        q = b;
        b = b->next;
        q->next = p;
    }
    return h;
}

node *merge_2(node *a,node *b)
{
    node *c, *pa, *pb, *pc;
    if (a->val <= b->val)
    {
        pc = c = a;
        pa = a->next;
        pb = b;
    }
    else
    {
        pc = c = b;
        pb = b->next;
        pa = a;
    }

    while (pa && pb)
    {
        if (pa->val <= pb->val)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = (pa ? pa : pb);
    return c;
}

node *merge_3(node *a,node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    node * head = NULL;
    if (a->val < b->val)
    {
        head = a;
        a->next = merge_3(a->next,b);
    }
    else
    {
        head = b;
        b->next = merge_3(a,b->next);
    }
    return head;
}

node * reverse( node *n)
{
    node *head = NULL;
    while (n)
    {
        node *temp = n->next;
        n->next = head ;
        head = n;
        n = temp;
    }
    return head;
}

void ShowNode(node *s)
{
    while(s != NULL)
    {
        printf("%d ",s->val);
        s = s->next;
    }
}
void DeleteAllNodes(node *s)
{
    node *p = s;
    while(s != NULL)
    {
        p = s;
        s = s->next;
        free(p);
    }
}
node* DeleteNodeByValue(node *head,int value)
{
    node *pCur = head;
    node *pCurPre = NULL;
    bool bfind = false;
    if (head == NULL)
    {
        return NULL;
    }
    while (pCur->next != NULL && pCur->val != value)
    {
        pCurPre = pCur;
        pCur = pCur->next;
    }
    if (pCur != NULL && pCur->val == value)
    {
        if (pCurPre == NULL)
        {
            head = head->next;
        }
        else
        {
            pCurPre->next = pCur->next;
        }
        free(pCur);
        bfind = true;
    }
    if (bfind)
    {
        printf("\nfind the %d",value);
    }
    else
    {
        printf("\ncan't find the %d",value);
    }
    return head;
}

node* DeleteNodeById(node *head,unsigned int id)
{
    unsigned int i = 1;
    node *pCur = head;
    node *pCurNext;
    if (head == NULL)
    {
        return NULL;
    }
    pCurNext = pCur->next;
    if (id == 0)
    {
        free(pCur);
		printf("\nfree the %d node", id);
        return pCurNext;
    }
    while (pCur->next != NULL && i++ < id)
    {
        pCur     = pCur->next;
        pCurNext = pCur->next;
    }
    if (pCurNext == NULL && i <= id)
    {
		printf("\ncan't free the %d node", id);
        return head;
    }
    pCur->next = pCurNext->next;
    free(pCurNext);
	printf("\nfree the %d node", id);
    return head;
}

void LinkAction()
{
    int i;
    node *a = NULL;
    node *b = NULL;
    node *c = NULL;
    node *a2 = NULL;
    node *b2 = NULL;
    cout << "\n===========================Link===========================" << endl;
    for (i = 2;i <= 20; i += 2)
    {
        a = AddNode(i, a);
    }

    for (i = 1 ;i < 20; i += 2)
    {
        b = AddNode(i, b);
    }

    for (i = 100;i < 120;i++)
    {
        AddNode(i,&a2);
        AddNode(i + 1,&b2);
    }
    printf("\na=");
    ShowNode(a);
    
    printf("\nb=");
    ShowNode(b);

    printf("\na2=");
    ShowNode(a2);

    printf("\nb2=");
    ShowNode(b2);
    ////////////////////////////
    int keytemp = 20;
    if (remove_if(&a, keytemp))
    {
        printf("\nremoved the %d",keytemp);
    }
    else
    {
         printf("\ncan't find the %d",keytemp);
    }
    printf("\na=");
    ShowNode(a);
    ///////////////////////
    int k2 = 12;
    b = DeleteNodeByValue(b,k2);
    printf("\nCall the DeleteNodeByValue then b=");
    ShowNode(b);
	///////////////////////////
	int k3 = 10;
	b = DeleteNodeById(b, k3);
	printf("\nCall the DeleteNodeById then b=");
	ShowNode(b);
	///////////////
    int key = 19;
    c = merge_2(a , b);
	printf("\nc=");
	ShowNode(c);
    node ** pfind = findNode(c,key);
    if (*pfind)
    {
        printf("find the number:%d.\n",(*pfind)->val);
    }
    else
    {
        printf("Can't find the number:%d.\n",key);
    }
	printf("\nc=");
	ShowNode(c);
	printf("\nc reverse = ");
	ShowNode(reverse(c));
	///////////////////////
	DeleteAllNodes(c);
	DeleteAllNodes(a2);
	DeleteAllNodes(b2);
}
