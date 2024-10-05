#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n;

bool cmp(const string& a, const string& b){
	if(a.length() == b.length()){
		int a_sum = 0;
		int b_sum = 0;
		for(int i = 0; i < a.length(); i++){
			if(isdigit(a[i])) a_sum += a[i] - '0';
			if(isdigit(b[i])) b_sum += b[i] - '0';
		}
		if( a_sum == b_sum ){
			return a < b;
		}
		return a_sum < b_sum;
	}
	return a.length() < b.length();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	string arr[n];
	for(string& s : arr){
		cin >> s;
	}
	sort(arr, arr+n, cmp);
	for(string& s : arr){
		cout << s << '\n';
	}
}
