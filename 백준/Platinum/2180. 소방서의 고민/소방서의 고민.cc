#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, t, f_index;
int fire[200000][2];
int temp[200000][2];

void MergeSort(int Arr[200000][2], int temp[200000][2], int left, int right_end);
void Merge(int Arr[200000][2], int temp[200000][2], int left, int right, int right_end);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			ans += b;
			ans %= 40000;
		}
		else if (b == 0) continue;
		else {
			fire[f_index][0] = a;
			fire[f_index++][1] = b;
		}
	}
	MergeSort(fire, temp, 0, f_index - 1);	
	for (int i = 0; i < f_index; i++) {
		ans += (fire[i][0] * t + fire[i][1]) % 40000;
		ans %= 40000;
		t += (fire[i][0] * t + fire[i][1]) % 40000;
		t %= 40000;
	}
	cout << ans;
	return 0;
}

void MergeSort(int Arr[200000][2], int temp[200000][2], int left, int right_end) {
	int mid = (left + right_end) / 2;
	if (left < right_end) {
		MergeSort(Arr, temp, left, mid);
		MergeSort(Arr, temp, mid + 1, right_end);
		Merge(Arr, temp, left, mid + 1, right_end);
	}
}

void Merge(int Arr[200000][2], int temp[200000][2], int left, int right, int right_end) {
	int i, j, pos;
	i = left;
	j = right;
	pos = left;
	while (i < right && j <= right_end) {
		if((Arr[i][1] / (double)Arr[i][0]) <= (Arr[j][1]/ (double)Arr[j][0])){
			temp[pos][0] = Arr[i][0];
			temp[pos++][1] = Arr[i++][1];
		}
		else {
			temp[pos][0] = Arr[j][0];
			temp[pos++][1] = Arr[j++][1];
		}
	}
	while (i < right) {
		temp[pos][0] = Arr[i][0];
		temp[pos++][1] = Arr[i++][1];
	}
	while (j <= right_end) {
		temp[pos][0] = Arr[j][0];
		temp[pos++][1] = Arr[j++][1];
	}
	for (int i = left; i <= right_end; i++) {
		Arr[i][0] = temp[i][0];
		Arr[i][1] = temp[i][1];
	}
}
