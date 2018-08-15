/*Linked list
operations 
1.insert at first
2.insert at last
3.insert in between
4.displaying list
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertinBet(PPNODE first,int ino,int pos);
void InsertatLast(PPNODE first,int ino);
void InsertatStart(PPNODE first,int ino);
void Display(PPNODE first);

int main( void)
{
	PNODE head=NULL;
	int choice,n,pos;
	while(1)
	{
	 fflush(stdin);//clearing i/o buffer sometime user enters charcter in interger values	
	 printf("1.Insert at First\n2.Insert at Last\n3.Insert in Between\n4.Display\n5.Exit\n\n");
	 printf("Enter Choice :\t");
	 scanf("%d",&choice);
	 
	 switch(choice)
	 {
	 	fflush(stdin);//clearing i/o buffer sometime user enters charcter in interger values
	 	case 1:
	 		  printf("Enter number\t");
	 		  scanf("%d",&n);
		      InsertatStart(&head,n);
		      break;
		case 2:
	 		  printf("Enter number\t");
	 		  scanf("%d",&n);
		      InsertatLast(&head,n);
		      break;
		case 3:
			  printf("Enter number\t");
	 		  scanf("%d",&n);
	 		  printf("At which postion\t");
	 		  scanf("%d",&pos);
		      InsertinBet(&head,n,pos);
		      break;
	 		
		case 4:
	 		  Display(&head);
	 		  printf("\n");
		      break;
		case 5:return;
	   default :
	             printf("\nWRONG CHOICE...TRY AGIN\n");  
				  
	 }
	 printf("\n");
   }
   return;
}


void InsertinBet(PPNODE first,int ino,int pos)
{
	int i;
	PNODE temp=*first;
	PNODE temp2=NULL;
	PNODE newn=NULL;
	if(pos==1)
	{
	 InsertatStart(first,ino);  
	 return;
	}
	if(temp==NULL)
	{
	
     InsertatLast(first,ino);
	 return;
    }
	else
	{
	 for(i=1;i<pos-1;i++)
	  { 
      		temp=temp->next;
      } 	
	}

		
	 newn=(PNODE)malloc(sizeof(NODE));
	 temp2=temp->next;
	 newn->data=ino;
	 temp->next=newn;
	 newn->next=temp2;
    
}
void InsertatLast(PPNODE first,int ino)
{
	PNODE newn=NULL;
	
	PNODE temp=*first;
	
	
	
	newn=(PNODE)malloc(sizeof(NODE));
	if(newn==NULL)
	{
		printf("error occure while creating node\n");
        return;
	}
	newn->data=ino;
	newn->next=NULL;
	if(*first==NULL)
	{
		*first=newn;
	}
	else
	{
	  while(temp->next!=NULL)
	  {
	  	temp=temp->next;
	  }	
	  temp->next=newn;
	}
}
void InsertatStart(PPNODE first,int ino)
{

	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	if(newn==NULL)
	{
		printf("error occure while creating node\n");
	}
	newn->data=ino;
	newn->next=NULL;
	if(*first==NULL)
	{
		*first=newn;
	}
	else
	{
		newn->next=*first;
		*first=newn;
	}
}
void Display(PPNODE first)
{
	PNODE temp=*first;
	while(temp!=NULL)
	{
	
		printf("-->%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
