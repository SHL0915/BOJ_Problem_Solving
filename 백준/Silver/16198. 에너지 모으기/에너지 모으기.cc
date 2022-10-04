#include <iostream>
using namespace std;

int N, ans;
int weight[10];

void BackTracking(int arr[10], int index, int energy, int n);

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	for(int i = 1; i < N - 1; i ++)
		BackTracking(weight, i, 0, N);
	cout << ans;
	return 0;
}

void BackTracking(int arr[10], int index, int energy, int n) {
	int new_energy = energy + arr[index - 1] * arr[index + 1];
	if (n == 3) {
		ans = max(ans, new_energy);
		return;
	}
	int temp[10];
	for (int i = 0; i < index; i++)
		temp[i] = arr[i];
	for (int i = index + 1; i < n; i++)
		temp[i - 1] = arr[i];
	for (int i = 1; i < n - 2; i++) {
		BackTracking(temp, i, new_energy, n - 1);
	}
}