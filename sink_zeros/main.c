#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "../trees_lib.h"

ptr search_no_0_tree(ptr R){
   if(R==NULL || data(R) != 0)
     return R;
   else{
     ptr L = search_no_0_tree(LC(R));
     if(L!=NULL)
        return L;
     else
        return search_no_0_tree(RC(R));
   }

}


void sink_zeros(ptr R){
   if(R!=NULL){
       if(data(R)==0){
            //we search for a node to replace with
            ptr rep = search_no_0_tree(R);
            if(rep != NULL){ //we swap
                R->val = data(rep);
                rep->val =0;

            }
            ///if it's NULL then R is either a leaf or all its grandkids are 0s
       }

        sink_zeros(LC(R));
        sink_zeros(RC(R));

   }


}

int main()
{

    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(0);
    root->left->left = new_node(4);
    root->right->left = new_node(0);
    root->right->right = new_node(6);
    root->right->left->left = new_node(7);
    root->right->left->right = new_node(0);
    printf("before :\n\n");
    displayTree(root,0,'-');

    sink_zeros(root);
    printf("after sinking zeros:  \n");
    displayTree(root,0,'-');


    return 0;
}
