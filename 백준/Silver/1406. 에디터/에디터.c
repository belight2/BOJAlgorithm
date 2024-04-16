#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 연결리스트의 기본 단위 : Node
typedef struct Node{
  char data;
  struct Node *next;
  struct Node *prev;
} node;

// 연결리스트의 기점과 종점, 크기
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

void add(node *cur, char data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = cur;
  size++;
  if(cur == head){
    new_node->prev = NULL;
    cur->prev = new_node;
    head = new_node;
    return;
  }
  cur->prev->next = new_node;
  new_node->prev = cur->prev;
  cur->prev = new_node;
}

void erase(node *cur){
  if(cur == head || size == 0) return;
  node *erase_node = cur->prev;
  size--;
  if(erase_node == head){
    cur->prev = NULL;
    head = cur;
    free(erase_node);
    return;
  }
  erase_node->prev->next = cur;
  cur->prev = erase_node->prev;
  free(erase_node);
}

void print_list(){
  node *cur = head;
  if(cur == NULL) return;
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
}

int main(){
  char str[100005], op, x;
  int t;
  scanf("%[^\n]s", &str);
  scanf("%d", &t);

  init(); //연결리스트 초기화

  node *cursor = tail;
  int len = strlen(str);
  for(int i = 0; i < len; i++) add(cursor, str[i]);
  
  while(t--){
    scanf(" %c", &op);
    if(op == 'P'){
      scanf(" %c", &x);
      add(cursor, x);
    }
    else if(op == 'B') erase(cursor);
    else if(op == 'L' && cursor->prev != NULL) cursor = cursor->prev;
    else if(op == 'D' && cursor->next != NULL) cursor = cursor->next;
  }
  print_list();
  // destroy(); // 연결리스트 동적해제
}