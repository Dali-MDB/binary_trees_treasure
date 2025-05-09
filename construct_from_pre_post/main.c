#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <stdbool.h>

int srch_array(int* T,int min,int max,int V){
   int i;
   for(i=min;i<=max;i++){
       if(T[i] == V)
          return i;
   }
   return -1;   //cuz we didn't quit already

}

ptr generate_from_pre_post(int* Preorder, int* Postorder , int index_pre, int size){
    if(index_pre>=0 && index_pre < size){
        ptr N = new_node(Preorder[index_pre]);
        ptr Left,Right;

        int index_post = srch_array(Postorder,0,size-1,Preorder[index_pre]); //we get the index of the current node in postorder

        ///Preorder[index_pre+1] is a potential lc
        if(index_pre+1<size){ //within the range of the array


           int potential_LC = srch_array(Postorder,0,index_post-1,Preorder[index_pre+1]);
           if(  potential_LC != -1)  ///if the potential lc exists in the left of the node in post
               Left = generate_from_pre_post(Preorder,Postorder,index_pre+1,size);
           else
               Left = NULL;
        }
        else
            Left = NULL;  ///no lc cuz we exceeded the range


        ///Postorder[index_post-1] is a potential RC
        if(index_post-1>=0){ //within the range of the array

           int potential_RC = srch_array(Preorder,index_pre+1,size-1,Postorder[index_post-1]);
           if( potential_RC != -1)///if the potential rc exists in the right of the node in preorder
               Right = generate_from_pre_post(Preorder,Postorder,Preorder[potential_RC],size);
           else
               Right = NULL;

        }
        else
            Right = NULL;  ///no rc cuz qw exceeded the range

        N->left = Left;
        N->right = Right;
        return N;  ///for the calling parent node


    }
    else
        return NULL;


}

int main()
{
    printf("Hello world!\n");
    return 0;
}
