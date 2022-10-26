#include <iostream>
using namespace std;

int H, W, left_wall, right_wall, temp, ans;
int height[500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> H >> W;
	for (int i = 0; i < W; i++) cin >> height[i];	
	for(int i = 0; i < W; i++){
		if (height[i] >= left_wall) {
			left_wall = height[i];
			ans += temp;
			temp = 0;
		}
		else temp += (left_wall - height[i]);
	}
	temp = 0;
	for (int i = W - 1; i >= 0; i--) {
		if (height[i] > right_wall) {
			right_wall = height[i];
			ans += temp;
			temp = 0;
		}
		else temp += (right_wall - height[i]);
	}
	cout << ans;
	return 0;
}