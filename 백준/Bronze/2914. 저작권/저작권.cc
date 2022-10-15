#include <iostream>
using namespace std;

int A, I;

int main(void) {
	cin >> A >> I;
	if (A == 1) cout << I;
	else cout << (A * (I - 1)) + 1;	
	return 0;
}