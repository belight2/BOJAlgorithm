#include <iostream>
using namespace std;

const int MX = 100005;
int dat[2*MX-1];
int head = MX, tail = MX;

void push_front(int x){
	dat[--head] = x;
}
void push_back(int x){
	dat[tail++] = x;
}
void pop_front(){
	if(head == tail) cout << -1 << '\n';
	else cout << dat[head++] << '\n';
}
void pop_back(){
	if(head == tail) cout << -1 << '\n';
	else cout << dat[--tail] << '\n';
}
int size(){
	return tail-head;
}
int empty(){
	if(head == tail) return 1;
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
	int t, x;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		if( s == "push_back" ){
			cin >> x;
			push_back(x);
		}
		else if( s == "push_front"){
			cin >> x;
			push_front(x);
		}
		else if( s == "front" ) cout << front() << '\n';
		else if( s == "back" ) cout << back() << '\n';
		else if( s == "size" ) cout << size() << '\n';
		else if( s == "empty") cout << empty() << '\n';
		else if( s == "pop_front" ) pop_front();
		else if( s == "pop_back") pop_back();
	}
}