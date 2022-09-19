#include <iostream>
using namespace std;

unsigned long long m;

unsigned long long pow(unsigned long long num, int n) {
	unsigned long long result = 1;
	for (int i = 0; i < n; i++) {
		result = result * num;		
	}
	return result;
}

int main(void) {	
	unsigned long long sum, i, j;
	cin >> m;	
	for (i = 3; ; i++) {		
		sum = 0;
		if (m == 1) {
			cout << "3 1";
			return 0;
		}
		if (1 + pow(2, i - 1) > m) {
			cout << "impossible";
			return 0;
		}
		for (j = 1; ; j++) {			
			sum += pow(j, i - 1);			
			if (sum == m) {
				cout << i << " " << j;
				return 0;
			}
			else if (sum > m)
				break;
		}
	}
	return 0;
}