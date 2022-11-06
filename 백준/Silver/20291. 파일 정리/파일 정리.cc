#include <iostream>
#include <map>
using namespace std;

int N;
string input;
map <string, int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		int flag = 0;
		string temp = "";
		for (int j = 0; j < input.length(); j++) {
			if (flag == 1) temp += input[j];
			if (input[j] == '.') flag = 1;
		}
		m[temp] ++;
	}
	for (auto i = m.begin(); i != m.end(); i++) cout << (*i).first << " " << (*i).second << '\n';
	return 0;
}