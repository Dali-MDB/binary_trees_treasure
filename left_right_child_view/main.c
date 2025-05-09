#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"
#include <malloc.h>
#include <stdbool.h>


typedef struct cell{
   ptr value;
   struct cell* next;
}cell;

typedef struct cell* ptr_cell ;

ptr_cell allocate(){
   return (ptr_cell) malloc(sizeof(cell));
}

void ass_val(ptr_cell P,ptr val){
    P->value = val;
 }

void ass_adr(ptr_cell P , ptr_cell Q){
    P->next = Q;
 }

ptr val(ptr_cell P){
   return P->value;
}

ptr next(ptr_cell P){
   return P->next;
}

typedef struct stack{
    ptr_cell Head;
}stack;

bool empty_stack(stack P){
   return P.Head == NULL;
}

void create_stack(stack* P){
   P->Head = NULL;
}

void push(stack* S , ptr X){
   ptr_cell P= allocate();
   ass_val(P,X);
   ass_adr(P,S->Head);
   S->Head = P;

}

void pop(stack * S ,ptr* X){
    if(!empty_stack(*S)){
       ptr_cell save;
       save = S->Head;
       S->Head = next(S->Head);
       *X = val(save);
       free(save);
   }
}

ptr closest_right_sibling(ptr root, ptr R) {
    ptr N = root;
    stack S;

    ///the first phase consists of identifying the node
    create_stack(&S);
    while (N != R && N != NULL) {  //till we reach the node or both null
        push(&S, N);
        if (data(R) < data(N))
            N = LC(N);
        else
            N = RC(N);
    }


    ///now we search for the closest sibling
    bool found = false;
    int level, save_level = 0;
    ptr temp;
    ptr current = R ;
    ///R level is the reference ( 0 )

    while (!empty_stack(S) && !found) {
        pop(&S, &N);
        save_level--;
        level = save_level;
        temp = NULL;
        ///we only search if we ascended from the left (so we don't return to the same node)

        if (current != RC(N)) {
            temp = RC(N);  //of the parent
            level++;   ///cuz we ascended by one node

            while ((level != 0) && (temp != NULL)) {  //we get the closes node at the same level of R (0)
                if (LC(temp) != NULL)
                    temp = LC(temp);
                else//no lc so we move to the right
                    temp = RC(temp);

                level++;
            }
        }

         ///now we check the result of quiting the inner loop
        if (level == 0 && temp != NULL) {
            found = true;
            return temp;
        }

        current = N;   //for the next ancestor
    }

     // if(!found || empty_stack(S))
    return NULL;
}
void convert_to_LC_Tree(ptr root ,ptr R){
   //we perfom postorder traversal so we don't lose links between nodes
   if(R!= NULL){
      convert_to_LC_Tree(root,LC(R));
      convert_to_LC_Tree(root,RC(R));
      ///now the current node


      ptr P = closest_right_sibling(root,R);
      R->right = P;


   }


}

ptr closest_left_sibling(ptr root, ptr R) {
    ptr N = root;
    stack S;

    ///the first phase consists of identifying the node
    create_stack(&S);
    while (N != R && N != NULL) {  //till we reach the node or both null
        push(&S, N);
        if (data(R) < data(N))
            N = LC(N);
        else
            N = RC(N);
    }


    ///now we search for the closest sibling
    bool found = false;
    int level, save_level = 0;
    ptr temp;
    ptr current = R ;
    ///R level is the reference ( 0 )

    while (!empty_stack(S) && !found) {
        pop(&S, &N);
        save_level--;
        level = save_level;
        temp = NULL;
        ///we only search if we ascended from the left (so we don't return to the same node)

        if (current != LC(N)) {
            temp = LC(N);  //of the parent
            level++;   ///cuz we ascended by one node

            while ((level != 0) && (temp != NULL)) {  //we get the closes node at the same level of R (0)
                if (RC(temp) != NULL)
                    temp = RC(temp);
                else//no rc so we move to the left
                    temp = LC(temp);

                level++;
            }
        }

         ///now we check the result of quiting the inner loop
        if (level == 0 && temp != NULL) {
            found = true;
            return temp;
        }

        current = N;   //for the next ancestor
    }

     // if(!found || empty_stack(S))
    return NULL;
}


void convert_to_RC_Tree(ptr root ,ptr R){
   //we perfom postorder traversal so we don't lose links between nodes
   if(R!= NULL){
      convert_to_RC_Tree(root,RC(R));
      convert_to_LC_Tree(root,LC(R));
      ///now the current node


      ptr P = closest_left_sibling(root,R);
      R->left = P;


   }


}

int main()
{
    ptr T = new_node(4);
    T->left = new_node(2);
    T->left->left = new_node(1);
    T->left->right = new_node(3);
    T->right = new_node(9);
    T->right->left = new_node(7);
    T->right->left->left = new_node(5);
    T->right->left->right = new_node(8);

    displayTree(T,10,'-');

    convert_to_LC_Tree(T,T);
    printf("after :   \n\n\n");
    displayTree(T,10,'-');

   // printf(" %d ",closest_right_sibling(T,T->right));



    return 0;
}
