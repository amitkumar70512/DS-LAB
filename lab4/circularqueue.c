#include <stdio.h>
#include <stdlib.h>


int front=-1;
int rear=-1;




void insert(int,int,int[]);
int delete(int,int[]);
void display(int,int[]);



int main()
{
     printf("-------Circular Queue---------\n");
        int size;
     printf("\n Size of Queue::");
     scanf("%d",&size);
        int queue[size];

	int option;
    int item;
    do{


        printf("\n 1. Insert to Queue. ");
        printf("\n 2. delete from the Queue. ");
        printf("\n 3. Display the Queue elements. ");
        printf("\n 4. Exit\n");
        printf("  choice ::>");
        scanf("%d",&option);
        switch(option)
        {
            case 1:  if(((front == 0 && rear == size - 1))|| (front == rear + 1) )
                    {
                        printf("\nAlert: OVERFLOW!! Queue is full,element cant be inserted\n\n");
                    }
                    else
                    {


                     printf("Enter the element=>\t");
                     scanf("%d",&item);
                    insert(item,size,queue);
                    }
                     break;
            case 2: item=delete(size,queue);
                    if(item==-0)
                        printf("Alert: UNDERFLOW!! Queue is already empty\n\n");
                    else
                    printf("the deleted element is= %d\n ",item);
                    break;
            case 3: display(size,queue);
                    break;
            case 4: exit(0);
                     break;
            default: printf("");
        }
    } while (option!=4);
	return 0;
}

void insert (int ele,int size,int  queue[size])
{

    if(((front == 0 && rear == size - 1))|| (front == rear + 1) )
    {
       printf("\nAlert: OVERFLOW!! Queue is full,element=%d  cant be inserted\n\n",ele);return;

    }
    else
    {
      rear=(rear+1)%size;
      queue[rear]=ele;
      if(front ==-1)
          front=0;



    }
}
int delete(int size,int queue[size])
{
    int item;

    if((front == -1)&&(rear == -1))
    {

        return(-0);
    }
    else
    {
        item=queue[front];

  if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }

        return item;
    }

}

void display(int size,int queue[size])
{
    int i;

    if(((front==-1)&& (rear==-1)))
    {

        printf("Alert: UNDERFLOW !! Queue is already empty\n");
        return;

    }
    else
    {
        printf("\n Queue elements are :: ");




        if(rear<front){

           for(i=0;i<=rear;i++)
           {

                printf("%d\t", queue[i]);
           }
           for(i=front;i<size;i++)
           {
               printf("%d\t", queue[i]);

           }
        }

           else{ for(i=front;i<=rear;i++)
                printf("%d\t", queue[i]);}


        }



    printf("\n---------------------\n");
}

