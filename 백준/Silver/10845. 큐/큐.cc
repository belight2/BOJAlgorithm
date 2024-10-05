#include <iostream>
using namespace std;

int dat[100005];
int head = 0, tail = 0;

void push(int x){
	dat[tail++] = x;
}
void pop(){
	if( tail > head ) cout << dat[head++] << '\n';
	else cout << -1 << '\n';
}
int size(){
	return tail - head;
}
int empty(){
	if( head == tail ) return 1;
	return 0;
}
int front(){
	if(empty()) return -1;
	return dat[head];
}
int back(){
	if(empty()) return -1;
	return dat[tail-1];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, elem;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		if( s == "push"){
			cin >> elem;
			push(elem);
		}
		else if( s == "front") cout << front() << '\n';
		else if( s == "back" ) cout << back() << '\n';
		else if( s == "size" ) cout << size() << '\n';
		else if( s == "empty" ) cout << empty() << '\n';
		else if( s == "pop") pop();
	}
}