#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
int map[50][50];
vector <pair<int, int>> cloud;

void func();
bool bug(int x, int y);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
	cloud.push_back({ 0,N - 1 });
	cloud.push_back({ 1,N - 1 });
	cloud.push_back({ 0,N - 2 });
	cloud.push_back({ 1,N - 2 });
	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;	
		if (d == 1) for (int i = 0; i < cloud.size(); i++) cloud[i] = { (cloud[i].first - s + 500 * N) % N, cloud[i].second };		
		else if (d == 2) for (int i = 0; i < cloud.size(); i++) cloud[i] = { (cloud[i].first - s + 500 * N) % N, (cloud[i].second - s + 500 * N) % N };
		else if (d == 3) for (int i = 0; i < cloud.size(); i++) cloud[i] = { cloud[i].first, (cloud[i].second - s + 500 * N) % N };
		else if (d == 4) for (int i = 0; i < cloud.size(); i++) cloud[i] = { (cloud[i].first + s + 500 * N) % N, (cloud[i].second - s + 500 * N) % N };
		else if (d == 5) for (int i = 0; i < cloud.size(); i++) cloud[i] = { (cloud[i].first + s + 500 * N) % N, cloud[i].second };
		else if (d == 6) for (int i = 0; i < cloud.size(); i++) cloud[i] = { (cloud[i].first + s + 500 * N) % N, (cloud[i].second + s + 500 * N) % N };
		else if (d == 7) for (int i = 0; i < cloud.size(); i++) cloud[i] = { cloud[i].first, (cloud[i].second + s + 500 * N) % N };
		else for (int i = 0; i < cloud.size(); i++) cloud[i] = { (cloud[i].first - s + 500 * N) % N, (cloud[i].second + s + 500 * N) % N };
		func();
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) sum += map[i][j];
	}
	cout << sum;
	return 0;
}

void func() {
	for (int i = 0; i < cloud.size(); i++) map[cloud[i].second][cloud[i].first] ++;
	for (int i = 0; i < cloud.size(); i++) {
		int cnt = 0;
		if (bug(cloud[i].first - 1, cloud[i].second - 1) == true) cnt++;
		if (bug(cloud[i].first - 1, cloud[i].second + 1) == true) cnt++;
		if (bug(cloud[i].first + 1, cloud[i].second - 1) == true) cnt++;
		if (bug(cloud[i].first + 1, cloud[i].second + 1) == true) cnt++;
		map[cloud[i].second][cloud[i].first] += cnt;
	}
	set <pair<int,int>> s;
	for (int i = 0; i < cloud.size(); i++) s.insert({ cloud[i].first,cloud[i].second });
	cloud.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s.count({ j, i }) != 0) continue;
			if (map[i][j] >= 2) {
				map[i][j] -= 2;
				cloud.push_back({ j,i });
			}
		}
	}
}

bool bug(int x, int y) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return false;
	if (map[y][x] > 0) return true;
	else return false;
}