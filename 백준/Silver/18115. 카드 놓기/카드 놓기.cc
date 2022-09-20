#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	deque <int> Deque;
	int N, temp;
	cin >> N;
	int* Arr = new int[N];
	for (int i = 0; i < N; i++) 
		cin >> Arr[i];
	for (int i = N - 1; i >= 0; i--) {
		switch (Arr[i]) {
		case 1: Deque.push_back(N - i); break;
		case 2: temp = Deque.back();
			Deque.pop_back();
			Deque.push_back(N - i);
			Deque.push_back(temp);
			break;
		case 3: Deque.push_front(N - i);
		}
	}
	while (Deque.size() != 0) {		
		cout << Deque.back() << " ";
		Deque.pop_back();
	}
	return 0;
}