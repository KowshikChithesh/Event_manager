#include<stdio.h>
#include<module.h>
#include<evt_mgr.h>

int number;

int main(){

	int event;
	printf("Enter the number of events \n");
	scanf("%d" ,&number);
	init();
	evt_exec();
	free_mod();
	return 0;
}

