#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, x_index, y_index, ans = 0;
pair <int, int> point[5000];
int x_pos[5000];
int y_pos[5000];
int temp[5000];
int coor[5000][5000];

int compress(int* Arr);
int BinarySearch(int* Arr, int left, int right, int data);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x_pos[i] >> y_pos[i];
		point[i].first = x_pos[i];
		point[i].second = y_pos[i];
	}
	sort(x_pos, x_pos + N);
	sort(y_pos, y_pos + N);
	x_index = compress(x_pos);
	y_index = compress(y_pos);
	for (int i = 0; i < N; i++) {
		point[i].first = BinarySearch(x_pos, 0, x_index, point[i].first);
		point[i].second = BinarySearch(y_pos, 0, y_index, point[i].second);
		coor[point[i].second][point[i].first] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (point[i].first == point[j].first || point[i].second == point[j].second)
				continue;			
			if (coor[point[i].second][point[j].first] == 1 && coor[point[j].second][point[i].first])
				ans++;
		}
	}
	cout << ans/2;
	return 0;
}

int compress(int* Arr) {
	int i = 1, j = N-1;
	temp[0] = Arr[0];
	for (int k = 1; k < N; k++) {
		if (Arr[k] != Arr[k - 1]) 
			temp[i++] = Arr[k];		
		else 
			temp[j--] = Arr[k];		
	}
	for (int k = 0; k < N; k++)
		Arr[k] = temp[k];
	return j;
}

int BinarySearch(int* Arr, int left, int right, int data) {
	if (left < right) {
		int mid = (left + right) / 2;
		if (Arr[mid] == data) {
			return mid;
		}
		else if (Arr[mid] > data)
			return BinarySearch(Arr, left, mid - 1, data);
		else
			return BinarySearch(Arr, mid + 1, right, data);		
	}
	return left;
}