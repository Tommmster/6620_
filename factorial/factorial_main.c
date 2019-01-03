#include <stdio.h>

#define FACTPRINT(n)						\
	do{							\
		printf("%u! = %u\n",(n),factorial((n)));	\
	}while(0)


int main(int argc,char** argv)
{

	if (argc==1){
		FACTPRINT(1);
		FACTPRINT(2);
		FACTPRINT(3);
		FACTPRINT(4);
		FACTPRINT(5);
	}
	else{
		unsigned int n = atoi(argv[1]);
		FACTPRINT(n);
	}

	return 0;
}
