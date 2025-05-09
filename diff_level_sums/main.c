#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"


int diff_levels_sum(ptr R , int level , int* sum_even , int* sum_odd  ){
    if(R==NULL)
         return 0;

    if(level % 2 == 0){//even level
        *sum_even += data(R);
        return data(R) + diff_levels_sum(LC(R),level+1,sum_even,sum_odd);
    }
    else{
        *sum_odd +=data(R);
        return -data(R) + diff_levels_sum(LC(R),level+1,sum_even,sum_odd);
    }
}

int diff_levels_sum_even_odd(ptr R,int level){
   if(R==NULL)
       return 0;

   int value = (level % 2 == 0 ? data(R) : -data(R));   //if the level is even we add else (odd) we subtract
   return value+diff_levels_sum_even_odd(LC(R),level+1)+diff_levels_sum_even_odd(RC(R),level+1);

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


    printf("the difference between sum values of odd and even levels is :   %d\n",diff_levels_sum_even_odd(root,0));
    return 0;
}
