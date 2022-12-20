#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, ans = -INF;
string s;
vector <ll> num;
int bt[20];

void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i % 2) {
			switch (s[i]) {
			case '+': num.push_back(0); break;
			case '-': num.push_back(1); break;
			case '*': num.push_back(2); break;
			}
		}
		else num.push_back(s[i] - '0');
	}
	BackTracking(1);
	cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k >= N) {
		vector<ll> ret;	
		ret.push_back(num[0]);
		for (int i = 1; i < N; i += 2) {
			if (bt[i] == 0) {
				ret.push_back(num[i]);
				ret.push_back(num[i + 1]);
			}
			else {
				ll result = ret.back();
				ret.pop_back();
				switch (num[i]) {
				case 0: result += num[i + 1]; break;
				case 1: result -= num[i + 1]; break;
				case 2: result *= num[i + 1]; break;
				}
				ret.push_back(result);
			}
		}
		vector <ll> ret2;
		ret2.push_back(ret[0]);
		for (int i = 1; i < ret.size(); i += 2) {
			if (ret[i] != 2) {
				ret2.push_back(ret[i]);
				ret2.push_back(ret[i + 1]);
			}
			else {
				ll result = ret2.back() * ret[i + 1];
				ret2.pop_back();
				ret2.push_back(result);
			}
		}
		ll result = ret2[0];
		for (int i = 1; i < ret2.size(); i += 2) {
			switch(ret2[i]) {
			case 0: result += ret2[i + 1]; break;
			case 1: result -= ret2[i + 1]; break;
			}
		}
		ans = max(ans, result);
	}
	else {
		BackTracking(k + 2);
		bt[k] = 1;
		BackTracking(k + 4);
		bt[k] = 0;
	}
}