#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<string, string>, string> sss;

int num_A, num_B, num_C;
string s[3];
queue <pair<sss,int>> q;
set <sss> mark;
string cmp_A, cmp_B, cmp_C;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		int A;
		cin >> A;
		if (A == 0) continue;
		cin >> s[i];
		for (int j = 0; j < A; j++) {
			if (s[i][j] == 'A') num_A++;
			else if (s[i][j] == 'B') num_B++;
			else num_C++;
		}
	}
	for (int i = 0; i < num_A; i++) cmp_A += 'A';
	for (int i = 0; i < num_B; i++) cmp_B += 'B';
	for (int i = 0; i < num_C; i++) cmp_C += 'C';
	q.push({ {{s[0],s[1]},s[2]}, 0 });
	while (q.size()) BFS();
	return 0;
}

void BFS() {
	pair<sss, int> f = q.front();
	q.pop();
	string A = f.first.first.first;
	string B = f.first.first.second;
	string C = f.first.second;
	int d = f.second;
	if (mark.count({ {A,B},C })) return;
	mark.insert({ {A,B},C });
	if (A == cmp_A && B == cmp_B && C == cmp_C) {
		cout << d;
		exit(0);
	}
	if (A.length() >= 1) {
		char b = A.back();
		string input = A;
		input.pop_back();
		q.push({ {{input, B + b}, C}, d + 1 });
		q.push({ {{input, B}, C + b}, d + 1 });
	}
	if (B.length() >= 1) {
		char b = B.back();
		string input = B;
		input.pop_back();
		q.push({ {{A + b, input}, C}, d + 1 });
		q.push({ {{A, input}, C + b}, d + 1 });
	}
	if (C.length() >= 1) {
		char b = C.back();
		string input = C;
		input.pop_back();
		q.push({ {{A, B + b}, input}, d + 1 });
		q.push({ {{A + b, B}, input}, d + 1 });
	}
}