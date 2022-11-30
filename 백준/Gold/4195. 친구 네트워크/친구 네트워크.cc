#include <bits/stdc++.h>
using namespace std;

int T, F;
set <string> names;
map <string, string> parent;
map <string, int> cnt;

string Find(string name);
void Union(string A, string B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		names.clear();
		parent.clear();
		cnt.clear();
		cin >> F;
		for (int i = 0; i < F; i++) {
			string A, B;
			cin >> A >> B;
			if (names.count(A) == 0) {
				names.insert(A);
				parent[A] = A;
				cnt[A] = 1;
			}
			if (names.count(B) == 0) {
				names.insert(B);
				parent[B] = B;
				cnt[B] = 1;
			}
			Union(A, B);
			cout << cnt[Find(A)] << '\n';
		}
	}
	return 0;
}

string Find(string name) {
	if (parent[name] == name) return name;
	else return parent[name] = Find(parent[name]);
}

void Union(string A, string B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	if (A > B) {
		parent[A] = B;
		cnt[B] += cnt[A];
	}
	else {
		parent[B] = A;
		cnt[A] += cnt[B];
	}
	return;
}