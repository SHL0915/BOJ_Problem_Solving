#include <bits/stdc++.h>
using namespace std;

string A, T;
int f_pos, e_pos;
deque <char> f, b;
stack <char> fs, bs;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> T;
	f_pos = 0;
	e_pos = T.size() - 1;
	while (f_pos <= e_pos) {
		for (; f_pos <= e_pos; f_pos++) {
			if (T[f_pos] == A.back()) {
				fs.push(T[f_pos]);
				for (int i = A.size() - 2; i >= 0; i--) {
					if (f.size() == 0 || A[i] != f.back()) {
						while (fs.size()) {
							f.push_back(fs.top());
							fs.pop();
						}
						break;
					}
					fs.push(f.back());
					f.pop_back();
				}
				if (fs.size()) {
					while (fs.size()) fs.pop();
					f_pos++;
					break;
				}
			}
			else f.push_back(T[f_pos]);
		}
		for (; e_pos >= f_pos; e_pos--) {
			if (T[e_pos] == A.front()) {
				bs.push(T[e_pos]);
				for (int i = 1; i < A.size(); i++) {
					if (b.size() == 0 || A[i] != b.front()) {
						while (bs.size()) {
							b.push_front(bs.top());
							bs.pop();
						}
						break;
					}
					bs.push(b.front());
					b.pop_front();
				}
				if (bs.size()) {
					while (bs.size()) bs.pop();
					e_pos--;
					break;
				}
			}
			else b.push_front(T[e_pos]);
		}
	}
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == A.back()) {
			fs.push(b[i]);
			for (int j = A.size() - 2; j >= 0; j--) {
				if (f.size() == 0 || f.back() != A[j]) {
					while (fs.size()) {
						f.push_back(fs.top());
						fs.pop();
					}
					break;
				}
				fs.push(f.back());
				f.pop_back();
			}
			while (fs.size()) fs.pop();
		}
		else f.push_back(b[i]);
	}
	for (int i = 0; i < f.size(); i++) cout << f[i];
	return 0;
}