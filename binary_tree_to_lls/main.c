#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

ptr BT_to_LLS(ptr R){
    if(R==NULL)
        return NULL;

    ptr L_SUB_list = BT_to_LLS(LC(R));
    ///we reach the right hand node of the left sub list
    if(L_SUB_list != NULL){
        while( L_SUB_list->right != NULL)
            L_SUB_list = L_SUB_list->right;

        ass_LC(&R,L_SUB_list);  //the new lc
        ass_RC(&L_SUB_list,R);
    }
    else
        R->left = NULL;


    ptr R_SUB_list = BT_to_LLS(RC(R));

    ///we reach the right hand node of the left sub list
    if(R_SUB_list != NULL){

        while( R_SUB_list->left != NULL)
            R_SUB_list = R_SUB_list->left;

        printf("%d is about to be assigned as rc for %d",data(R_SUB_list),data(R));
        ass_RC(&R,R_SUB_list);  //the new rc
        ass_LC(&R_SUB_list,R);
        printf("   %d <==>  %d\n",data(R),data(R_SUB_list));   getchar();

    }
    else
        R->right = NULL;

    return R;



}

void display_list_from_bt(ptr R){
   if(R!=NULL){
       ///first we reach the leftmost node
       while(R->left != NULL)
          R=R->left;

       ///now we display
       while(R != NULL){
           if(R->left == NULL)
              printf("=|-");
           printf("( %d )",data(R));
           if(R->right ==NULL)
              printf("-|=");
           else
              printf("<==>");

           R = R->right;
       }
   }

}
int main(){
    ptr root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    displayTree(root,10,'-');
    root = BT_to_LLS(root);
    printf("the constructed lls :   \n");
    display_list_from_bt(root);
    return 0;
}
