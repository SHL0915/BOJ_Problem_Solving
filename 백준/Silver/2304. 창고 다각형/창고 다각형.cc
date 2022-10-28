#include <iostream>
#include <algorithm>
using namespace std;

int N, max_height, left_pillar, right_pillar, ans;
pair <int, int> pillar[1000];



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int pos, height;
		cin >> pos >> height;
		pillar[i] = { pos,height };
		max_height = max(max_height, pillar[i].second);
	}
	sort(pillar, pillar + N);
	for (int i = 1; i < N; i++) {
		if (pillar[i].second >= pillar[left_pillar].second) {
			ans += (pillar[i].first - pillar[left_pillar].first) * pillar[left_pillar].second;
			left_pillar = i;
		}
	}
	right_pillar = N - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (pillar[i].second > pillar[right_pillar].second) {
			ans += (pillar[right_pillar].first - pillar[i].first) * pillar[right_pillar].second;
			right_pillar = i;
		}
	}
	ans += max_height;
	cout << ans;
	return 0;
}