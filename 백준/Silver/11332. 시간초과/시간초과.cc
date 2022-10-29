#include <iostream>
using namespace std;

string a = "O(N)";
string b = "O(N^2)";
string c = "O(N^3)";
string d = "O(2^N)";
string e = "O(N!)";

int C;
string S;
unsigned long long N, T, L;
unsigned long long factorial[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	factorial[0] = 1;
	for (int i = 1; i <= 1000000; i++) factorial[i] = min(factorial[i - 1] * i, 100000000000ULL);
	cin >> C;
	while (C--) {
		cin >> S;
		cin >> N >> T >> L;
		unsigned long long max_oper = L * 100000000ULL;		
		if (S == a) {
			if (N * T > max_oper) cout << "TLE!\n";
			else cout << "May Pass.\n";
		}
		else if (S == b) {
			if (N * N * T > max_oper) cout << "TLE!\n";
			else cout << "May Pass.\n";
		}
		else if (S == c) {
			if (N * N * N * T > max_oper) cout << "TLE!\n";
			else cout << "May Pass.\n";
		}
		else if (S == d) {
			int flag = 0;
			unsigned long long temp = 1;
			for (int i = 1; i <= N; i++) {
				temp *= 2;
				if (temp * T > max_oper) {
					cout << "TLE!\n";
					flag = 1;
					break;
				}
			}
			if (flag == 0) cout << "May Pass.\n";
		}
		else {
			if (factorial[N] * T > max_oper) cout << "TLE!\n";
			else cout << "May Pass.\n";
		}
	}
	return 0;
}