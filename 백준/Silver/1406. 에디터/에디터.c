#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
  char data;
  struct Node *next;
  struct Node *prev;
}node;

node *head = NULL;
node *tail = NULL;
int size = 0;
void init(char *s, int len){
  head = (node*)malloc(sizeof(node));
  head->data = '\0'; head->next = NULL; head->prev = NULL;
  tail = (node*)malloc(sizeof(node));
  tail->data = '\0'; tail->next = NULL; tail->prev = head;
  head->next = tail;

  if(len == 0) return;
  node *cursor = tail;
  for(int i = 0; i < len; i++) add(cursor, s[i]);
}
void add(node *cursor, char data){
  if(size++ == 0){
    head->data = data;
    return;
  }
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = cursor;
  if(cursor == head){
    new_node->prev = NULL;
    cursor->prev = new_node;
    head = new_node;
    return;
  }
  new_node->prev = cursor->prev;
  cursor->prev->next = new_node;
  cursor->prev = new_node;
}
void erase(node *cursor){
  if(cursor == head || size == 0) return;
  size--;
  node *erase_node = cursor->prev;
  if(erase_node == head){
    head = cursor;
    free(erase_node);
    return;
  }
  erase_node->prev->next = cursor;
  cursor->prev = erase_node->prev;
  free(erase_node);
}

void destroy(){
  node *cursor = head;
  while(cursor != NULL){
    node *temp = cursor;
    cursor = cursor->next;
    free(temp);
  }
  head = NULL;
  tail = NULL;
  size = 0;
}
void print_node(){
  if(size == 0) return;
  node *cursor = head;
  while(cursor != tail){
    printf("%c", cursor->data);
    cursor = cursor->next;
  }
  printf("\n");
}
int main(){
  char str[100005], op, x;
  int t;
  scanf("%[^\n]s", &str);
  init(str, strlen(str));
  scanf("%d", &t);
  node *cursor = tail;
  while(t--){
    scanf(" %c", &op);
    if(op == 'P'){
      scanf(" %c", &x);
      add(cursor, x);
    }
    else if(op == 'L'){
      if(cursor != head) cursor = cursor->prev;
    }
    else if(op == 'B'){
      erase(cursor);
    }
    else if(op == 'D'){
      if(cursor != tail) cursor = cursor->next;
    }
  }
  print_node();
  destroy();
}