#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

bool cmp(int A, int B) {
	return A < B;
}

int main(void) {
	int N, cnt = 0, i, j, k;
	cin >> N;
	int* Arr = new int[N];
	int* Sorted = new int[N];	
	int** dq = new int* [N];
	for (i = 0; i < N; i++) {
		dq[i] = new int[2];
		cin >> Arr[i];
		Sorted[i] = Arr[i];
	}
	stable_sort(Sorted, Sorted + N, cmp);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (Sorted[j] == Arr[i]) {
				k = j;
				break;
			}
		}
		for (j = 0; j < cnt; j++) {
			if (k == dq[j][0] - 1) {
				dq[j][0] = k;
				break;
			}
			else if (k == dq[j][1] + 1) {
				dq[j][1] = k;
				break;
			}
		}
		if (j == cnt) {			
			dq[cnt][0] = k;
			dq[cnt][1] = k;
			cnt++;
		}		
	}	
	cout << cnt;
	return 0;
}