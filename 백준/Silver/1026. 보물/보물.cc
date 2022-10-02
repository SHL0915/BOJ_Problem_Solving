#include <iostream>
#include <algorithm>
using namespace std;

int N, sum;
int A[50];
int B[50];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + N);
	for (int i = 0; i < N; i++)
		sum += A[i] * B[N - 1 - i];
	cout << sum;
	return 0;
}