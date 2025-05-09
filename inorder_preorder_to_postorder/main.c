#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>


int srch_array(int* T,int min,int max,int V){
   int i;
   for(i=min;i<=max;i++){
       if(T[i] == V)
          return i;
   }
   return -1;   //cuz we didn't quit already

}

int srch_array_reversed(int* T,int min,int max,int V){
   int i;
   for(i=max;i>=min;i--){
       if(T[i] == V)
          return i;
   }
   return -1;   //cuz we didn't quit already

}

void in_pre_to_postorder(int* Inorder,int* Preorder,int post[100],int min,int max,int* i /*to insert*/){
    if(min<=max){
        ///first we identify the current root
        int j=0;
        int index = srch_array(Inorder,min,max,Preorder[j]);

        while(index==-1 /*not found*/){
             j++; //next el in inorder
             index = srch_array(Inorder,min,max,Preorder[j]);
        }


        ///now we have the index of the current root , we add it to postorder array
        //we fill it from right to left
        post[*i]=Preorder[j];      (*i)--;


        //recursive calls:
        ///we split the array into two arrays around the current root using min and max and index
        //root then right then left

        in_pre_to_postorder(Inorder,Preorder,post,index+1,max,i);  //right array

        in_pre_to_postorder(Inorder,Preorder,post,min,index-1,i);  //left array


    }///otherwise we stop
}

ptr generate_from_in_pre_order(int* Inorder,int* Preorder,int min , int max ){
    if(min<=max){
        ///we identify the current root
        int j=0;
        int index = srch_array(Inorder,min,max,Preorder[j]);

        while(index==-1 /*not found*/){
             j++; //next el in inorder
             index = srch_array(Inorder,min,max,Preorder[j]);
        }

        ///now that we heave the index of the current root
        ptr R = new_node(Inorder[index]);

        ///we split the array in two and identify its children
        ptr Left = generate_from_in_pre_order(Inorder,Preorder,min,index-1);
        ptr Right = generate_from_in_pre_order(Inorder,Preorder,index+1,max);
        ///we link em and return R
        R->left = Left;           R->right = Right;

        return R;


    }
    else
        return NULL;


}

void in_post_to_preorder(int* Inorder,int* Postorder,int pre[100],int min,int max,int size,int* i /*to insert*/){
    if(min<=max){
        ///first we identify the current root in reversed order
        int j=size-1;
        int index = srch_array_reversed(Inorder,min,max,Postorder[j]);

        while(index==-1 /*not found*/){
             j--; //next el in inorder       till the first node we encounter than exists in preorder (from the right)
             index = srch_array_reversed(Inorder,min,max,Postorder[j]);
        }


        ///now we have the index of the current root , we add it to preorder array
        pre[*i]=Postorder[j];      (*i)++;


        //recursive calls:
        ///we split the array into two arrays around the current root using min and max and index
        //root then left then right

        in_post_to_preorder(Inorder,Postorder,pre,min,index-1,size,i);   //left array
        in_post_to_preorder(Inorder,Postorder,pre,index+1,max,size,i);   //right array




    }///otherwise we stop
}

ptr generate_from_in_post_order(int* Inorder,int* Postorder,int min , int max ,int size){
    if(min<=max){
        ///first we identify the current root in reversed order
        int j=size-1;
        int index = srch_array_reversed(Inorder,min,max,Postorder[j]);

        while(index==-1 /*not found*/){
             j--; //next el in inorder       till the first node we encounter than exists in preorder (from the right)
             index = srch_array_reversed(Inorder,min,max,Postorder[j]);
        }

        ///now that we heave the index of the current root
        ptr R = new_node(Inorder[index]);

        ///we split the array in two and identify its children
        ptr Left = generate_from_in_post_order(Inorder,Postorder,min,index-1,size);
        ptr Right = generate_from_in_post_order(Inorder,Postorder,index+1,max,size);
        ///we link em and return R
        R->left = Left;           R->right = Right;

        return R;


    }
    else
        return NULL;


}


int main()
{
    int Inorder_traversal[] = { 4, 2, 1, 7, 5, 8, 3, 6 };
    int Preorder_traversal[] = { 1, 2, 4, 3, 5, 7, 8, 6 };
    int Postorder_traversal[] = {4,2,7,8,5,6,3,1};
    int levelorder_traversal[] = {1,2,3,4,5,6,7,8};
    int size=(sizeof(Inorder_traversal)/sizeof(Inorder_traversal[0]));

    int Postorder_traversal_result[size] , Preorder_traversal_result[size];

    int insertion_index = size-1,K;
    in_pre_to_postorder(Inorder_traversal,Preorder_traversal,Postorder_traversal_result,0,size-1,&insertion_index);

    //now we display
    printf("\n\nPost order : ");
    for(K=0;K<size;K++)
        printf(" %d ",Postorder_traversal_result[K]);


    printf("\n\n");
    insertion_index = 0;
    in_post_to_preorder(Inorder_traversal,Postorder_traversal,Preorder_traversal_result,0,size-1,size,&insertion_index);

    printf("\n\nPreorder traversal :  ");
    for(K=0;K<size;K++)
        printf(" %d ",Preorder_traversal_result[K]);


    printf("the tree from inorder and preorder :\n\n");
    ptr T1= generate_from_in_pre_order(Inorder_traversal,Preorder_traversal,0,size-1);
    displayTree(T1,10,'-');

    printf("\nthe tree from inorder and preorder :\n\n");
    ptr T2= generate_from_in_post_order(Inorder_traversal,Postorder_traversal,0,size-1,size);
    displayTree(T2,10,'-');

    ///from inorder and level order we can construct the tree using the same method with preorder
    ptr T = generate_from_in_pre_order(Inorder_traversal,levelorder_traversal,0,size-1);
    displayTree(T,10,'-');
    return 0;
}
