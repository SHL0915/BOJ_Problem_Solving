#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int G, P, ans;
vector <int> validGate;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) validGate.push_back(i);
	for (int i = 0; i < P; i++) {
		int g;
		cin >> g;
		if (validGate.size() == 0) break;
		int idx = upper_bound(validGate.begin(), validGate.end(), g) - validGate.begin();
		if (idx == 0) break;
		else {
			validGate.erase(validGate.begin() + idx - 1);
			ans++;
		}
	}
	cout << ans;
	return 0;
}