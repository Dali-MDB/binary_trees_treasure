#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <limits.h>


int max_in_Tree(ptr R){
  if(R==NULL)
     return 0;

  int Left = max_in_Tree(LC(R));
  int Right = max_in_Tree(RC(R));

  if(data(R) >= Left && data(R) >= Right)
      return data(R);

  if(Left >= data(R) && Left >= Right)
      return Left;

  if(Right >= data(R) && Right >= Left)
      return Right;

}

int min_in_Tree(ptr R){
   if(R==NULL)
     return 0;

  int Left = min_in_Tree(LC(R));
  int Right = min_in_Tree(RC(R));

  if(data(R) <= Left && data(R) <= Right)
      return data(R);

  if(Left <= data(R) && Left <= Right)
      return Left;

  if(Right <= data(R) && Right <= Left)
      return Right;

}

int size_Binary_Tree(ptr R){
   if(R==NULL)
      return 0;
   else
      return 1+size_Binary_Tree(LC(R))+size_Binary_Tree(RC(R));


}
ptr largest_sub_BST(ptr R, int* size) {

    if (R == NULL) {
        *size = 0;
        return NULL;
    }

    if (is_BST(R, INT_MIN, INT_MAX)) {
        *size = size_Binary_Tree(R);
        return R;
    }


    int left_size = 0, right_size = 0;
    ptr left_largest = largest_sub_BST(LC(R), &left_size);
    ptr right_largest = largest_sub_BST(RC(R), &right_size);


    if(left_size== 0 && right_size==0){
        *size=0;
        return NULL;
    }

    if (left_size > right_size) {
        *size = left_size;
        return left_largest;
    } else {
        *size = right_size;
        return right_largest;
    }
}
int main()
{

    ptr root = new_node(10);

    root->left = new_node(15);
    root->right = new_node(8);

    root->left->left = new_node(12);
    root->left->right = new_node(20);

    root->right->left = new_node(5);
    root->right->right = new_node(2);
    displayTree(root,10,'-');

    printf("the largest subtree is :\n");
    int size=0;
    ptr Largest_ST = largest_sub_BST(root,&size);
    displayTree(Largest_ST,10,'-');
    printf("\nwhose size is : %d",size);

    return 0;
}
