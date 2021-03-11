#include<stdio.h>
#include<module.h>
#include<evt_mgr.h>
#include<stdlib.h>

extern int number;
extern struct module *head;
int register_event(int id , int bitmap , fptr clbck){
	struct module *temp = (struct module*)malloc(sizeof(struct module));
	struct module *ptr = head;
 	if (ptr == NULL){
		temp->module = id;
		temp->evt_bitmap = bitmap;
		temp->cb = clbck;
		temp->next = NULL;
		head = temp;
		return -1;
	}
	while(ptr->next!= NULL){
		ptr = ptr->next;}
	ptr -> next = temp ;
	temp->module = id;
	temp->evt_bitmap = bitmap;
	temp -> cb = clbck;
	temp -> next = NULL;

}

int right_shift(int evt , struct module* verify)
	{return((verify -> evt_bitmap >> (evt -1)) &1);}

int evt_exec(){
	int evt,loop = 1;
	while(loop){
	printf("Enter the events that need to be executed");
	scanf("%d", &evt);
	if ((evt > 0) && (evt <= number)){
			struct module *ptr = head;
			while(ptr!=NULL){
			if(right_shift(evt , ptr))
				ptr->cb(evt);

			ptr = ptr->next;
			}
	}
	else
		loop = 0;
}
}

		       	


		
	
