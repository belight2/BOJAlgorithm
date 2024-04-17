#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
} node;

node *head = NULL;
node *tail = NULL;
int size = 0;

void init(){
  tail = (node*)malloc(sizeof(node));
  tail->data = '\0';
  tail->next = NULL;
  tail->prev = NULL;
  head = tail;
  size = 0;
}
void add(node *cursor, int data){
  size++;
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = cursor;
  if(cursor == head){
    new_node->prev = NULL;
    cursor->prev = new_node;
    head = new_node;
    return;
  }
  cursor->prev->next = new_node;
  new_node->prev = cursor->prev;
  cursor->prev = new_node;
}
void erase(node *cursor){
  if(size == 0) return;
  size--;
  if(cursor == head) cursor = tail;
  node *erase_node = cursor->prev;
  if(erase_node == head){
    cursor->prev = NULL;
    head = cursor;
    free(erase_node);
    return;
  }
  erase_node->prev->next = cursor;
  cursor->prev = erase_node->prev;
  free(erase_node);
}
void destroy(){
  node *cur = head;
  while(cur != NULL){
    node *temp = cur;
    cur = cur->next;
    free(temp);
  }
}
int main(){
  init();
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) add(tail, i);
  int dep = n-1;
  int cnt = 0;
  printf("<");
  node *cursor = head;
  while(size > 0){
    if(cnt++ == k-1){
      if(cursor != tail) cursor = cursor->next;
      printf("%d", cursor->prev->data);
      if(dep-- > 0) printf(", ");
      erase(cursor);
      if(cursor == tail) cursor = head;
      cnt = 0;
      continue;
    }
    cursor = (cursor->next == tail ) ? head : cursor->next;
  }
  printf(">");
  destroy();
}