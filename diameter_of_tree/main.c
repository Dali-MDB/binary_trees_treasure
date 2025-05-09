#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../trees_lib.h"

int min(int a , int b){
  if (a>b)
    return b;
  else
    return a;

}


void diameter_tree(ptr R, char des) {
    if (R == NULL)
        return;

    ptr Left, Right;
    printf("\t"); // to separate nodes

    // If the current node is a leaf node, print its data
    if (LC(R) == NULL && RC(R) == NULL) {
        printf("%d", data(R));
        return;
    }

    // If the left child is NULL, explore the right subtree
    if (LC(R) == NULL) {
        Right = RC(R);
        if (1 + min(depthTree(LC(Right)), depthTree(RC(Right))) == 0) {
            printf("%d", data(R));
            diameter_tree(Right, 'R');
        }
        return;
    }

    // If the right child is NULL, explore the left subtree
    if (RC(R) == NULL) {
        Left = LC(R);
        if (1 + min(depthTree(LC(Left)), depthTree(RC(Left))) == 0) {
            printf("%d", data(R));
            diameter_tree(Left, 'L');
        }
        return;
    }

    // Both children are not NULL
    Left = LC(R);
    Right = RC(R);
    int left_path = depthTree(LC(Left)) + 1 + depthTree(RC(Left)) + 1;
    int right_path = depthTree(LC(Right)) + 1 + depthTree(RC(Right)) + 1;
    int mix_path = depthTree(Left) + 1 + depthTree(Right) + 1 + 1;

    if ((mix_path >= left_path) && (mix_path >= right_path)) { // Explore both subtrees
        printf("%d", data(R));
        switch (des) {
            case 'B':
                diameter_tree(Left, 'L');
                diameter_tree(Right, 'R');
                break;
            case 'L':
                diameter_tree(Left, 'L');
                break;
            case 'R':
                diameter_tree(Right, 'R');
                break;
        }
        return;
    }

    if ((left_path > mix_path) && (left_path >= right_path)) { // Explore left subtree
        diameter_tree(Left, 'L');
        return;
    }

    if ((right_path > mix_path) && (right_path > left_path)) { // Explore right subtree
        diameter_tree(Right, 'R');
        return;
    }
}


int main()
{
    ptr R = new_node(49);

    R->left = new_node(30);
    R->left->left = new_node(22);
    R->left->right = new_node(41);
   // R->left->left->left = new_node(15);
  //  R->left->left->right = new_node(27);
  //  R->left->right->left = new_node(36);
    R->left->right->right = new_node(44);

    R->right = new_node(70);
  //  R->right->left = new_node(60);
   // R->right->right = new_node(87);
    //R->right->left->left = new_node(55);
    //R->right->left->right = new_node(62);
  //  R->right->right->left = new_node(75);
//    R->right->right->right = new_node(99);

    displayTree(R,0,' ');
    diameter_tree(R,'B');
    return 0;
}
