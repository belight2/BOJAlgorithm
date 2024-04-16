#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
  char data;
  struct Node *prev;
  struct Node *next;
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
}

void add(node *cursor, char data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = cursor;
  size++;
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
  if(cursor == head || size == 0) return;
  size--;
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

void print_linked_list(){
  node *cur = head;
  if(cur == tail) return;
  while(cur->next != NULL){
    printf("%c", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void destroy(){
  node *cur = head;
  while(cur != NULL){
    node *temp = cur;
    cur = cur->next;
    free(temp);
  }
  head = NULL;
  tail = NULL;
  size = 0;
}

void solve(){
  char str[1000005];
  int len;
  scanf(" %[^\n]s", &str); 
  len = strlen(str);
  init();
  node *cursor = tail;
  for(int i = 0; i < len; i++){
    char c = str[i];
    if(c == '<') { if(cursor->prev != NULL) cursor = cursor->prev; }
    else if(c == '>'){ if(cursor->next != NULL) cursor = cursor->next;}
    else if(c == '-') erase(cursor);
    else add(cursor, c);
  }
  print_linked_list();
  destroy();
}
int main(){
  int test_case;
  scanf("%d", &test_case);
  while(test_case--) solve();
}