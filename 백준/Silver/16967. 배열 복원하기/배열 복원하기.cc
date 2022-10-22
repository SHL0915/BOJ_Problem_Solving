#include <iostream>
using namespace std;

int H, W, X, Y;
int arr[600][600];
int org[300][300];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> H >> W >> Y >> X;
	for (int i = 0; i < H + Y; i++) {
		for (int j = 0; j < W + X; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < W; j++) org[i][j] = arr[i][j];
	}	
	for (int i = Y; i < H; i++) {
		for (int j = 0; j < X; j++) org[i][j] = arr[i][j];
	}
	for (int i = Y; i < H + Y; i++) {
		for (int j = W; j < W + X; j++) org[i - Y][j - X] = arr[i][j];
	}
	for (int i = H; i < H + Y; i++) {
		for (int j = X; j < W + X; j++) org[i - Y][j - X] = arr[i][j];
	}
	for (int i = Y; i < H; i++) {
		for (int j = X; j < W; j++) org[i][j] = arr[i][j] - org[i - Y][j - X];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cout << org[i][j] << " ";
		cout << '\n';
	}
	return 0;
}