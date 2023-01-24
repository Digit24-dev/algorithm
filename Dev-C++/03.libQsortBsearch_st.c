#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _INFO {
	int age;
	char name[20];
	float height;
} INFO;

void printData(INFO *data, int nelem)
{
	int i;
	
	for(i=0; i<nelem; i++) {
		printf("%s, %d, %.1f\n", 
			data[i].name, data[i].age, data[i].height);
	}
}

#if 0
int fcmp_sort(const void *d1, const void *d2)
{
	return strcmp(((INFO*)d1)->name, ((INFO*)d2)->name);
}
#else
int fcmp_sort(const void *d1, const void *d2)
{
	INFO *t1=(INFO*)d1, *t2=(INFO*)d2;
	return strcmp(t1->name, t2->name);
	//return (t1->age) - (t2->age);
}
#endif

int fcmp_search(const void *d1, const void *d2)
{
	char *t1=(char*)d1;
	INFO *t2=(INFO*)d2;
	return strcmp(t1, t2->name);
}

#if 1
void dataSearch(INFO *data, int nelem)
{
	char sname[80];
	INFO *tdata;
	
	while(1) {
		printf("\nInput Search Name(quit:'end') => ");
		fgets(sname, sizeof(sname), stdin);
		sname[strlen(sname)-1] = '\0';
		if(!strcmp(sname, "end")) break;
		tdata = bsearch(sname, data, nelem, sizeof(INFO), fcmp_search);
		printf("\nSearch Result....\n");
		if(tdata == NULL) {
			printf("%s => no data!!\n", sname);
		} else {
			printf("%s, %d, %.1f\n", 
				tdata->name, tdata->age, tdata->height);
		}
	
	}
}
#endif

int main(void)
{
	INFO data[] = {
		{17, "park", 170.1F},
		{20, "lee", 168.2F},
		{18, "kim", 172.3F},
		{22, "yang", 180.1F},
		{19, "kang", 177.3F}};
	
	printf("Before Sort....\n");
	printData(data, sizeof(data)/sizeof(INFO));
	qsort(data, sizeof(data)/sizeof(INFO), sizeof(INFO), fcmp_sort);
	printf("---------------------------\n");
	printf("After Sort....\n");
	printData(data, sizeof(data)/sizeof(INFO));
	
	dataSearch(data, sizeof(data)/sizeof(INFO));
	
	return 0;
}
