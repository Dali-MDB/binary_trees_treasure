#include <stdio.h>
#include <stdlib.h>
#include "../trees_lib.h"



ptr_cell all_trees_inorder(int* Inorder, int min , int max){
    ptr_cell Trees = allocate();
    if (min > max) { // we create a list of NULL as the single element
         ass_val(Trees, NULL);
         ass_adr(Trees, NULL);
    } else {
        Trees = NULL;
        ptr_cell Q = NULL;
        int i;

        for (i = min; i <= max; i++) {
            ptr N = NULL; // a potential root

            // we get a list of all possible left and right sub trees
            ptr_cell L = all_trees_inorder(Inorder, min, i-1);
            ptr_cell R = all_trees_inorder(Inorder, i+1, max);

            ptr_cell save = R;
            while (L != NULL) { // all possible combinations (in case of no sub trees we have one element as NULL)

                R = save;

                while (R != NULL) { // we traverse R
                    N = new_node(Inorder[i]);
                    ass_LC(&N, val(L)); ass_RC(&N, val(R)); // we create a node with the current root
                    ptr_cell Current = allocate();
                    ass_val(Current,N);     ass_adr(Current,NULL);

                    // first creation
                    if (Trees == NULL)
                        Trees = Current;
                    else
                        ass_adr(Q, Current);

                    Q = Current; // we update the tail of the list

                    R = next(R); // next possibility of right sub tree
                }

                L = next(L); // next possibility of left sub tree
            }
        }
    }

    return Trees; // all the possibilities for this sub tree to be returned to the parent in a linked list
}


int main()
{
    int Inorder[] = {1,2,3,4};

    ptr_cell Possibilities = all_trees_inorder(Inorder,0,3);
    int i=1;
    while(Possibilities!=NULL){
        printf("\n\npossibility %d  :  \n",i);
        displayTree(val(Possibilities),10,'-');
        i++;
        Possibilities = next(Possibilities);   //to more for the following tree
    }
    return 0;
}
