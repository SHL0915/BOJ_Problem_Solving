#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, ans;
vector <int> x_val, y_val;
map <int, int> dots_x;
map <int, int> dots_y;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		dots_x[x]++;
		dots_y[y]++;
		x_val.push_back(x);
		y_val.push_back(y);
	}
	sort(x_val.begin(), x_val.end());
	sort(y_val.begin(), y_val.end());
	x_val.erase(unique(x_val.begin(), x_val.end()), x_val.end());
	y_val.erase(unique(y_val.begin(), y_val.end()), y_val.end());
	for (int i = 0; i < x_val.size(); i++) if (dots_x[x_val[i]] >= 2) ans++;
	for (int i = 0; i < y_val.size(); i++) if (dots_y[y_val[i]] >= 2) ans++;
	cout << ans;
	return 0;
}