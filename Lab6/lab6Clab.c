#include<stdio.h>
#include<stdlib.h>



struct student // for storing details of student of different types using structure
{
  int sem;
  char name[40];
  char  USN[20];
};


struct node
{
  struct student s;
  struct node *next;
};

// declaring head as global
 struct node *head;
 struct node *new,*temp;




 // inserting node at the end case 1
 void insertEnd(){

new = (struct node*)malloc (sizeof(struct node));
        if(head==NULL){

            head=new;
    printf("\n \t DETAILS OF STUDENT \n");
   printf("\nEnter the current semester >>\t");
   scanf("%d",&new->s.sem);
    printf("\nEnter the Name >>\t");
    scanf("%s",new->s.name);
    printf("\nEnter USN >>\t");
   scanf("%s",&new->s.USN);
            new->next=NULL;
        }
        else
        {
            temp=head;

            while(temp->next!=NULL){
                temp=temp->next;
            }

               printf("\n \t DETAILS OF STUDENT \n");
               printf("\nEnter the current semester >>\t");
               scanf("%d",&new->s.sem);
               printf("\nEnter the Name >>\t");
               scanf("%s",new->s.name);
               printf("\nEnter USN >>\t");
               scanf("%s",&new->s.USN);
               temp->next=new;
               new->next=NULL;

        }
}







      void deletefirst(){
        if(head==NULL)
		{
				printf("\n Warning!!!   LIST is Already Empty... \n");
				return;
		}
        else

				temp=head;
				printf("\n \t DETAILS OF STUDENT \n");
                 printf("\tSemester : %d\n" ,temp->s.sem);
                printf("\tName: %s\n" ,temp->s.name);
                printf("\tUSN : %s\n" ,temp->s.USN);
				head=temp->next;
				free(temp);
	}



    void deletepos(int n){

        if(head==NULL)
		{
            printf("\n Warning!!!   LIST Is Already Empty... \n");
            return;
        }
        else
        {
            int pos=0;
             printf("\n Enter the position of Node to DElete");
             scanf("%d",&pos);
                 if(pos>n){
                    printf("\n Alert!! node not found , out of bound position entered\n Enter position from 1 to %d\t\n",n);
                    return;
                 }
                 else

          if(pos==1){
            deletefirst();
          }
              else{
					struct node *prev=head;
                    temp=head;
                    int i=1;
                        while( i<pos){
                              prev=temp;
                              temp=temp->next;
                              i++;
                            }
                        if(temp->next==NULL)
						{
                            deletelast();
                        }
                        else
						{
                           printf("\n \t DETAILS OF STUDENT \n");
                            printf("\tSemester : %d\n" ,temp->s.sem);
                            printf("\tName: %s\n" ,temp->s.name);
                            printf("\tUSN : %s\n" ,temp->s.USN);
                            prev->next=temp->next;
                            free(temp);
                        }
                   }

        }

    }

    void deletelast(int count){
        if(head==NULL){
            printf("\nWarning!!!   LIST is Already Empty... \n");
            return;
        }
        else
            temp=head;
            struct node *ptr;
            if(count==1){
              free(temp);
              head=NULL;
              return;
            }
            else



    while(temp->next!=NULL)
	{
        ptr=temp;
        temp=temp->next;
    }
		ptr->next=NULL;
		printf("\n \t DETAILS OF STUDENT \n");
        printf("\tSemester : %d\n" ,temp->s.sem);
        printf("\tName: %s\n" ,temp->s.name);
        printf("\tUSN : %s\n" ,temp->s.USN);
        free(temp);
    }

// to display the list
void display()
{
    if(head==NULL){
        printf("\n alert!! LIST is already Empty ");
    }
    else
    printf("\n \n \t <--------------------------->\n\n");
    struct node *temp;
    temp=head;
    int j=1;
    while(temp)// loop until temp not NULL
    {

        printf("\n\n \t Details of Student %d \n\n",j);
        printf("\tSemester : %d\n" ,temp->s.sem);
        printf("\tName: %s\n" ,temp->s.name);
        printf("\tUSN : %s\n" ,temp->s.USN);
        temp=temp->next;
        j++;
    }
}








    int main(){

    printf("\t <<<<<SINGLY LINKED LIST>>>>>\n");
    int choice;
    int nodecount=0;
    int x;
    do{
         printf("\n\t Enter your choice :> \n  \n 1. Insertion of node  \n 2. Deletion of first node \n 3. Deletion of Specific Node \n 4. Deletion of last node \n 5. Display the contents of the linked list. \n 6. Exit\n\t>>");
         scanf("%d",&choice);

    switch(choice)
    {




        case 1:
                    {
                    insertEnd();
                    nodecount++;
                    break;

                    }
        case 2:
            {
                deletefirst();
                break;

            }
        case 3:
            {
               deletepos(nodecount);
               break;

            }
        case 4:
            {
              deletelast(nodecount);
              break;

            }
        case 5:
            {

               display();
                break;
            }
        case 6:
            {
                printf("\n\n\t <---- EXITED----->\n\n");
              exit(0);
              break;

            }
        default:
            printf("invalid choice");

    }
    printf("\n \t<<<TO repeat, enter '0'+>>\t");
    scanf("%d",&x);

    }while(x==0);


    return 0;

}


