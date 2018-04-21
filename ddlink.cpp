#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	node *p;
	node *n;
};

struct dd_link
{
	node *head;
	node *tail;
};
void add(dd_link *link,node *n,bool first = false)
{

	if (link->head==NULL)
	{
		link->head = link->tail = n;
	}
	else
	{
		if (first)
		{
			node* tmp = link->head;
			link->head = n;
			n->n = tmp;
			tmp->p = n;

		}else {
			node* tmp = link->tail;
			link->tail->n = n;
			n->p = tmp;
			link->tail = n;
		}
	}
}
void loop_print(dd_link *link)
{
	node *r = link->head;
	while (r!=NULL)
	{
		printf("node=>%d\n", r->data);
		r = r->n;
	}
}
void swap(node *&x, node *&y)
{

	node *temp = x;
	x = y;
	y = temp;
}
void rever(dd_link *link)
{
	node* n, *old_head;n = old_head = link->head;
	while (n != NULL)
	{
		node *tmp_n = n;
		n = n->n;
		swap(tmp_n->p,tmp_n->n);
	}
	link->head = link->tail;
	link->tail = old_head;
}


void main( void )
{
	 dd_link link = {};
	 link.head = NULL;
	 link.tail = NULL;

	 node node1 = {};
	 node1.data = 1;

	 node node2 = {};
	 node2.data = 2;

	 node node3 = {};
	 node3.data = 3;

	 add(&link, &node2);
	 add(&link, &node1,true);
	 add(&link, &node3);

	 loop_print(&link);
	 rever(&link);
	 printf("after rever\n");
	 loop_print(&link);
	 system("pause");
   return;
 }
