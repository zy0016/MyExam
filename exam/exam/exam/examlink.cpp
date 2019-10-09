#include "stdafx.h"
#include "linkstructor.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};
node* rotateRight(node* head, int k)
{
    if (head == NULL)
        return NULL;
    int len = 0;
    node* pcur = head;
    node* pcurpre = NULL;
    
    while(pcur != NULL)
    {
        pcur = pcur->next;
        len++;
    }
    k = k % len;
    int i = 0;
    while(i < k)
    {
        pcur = head;
        pcurpre = NULL;
        while(pcur->next != NULL)
        {
            pcurpre = pcur;
            pcur = pcur->next;
        }
        if (pcurpre == NULL)
        {
            return head;
        }
        pcur->next = head;
        pcurpre->next = NULL;
        head = pcur;
        i++;
    }
    return head;
}
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
int getcount(struct ListNode* l1)
{
	int count = 0;
	while (l1 != NULL)
	{
		count++;
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

nodem * AddNode(const char* str_ori, const char* str_sorted, nodem *a)
{
	int len_ori,len_sorted;
	nodem *p = NULL;
	nodem *pNext = a;
	p = (nodem*)malloc(sizeof(nodem));
	if (p == NULL)
		return NULL;
	const char *pstr_ori = str_ori;
	const char *pstr_sorted = str_sorted;
	len_ori = strlen(str_ori) + 1;
	len_sorted = strlen(str_sorted) + 1;

	p->str_sorted = (char*)malloc(sizeof(char) * len_sorted);
	memset(p->str_sorted, 0, sizeof(char) * len_sorted);
	strcpy(p->str_sorted, pstr_sorted);

	p->next = NULL;
	p->pcnode = NULL;
	if (a == NULL)
	{
		p->pcnode = AddNode(pstr_ori, p->pcnode);
		return p;
	}
	while (pNext != NULL)
	{
		if (strcmp(pNext->str_sorted, pstr_sorted) == 0)
		{
			pNext->pcnode = AddNode(pstr_ori, pNext->pcnode);
            free(p);
			return a;
		}
		pNext = pNext->next;
	}
	pNext = a;
	while (pNext->next != NULL)
	{
		pNext = pNext->next;
	}
	p->pcnode = AddNode(pstr_ori, p->pcnode);
	pNext->next = p;
	return a;
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
node * deleteDuplicates(node *head,int)
{
    node *pCur = head, *pCurNext = NULL, *pCurNextNext = NULL, *p, *pCurPre = NULL;
    if (head == NULL || head->next == NULL)
        return head;

    pCurNext = pCur->next;
    if (pCurNext->next == NULL)
    {
        //only has 2 node.
        if (pCur->val == pCurNext->val)
        {
            pCur->next = NULL;
            free(pCurNext);
        }
        return head;
    }
    pCurNextNext = pCurNext->next;
    while (pCur->next != NULL)
    {
        if (pCurNextNext == NULL)
        {
            if (pCur->val == pCurNext->val)
            {
                if (pCurPre == NULL)
                {
                    free(pCurNext);
                    head->next = NULL;;
                }
                else
                {
                    pCur->next = pCurNext->next;
                    free(pCurNext);
                }
            }
            break;
        }
        if (pCur->val == pCurNext->val && pCur->val == pCurNextNext->val)
        {
            if (pCurPre == NULL)
            {
                head = head->next;
            }
            else
            {
                pCurPre->next = pCur->next;
            }
            p = pCur;
            pCur = pCurNext;
            if (pCurNext != NULL)
            {
                pCurNext = pCurNext->next;
            }
            if (pCurNext != NULL)
            {
                pCurNextNext = pCurNext->next;
            }
            free(p);
        }
        else if (pCur->val == pCurNext->val && pCur->val != pCurNextNext->val)
        {
            pCur->next = pCurNext->next;
            free(pCurNext);
            if (pCur != NULL)
            {
                pCurNext = pCur->next;
            }
            if (pCurNext != NULL)
            {
                pCurNextNext = pCurNext->next;
            }
        }
        else
        {
            pCurPre = pCur;
            pCur = pCur->next;
            if (pCurNext != NULL)
            {
                pCurNext = pCurNext->next;
            }
            if (pCurNextNext != NULL)
            {
                pCurNextNext = pCurNextNext->next;
            }
        }
    }
    return head;
}
node * deleteDuplicates(node *head)
{
    node *pCur = head, *pCurNext = NULL, *pCurNextNext = NULL, *p, *pCurPre = NULL;
    if (head == NULL || head->next == NULL)
        return head;

    pCurNext = pCur->next;
    if (pCurNext->next == NULL)
    {
        //only has 2 node.
        if (pCur->val == pCurNext->val)
        {
            free(pCur);
            free(pCurNext);
            head = NULL;
        }
        return head;
    }
    pCurNextNext = pCurNext->next;
    while (pCur->next != NULL)
    {
        if (pCurNextNext == NULL)
        {
            if (pCur->val == pCurNext->val)
            {
                if (pCurPre == NULL)
                {
                    free(pCur);
                    free(pCurNext);
                    head = NULL;
                }
                else
                {
                    free(pCur);
                    free(pCurNext);
                    pCurPre->next = NULL;
                }
            }
            break;
        }
        if (pCur->val == pCurNext->val && pCur->val == pCurNextNext->val)
        {
            if (pCurPre == NULL)
            {
                head = head->next;
            }
            else
            {
                pCurPre->next = pCur->next;
            }
            p = pCur;
            pCur = pCurNext;
            if (pCurNext != NULL)
            {
                pCurNext = pCurNext->next;
            }
            if (pCurNext != NULL)
            {
                pCurNextNext = pCurNext->next;
            }
            free(p);
        }
        else if (pCur->val == pCurNext->val && pCur->val != pCurNextNext->val)
        {
            if (pCurPre == NULL)
            {
                head = pCurNextNext;
            }
            else
            {
                pCurPre->next = pCurNextNext;
            }
            free(pCur);
            free(pCurNext);
            pCur = pCurNextNext;
            if (pCur != NULL)
            {
                pCurNext = pCur->next;
            }
            if (pCurNext != NULL)
            {
                pCurNextNext = pCurNext->next;
            }
        }
        else
        {
            pCurPre = pCur;
            pCur = pCur->next;
            if (pCurNext != NULL)
            {
                pCurNext = pCurNext->next;
            }
            if (pCurNextNext != NULL)
            {
                pCurNextNext = pCurNextNext->next;
            }
        }
    }
    return head;
}
node* partition(node* head, int x)
{
    node *pNew = NULL,*pNewHead = NULL;
    node *pCur = head;
    while(pCur != NULL)
    {
        if (pCur->val < x)
        {
            if (pNewHead == NULL)
            {
                pNewHead = pCur;
                pNew = pCur;
            }
            else
            {
                pNew = pNewHead;
                while(pNew->next != NULL)
                {
                    pNew = pNew->next;
                }
                pNew->next = pCur;
            }
        }
        pCur = pCur->next;
    }
    return pNewHead;
}
charnode * pushNode(char value , charnode *a)
{
    charnode *p = NULL;
    charnode *pNext = a;

    p = (charnode*)malloc(sizeof(charnode));
    p->val = value;
    p->next = NULL;
    if (a != NULL)
    {
        p->next = a;
    }
    return p;
}
charnode* popupNode(charnode *a,char *c)
{
    if (a == NULL)
    {
        return NULL;
    }
    *c = a->val;
    charnode *p = a;
    a = a->next;
    free(p);
    return a;
}
int getAmountLink(node *p)
{
    int count = 0;
    while(p != NULL)
    {
        count += p->val;
        p = p->next;
    }
    return count;
}
int getTopNode(charnode *a,char *c)
{
    if (a == NULL)
        return 0;
    *c = a->val;
    return 1;
}
void releaseNode(charnode *s)
{
    charnode *p = s;
    while(s != NULL)
    {
        p = s;
        s = s->next;
        free(p);
    }
}
int getNodeCount(charnode *s)
{
    int i = 0;
    while(s != NULL)
    {
        s = s->next;
        i++;
    }
    return i;
}
int getNodeCharAll(charnode *s,char *buf,unsigned int buflen)
{
    int i = 0;
    char *p = buf;
    while(s != NULL)
    {
        *p = s->val;
        s = s->next;
        if (i == buflen - 1)
            break;
        i++;
        p++;
    }
    *p = '\0';
    return i;
}
pnode * AddNode(int* value,int len , pnode *a)
{
    pnode *p = NULL;
    pnode *pNext = a;

    p = (pnode*)malloc(sizeof(pnode));
    p->val = (int*)malloc(sizeof(int) * len);
    memset(p->val,0,sizeof(int) * len);
    memcpy(p->val,value,len);
    p->next = NULL;
    if (a == NULL)
    {
        return p;
    }
    while (pNext->next != NULL)
    {
        pNext = pNext->next;
    }
    pNext->next = p;
    return a;
}
cnode * AddNode(const char* value, cnode *a)
{
	cnode *p = NULL;
	cnode *pNext = a;
    int len = strlen(value);
	p = (cnode*)malloc(sizeof(cnode));
	p->val = (char*)malloc(sizeof(int) * (len+1));
	memset(p->val, 0, sizeof(int) * (len + 1));
	strcpy(p->val, value);
	p->next = NULL;
	if (a == NULL)
	{
		return p;
	}
	while (pNext->next != NULL)
	{
		pNext = pNext->next;
	}
	pNext->next = p;
	return a;
}
bool FindNode(cnode *s,const char *str)
{
	while (s != NULL)
	{
		if (strcmp(s->val, str) == 0)
			return true;
		s = s->next;
	}
	return false;
}
void DeleteAllNodes(cnode *s)
{
	cnode *p = s;
	while (s != NULL)
	{
		p = s;
		s = s->next;
		free(p);
	}
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
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
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
node* mergeKLists(node** lists, int listsSize)
{
    if (lists == NULL || listsSize == 0)
        return NULL;
    if (listsSize == 1)
    {
        return *lists;
    }
    node *p,*p1,*p2;
    int id = 0;
    p = lists[0];
    while(listsSize - 1 > id)
    {
        p1 = p;
        p2 = lists[id + 1];
        p = merge_2(p1,p2);
        id++;
    }
    return p;
}
node* swapPairs(node* head)
{
    if (head == NULL || head->next == NULL) 
		return head;
	node *start = head->next;
	node *next = start->next;
	start->next = head;
	head->next = swapPairs(next);
	return start;
}

node * reverse( node *begin,node *end)
{
    node *head = NULL;
    while (begin != end)
    {
        node *temp = begin->next;
        begin->next = head ;
        head = begin;
        begin = temp;
    }
    node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = end;
    return head;
}
node* reverseKGroup(node* head, int k)
{
    node* cur = head;
    for(int t = 1; t < k; t++) 
    {
        if(cur) 
            cur = cur->next;
        else 
            break;
    }
    if(!cur) 
        return head;
    node* end = cur->next;
    node* rev = reverse(head, end);
    head->next = reverseKGroup(end, k);
    return rev;
    //if(k==1 || head==NULL) 
    //    return head;
    ////判断当前链表剩余节点数是否满足翻转条件
    //node* tail = head;
    //int cnt = 1;
    //while(cnt<k)
    //{
    //    tail = tail->next;
    //    if(tail==NULL) //当前长度不支持reverse
    //        return head;
    //    cnt++;
    //}
    ////局部reverse
    //node* pre = head;
    //node* cur = pre->next;
    //cnt = 1;
    //while(cnt<k)
    //{
    //    node* next = cur->next;
    //    cur->next = pre;
    //    pre = cur;
    //    cur = next;
    //    cnt++;
    //}
    ////翻转结束后，pre指向当前k个元素的最后一个元素，翻转后会变成头元素，而cur则是下次待翻转元素的开头
    //head->next = reverseKGroup(cur, k); //翻转前的head会变成翻转后的最后一个元素
    //return pre;
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
    printf("\n");
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
node* reverseBetween(node* head, int m, int n)
{
    node *p = head,*pm = NULL,*pmPre = NULL,*pn = NULL,*pn_bak = NULL;
    if (m >= n || head == NULL || head->next == NULL)
        return head;
    int i = 1;
    while(p != NULL && i < m)
    {
        pmPre = p;
        p = p->next;
        i++;
    }
    if (p == NULL && i <= m)
    {
        return head;
    }
    pm = p;
    //////////////////
    while(p != NULL && i < n)
    {
        p = p->next;
        i++;
    }
    if (p == NULL && i <= n)
    {
        return head;
    }
    pn = p;
    pn_bak = pn->next;
    pn->next = NULL;
    if (pmPre == NULL)
    {
        head = reverse(pm);
    }
    else
    {
        pmPre->next = reverse(pm);
    }
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = pn_bak;
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
    //////////////////////
    node *p1 = NULL;
    node *p2 = NULL;
    node *p3 = NULL;
    p1 = AddNode(1,p1);
    p1 = AddNode(4,p1);
    p1 = AddNode(5,p1);

    p2 = AddNode(1,p2);
    p2 = AddNode(3,p2);
    p2 = AddNode(4,p2);

    p3 = AddNode(2,p3);
    p3 = AddNode(6,p3);

    //node *p12 = merge_2(p1,p2);
    //ShowNode(p12);
    node *ps[] = {p1,p2,p3};
    node *p4 = mergeKLists(ps,3);
    ShowNode(p4);
    /////////////////////
    node *pa = NULL;
    for (i = 1;i <= 4; i++)
    {
        pa = AddNode(i, pa);
    }
    pa = swapPairs(pa);
    ShowNode(pa);

    node *pb = NULL;
    for (i = 1;i <= 5; i++)
    {
        pb = AddNode(i, pb);
    }
    pb = swapPairs(pb);
    ShowNode(pb);

    node * psk = NULL;
    for (int i = 1;i < 6;i++)
    {
        psk = AddNode(i,psk);
    }
    ShowNode(psk);
    psk = reverseKGroup(psk,2);
    ShowNode(psk);
    ///////////////////////
    node *pr = NULL;
    for (int i = 0;i < 5;i++)
    {
        pr = AddNode(i+1,pr);
    }
    ShowNode(pr);
    pr = rotateRight(pr,2);
    ShowNode(pr);
    {
        node *pd = NULL;
        int ad[] = {1,1,2,2,3,4,4,5};
        for (int i = 0;i < sizeof(ad) / sizeof(int);i++)
        {
            pd = AddNode(ad[i],pd);
        }
        ShowNode(pd);
        pd = deleteDuplicates(pd);
        ShowNode(pd);

        node *pd2 = NULL;
        int ad2[] = {1,2,3,3,4,4,5};
        for (int i = 0;i < sizeof(ad2) / sizeof(int);i++)
        {
            pd2 = AddNode(ad2[i],pd2);
        }
        ShowNode(pd2);
        pd2 = deleteDuplicates(pd2);
        ShowNode(pd2);

        node *pd3 = NULL;
        int ad3[] = {1,1,1,2,3};
        for (int i = 0;i < sizeof(ad3) / sizeof(int);i++)
        {
            pd3 = AddNode(ad3[i],pd3);
        }
        ShowNode(pd3);
        pd3 = deleteDuplicates(pd3);
        ShowNode(pd3);

		node *pd4 = NULL;
		int ad4[] = { 1,2,2 };
		for (int i = 0; i < sizeof(ad4) / sizeof(int); i++)
		{
			pd4 = AddNode(ad4[i], pd4);
		}
		ShowNode(pd4);
		pd4 = deleteDuplicates(pd4);
		ShowNode(pd4);

        node *pd5 = NULL;
		int ad5[] = { 1,1,2 };
		for (int i = 0; i < sizeof(ad5) / sizeof(int); i++)
		{
			pd5 = AddNode(ad5[i], pd5);
		}
		ShowNode(pd5);
		pd5 = deleteDuplicates(pd5,0);
		ShowNode(pd5);

        node *pd6 = NULL;
		int ad6[] = { 1,1,2,3,3 };
		for (int i = 0; i < sizeof(ad6) / sizeof(int); i++)
		{
			pd6 = AddNode(ad6[i], pd6);
		}
		ShowNode(pd6);
		pd6 = deleteDuplicates(pd6,0);
		ShowNode(pd6);

        node *pd7 = NULL;
		int ad7[] = { 1,1,2,2 };
		for (int i = 0; i < sizeof(ad7) / sizeof(int); i++)
		{
			pd7 = AddNode(ad7[i], pd7);
		}
		ShowNode(pd7);
		pd7 = deleteDuplicates(pd7,0);
		ShowNode(pd7);
    }
    {
        node *pr = NULL;
        int iv[] = {1,2,3,4,5};
        for (int i = 0; i < sizeof(iv) / sizeof(int); i++)
		{
			pr = AddNode(iv[i], pr);
		}
		ShowNode(pr);
        pr = reverseBetween(pr,2,4);
		ShowNode(pr);
        ////////////////////
        node *pr1 = NULL;
        int iv1[] = {1,2,3,4,5};
        for (int i = 0; i < sizeof(iv1) / sizeof(int); i++)
		{
			pr1 = AddNode(iv1[i], pr1);
		}
		ShowNode(pr1);
        pr1 = reverseBetween(pr1,6,7);
		ShowNode(pr1);
        //////////////////////
        node *pr2 = NULL;
        int iv2[] = {3,5};
        for (int i = 0; i < sizeof(iv2) / sizeof(int); i++)
		{
			pr2 = AddNode(iv2[i], pr2);
		}
		ShowNode(pr2);
        pr2 = reverseBetween(pr2,1,2);
		ShowNode(pr2);
        ////////////////////////
        node *pr3 = NULL;
        int iv3[] = {1,2,3};
        for (int i = 0; i < sizeof(iv3) / sizeof(int); i++)
		{
			pr3 = AddNode(iv3[i], pr3);
		}
		ShowNode(pr3);
        pr3 = reverseBetween(pr3,2,3);
		ShowNode(pr3);
        //////////////////////////
        node *pr4 = NULL;
        int iv4[] = {1,2,3};
        for (int i = 0; i < sizeof(iv4) / sizeof(int); i++)
		{
			pr4 = AddNode(iv4[i], pr4);
		}
		ShowNode(pr4);
        pr4 = reverseBetween(pr4,1,3);
		ShowNode(pr4);
        //////////////////////////
        node *pr5 = NULL;
        int iv5[] = {1,2,3,4};
        for (int i = 0; i < sizeof(iv5) / sizeof(int); i++)
		{
			pr5 = AddNode(iv5[i], pr5);
		}
		ShowNode(pr5);
        pr5 = reverseBetween(pr5,1,4);
		ShowNode(pr5);
    }
    /*{
        node *pd1 = NULL;
		int ad1[] = { 1,4,3,2,5,2 };
		for (int i = 0; i < sizeof(ad1) / sizeof(int); i++)
		{
			pd1 = AddNode(ad1[i], pd1);
		}
		ShowNode(pd1);
		pd1 = partition(pd1,3);
		ShowNode(pd1);
    }*/
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
    /////////////////////

}
