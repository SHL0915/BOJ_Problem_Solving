#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	queue<int> Q;
	int n, w, L, weight = 0, time = 0, truck;
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> truck;
		if (Q.size() < w) {
			if (truck + weight > L) {
				while (Q.size() < w) {
					Q.push(0);					
					time++;
				}
				while (truck + weight - Q.front() > L) {
					weight -= Q.front();
					Q.pop();
					Q.push(0);					
					time++;
				}
				weight -= Q.front();
				Q.pop();
				Q.push(truck);				
				weight += truck;
				time++;
			}
			else {
				Q.push(truck);				
				weight += truck;
				time++;
			}
		}
		else {
			while (truck + weight - Q.front() > L) {
				weight -= Q.front();
				Q.pop();
				Q.push(0);
				time++;
			}
			weight -= Q.front();
			Q.pop();
			Q.push(truck);
			weight += truck;
			time++;
		}
	}
	time += w - Q.size();
	while (Q.size() != 0) {
		Q.pop();
		time++;
	}
	cout << time;
	return 0;
}