#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N;
double x, y, xSum, ySum, xNegSum, yNegSum, minVecSum;
pair<double, double> point[20];
int Arr[20];

void BackTracking(int n, int k);

double VectorSum(double x, double y) {
	return sqrt(x * x + y * y);
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cout.precision(12);
	cout << fixed;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;		
		minVecSum = -1;
		for (int j = 0; j < N; j++)
			Arr[j] = 0;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			point[j] = { x,y };
		}		
		BackTracking(0,0);
		cout << minVecSum << "\n";
	}	
	return 0;
}

void BackTracking( int n, int k) {
	if (k == N / 2) {
		xSum = 0;
		ySum = 0;
		xNegSum = 0;
		yNegSum = 0;
		for (int i = 0; i < N; i++) {		
			if (Arr[i] == 0) {
				xSum += point[i].first;
				ySum += point[i].second;
			}
			else {
				xNegSum += point[i].first;
				yNegSum += point[i].second;
			}
		}
		if (minVecSum == -1)
			minVecSum = VectorSum(xSum - xNegSum, ySum - yNegSum);
		else
			minVecSum = min(minVecSum, VectorSum(xSum - xNegSum, ySum - yNegSum));
		return;
	}
	else if (n == N)
		return;
	else {
		for (int i = 0; i < 2; i ++) {
			if (i == 0) 
				BackTracking(n + 1, k);			
			else {
				Arr[n] = 1;
				BackTracking(n + 1, k + 1);
				Arr[n] = 0;
			}
		}
	}
}