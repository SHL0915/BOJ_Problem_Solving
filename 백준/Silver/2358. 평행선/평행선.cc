#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
int arr[100000][2];
vector <int> x_val, y_val;
int x_pos[100000];
int y_pos[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {	
		cin >> arr[i][0] >> arr[i][1];
		x_val.push_back(arr[i][0]);
		y_val.push_back(arr[i][1]);
	}
	sort(x_val.begin(), x_val.end());
	sort(y_val.begin(), y_val.end());
	x_val.erase(unique(x_val.begin(), x_val.end()), x_val.end());
	y_val.erase(unique(y_val.begin(), y_val.end()), y_val.end());
	for (int i = 0; i < N; i++) {
		x_pos[lower_bound(x_val.begin(), x_val.end(), arr[i][0]) - x_val.begin()]++;
		y_pos[lower_bound(y_val.begin(), y_val.end(), arr[i][1]) - y_val.begin()]++;
	}	
	for (int i = 0; i < x_val.size(); i++) if (x_pos[i] >= 2) ans++;
	for (int i = 0; i < y_val.size(); i++) if (y_pos[i] >= 2) ans++;
	cout << ans;
	return 0;
}