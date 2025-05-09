#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int val;
   struct node *left,*right,*mid;

}node;

typedef struct node* ptr;

ptr new_node(int V){
   ptr N = (ptr) malloc(sizeof(node));
   N->left = NULL;
   N->right = NULL;
   N->mid = NULL;
   N->val = V;
   return N;

}


ptr convert_ternary_to_LLS(ptr root){  ///we convert a ternary tree to a linked list where right is used ad next
   if(root ==NULL)
       return NULL;


//    printf("here   %d\n",root->val);   getchar();

   ptr L = convert_ternary_to_LLS(root->left);
   ptr M = convert_ternary_to_LLS(root->mid);
   ptr R = convert_ternary_to_LLS(root->right);

  // printf("done  %d\n",root->val);

   ///now we link them
   root->right = L;

   //printf("left has been linked\t");

   ptr temp=root;

   while(temp->right != NULL)
       temp = temp->right;  //till we reach the end of (root U Left)

   temp->right = M;
   //printf("mid has been linked\t");
   while(temp->right != NULL)
       temp = temp->right;  //till we reach the end of (root U Left U Middle)

   temp->right = R;
   //printf("right has been linked\t");

   return root;    ///we return the head of the linked list

}

void display_DLLS(ptr head){

    while(head != NULL){
        printf("( %d )",head->val);
        if(head->right == NULL)  ///tail
            printf("--|=");
        else
            printf("==>");
         head = head->right;  //we move to the following element
    }

}

int main()
{
    ptr root = new_node(1);

    root->left = new_node(2);
    root->mid = new_node(9);
    root->right = new_node(12);

    root->left->left = new_node(3);
    root->left->mid = new_node(6);
    root->left->right = new_node(8);

    root->mid->left = new_node(10);
    root->mid->right = new_node(11);

    root->right->mid = new_node(13);
    root->right->right = new_node(16);

    root->left->left->mid = new_node(4);
    root->left->left->mid->right = new_node(5);
    root->left->mid->right = new_node(7);

    root->right->mid->left = new_node(14);
    root->right->mid->right = new_node(15);
    root->right->right->mid = new_node(17);

    ///we treat
    root = convert_ternary_to_LLS(root);
    ///we display
    printf("the new tree is :   \n");
    display_DLLS(root);


    return 0;
}
