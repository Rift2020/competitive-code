#include <iostream>
#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct node
{
ElemType data;
struct node* next;
} SLinkNode;
void InitList(SLinkNode*& L)
{
L = (SLinkNode*)malloc(sizeof(SLinkNode));
L->next = NULL;
}
void DestroyList(SLinkNode*& L)
{
SLinkNode* pre = L, * p = pre->next;
while (p != NULL)
{
free(pre);
pre = p; p = p->next;
}
free(pre);
}
int GetLength(SLinkNode* L)
{
int i = 0;
SLinkNode* p = L->next;
while (p != NULL)
{
i++;
p = p->next;
}
return i;
}
int GetElem(SLinkNode* L, int i, ElemType& e)
{
int j = 0;
SLinkNode* p = L;
if (i <= 0) return 0;
while (p != NULL && j < i)
{
j++;
p = p->next;
}
if (p == NULL)
return 0;
else
{
e = p->data;
return 1;
}
}
int Locate(SLinkNode* L, ElemType e)
{
SLinkNode* p = L->next;
int j = 1;
while (p != NULL && p->data != e)
{
p = p->next;
j++;
}
if (p == NULL) return(0);
else return(j);
}
int InsElem(SLinkNode*& L, ElemType x, int i)
{
int j = 0;
SLinkNode* p = L, * s;
if (i <= 0) return 0;
while (p != NULL && j < i - 1)
{
j++;
p = p->next;
}
if (p == NULL)
return 0;
else
{
s = (SLinkNode*)malloc(sizeof(SLinkNode));
s->data = x;
s->next = p->next;
p->next = s;
return 1;
}
}
int DelElem(SLinkNode*& L, int i)
{
int j = 0;
SLinkNode* p = L, * q;
if (i <= 0) return 0;
while (p != NULL && j < i - 1)
{
j++;
p = p->next;
}
if (p == NULL)
return 0;
else
{
q = p->next;
if (q == NULL)
return 0;
else
{
p->next = q->next;
free(q);
return 1;
}
}
}
void DispList(SLinkNode* L)
{
SLinkNode* p = L->next;
while (p != NULL)
{
printf("%d ", p->data);
p = p->next;
}
printf("\n");
}

void CreateListF(SLinkNode*& L, ElemType a[], int n)
{
SLinkNode* s;  int i;
L = (SLinkNode*)malloc(sizeof(SLinkNode));
L->next = NULL;
for (i = 0; i < n; i++)
{
s = (SLinkNode*)malloc(sizeof(SLinkNode));
s->data = a[i];
s->next = L->next;
L->next = s;
}
}

void CreateListR(SLinkNode*& L, ElemType a[], int n)
{
SLinkNode* s, * tc;  int i;
L = (SLinkNode*)malloc(sizeof(SLinkNode));
tc = L;
for (i = 0; i < n; i++)
{
s = (SLinkNode*)malloc(sizeof(SLinkNode));
s->data = a[i];
tc->next = s;
tc = s;
}
tc->next = NULL;
}

int main()
{
int i;
ElemType e;
SLinkNode* L;
InitList(L);
InsElem(L, 1, 1);
InsElem(L, 3, 2);
InsElem(L, 1, 3);
InsElem(L, 5, 4);
InsElem(L, 4, 5);
InsElem(L, 2, 6);
printf("线性表:"); DispList(L);
printf("长度:%d\n", GetLength(L));
i = 3; GetElem(L, i, e);
printf("第%d个元素:%d\n", i, e);
e = 1;
printf("元素%d是第%d个元素\n", e, Locate(L, e));
i = 4; printf("删除第%d个元素\n", i);
DelElem(L, i);
printf("线性表:"); DispList(L);
DestroyList(L);
return 0;
