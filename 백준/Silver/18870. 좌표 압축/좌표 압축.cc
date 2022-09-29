#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, input;
vector <int> x_pos, x_coor;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		x_coor.push_back(input);
		x_pos.push_back(input);
	}
	sort(x_pos.begin(), x_pos.end());
	x_pos.erase(unique(x_pos.begin(), x_pos.end()), x_pos.end());
	for (int i = 0; i < N; i++) 
		cout << lower_bound(x_pos.begin(), x_pos.end(), x_coor[i]) - x_pos.begin() << " ";
	return 0;
}