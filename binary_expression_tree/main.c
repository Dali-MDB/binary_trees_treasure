#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

typedef struct node{
   char val[20];
   struct node *left,*right;

}node;

typedef struct node* ptr;

ptr new_node(char V[20]){
   ptr N = (ptr) malloc(sizeof(node));
   N->left = NULL;
   N->right = NULL;
   strcpy(N->val,V);
   return N;

}

int data(ptr R){
   return R->val;
}

ptr LC(ptr R){
   return R->left;
}

ptr RC(ptr R){
   return R->right;
}

void ass_LC(ptr* R, ptr Q) {
    if (R != NULL && *R != NULL && (*R)->left == NULL) {
        (*R)->left = Q;
    }
}

void ass_RC(ptr* R, ptr Q) {
    if (R != NULL && *R != NULL && (*R)->right == NULL) {
        (*R)->right = Q;
    }
}

void ass_data(ptr* R , char V[20]){
    strcpy((*R)->val , V);
}


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




void Textecolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
// Texte couleur et fond:
void Color(int couleurdutexte, int couleurdufond)
{

    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurdufond * 16 + couleurdutexte);
}
void displayTree(ptr root, int space, char direction)
{
    const int COUNT = 10;

    Textecolor(14);
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    int Value  =  data(root);

    ///RC first
    displayTree(RC(root), space, '/'); // For right child, direction is '/'

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");

    Textecolor(14);
    printf("%c(", direction);


    Textecolor(11);
    printf("%s",Value);
    Textecolor(14);



    if((LC(root) !=NULL) && (RC(root) != NULL)){
        printf(")<\n");
    }
    else if (LC(root) != NULL ){ //RC == NULL
        printf(")\\\n");
    }
    else if(RC(root) != NULL){ //LC == NULL
        printf(")/\n");
    }
    else{ //a leaf
        printf(")=E\n");
    }

    ///LC
    displayTree(LC(root), space, '\\'); // For left child, direction is '\'
}

float calculate(float a,float b,char op[],bool* error){
   switch(op[0]){  ///since it's of one character only
      case '+' : return a+b;
                 break;
      case '-' : return a-b;
                 break;
      case '*' : return a*b;
                 break;
      case '/' : if(b==0){
                    *error = false;
                    printf("errrrrrr");
                    return 0;
                 }else
                    return a/b;

                 break;
      default     : //unidentified operator
                  printf("zebi");
                 *error = true;
                  return 0;



   }



}
float evaluate_binary_expresson_tree(ptr R,bool* error){
    if(R==NULL)    //empty tree
        return 0;
    ///we perform bottom to top traversal since the leaves contain the numerical values

    if(LC(R) == NULL && RC(R) == NULL)  //a leaf
        return atof(data(R));
    else{//supposing that each non leaf node has two children
        float left_result = evaluate_binary_expresson_tree(LC(R),error);
        float right_result = evaluate_binary_expresson_tree(RC(R),error);

        return calculate(left_result,right_result,data(R),error);    //data(R) is the operator in this case

    }
}

ptr expression_postf_to_tree(char exp[],bool* error){
   stack S;
   create_stack(&S);   //contains the nodes supposed value
   ///for each char , if it's an operand : we create a new node containing its value and push it to the stack
   ///if it's an operator : we create a new node the pop two operands and set the new node to be their parent
   int i;
   ptr N,child;
   for(i=0;i<strlen(exp);i++){

      char value[20];
      value[0]=exp[i];
      value[1]=' ';
      value[2]='\0';

      N=new_node(value);   //a new node of the value
      if(exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' ){ ///operation
            //printf("here");

          //we pop two operands
          if(empty_stack(S)){
              *error = true;
              return NULL;
          }
          else{
              child = NULL;
              pop(&S,&child);
              ass_RC(&N,child);
              //now the second operand
              if(empty_stack(S)){
                 *error = true;
                 return NULL;
              }
              else{
                 child = NULL;
                 pop(&S,&child);
                 ass_LC(&N,child);
              }

           }
      }

      push(&S,N);//push the new node



   }
   ///finally we return the result
   if(empty_stack(S)){
      *error = true;
      return NULL;
   }
   else{
      pop(&S,&N);
      return N;    ///the root of the constructed tree
   }

}
int main()
{
    ptr root = new_node("+");
    root->left = new_node("*");
    root->right = new_node("/");
    root->left->left = new_node("-");
    root->left->right = new_node("5");
    root->right->left = new_node("21");
    root->right->right = new_node("7");
    root->left->left->left = new_node("10");
    root->left->left->right = new_node("5");

    bool err=false;

  //  printf(" =  %.2f",evaluate_binary_expresson_tree(root,&err));

    ptr Tree = expression_postf_to_tree("ab+cde+**",&err);

    displayTree(Tree,10,'-');

    return 0;
}
