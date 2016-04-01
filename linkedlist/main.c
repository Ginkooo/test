#include <stdio.h>
#include <stdlib.h>


typedef struct element{
	int value;
	struct element *prev, *next;
} element;

typedef struct linked_list{
	element *start;
	int count;
}  ll;

ll* create_ll(){
	element *head = (element*)malloc(sizeof(element));
	head->value=0;
	head->prev=NULL;
	head->next=NULL;
	
	ll *linked_list = (ll*)malloc(sizeof(ll));
	linked_list->start=head;
	linked_list->count=0;
	return linked_list;
}


void print_ll(ll *linked_list){
	puts("");
	int index=0;
	element* temp=linked_list->start;
	if (temp->next!=NULL){
			temp=linked_list->start->next;
	}
	if (temp->next==NULL && temp->prev==NULL){
		
		printf("There is no elements"); return;
		}
	while (temp->next!=NULL){
		printf("ll[%d]=%d\n", index, temp->value);
		index++;
		temp=temp->next;
	}
	if (temp->prev!=NULL)
		printf("ll[%d]=%d\n", index, temp->value);
}

void print_ll_bck(ll *linked_list){
	int index=0;
	element *temp = linked_list->start;
	if (temp->next!=NULL)
			temp=linked_list->start->next;
	if (temp->next==NULL && temp->prev==NULL){
		
		printf("There is no elements"); return;
		}
	while(temp->next!=NULL){
		temp=temp->next;
		index++;
	}
	while (temp->prev!=NULL){
		printf("ll[%d]=%d\n", index, temp->value);
		index--;
		temp=temp->prev;
	}
}

void add_node_after_inx(ll* linked_list, int value, int index){
	index++;
	element* temp=linked_list->start;
	if (index<=0) { printf("Error: index must be greater than 0"); fflush(stdout); return; }
	while(temp->next!=NULL && index>0){
		temp=temp->next;
		index--;
	}
		element* node = (element*)malloc(sizeof(element));
		node->next=temp->next;
		node->prev=temp;
		temp->next=node;
		node->value=value;
		if (node->next!=NULL)
			node->next->prev=node;
		linked_list->count++;
}



int main(){
	ll* linked_list = create_ll();
	int choose, val, idx;
	while(1==1){
		printf("What do you want to do? 1-add an element, 2-print elements 3-print backwards: ");
		scanf("%d", &choose);
		switch(choose){
			case 1:
				printf("Input value of element and index you want to put it after: ");
				scanf("%d %d", &val, &idx);
				add_node_after_inx(linked_list, val, idx);
				break;
			case 2: print_ll(linked_list); printf("\n"); break;
			case 3: print_ll_bck(linked_list); printf("\n"); break;
			default: printf("Wrong choice\n");
		}
		printf("\n\n\n\n");
	}
}

