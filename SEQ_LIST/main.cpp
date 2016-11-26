#include<stdio.h>
#include<stdlib.h>
#include"seq_list.h"


int main()
{
	SEQ_LIST s1;
	init_seq_list(&s1);
	elem_type e = 10;
	for (int i = 0; i < 10; i++)
	{
		insert_head(&s1, e*i);
	}
	show(&s1);

	sort(&s1);
	show(&s1);

	del(&s1, 2, &e);
	show(&s1);

	insert(&s1, 3, 25);
	show(&s1);


	return 0;
}