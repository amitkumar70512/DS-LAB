
/*WAP to Implement Singly Linked List with following operations
a) a) Create a linked list. b) Deletion of  last element in
the list. c) sorting of linked list  d) reverse e) concatenation of linked list e)display .*/


#include<stdio.h>
#include<stdlib.h>

struct node1{
int data;
struct node1 *next
};


struct node1 *head1=NULL,*temp1;



struct node1 *head2=NULL ,*temp2;// for concatenation


void createList2(int x){
int i=0;
while(i<x){
       struct node1 *new=malloc (sizeof(struct node1));
    int item;
    printf("\n Enter the data :");
    scanf("%d",&item);
    new->data=item;
    new->next=NULL;
        if(head2==NULL)
        {
          head2=new;

        }

        else
        { temp2=head2;
            while(temp2->next!=NULL)
            {
                temp2=temp2->next;
            }
         temp2->next=new;
        }
i++;
}

}



    void create(){
    struct node1 *new=malloc (sizeof(struct node1));
    int item;
    printf("\n Enter the data :");
    scanf("%d",&item);
    new->data=item;
    new->next=NULL;
        if(head1==NULL)
        {
          head1=new;

        }

        else
        { temp1=head1;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
         temp1->next=new;
        }

    }






    void deletelast(){
        if(head1==NULL){
            printf("\nWarning!!!   LIST is Already Empty... \n");
            return;
        }
        else if(head1->next==NULL){
            temp1=head1;

            printf("\n '%d' is Deleted from the  LIST\n",temp1->data);
            free(head1);
            head1=NULL;
            return;
        }

        else
		temp1=head1;
		struct node1 *ptr;

    while(temp1->next!=NULL)
	{
        ptr=temp1;
        temp1=temp1->next;
    }
		ptr->next=NULL;
		printf("\n '%d' is Deleted from the  LIST\n",temp1->data);
		free(temp1);
    }

void display()
{
    if(head1==NULL&&head2==NULL){
        printf("Warning!!!   LIST is Already Empty... \n");
        return;
    }
    else
    temp1=head1;
    printf("\n \t head1-->");
    while(temp1!=NULL){
        printf(" %d > ",temp1->data);
        temp1=temp1->next;
    }
    printf("-->tail");
}

 void reverse()
    {
        // Initialize current, previous and
        // next pointers
       struct node1 *current = head1;
      struct node1 *prev = NULL;
      struct node1 *nxt = NULL;

        while (current != NULL) {
            // Store next
            nxt = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = nxt;
        }
        head1 = prev;
        printf("\n\t --> List has been reversed\n");
    }


     void sort() {
        //Node current will point to head
        struct node1 *current = head1, *index = NULL;
        int temp1;

        if(head1 == NULL) {
            return;
        }
        else {
            while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;

                while(index != NULL) {
                    //If current node's data is greater than index's node data, swap the data between them
                    if(current->data > index->data) {
                        temp1 = current->data;
                        current->data = index->data;
                        index->data = temp1;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
         printf("\n\t --> List has been Sorted\n");
    }


        void concat()
            {

                temp1=head1;
                if(temp1->next==NULL){
                    temp1->next=head2;
                    return;
                }
                else
                {
                   while(temp1->next!=NULL){
                    temp1=temp1->next;
                   }
                   temp1->next=head2;
                }

            }





int main(){
    int choice;
    int ch=1;
    printf("\n\t ------------SINGLY LINKED LIST-------------\n\n");
    do{
    printf("\n\n\t Enter your choice:>\n \n \t 1. Create a linked list. \n \t 2. Deletion last  element,\n \t 3. Sort in Ascending Order \n \t 4. Reverse the linked list \n \t 5. Concatenate the two linked list \n \t 6. Display the contents of the linked list. \n \t 7. Exit \n \n \t --:> ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            {
             create();
             break;
            }
        case 2:
            {
           deletelast();
             break;
            }
        case 3:
            {

             sort();
             break;
            }
        case 4:
            {
               reverse();
                break;
            }
        case 5:
            {
                printf("\n Enter the second list first for Concatenate:\n");
                printf("\n Number of nodes in second list:");
                int nodecount2=0;
                scanf("%d",&nodecount2);
                createList2(nodecount2);
                concat();
                break;

            }
        case 6:
            {
                display();
                break;
            }
        case 7:
            {
               exit(0);

            }
        default:
             printf("\n Warning! INVALID CHOICE...\n ");
        }

    }while(1);
return 0;}


