#include <stdio.h>
#include <string.h>
int main(){
  int freq['z'-'a'+1] = {0};
  char c[105];
  scanf("%[^\n]s", c);
  for(int i = 0; i < strlen(c); i++) freq[c[i]-'a']++;
  for(int i = 0; i <= 'z'-'a'; i++) printf("%d ", freq[i]);
}