# [Gold II] 롤러코스터 타기 - 3958 

[문제 링크](https://www.acmicpc.net/problem/3958) 

### 성능 요약

메모리: 12708 KB, 시간: 208 ms

### 분류

다이나믹 프로그래밍, 수학

### 제출 일자

2025년 1월 31일 09:03:49

### 문제 설명

<p>Jimmy and his friends like to visit large theme parks. In the current theme park there are many roller coasters which then are categorized by Jimmy. He assigns a fun value to each coaster; however, the fun decreases with each run.</p>

<p>More formal: for a speci fic roller coaster i, Jimmy assigns two fun coefficients ai and bi. While riding this roller coaster for the k-th time, Jimmy gains a fun value of f(i, k) = ai - (k - 1)<sup>2</sup> × bi. If f(i, k) is non-positive, riding the roller coaster is no longer funny.</p>

<p>Jimmy tries to maximize the total fun until he leaves the park. Can you tell Jimmy how much fun he can gain for a given time?</p>

### 입력 

 <p>The input consists of a single test case.</p>

<p>The fi rst line contains the integer N, where N is the amount of different roller coasters in the theme park (0 < N ≤ 100).</p>

<p>The following N lines contain the integers a<sub>i</sub>, b<sub>i</sub> and t<sub>i</sub> where a<sub>i</sub> and b<sub>i</sub> are the fun coefficients as specifi ed above and ti is the time for a single ride with the i-th roller coaster (0 ≤ a<sub>i</sub> ≤ 1 000, 0 ≤ b<sub>i</sub> ≤ 1 000; 0 < t<sub>i</sub> ≤ 25 000).</p>

<p>The next line contains a positive integer Q denoting the number of times that Jimmy is visiting the park (0 ≤ Q ≤ 1 000). Each of the following Q lines contains an integral time T<sub>i</sub> that Jimmy spends during his i-th visit (0 ≤ T<sub>i</sub> ≤ 25 000).</p>

### 출력 

 <p>For each of the Q possible times, print one line containing the maximal total fun value if Jimmy spends T<sub>i</sub> minutes in the theme park.</p>

