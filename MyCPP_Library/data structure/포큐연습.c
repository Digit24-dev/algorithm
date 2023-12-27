#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

enum school_role{
	ROLE_TEACHER,
	ROLE_STUDENT
};

int has_access(school_role role){
	
	switch(role){
		case ROLE_TEACHER:
			return TRUE;
		case ROLE_STUDENT:
			return FALSE;
		default:
			return FALSE;
	}
	return FALSE;
}

int main(){
	
	printf("%d\n", has_access(0));
	
	return 0;
}
