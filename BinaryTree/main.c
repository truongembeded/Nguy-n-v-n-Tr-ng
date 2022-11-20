#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *left, *right;
}Tree;
Tree *CreateNode(int data)
{
Tree *temp = (Tree *)malloc(sizeof(Tree)); // Allocating memory to the node
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
void display(struct node *root) // A function for the inroder traversal of the binary tree
{
    
if (root != NULL)
{
    
display(root->left);
printf("%d \n", root->data);
display(root->right);

}
}
Tree* insert(Tree* node, int data) 
{
    static int flag = 1;

    if(flag){
        node = NULL;
        flag = 0;
    }
if (node == NULL) return CreateNode(data); 
if (data < node->data)
{
node->left = insert(node->left, data);
}
else if (data > node->data)
{
node->right = insert(node->right, data);
}
return node;
}
int main()
{

Tree *root ;
root = insert(root, 10);
insert(root, 20);
insert(root, 30);
insert(root, 40);
insert(root, 50);
insert(root, 60);
insert(root, 70);
insert(root, 80);
display(root);
return 0;
}
