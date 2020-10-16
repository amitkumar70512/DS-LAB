#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];


int insertion ( int queue[max], int *rear , int *data)
{
      if ( *rear == max -1 )
            return(-1);
      else
      {
            *rear = *rear + 1;
            queue[*rear] = *data;
            return(1);
      }
}
int deletion( int queue[max], int *front, int *rear , int *data)
{
      if ( *front > *rear)
            return(-1);
      else
      {

            *data = queue[*front];
            (*front)++;
            return(1);
      }

}
void display(int queue[],int *front, int *rear)
{
   if(*rear==-1||*front>*rear)
        printf("\n-- Queue is already empty!!--");
   else{
    int i;
    printf("\n QUEUE::\t");
     (*front)++;
        for(i=*front;i<=*rear;i++)
        {


            printf("%d\t",queue[i]);
        }
   }
}


int main()
{
      int queue[max],data;
      int front,rear,reply,option;
      int count=0;

      front = rear = -1;
      printf("\t*****QUEUE*****");
      printf("\n<<---------------------------->>");
      printf("\n 1. Insert element in queue");
      printf("\n 2. Delete element from queue");
      printf("\n 3. Display queue elements");
      printf("\n 4. Exit");
      printf("\n\t----------------");
      while(1)
      {
            printf("\n\tChoose operation : ");
            scanf("%d",&option);
            switch(option)
            {
                          case 1 :
                                printf("\nEnter element to insert  : ");
                                scanf("%d",&data);
                                reply = insertion(queue,&rear,&data);
                                    if ( reply == - 1)
                                          printf("Queue is full,Queue overflow!!!");
                                    else {
                                          printf("%d is inserted in queue.\n",data);
                                    }
                            count++;
                                break;
                          case 2 :
                                reply = deletion(queue,&front,&rear,&data);
                                if ( reply == -1 )
                                      printf("WARNING:   Queue underflow!! queue is empty\n ");
                                else {
                                      printf("\nDeleted number is : %d\n", data);
                                }

                                count--;
                                      break;
                              case 3:
                                  {


                                      display(queue,&front,&rear);
                                        break;
                                    }
                        case 4 : exit(0);
            }
      }
}
