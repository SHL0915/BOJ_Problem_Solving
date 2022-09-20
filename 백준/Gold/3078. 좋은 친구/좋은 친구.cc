#include <iostream>
using namespace std;

int main(void) {	
	long long N, K, sum = 0;
	cin >> N >> K;
	long long lenArr[21] = { 0 };
	string* Arr = new string[N];
	for (long long i = 0; i < K; i++) {
		cin >> Arr[i];
		sum += lenArr[Arr[i].length()]++;
	}
	for (long long i = K; i < N; i++) {
		cin >> Arr[i];
		sum += lenArr[Arr[i].length()]++;
		lenArr[Arr[i - K].length()] --;
	}
	cout << sum;
	return 0;	
}