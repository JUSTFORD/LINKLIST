#include"seq_list.h"
#include<stdio.h>
#include<stdlib.h>

bool init_seq_list(SEQ_LIST *p)
{
	if (p == NULL)
	{
		return false;
	}
	p->len =0;

	return true;
}

bool clear_seq_list(SEQ_LIST *p)
{

	if (p == NULL)
	{
		return false;
	}
	p->len = 0;

	return true;
}

bool is_empty(SEQ_LIST *p)
{
	if (p == NULL)
	{
		printf("空间不存在\n");
		return false;
	}

	return p->len==0;
}
bool is_full(SEQ_LIST*p)
{
	if (p == NULL)
	{
		printf("空间不存在\n");
		return false;
	}

	return p->len == MAX_SIZE;
}

int get_length(SEQ_LIST *p)
{
	if (p == NULL)
	{
		printf("空间不存在\n");
		return ERROR;
	}

	return p->len;

}

bool get(SEQ_LIST *p, int pos, elem_type *e)
{
	if (p == NULL)
	{
		printf("空间不存在\n");
		return false;
	}
	if (pos > p->len || p < 0)
	{
		printf("get error\n");
		return false;
	}

	*e = p->data[pos];

	return true;

}
bool put(SEQ_LIST *p, int pos, elem_type e)
{
	if (p == NULL)
	{
		printf("空间不存在\n");
		return false;
	}

	if (pos > p->len || p < 0)
	{
		printf("put error\n");
		return false;
	}

	p->data[pos] = e;
	return false;
}

int search(SEQ_LIST *p, elem_type e)
{
	if (p == NULL)
	{
		printf("search error\n");
		return ERROR;
	}
	for (int i = 0; i < p->len; i++)
	{
		if (p->data[i] == e)
		{
			return i;
		}
	}
	return -1;
}

bool insert_tail(SEQ_LIST *p, elem_type e)
{
	if (p == NULL || is_full(p))
	{
		printf("insert error\n");
		return false;
	}

	p->data[++(p->len)] = e;
	return true;
}
bool insert_head(SEQ_LIST *p, elem_type e)
{
	if (p == NULL || is_full(p))
	{
		printf("insert error\n");
		return false;
	}
	
	for (int i = p->len; i >0; i--)
	{
		p->data[i] = p->data[ i-1 ];
	}
	p->data[0] = e;
	p->len++;
	return true;
}


bool del_tail(SEQ_LIST *p, elem_type *e)
{
	if (p == NULL || is_empty(p))
	{
		printf("delete error\n");
		return false;
	}

	*e=p->data[p->len--];
	return true;
}
bool del_head(SEQ_LIST *p, elem_type *e)
{
	if (p == NULL || is_empty(p))
	{
		printf("delete error\n");
		return false;
	}

	for (int i = 0; i < p->len-1; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->len--;
	return true;
}


bool show(SEQ_LIST *p)
{
	if (p == NULL||is_empty(p))
	{
		printf("print error\n");
		return false;
	}

	for (int i=0; i < p->len; i++)
	{
		printf("%d ", p->data[i]);
	}
	printf("\n");
	return true;
}

bool sort(SEQ_LIST *p)
{
	if (p == NULL)
	{
		return false;
	}
	elem_type tmp;
	for (int i = 0; i < p->len; i++)
	{
		for (int j = i; j < p->len ; j++)
		{
			if (p->data[i] > p->data[j])
			{
				tmp = p->data[i];
				p->data[i] = p->data[j];
				p->data[j] = tmp;
			}
		}
	}

	return true;
}



bool insert(SEQ_LIST *p, int pos, elem_type e)
{
	if (p == NULL || is_full(p))
	{
		printf("insert error\n");
		return false;
	}

	for (int i = p->len; i >pos-1; i--)
	{
		p->data[i] = p->data[i - 1];
	}
	p->data[pos-1] = e;
	p->len++;
	return true;
}
bool del(SEQ_LIST *p, int pos, elem_type *e)
{
	if (p == NULL || is_empty(p))
	{
		printf("delete error\n");
		return false;
	}
	*e = p->data[pos-1];
	for (int i = pos-1; i < p->len - 1; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->len--;
	return true;
}

