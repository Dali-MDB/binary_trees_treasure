#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"


void ancestor_matrix(ptr R,int min , int* size,int T[10],int M[10][10]){
   if(R!=NULL){
       ///we obtain the children from both sub trees

       ancestor_matrix(LC(R),min,size,T,M);

       ancestor_matrix(RC(R),(*size),size,T,M);   //start is the index where to start considering the children of rc


       int i;
       printf("\nthe children of %d are : ",data(R));
       for(i=min;i<*size;i++){  //we iterate through the children of this node and add them to the matrix
            printf(" %d ",T[i]);
            M[data(R)][T[i]] = 1;
            printf("(%d)",M[data(R)][T[i]]);
       }

       //we finally add the current node to be returned to the parent
       T[*size] =  data(R);
       (*size)++;


   }



}

ptr matrix_to_tree(int M[10][10],int length){
    //we first start by creating the tree nodes and store them in an array
    ptr Nodes[length];
    int i,j,k;

    for(i=0;i<length;i++)
        Nodes[i] = new_node(i);     //the index represents the value

    for(i=0;i<length;i++){
        //for each node we create an array of descendents
        ///a copy for each row
        int D[length];
        for(j=0;j<length;j++){
            D[j] = M[i][j];
        }


        ///now we eliminate sub children from the new constructed array
        for(k=0;k<length;k++){
            if(D[k] == 1){//non null
                for(j=0;j<length;j++){ ///we go the row number k to check its descendents
                    if(M[k][j] == 1) //a child so we eliminates it from D
                         D[j] = 0;

                }

            }
        }


        ///now we're left with two children at most
        for(j=0;j<length;j++){
            if(D[j] == 1){  //we set it as a child
                if(LC(Nodes[i]) == NULL){
                     (Nodes[i])->left = Nodes[j];

                }
                else
                     (Nodes[i])->right = Nodes[j];


            }


        }


    }



    ///now we determine the root
    ptr copy[length];
    for(i=0;i<length;i++){
        copy[i] = Nodes[i];
    }


    for(i=0;i<length;i++){
        if(copy[i] != NULL){ //we eliminate children cells
            if(LC(copy[i]) != NULL)
                   copy[data(LC(copy[i]))] = NULL;
            if(RC(copy[i]) != NULL)
                   copy[data(RC(copy[i]))] = NULL;
        }
    }

    for(i=0;i<length;i++)
        if(copy[i] != NULL)
            return copy[i];

    return NULL;   //error



}


void display_matrix(int Matrix[10][10],int r , int c){
   int i,j,k;

   printf(" ");
   for(k=0;k<(c*3+c-1);k++)
      printf("_");
   printf("\n");
   for (i=0;i<r;i++){
       for(j=0;j<c;j++){
           if(j==0)
              printf("|");
           printf(" %d ",Matrix[i][j]);
           printf("|");
       }

       printf("\n|");
       for(k=0;k<c;k++)
          printf("___|");
       printf("\n");
   }
}

int main()
{
    ptr root = new_node(4);
    root->left = new_node(3);
    root->right = new_node(1);
    root->left->left = new_node(2);
    root->left->right = new_node(0);
    root->right->right = new_node(5);
/*
    displayTree(root,10,'-');
    int T[10],size = 0;

    int M[10][10] ;
    int i,j;
    for(i=0;i<=5;i++){
        for(j=0;j<=5;j++){
            M[i][j]=0;     ///initialized to 0
        }
    }
    ancestor_matrix(root,0,&size,T,M);

    printf("\n");

    display_matrix(M,6,6);*/

    int MAT[10][10] ;
    MAT[0][0] = 0; MAT[0][1] = 0; MAT[0][2] = 0; MAT[0][3] = 0; MAT[0][4] = 0;
MAT[1][0] = 1; MAT[1][1] = 0; MAT[1][2] = 0; MAT[1][3] = 0; MAT[1][4] = 0;
MAT[2][0] = 0; MAT[2][1] = 0; MAT[2][2] = 0; MAT[2][3] = 1; MAT[2][4] = 0;
MAT[3][0] = 0; MAT[3][1] = 0; MAT[3][2] = 0; MAT[3][3] = 0; MAT[3][4] = 0;
MAT[4][0] = 1; MAT[4][1] = 1; MAT[4][2] = 1; MAT[4][3] = 1; MAT[4][4] = 0;

    ptr Tree = matrix_to_tree(MAT,5);

    printf("result :   \n");
    displayTree(Tree,10,'-');




    return 0;
}
