#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string S;
vector <int> cow[26];
int ans;

bool cmp(vector <int> A, vector <int> B) {
	return A.front() < B.front();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.length(); i++) cow[S[i] - 'A'].push_back(i);
	sort(cow, cow + 26, cmp);	
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (cow[i][0] < cow[j][0] && cow[j][0] < cow[i][1] && cow[i][1] < cow[j][1]) ans++;
		}
	}
	cout << ans;
	return 0;
}