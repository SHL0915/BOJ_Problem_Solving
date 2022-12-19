#include <bits/stdc++.h>
using namespace std;

int T;
string arr[20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int flag = 0, cnt = 0;
		map <string, int> m;
		for (int i = 0; i < 4; i++) {
			cin >> arr[i];
			m[arr[i]] ++;
		}
		for (auto i = m.begin(); i != m.end(); i++) {
			if ((*i).second >= 3) flag = 1;
			else if ((*i).second == 2) cnt++;
		}
		if (cnt == 2) flag = 1;
		if (flag == 1) {
			cout << ":)\n";
			continue;
		}
		int mm = 0, pp = 0, ss = 0;
		for (int i = 0; i < 4; i++) {
			switch (arr[i][1]) {
			case 'm': mm++; break;
			case 'p': pp++; break;
			case 's': ss++; break;
			}
		}
		vector<int> v;
		if (mm >= 3) {
			for (int i = 0; i < 4; i++) if (arr[i][1] == 'm') v.push_back(arr[i][0] - '0');
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			if (v.size() >= 3) {
				for (int i = 1; i < v.size() - 1; i++) {
					if ((v[i] == v[i - 1] + 1) && (v[i + 1] == v[i] + 1)) flag = 1;
				}
			}
		}
		else if (pp >= 3) {
			for (int i = 0; i < 4; i++) if (arr[i][1] == 'p') v.push_back(arr[i][0] - '0');
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			if (v.size() >= 3) {
				for (int i = 1; i < v.size() - 1; i++) {
					if ((v[i] == v[i - 1] + 1) && (v[i + 1] == v[i] + 1)) flag = 1;
				}
			}
		}
		else if (ss >= 3) {
			for (int i = 0; i < 4; i++) if (arr[i][1] == 's') v.push_back(arr[i][0] - '0');
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			if (v.size() >= 3) {
				for (int i = 1; i < v.size() - 1; i++) {
					if ((v[i] == v[i - 1] + 1) && (v[i + 1] == v[i] + 1)) flag = 1;
				}
			}
		}
		if (flag == 1) {
			cout << ":)\n";
			continue;
		}
		cout << ":(\n";
	}
	return 0;
}