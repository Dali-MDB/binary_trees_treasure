#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define m 5
typedef struct node{
   int val;
   struct node* children[m];

}node;

typedef struct node* ptr;

ptr new_node(int V){
   ptr N = (ptr) malloc(sizeof(node));
   int i;
   for(i=0;i<m;i++)
      (N->children)[i] = NULL;
   N->val = V;
   return N;

}

int data(ptr R){
   return R->val;
}

ptr child(ptr R,int index){
   if(R!=NULL)
      return (R->children)[index];  //since we start from 0
   else
      return NULL;
}

void ass_child(ptr* R, ptr Q,int index) {
    if (R != NULL && *R != NULL && index <= m) {
        ((*R)->children)[index] = Q;
    }
}

void ass_data(ptr* R , int V){
    (*R)->val = V;
}
int main()
{

    return 0;
}
