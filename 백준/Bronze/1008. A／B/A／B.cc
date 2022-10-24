#include <iostream>
using namespace std;

int A, B;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(20);
	cin >> A >> B;
	cout << double(A) / B;
	return 0;	
}