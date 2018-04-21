# 一个简单双向链表-内容倒置
------

### 双向链表比基础的链表结构多了一个前置指针。
```c
struct node {
	int data;
	node *p;
	node *n;
};
```
### 链表对象
```c
struct dd_link
{
	node *head;
	node *tail;
};
```
### 添加元素
```c
void add(dd_link *link,node *n,bool first = false)
{
	//需要复制 node内容需要malloc 这里不做内容复制只做逻辑处理
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
```
### 内容倒置 逻辑很简单就是把 前置和后继 指针做一下交换
```c
//交换
void swap(node *&x, node *&y)
{

	node *temp = x;
	x = y;
	y = temp;
}
//倒置
void rever(dd_link *link)
{
	node* n, *old_head;n = old_root = link->head;
	while (n != NULL)
	{
		node *tmp_n = n;
		n = n->n;
		swap(tmp_n->p,tmp_n->n);
	}
	link->head = link->tail;
	link->tail = old_head;
}

```
### 测试
```c
 void main( void )   
{   
	 dd_link link = {};
	 link.root = NULL;
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
}
```
