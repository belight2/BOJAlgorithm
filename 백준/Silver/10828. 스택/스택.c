#include <stdio.h>
#include <string.h>
int stack[10005]; // 스택
int top = -1;
int main(){
  int N;
  char op[10];
  scanf("%d", &N);
  while(N--){
    scanf(" %s", &op);
    if(!strcmp(op, "push")){
      int data;
      scanf(" %d", &data);
      stack[++top] = data;
    } 
    else if(!strcmp(op, "top")){
      int top_data = (top == -1) ? -1 : stack[top];
      printf("%d\n", top_data);
    }
    else if(!strcmp(op, "pop")){
      int top_data = (top == -1) ? -1 : stack[top--];
      printf("%d\n", top_data);
    }
    else if(!strcmp(op, "size")){
      printf("%d\n", top+1);
    }
    else if(!strcmp(op, "empty")){
      printf("%d\n", (top == -1));
    }
  }
}