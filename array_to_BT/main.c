#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>

ptr localize_node(ptr R,int V){

    if(R!=NULL){
        if(data(R) == V)
            return R;
        else{
            ptr Left = localize_node(LC(R),V);   //we search in the left sub tree
            if(Left != NULL)   //we found it
                return Left;
            else{
                //we search in the right
                ptr Right = localize_node(RC(R),V);
                if(Right != NULL)
                    return Right;
                else
                    return NULL;   ///doesn't exist in neither left nor right sub trees
            }
        }

    }else{
       return NULL;
     }

}


ptr array_to_Tree(int Parent[100],int Index[100],int size){
    int i;
    ptr root = NULL;


    for(i=0;i<size;i++){
        ptr N=new_node(Index[i]);

        ///particular case (empty tree)
        if(Parent[i]==-1)
            root = N;
        else{
            ptr P = localize_node(root,Parent[i]);    //we identify its parent
            if(P!=NULL){  ///otherwise the parent couldn't be found

                if(LC(P) == NULL)  //first sibling from the array
                     P->left = N;
                else{//second sibling
                    if(RC(P) == NULL)
                          P->right = N;
                    ///else there's an error an we don't insert

                }

            }
        }

    }

    return root;  //we return the root of the constructed tree


}

int main()
{
    int parent[] = {-1, 0, 0, 1, 2, 2, 4, 4};
    int index[]  = { 0, 1, 2, 3, 4, 5, 6, 7};

    int size = (int) (sizeof(parent)/sizeof(parent[0]));

    ptr Tree = array_to_Tree(parent,index,size);


    displayTree(Tree,10,'-');

    return 0;
}
