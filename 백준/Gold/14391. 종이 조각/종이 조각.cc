#include <iostream>
using namespace std;

int max_num = -1, sum;

void BF(int** mark, char** Arr, int N, int M, int k);

int main(void) {
	int N, M, i, j;
	cin >> N >> M;
	char** Arr = new char*[N];
	int** mark = new int* [N];
	for (i = 0; i < N; i++) {
		Arr[i] = new char[M];
		mark[i] = new int[M];
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> Arr[i][j];			
		}
	}
	BF(mark, Arr, N, M, 0);
	cout << max_num;
	return 0;	
}

void BF(int** mark, char** Arr, int N, int M, int k) {
	int i, j, temp, l;	
	if (k == N * M) {			
		int** visited = new int* [N];
		for (i = 0; i < N; i++) {
			visited[i] = new int[M];
			for (j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}
		sum = 0;		
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (visited[i][j] == 0) {
					visited[i][j] = 1;
					temp = Arr[i][j] - '0';
					l = 1;
					if (mark[i][j] == 0) { // 가로
						while (1) {
							if (j + l >= M)
								break;
							if (mark[i][j + l] == 1)
								break;
							visited[i][j + l] = 1;
							temp = temp * 10;
							temp += Arr[i][j + l] - '0';
							l++;
						}
					}
					else { // 세로
						while (1) {
							if (i + l >= N)
								break;
							if (mark[i + l][j] == 0)
								break;
							visited[i + l][j] = 1;
							temp = temp * 10;
							temp += Arr[i + l][j] - '0';
							l++;
						}
					}
					sum += temp;
				}
			}
		}			
		if (sum >= max_num)
			max_num = sum;
		for (i = 0; i < N; i++) {
			delete[]visited[i];
		}
		delete[]visited;
	}
	else {
		for (i = 0; i < 2; i++) {
			mark[k / M][k % M] = i;
			BF(mark, Arr, N, M, k + 1);
		}
	}
}