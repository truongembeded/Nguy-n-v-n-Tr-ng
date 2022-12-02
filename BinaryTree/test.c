#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *left_child, *right_child;
};
struct node *new_node(int value)
{
struct node *tmp = (struct node *)malloc(sizeof(struct node));
tmp->value = value;
tmp->left_child = tmp->right_child = NULL;
return tmp;
}
void print(struct node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{
printf("%d \n", root_node->value);
print(root_node->left_child);

print(root_node->right_child);

}
}
struct node* insert_node(struct node* node, int value) // inserting nodes!
{
if (node == NULL) return new_node(value);
if (value < node->value)
{
node->left_child = insert_node(node->left_child, value);
}
else if (value > node->value)
{
node->right_child = insert_node(node->right_child, value);
}
return node;
}

struct node *search(struct node ** binary_tree, int value) {
if(!(*binary_tree)) {
return NULL;
}
if(value == (*binary_tree)->value) {
return *binary_tree;
} else if(value < (*binary_tree)->value) {
search(&((*binary_tree)->left_child), value);
} else if(value > (*binary_tree)->value){
search(&((*binary_tree)->right_child), value);
}
}

void delete_tree(struct node * binary_tree) {
if (binary_tree) {
delete_tree(binary_tree->left_child);
delete_tree(binary_tree->right_child);
free(binary_tree);
}
}
int main()
{
printf("TechVidvan Tutorial: Implementation of a Binary Tree in C!\n\n");
struct node *root_node = NULL;
root_node = insert_node(root_node, 10);
insert_node(root_node, 10);
insert_node(root_node, 30);
insert_node(root_node, 25);
insert_node(root_node, 36);
insert_node(root_node, 56);
insert_node(root_node, 78);
print(root_node);


return 0;
}