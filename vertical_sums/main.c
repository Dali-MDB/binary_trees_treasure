#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

void vertical_sums(ptr R,int level, int T_pos[100] , int* size_pos , int T_neg[100] , int* size_neg){
   if(R!=NULL){
      if(level >= 0){
         T_pos[level] += data(R);
         *size_pos = level + 1 > *size_pos ? level+1 : *size_pos;     //update pos size if needed
      }
      else{
         T_neg[level] += data(R);
         *size_neg = -level + 1 > *size_neg ? -level+1 : *size_neg;    //level is neg but size_neg is pos
      }

      ///now the call for children
      vertical_sums(LC(R),level-1,T_pos,size_pos,T_neg,size_neg);
      vertical_sums(RC(R),level+1,T_pos,size_pos,T_neg,size_neg);
   }


}

void display_result(int T_pos[100] , int size_pos , int T_neg[100] , int size_neg ){
    int i;
    printf(".");
    for(i=0;i<size_neg+size_neg-1;i++)
        printf("______");
    printf(".\n");

    printf("|");
    for(i=size_neg-1;i>0;i--)
        printf("  %2d  |",-i);

    for(i=0;i<size_pos;i++)
        printf("  %2d  |",i);

    printf("\n");


    printf("|");
    for(i=0;i<size_neg+size_neg-2;i++)
        printf("______|");
    printf("\n");

    printf("|");
    for(i=size_neg-1;i>0;i--)
        printf("  %2d  |",T_neg[i]);

    for(i=0;i<size_pos;i++)
        printf("  %2d  |",T_pos[i]);

    printf("\n");


    printf("|");
    for(i=0;i<size_neg+size_neg-2;i++)
        printf("______|");
    printf(".\n");


}


int main()
{
    int T_pos[100] , T_neg[100] , size_pos = 6, size_neg = 5;   //used for vertical lines whose index is negative
    int i;
    for (int i = 0; i < 100; ++i) {
        T_pos[i] = 0;    T_neg[i] = 0;

    }
    display_result(T_pos,size_pos,T_neg,size_neg);


    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(8);

 //   displayTree(root,10,'-');
   // vertical_sums(root,0,T_pos,&size_pos,T_neg,&size_neg);

    return 0;
}
