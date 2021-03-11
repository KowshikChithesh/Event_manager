


typedef void(*fptr)(int);

struct module{
	int module;
	int evt_bitmap;
	fptr cb;
	struct module *next;
};


void module1();

void module2();

void module3();

void module4();

void module5();

fptr clbck(int a);

void init();

void free_mod();



