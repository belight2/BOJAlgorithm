#include <stdio.h> 
#include <stdlib.h>
typedef struct Node{
  void *data;
  struct Node *next;
} Node;

typedef struct{
  Node *top;
} Stack;

void push(Stack *stack, Node *node){
  node->next = stack->top;
  stack->top = node;
}

void* top(Stack *stack){
  return stack->top->data; 
}

void pop(Stack *stack){
  if(stack->top == NULL) return;
  Node *delete_node = stack->top;
  stack->top = stack->top->next;
  free(delete_node);
}

Node* create_node(int a){
  void *data = malloc(sizeof(int));
  *(int*)(data) = a;
  Node *node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

int main(){
  Stack *stk = malloc(sizeof(Stack));
  stk->top = NULL;
  int k, x, ans = 0;
  scanf("%d", &k);
  while(k--){
    scanf("%d", &x);
    if(x) push(stk, create_node(x));
    else pop(stk);
  }
  while(stk->top != NULL){
    ans += *(int*)(top(stk));
    pop(stk);
  }
  printf("%d", ans);
  free(stk);
}