#include<stdio.h>
#include<module.h>
#include<evt_mgr.h>
#include<stdlib.h>

extern int number;
struct module *head = NULL;

void module1(){
	printf("%s\n",__func__);}
void module2(){
        printf("%s\n",__func__);}
void module3(){
        printf("%s\n",__func__);}
void module4(){
        printf("%s\n",__func__);}
void module5(){
        printf("%s\n",__func__);}


fptr clbck(int a){
	switch(a){
                case 1:
                        return(&module1);
                case 2:
                        return(&module2);
                case 3:
                        return(&module3);
                case 4:
                        return(&module4);
                case 5:
                        return(&module5);
                default:
                        return(NULL);
        }
}

void init(){
	int mod , evt, map=0,i=1;
	for(mod = 1 ; mod < 6 ; mod ++){
	printf("Enter the events that the module %d is interested \n",mod);
	scanf("%d",&evt);
	while ((evt > 0)&&(i < number))
	{      map = map | (1 << (evt - 1));
	       scanf("%d",&evt);
	       i++;
	}
	       register_event (mod,map,clbck(mod));
	       i=1;
	       map = 0;
	}

	   }
	
void free_mod(){
	printf("Freeing nodes\n");
	struct module *temp = head;
	while(temp->next!=NULL){
		head = temp->next;
		free(temp);
		temp = head;
		}
		free (temp);
		}

