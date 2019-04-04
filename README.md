# hello-world
记录学习，记录成长
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	int num;
	struct Node * next;
} Node, *LinkList;

void InitList(LinkList * L)//初始化链表
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = *L;
}

void CreateFromTail(LinkList L, int n)//用尾插法建立新链表
{
	Node * s, *r;
	int flag = 1;
	int data;
	int j = 0;
	r = L;
	while (flag)
	{
		if (j < n)
		{
			printf("请输入第%d位密码\n", j + 1);
			scanf("%d", &data);
			s = (Node *)malloc(sizeof(Node));
			s->data = data;
			s->num = j + 1;
			r->next = s;
			r = s;
			j++;
		}
		else
		{
			flag = 0;
			r->next = L->next;
		}
	}
}

LinkList DelList(LinkList L, int * a)//删除链表l中第i个元素
{
	Node * pre, *r, *s;
	int j = 1;
	pre = L;
	if (*a == 1)
	{
		s = pre;
		while (s->next != pre)
		{
			s = s->next;
		}
		*a = pre->data;
		s->next = pre->next;
		return pre;
	}
	else
	{
		while (j < *a - 1)
		{
			pre = pre->next;
			j++;
		}
		r = pre->next;
		*a = r->data;
		pre->next = r->next;
		return r;
	}
}
int main(void)
{
	int n, m; //总人数n,初始报人数及后续密码存放m
	int i = 0, j = 0;
	LinkList l, q; //原链表头指针
	Node * r; //删除的的节点存放r,建立输出链表中间变量s
	printf("请输入总人数n\n");
	scanf("%d", &n);
	printf("请输入初始报数人数m\n");
	scanf("%d", &m);
	InitList(&l); //初始化原链表
	CreateFromTail(l, n); //尾插法建立链表
	q = l->next;
	for (i = 0; i < n; i++)
	{
		r = DelList(q, &m);
		printf("%2d", r->num);
		q = r->next;
	}
	system("pause");
	return 0;
}
