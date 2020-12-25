
/* /write a program
a) to constrct a binary search tree.
b) to traverse the tree using all the methods i.e.,
in-order,preorder and postorder.
c) to display the elements in a tree.
*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
}*root=NULL;


struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void  inorder(struct node *root)
{
    if(root!=NULL)
    {
       inorder(root->left);
       printf("%d\t",root->key);
       inorder(root->right);
    }
}
void  preorder(struct node *root)
{
    if(root!=NULL)
    {  printf("%d\t",root->key);
       preorder(root->left);
       preorder(root->right);
    }
}
void  postorder(struct node *root)
{
    if(root!=NULL)
    {
      postorder(root->left);
      postorder(root->right);
      printf("%d\t",root->key);

    }
}

void main()
{
int ch;
printf("\n \t <<  Binary Search Tree >> \n\n ");
    while(1)
    {
        printf("\t<------------------------------------->\t");
        printf("\n\nEnter option:> \n\t 1. construct a tree \n\n *. Display  : \n\t 2. inorder traversal \n\t 3. preorder traversal \n\t 4. postorder traversal  \n\n\t 5. exit\n\n :-->  ");
        scanf("%d",&ch);
                switch(ch)
                {
                case 1:
                    {
                        int no=0,i;
                        int data[40];
                        printf("\n No of nodes to insert:\t");
                        scanf("%d",&no);
                        printf("\n Enter data for Tree: \n");
                        for(i=0;i<no;i++)
                        {
                            scanf("%d",&data[i]);
                        }
                        root=insert(root,data[0]);
                        for(i=1;i<no;i++)
                        {
                            insert(root,data[i]);
                        }

                        break;

                    }
                case 2:
                    {
                        if(root==NULL)
                        {
                            printf("Warning!! Tree not found..\n cannot Traverse Tree !! \n\n");
                        }
                        else{    printf("\n displaying in inorder traversal\n");

                            inorder(root);
                        }

                        break;
                    }
                case 3:
                    {
                        if(root==NULL)
                        {
                            printf("Warning!! Tree not found..\n cannot Traverse Tree !! \n\n");
                        }
                        else{    printf("\n displaying in Preorder traversal\n");

                            preorder(root);
                        }

                        break;
                    }
                case 4:
                    {
                        if(root==NULL)
                        {
                            printf("Warning!! Tree not found..\n cannot Traverse Tree !! \n\n");
                        }
                        else{    printf("\n displaying in Postorder traversal\n");

                            postorder(root);
                        }

                        break;

                    }
                case 5:
                    {
                        printf("\n\t\t<---- Exited ..  ---->\n\n\n");
                        exit(0);
                        break;

                    }
                default:
                    printf("\n Alert ! invalid option !!\n");
               }

    }

}
