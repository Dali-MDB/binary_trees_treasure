#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"

int fix_child_sum_inc(ptr R){
    if(R==NULL)
        return 0;

    //particular case (leaf)
    if(is_leaf(R))
        return data(R);
    else{
        int Left = fix_child_sum_inc(LC(R));
        int Right = fix_child_sum_inc(RC(R));

        if(Left+Right >= data(R))   ///we just increment the value of the current node
            R->val = Left+Right;
        else{ //we must increment the children
            int diff = data(R) -(Left+Right);
            //we keep incrementing each node on the left most path by this difference
            ptr temp=RC(R);
            if(LC(R) != NULL)
                temp = LC(temp);

            while(temp!=NULL){
                temp->val += diff;
                if(LC(temp)!=NULL)
                    temp = LC(temp);
                else
                    temp = RC(temp);
            }


        }

     return data(R);   //after modification


    }


}

int main()
{
    ptr root = new_node(25);
    root->left = new_node(8);
    root->right = new_node(10);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);

    displayTree(root,10,'-');
    printf("after modification :\n\n");
    fix_child_sum_inc(root);

    displayTree(root,10,'-');


    return 0;
}
