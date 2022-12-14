#include <bits/stdc++.h>
using namespace std;

vector <int> ans;
string T, P;
int pi[1000000];

void makepi(string str);
void kmp(string org, string cmp);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin, T);
	getline(cin, P);
	makepi(P);
	kmp(T, P);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}

void makepi(string str) {
	int n = str.length(), pos = 1, k = 0;
	while (pos + k < n) {
		if (str[pos + k] == str[k]) {
			k++;
			pi[pos + k - 1] = k;
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}

void kmp(string org, string cmp) {
	int n = org.length();
	int m = cmp.length();
	int pos = 0, k = 0;
	while (pos + m <= n) {
		if (org[pos + k] == cmp[k]) {
			k++;
			if (k == m) ans.push_back(pos + 1);
		}
		else {
			if (k == 0) pos++;
			else {
				pos += (k - pi[k - 1]);
				k = pi[k - 1];
			}
		}
	}
	return;
}