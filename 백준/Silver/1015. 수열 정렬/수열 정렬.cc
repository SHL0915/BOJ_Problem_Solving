#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> Arr[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		Arr[i] = { input, i };
	}
	stable_sort(Arr, Arr + N);
	for (int i = 0; i < N; i++) {
		Arr[i] = { Arr[i].second, i };
	}
	stable_sort(Arr, Arr + N);
	for (int i = 0; i < N; i++) cout << Arr[i].second << " ";
	return 0;
}