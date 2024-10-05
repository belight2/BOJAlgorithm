#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

deque<int> dq;
string p, arr;
int n;

void solve(){
	bool front = true;
	for(int i = 0; i < p.length(); i++){
		if( p[i] == 'R' ) front = !front;
		else{
			if(dq.empty()){
				cout << "error" << '\n';
				return;
			}
			if(front) dq.pop_front();
			else dq.pop_back();
		}
	}
	if(front){
		cout << '[';
		if(!dq.empty()){
			cout << dq.front();
			dq.pop_front();
		}
		while(!dq.empty()){
			cout << ',' << dq.front();
			dq.pop_front();
		}
	}
	else{
		cout << '[';
		if(!dq.empty()){
			cout << dq.back();
			dq.pop_back();
		}
		while(!dq.empty()){
			cout << ',' << dq.back();
			dq.pop_back();
		}
	}
	cout << ']' << '\n';
}

void InputDeque(){
	arr = arr.substr(1, arr.length()-2);
	istringstream ss(arr);
	string buffer;
	while(getline(ss, buffer, ',')){
		dq.push_back(stoi(buffer));
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> p;
		cin >> n;
		cin >> arr;
		InputDeque();
		solve();
	}
}