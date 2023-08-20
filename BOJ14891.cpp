#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<deque<char>> saw_wheel;
int k;
int wheel_num;
int dir[4];
int res = 0;
void rotation(int num, int dir){
	if( dir == 1 ){
		saw_wheel[num].push_front(saw_wheel[num].back());
		saw_wheel[num].pop_back();
	}
	else if( dir == -1 ){
		saw_wheel[num].push_back(saw_wheel[num].front());
		saw_wheel[num].pop_front();
	}
}
void decide_direct(int init){
	//¿ÞÂÊ
	for(int left = init; left > 0; left--){
		if(saw_wheel[left][6] == saw_wheel[left-1][2]) break;
		dir[left-1] = dir[left] * -1;
	}
	//¿À¸¥ÂÊ 
	for(int right = init; right < 3; right++){
		if(saw_wheel[right][2] == saw_wheel[right+1][6] ) break;
		dir[right+1] = dir[right] * -1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	for(int i = 0; i < 4; i++){
		cin >> s;
		deque<char> d;
		for(int j = 0; j < 8; j++) d.push_back(s[j]);
		saw_wheel.push_back(d);
	}
	cin >> k;
	while(k--){
		fill(dir,dir+4,0);
		cin >> wheel_num; wheel_num--;
		cin >> dir[wheel_num]; 
		decide_direct(wheel_num);
		for(int i = 0; i < 4; i++){
			rotation(i,dir[i]);
		}
	}
	for(int i = 0; i < 4; i++){
		if(saw_wheel[i].front() == '0') continue;
		res += ( 1 << i );
	}
	cout << res;
} 
