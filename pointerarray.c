#include<stdio.h>
#include<conio.h>

void main(){
	int ar[4] = {5,10,15,20};
	int *ptr;
	int i;
	
	for(i=0;i<4;i++)
		printf("%d\n",ar[i]);
		
		
		ptr = ar;
		for(i=0;i<4;i++)
			printf("%d\n", ptr[i]);
	
	getch();
}
