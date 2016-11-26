#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

typedef int elem_type;
#define MAX_SIZE 100
#define ERROR -1

typedef struct _SEQ_LIST
{
	elem_type data[MAX_SIZE];
	int len;

}SEQ_LIST;


bool init_seq_list(SEQ_LIST *p);

bool clear_seq_list(SEQ_LIST *p);

bool is_empty(SEQ_LIST *p);
bool is_full(SEQ_LIST*p);

int get_length(SEQ_LIST *p);

bool get(SEQ_LIST *p, int pos, elem_type *e);
bool put(SEQ_LIST *p, int pos, elem_type e);

int search(SEQ_LIST *p, elem_type e);

bool insert_tail(SEQ_LIST *p, elem_type e);
bool insert_head(SEQ_LIST *p, elem_type e);


bool del_tail(SEQ_LIST *p, elem_type *e);
bool del_head(SEQ_LIST *p, elem_type *e);


bool show(SEQ_LIST *p);

bool sort(SEQ_LIST *p);

////////////////////////////////////////////

bool insert(SEQ_LIST *p, int pos, elem_type e);
bool del(SEQ_LIST *p, int pos, elem_type *e);

#endif // !_SEQ_LIST_H_
