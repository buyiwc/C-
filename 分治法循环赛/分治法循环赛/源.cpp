#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int k;
	struct node *lchild, *rchild;
}bs;

typedef bs *bstree;
bstree find(bs *s, int x)
{
	int m;
	if (s == NULL || x == s->k)
		return s;
	if (x < s->k)
		return find(s->lchild, x);
	else
		return find(s->rchild, x);
}
void insert(bstree *s, int x)
{
	bstree f = NULL, p;
	p = *s;
	while (p)
	{
		if (x == p->k) return;
		f = p;
		p = (x < p->k) ? p->lchild : p->rchild;
	}
	p = (bs*)malloc(sizeof(bs));
	p->k = x;
	p->lchild = p->rchild = NULL;
	if (*s == NULL)  *s = p;
	else
		if (x < f->k)
			f->lchild = p;
		else  f->rchild = p;
}
bstree Ctree()
{
	bstree t = NULL;
	int k;
	printf("请输入一个以5000为结束标记的结点序列:\n");
	scanf_s("%d", &k);
	while (k != 5000)
	{
		insert(&t, k);
		scanf_s("%d", &k);
	}
	return t;
}
int main()
{

	bstree n, m;
	int a;
	m = Ctree();
	printf("请输入需要找的结点数值：\n");
	scanf_s("%d", &a);
	n = find(m, a);
	if (n != NULL)
		printf("%d", n->k);
	else
		printf("二叉树没有该值\n");
	system("pause");
	return 0;
}
