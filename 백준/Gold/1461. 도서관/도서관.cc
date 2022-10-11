#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans, m_index, p_index, m_ptr, p_ptr;
int mBook[50];
int pBook[50];

int findAbs(int A) {
	if (A < 0) return A * (-1);
	return A;
}

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int book;
		cin >> book;
		if (book > 0) pBook[p_index++] = book;
		else mBook[m_index++] = book;
	}
	sort(pBook, pBook + p_index);
	sort(mBook, mBook + m_index, cmp);
	p_ptr = p_index - 1;
	m_ptr = m_index - 1;
	if (p_ptr < 0) {
		ans += findAbs(mBook[m_ptr]);
		for (int i = 0; i < M; i++) m_ptr--;
	}
	else if (m_ptr < 0) {
		ans += findAbs(pBook[p_ptr]);
		for (int i = 0; i < M; i++) p_ptr--;
	}
	else {
		if (findAbs(pBook[p_ptr]) >= findAbs(mBook[m_ptr])) {
			ans += pBook[p_ptr];
			for (int i = 0; i < M; i++) p_ptr--;
		}
		else {
			ans += findAbs(mBook[m_ptr]);
			for (int i = 0; i < M; i++) m_ptr--;
		}
	}
	while (p_ptr >= 0 || m_ptr >= 0) {
		if (p_ptr < 0) {
			ans += 2 * findAbs(mBook[m_ptr]);
			for (int i = 0; i < M; i++) m_ptr--;
		}
		else if (m_ptr < 0) {
			ans += 2 * findAbs(pBook[p_ptr]);
			for (int i = 0; i < M; i++) p_ptr--;
		}
		else {
			if (findAbs(pBook[p_ptr]) >= findAbs(mBook[m_ptr])) {
				ans += 2 * pBook[p_ptr];
				for (int i = 0; i < M; i++) p_ptr--;
			}
			else {
				ans += 2 * findAbs(mBook[m_ptr]);
				for (int i = 0; i < M; i++) m_ptr--;
			}
		}
	}
	cout << ans;
	return 0;
}