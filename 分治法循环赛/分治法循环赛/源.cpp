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
	printf("������һ����5000Ϊ������ǵĽ������:\n");
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
	printf("��������Ҫ�ҵĽ����ֵ��\n");
	scanf_s("%d", &a);
	n = find(m, a);
	if (n != NULL)
		printf("%d", n->k);
	else
		printf("������û�и�ֵ\n");
	system("pause");
	return 0;
}
