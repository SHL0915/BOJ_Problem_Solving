#include <iostream>
using namespace std;

int main(void) {
	long long n, sum;
	while (true) {
		sum = 1;		
		cin >> n;
		if (cin.eof() == true)
			break;		
		for (int i = 1; ; i++) {			
			if (sum % n == 0) {
				cout << i << endl;
				break;
			}
			sum = sum * 10 + 1;
			sum %= n;
		}
	}
}