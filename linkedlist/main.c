#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int value;
	struct element *prev, *next;
} element;

typedef struct linked_list{
	element *start;
}  ll;

ll* create_ll(){
	element *head = (element*)malloc(sizeof(element));
	head->value=0;
	head->prev=NULL;
	head->next=NULL;
	
	ll *linked_list = (ll*)malloc(sizeof(ll));
	linked_list->start=head;
	return linked_list;
}


void print_ll(ll *linked_list){
	puts("");
	if (linked_list->start->next!=NULL && linked_list->start->prev==NULL){ printf("There is no elements"); return; }
	while (linked_list->start->next!=NULL){
		printf("%d, ", linked_list->start->value);
		linked_list->start=linked_list->start->next;
	}
	if (linked_list->start->prev!=NULL)
		printf("%d, ", linked_list->start->value);
}

void add_node_after_inx(ll* linked_list, int value, int index){
	if (index<=0) printf("Error: index must be greater than 0");
	while(linked_list->start->next!=NULL && index>0){
		linked_list->start=linked_list->start->next;
	}
		element* node = (element*)malloc(sizeof(element));
		node->prev=linked_list->start;
		node->prev->next=node;
		node->value=value;
}



int main(){
	ll* linked_list = create_ll();
	add_node_after_inx(linked_list, 4, 1);
	print_ll(linked_list);
}

