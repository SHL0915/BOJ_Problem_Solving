#include <iostream>
#include <map>
using namespace std;

int N;
string input;
map <string, int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		s[input]++;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> input;
		s[input]--;
	}
	for (auto i = s.begin(); i != s.end(); i++) {
		if ((*i).second != 0) cout << (*i).first;
	}
	return 0;
}