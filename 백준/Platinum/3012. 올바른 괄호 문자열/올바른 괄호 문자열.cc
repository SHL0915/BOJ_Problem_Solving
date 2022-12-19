#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000LL;

int N;
string S;
long long table[201][201];

long long DP(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(table, -1, sizeof(table));
	cin >> N;
	cin >> S;
	long long ans = DP(0, N - 1);
	if (ans < mod) cout << ans;
	else {
		printf("%05lld\n", ans % mod);
	}
	return 0;
}

long long DP(int left, int right) {
	if (left > right) return 1;
	long long& ret = table[left][right];
	if (ret != -1) return ret;
	ret = 0;
	char s = S[left];
	if (s != '(' && s != '[' && s != '{' && s != '?') return ret;
	for (int i = left + 1; i <= right; i++) {
		if (S[i] == ')') {
			if (s == '(' || s == '?') {
				long long temp = DP(left + 1, i - 1) * DP(i + 1, right);
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
			}
		}
		else if (S[i] == ']') {
			if (s == '[' || s == '?') {
				long long temp = DP(left + 1, i - 1) * DP(i + 1, right);
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
			}
		}
		else if (S[i] == '}') {
			if (s == '{' || s == '?') {
				long long temp = DP(left + 1, i - 1) * DP(i + 1, right);
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
			}
		}
		else if (S[i] == '?') {
			if (s == '(' || s == '[' || s == '{') {
				long long temp = DP(left + 1, i - 1) * DP(i + 1, right);
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
			}
			else if (s == '?') {
				long long temp = DP(left + 1, i - 1) * DP(i + 1, right);
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
				ret += temp;
				if (ret >= mod) ret = mod + ret % mod;
			}
		}
	}
	return ret;
}