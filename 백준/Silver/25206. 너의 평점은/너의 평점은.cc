#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
unordered_map<string, double> m;
string name, grade;
double credit;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	m["A+"] = 4.5; m["A0"] = 4.0; m["B+"] = 3.5; m["B0"] = 3.0;
	m["C+"] = 2.5; m["C0"] = 2.0; m["D+"] = 1.5; m["D0"] = 1.0;
	m["F"] = 0.0;
	double cnt = 0; int t = 20;
	double ans = 0.0;
	while(t--){
		cin >> name >> credit >> grade;
		if(grade == "P") continue;
		cnt += credit;
		ans += credit * m[grade];
	}
	cout << ans / double(cnt);
}