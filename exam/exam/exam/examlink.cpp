#include "stdafx.h"
#include "linkstructor.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};
int getNum(struct ListNode* l1)
{
	int count = 0;
	int i = 1;
	while (l1 != NULL)
	{
		count = count + l1->val * i;
		i = i * 10;
		l1 = l1->next;
	}
	return count;
}
struct ListNode *addNode(int value, struct ListNode* a)
{
	struct ListNode *p = NULL;
	struct ListNode *pNext = a;
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (p == NULL)
		return NULL;
	p->val = value;
	p->next = NULL;
	if (a == NULL)
		return p;
	while (pNext->next != NULL)
	{
		pNext = pNext->next;
	}
	pNext->next = p;
	return a;
}
struct ListNode * reverse2(struct ListNode *n)
{
	struct ListNode *head = NULL;
	while (n)
	{
		struct ListNode *temp = n->next;
		n->next = head;
		head = n;
		n = temp;
	}
	return head;
}
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
	if (l1->val == 0 && !l1->next) return l2;
	if (l2->val == 0 && !l2->next) return l1;
	struct ListNode* l3 = new struct ListNode;
	struct ListNode* temp = l3;
	int sum = 0;
	temp->val = (sum = l1->val + l2->val) >= 10 ? sum % 10 : sum;
	while (sum >= 10 || l1->next || l2->next) {
		temp->next = new struct ListNode;
		temp = temp->next;
		sum = sum >= 10 ? 1 : 0;
		sum += l1->next ? (l1 = l1->next)->val : 0;
		sum += l2->next ? (l2 = l2->next)->val : 0;
		temp->val = sum >= 10 ? sum % 10 : sum;
	}
	return l3;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l3 = NULL;
	int morethan = 0;
	while (l1 && l2)
	{
		int i1 = l1->val;
		int i2 = l2->val;
		int result = 0;
		if (morethan == 0)
		{
			if (i1 + i2 >= 10)
			{
				morethan = 1;
				result = i1 + i2 - 10;
			}
			else
			{
				morethan = 0;
				result = i1 + i2;
			}
		}
		else
		{
			if (i1 + i2 + 1 >= 10)
			{
				morethan = 1;
				result = i1 + i2 + 1 - 10;
			}
			else
			{
				morethan = 0;
				result = i1 + i2 + 1;
			}
		}
		l1 = l1->next;
		l2 = l2->next;
		l3 = addNode(result, l3);
	}
	if (l1 != NULL)
	{
		struct ListNode *l1_first = NULL;
		while (l1 != NULL)
		{
			int i1 = l1->val;
			if (morethan == 1)
			{
				if (i1 == 9)
				{
					l1->val = 0;
					l3 = addNode(0, l3);
				}
				else
				{
					morethan = 0;
					l3 = addNode(++i1, l3);
				}
			}
			else
			{
				l3 = addNode(l1->val, l3);
			}
			l1_first = l1;
			l1 = l1->next;
		}
		if (morethan == 1)
		{
			if (l1_first->val == 9)
			{
				l3 = addNode(1, l3);
			}
			else
			{
				l3 = addNode(++l1_first->val, l3);
			}
		}
		return (l3);
	}
	else if (l2 != NULL)
	{
		struct ListNode *l2_first = NULL;
		while (l2 != NULL)
		{
			int i2 = l2->val;
			if (morethan == 1)
			{
				if (i2 == 9)
				{
					l2->val = 0;
					l3 = addNode(0, l3);
				}
				else
				{
					morethan = 0;
					l3 = addNode(++i2, l3);
				}
			}
			else
			{
				l3 = addNode(l2->val, l3);
			}
			l2_first = l2;
			l2 = l2->next;
		}
		if (morethan == 1)
		{
			if (l2_first->val == 9)
			{
				l3 = addNode(1, l3);
			}
			else
			{
				l3 = addNode(++l2_first->val, l3);
			}
		}
		return l3;
	}
	else
	{
		if (morethan == 1)
		{
			l3 = addNode(1, l3);
		}
		return (l3);
	}
}

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
int GetLinkLength(node *s)
{
    int i = 0;
    while(s != NULL)
    {
        i++;
        s = s->next;
    }
    return i;
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
	int k3 = 0;
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
	///////////////////////
	struct ListNode *l1 = NULL;
	struct ListNode *l2 = NULL;
	struct ListNode *l3 = NULL;
	
	/*l1 = addNode(2, l1);
	l1 = addNode(4, l1);
	l1 = addNode(3, l1);

	l2 = addNode(5, l2);
	l2 = addNode(6, l2);
	l2 = addNode(4, l2);*/

	/*l1 = addNode(9, l1);
	l2 = addNode(1, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);
	l2 = addNode(9, l2);*/

	/*l1 = addNode(9, l1);
	l1 = addNode(8, l1);
	l2 = addNode(1, l2);*/
	l1 = addNode(9, l1);
	l1 = addNode(9, l1);
	l2 = addNode(9, l2);
	l3 = addTwoNumbers(l1, l2);
}
