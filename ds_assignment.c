#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	long int contact;
	char s;
	char name[20];
	struct node*link;
}ob1,*start=NULL;

struct node*create()
{
	FILE *fp;   //Reading the file
	fp=fopen("input.txt","r");
	if(fp==NULL)
		printf("Error\n");
		
	while(fscanf(fp,"%s %ld %c",ob1.name,&ob1.contact,&ob1.s)!=EOF)
	{
		struct node*p,*last;
		p=(struct node*)malloc(sizeof(struct node));
		*p=ob1;
		p->link=NULL;
		if(start==NULL){
			start=p;
			last=p;
		}
		else
		{
			last->link=p;
			last=p;
		}
	}return start;
}
void display(struct node*start) 
{
	struct node*p;
	if(start==NULL)
		printf("Empty\n");
	else
	{
		p=start;
		printf("\n----------------- Proctee List -----------------\n");
		printf("Name\t\t Contact\t Residing Status\n");
		printf("------------------------------------------------\n");
		while(p!=NULL)
		{
			
			printf("%s\t\t %ld\t\t %c \n",p->name,p->contact,p->s);
			p=p->link;
		}
	}
}
void categorise(struct node*start) //To categorize between hostellites and day scholars
{
	struct node*p;
	if(start==NULL)
		printf("Empty\n");
	else
	{	p=start;
		while(p!=NULL)
		{
			if(p->s=='h'||p->s=='H')
			{
				printf("%s -  Hostelite\n",p->name);
				p=p->link;
			}
			else if(p->s=='d'||p->s=='D')
			{
				printf("%s -  Day Scholar\n",p->name);	
				p=p->link;
			}
		}
		if(p==NULL)
			return;
	}
}
void search(char name1[],struct node*start) //To print the contact of a particular student
{
	struct node*p;
	if(start==NULL)
		printf("Empty\n");
	else
	{	p=start;
		while(p!=NULL)
		{
			if(strcmp(p->name,name1)==0)
			{
			printf("%s  %ld\n ",p->name, p->contact);
			 break;
			 }
			p=p->link;
		}
		if(p==NULL)
			printf("No student with that name exists\n");	
	}
}
struct node* sort(struct node*start) //To sort in alphabetical order and display the list
{
	struct node*p,*q;
	char temp[20]="";
	

	if(start==NULL)
	return NULL;
	else
	{
		for(p = start; p->link!= NULL; p = p->link)
		{
			for(q=p->link; q!= NULL; q=q->link)
			{
				if(strcmp(p->name,q->name)>0)
				{
					strcpy(temp, p->name);
					strcpy(p->name, q->name);
					strcpy(q->name, temp);
				}
			}
		}
		p=start;    //Display
		while(p!=NULL)
		{
			printf("%s\n",p->name);
			p=p->link;
		}			
		return start;
	}
}			
																		
				
int main()
{
	char name1[20];
	start=create();
	display(start);
	int m;
	for(;;)
	{
		printf("\n Enter\n 1.To categorize between hostelites and day scholars\n 2.To print the contact of a particular student\n 3.To sort names in aphabetical order\n 4.To exit\n");
		scanf(" %d",&m);
		switch(m)
		{
			case 1: categorise(start);
				break;
			case 2: printf("Enter the student name \n\n");
				scanf("%s",name1);
				search(name1,start);
				break;
			case 3: printf("The sorted list is \n\n");
				start=sort(start);
				break;
			default:exit(0);
		}
	}	
	
	return 0;
}	
	
		
		
