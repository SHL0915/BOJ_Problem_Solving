#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, flag;
vector <ll> parent_A, parent_B;

ll findParent(ll N);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> a >> b;
	flag = 0;
	parent_A.push_back(a);
	while (1) {
		a = findParent(a);
		if (flag == 1) break;
		parent_A.push_back(a);
	}
	parent_A.push_back(1);
	flag = 0;
	parent_B.push_back(b);
	while (1) {
		b = findParent(b);
		if (flag == 1) break;
		parent_B.push_back(b);
	}
	parent_B.push_back(1);
	int lptr = 0, rptr = 0;
	while (1) {
		if (parent_A[lptr] == parent_B[rptr]) {
			cout << parent_A[lptr];
			return 0;
		}
		else if (parent_A[lptr] > parent_B[rptr]) lptr++;
		else rptr++;
	}
	return 0;
}

ll findParent(ll N) {
	ll ret = 1;
	for (ll i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			ret = i;
			break;
		}
	}
	if (ret == 1) flag = 1;
	return N / ret;
}