#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>

int maximum(int a,int b){
   if(a>b)
      return a;
   else
      return b;
}

void diagonals_sum(ptr R,int diagonal,int T[100],int *size){
    if(R!=NULL){
        T[diagonal] += data(R);        ///we add the value of the node to the sun of the corresponding level
        *size = maximum(*size,diagonal+1);     ///so we know how many diagonals we have

        ///now a recursive call
        diagonals_sum(LC(R),diagonal+1,T,size);        //another diag
        diagonals_sum(RC(R),diagonal,T,size);          //the same diag
    }

}

void display_sums(int T[100],int size){
   int i;
   for(i=0;i<size;i++){
       printf("the sum of diagonal %d  :   %d\n",i+1,T[i]);
   }

}
int main()
{
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);
    displayTree(root,0,'-');

    int T[100];
    int size=0,i;
    for(i=0;i<100;i++)
        T[i]=0;

    diagonals_sum(root,0,T,&size);
    display_sums(T,size);
    return 0;
}
