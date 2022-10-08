#include <iostream>
using namespace std;

int N;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) cout << " ";
		for (int j = 0; j < 2 * N - 1 - 2 * i; j++) cout << "*";		
		cout << "\n";
	}
	return 0;
}