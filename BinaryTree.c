#include<stdio.h> 
 #include<stdlib.h> 
  
 struct Node{ 
   int Data; 
   struct Node *Left; 
   struct Node *Right;}; 
  
 struct Node * NodeConst(int); 
 struct Node * TreeConst(int []); 
 void Traverse(struct Node *); 
  
 int main(){ 
     struct Node *Root; 
     int Nodes[]={1,2,-1,-1,3,4,-1,-1,5,-1,-1}; 
     Root=TreeConst(Nodes); 
     Traverse(Root);} 
  
   struct Node * NodeConst(int x){ 
     struct Node *New; 
     New=(struct Node*) malloc(sizeof(struct Node)); 
     New->Data=x; 
     New->Left=NULL; 
     New->Right=NULL; 
     return New;} 
  
   struct Node * TreeConst(int A[]){ 
     static int Index=-1; 
     Index++; 
     if(A[Index]==-1) return NULL; 
     struct Node *New=NodeConst(A[Index]); 
     New->Left = TreeConst(A); 
     New->Right = TreeConst(A); 
     return New;} 
  
   void Traverse(struct Node *Div){ 
     if(!Div) return; 
     printf("%i ",Div->Data); 
     Traverse(Div->Left); 
     Traverse(Div->Right);}
