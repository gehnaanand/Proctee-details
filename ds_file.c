#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	long int contact;
	char s;
	char name[20];
	struct node*link;
}ob1;

void main()
{
	FILE*fp;
	fp=fopen("input.txt","w"); //Writing into a file
	int n,i;
	printf("Enter the no. of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter name, contact, status \n");
		scanf("%s %ld %c",ob1.name,&ob1.contact,&ob1.s);
		fprintf(fp,"%s %ld %c\n",ob1.name,ob1.contact,ob1.s);
	}
	printf("\n");
	
	fclose(fp); //Closing the file
}	
