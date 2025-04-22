// q1. write a function to insert a node into binary search tree and traverse the binary search tree in- 1)inorder 2)preorder 3)postorder
// q2. write a program to find height of binary tree.
// q3. write a program to find depth of given node.
// q4. write a program to count number of leaf nodes and internal nodes in binary search tree.

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createnode(int value){
    struct node *nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=value;
    nnode->left=NULL;
    nnode->right=NULL;
    return nnode;
}

struct node *insert(struct node *root,int value){
    if(root==NULL){
        return createnode(value);
    }

    if(value<=root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }

    return root;
}

int height(struct node *root){
    if (root==NULL){
        return -1;
    }

    int leftheight=height(root->left);
    int rightheight=height(root->right);

    return (leftheight > rightheight ? leftheight : rightheight);
}

int main(){
    struct node *root=NULL;
    int opt=1,choice;
    while(opt){
        printf("Press 1 for inserting node, 2 for finding height of binary tree: ");
        scanf("%d",&choice);
        switch(choice){
            int data,findheight;
            case 1:
            if(root==NULL){
                printf("Enter data: ");
                scanf("%d",&data);
                root=insert(root,data);
            }
            else{
                printf("Enter data: ");
                scanf("%d",&data);
                insert(root,data);
            }
            break;
            case 2:
            findheight=height(root);
            printf("The height of thr tree is %d.\n",findheight);
            break;
            default:
            printf("Incorrect choice entered!\n");
            break;
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&opt);
    }
    return 0;
}