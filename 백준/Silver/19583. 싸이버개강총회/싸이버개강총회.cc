#include <iostream>
#include <set>
using namespace std;

string S, E, Q;
int S_time, E_time, Q_time, t_time, cnt;
string t, name;
set <string> s;

int convert(string A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> E >> Q;
	S_time = convert(S);
	E_time = convert(E);
	Q_time = convert(Q);
	while (cin >> t >> name) {
		t_time = convert(t);
		if (t_time <= S_time) s.insert(name);
		else if (t_time >= E_time && t_time <= Q_time) {
			if (s.count(name) == 0) continue;
			else {
				s.erase(name);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

int convert(string A) {
	int result = 0, degree = 1;
	for (int i = A.size() - 1; i >= 0; i--) {
		if (i == 2) continue;
		result += (degree * (A[i] - '0'));
		degree *= 10;
	}
	return result;
}