/*WAP Implement doubly link list with primitive operations
a) a) Create a doubly linked list. b) Insert a new node to the left of the node.
b) c) Delete the node based on a specific value. c) Display the contents of the list*/

#include<stdio.h>
#include<stdlib.h>



 struct node
{
 int data;
 struct node *next;
 struct node *prev;

}*head;
struct node *temp;



int cre=0;

void create()
{
    head=NULL;
    cre++;
    printf("\n List created ...\n");
}


void insertleft(int y)
{
    struct node *new=malloc(sizeof(struct node));

    if(head==NULL)
    {
        head=new;
        new->next=NULL;

    }
    else
    {
        new->next=head;
        head=new;

    }
    new->prev=NULL;
    new->data=y;
}


void insertright(int x)
{
    struct node *new=malloc(sizeof(struct node));
    if(head==NULL)
    {
      head=new;
      new->prev=NULL;


    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
         temp->next=new;
         new->prev=temp;

    }
  new->data=x;
   new->next=NULL;
}



void display()
{
    temp=head;
    printf("\n\tDisplaying: \n     \t");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("null\n\n");
}



void delete(int sele)
{
    if(head->next==NULL)
    {
        if(head->data==sele)
        {
            free(head);
            printf("\n %d is removed.",sele);
            head=NULL;
        }
        else
        printf("\n %d doesnt matched  in the list.",sele);

    }
    else
    {
            struct node *ptr;
             temp=head;
             ptr=temp;


            while(temp!=NULL&&temp->data!=sele)
            {

                ptr=temp;
                temp=temp->next;

            }
            if(temp==NULL){printf("\n %d is not present in the list.",sele);}
                else
            {


                        if(temp->next==NULL)// sele at last pos
                        {ptr->next=NULL;}

                        else if(temp==head)// sele at first pos
                        {
                            ptr=temp->next;
                            ptr->prev=NULL;
                            head=ptr;
                        }
                        else
                            {
                                 ptr->next=temp->next;
                                 temp->next->prev=ptr;
                            }


                                    free(temp);
                                    printf("\n %d is removed.", sele);

            }


    }


}


int main()
{
   printf("\t Double ended Linked list\n") ;
   int choice;
   while(1)
   {
       printf("\n\t<----------------------->");
     printf("\n1. Create a list \n2. Insert at front \n3. Insert at end \n4.Delete specific element \n5. Display \n6. Exit \n :>>");
     scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        {
            if(cre>0){
                printf("\n Alert! \t list already created.\n");
                break;
            }
            else
                create();
            break;
        }
    case  2:
        {
                int data;
                printf("\n Enter the data :");
                scanf("%d",&data);
                insertleft(data);

            break;
        }
         case  3:
        {
                int data;
                printf("\n Enter the data :");
                scanf("%d",&data);
                insertright(data);

            break;
        }
        case  4:
        {
             if(head==NULL)
            {
                printf("\n Alert !!  NULL \n \t List is already empty \n\n");
            }
            else
            {
                int specific;
                printf("\n Enter the element to delete:>\n");
                scanf("%d",&specific);
                delete(specific);
            }
            break;
        }
        case  5:
        {   if(head==NULL)
            {
                printf("\n Alert !!  NULL \n \t List is already empty \n");
            }
            else{display();}

            break;
        }
        case  6:
         {
            exit(0);
            break;
        }

        default:
            printf("\n\t Alert!! Invalid choice....");

     }
   }


}

