#include <iostream>
#include <algorithm>
using namespace std;

int N;
string word;

void BackTracking(string s, int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> word;
		sort(word.begin(), word.end());
		BackTracking(word, 0);
	}
	return 0;
}

void BackTracking(string s, int k) {
	if (k == word.length() - 1) {
		cout << s << '\n';
		return;
	}
	else {
		for (int i = k; i < word.length(); i++) {
			if (i != k && s[i] == s[k]) continue;
			if (s[i] != s[k]) {
				char temp = s[i];
				s[i] = s[k];
				s[k] = temp;
			}
			BackTracking(s, k + 1);
		}
	}
}