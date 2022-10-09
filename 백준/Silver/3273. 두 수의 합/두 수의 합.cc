#include <iostream>
#include <algorithm>
using namespace std;

int n, x, s_ptr, e_ptr, ans;
int sequence[100000];

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> sequence[i];
	sort(sequence, sequence + n);
	cin >> x;
	s_ptr = 0;
	e_ptr = n - 1;
	while (1) {
		if (s_ptr == e_ptr) break;
		if (sequence[s_ptr] + sequence[e_ptr] == x) {
			ans++;
			e_ptr--;
		}
		else if (sequence[s_ptr] + sequence[e_ptr] < x) s_ptr++;
		else e_ptr--;
	}
	cout << ans;
	return 0;	
}