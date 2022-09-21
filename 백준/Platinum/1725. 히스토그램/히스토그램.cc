#include <iostream>
#include <stack>
using namespace std;

struct stackData {
	int height, index;
};

int main(void) {
	int N, data, i, max = -1, temp;
	cin >> N;
	stack <stackData> s;
	for (i = 0; i < N; i++) {
		cin >> data;
		if (s.size() == 0) s.push({ data,i });
		else if (data > s.top().height) s.push({ data,i });
		else if (data < s.top().height) {
			while (1) {
				if (max <= s.top().height * (i - s.top().index)) {
					max = s.top().height * (i - s.top().index);
				}
				temp = s.top().index;
				s.pop();
				if (s.size() == 0) {
					s.push({ data,0 });
					break;
				}
				else if (s.top().height == data)
					break;
				else if (s.top().height < data) {
					s.push({ data,temp });
					break;
				}
			}
		}
	}
	while (s.size()) {
		if (max <= s.top().height * (N - s.top().index)) {
			max = s.top().height * (N - s.top().index);
		}
		s.pop();
	}
	cout << max;
	return 0;
}