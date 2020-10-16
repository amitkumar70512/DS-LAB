#include<stdio.h>
# define size 10
void push(int [],int value);
int pop ( int []);
void display (int []);
int top =-1;
int main (int argc, char **argv)
{
int stack[size];
int choice,element;
char ch;
 do {

 printf("enter your choice /n ");
 printf("1. push \n");
 printf("2. pop \n");
 printf("3. display\n");
  scanf("%d",&choice);

	  switch(choice)
	  {
	  case 1:
		  {
		  printf("enter the element to be pushed");
		  scanf("%d",&element);
		  push(stack,element);
		  break;
		  }

	  case 2:
			{
			printf("enter the element to be poped");
			scanf("%d",&element);
			int popedele=pop(stack);
			printf(" the poped element is :%d",popedele);
			break;
			}

	  case 3:
	        {
			display(stack);
			break;
			}
		}
		printf("do  you want to  continue ");
		 fflush(stdin);
		 scanf("%c",&ch);
		 }
		while(ch=='y'||ch=='Y');
		return 0;
	}

	 void push(int stack[],int ele)
	 {
            if ( top==size-1)
            {
                printf("\n stack overflow\n");
            }
            else
                top++;
              stack[top]=ele;


	 }
         int pop(int stack[])
         {  int popele;
                 if(top==-1)
                 {
                     printf("\n stack underflow\n");

                 }
                 else
                 {
                     int popele=stack[top];
                     top--;
                     return popele;
                 }


         }

     void display (int stack[])
     {

         int i;
         printf("the stack elements are \n")
         for(i=top;i>=0;i--)
         {
             printf("%d\t",stack[i]);
         }
     }
