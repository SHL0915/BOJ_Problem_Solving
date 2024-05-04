# [Platinum III] 버스 - 1161 

[문제 링크](https://www.acmicpc.net/problem/1161) 

### 성능 요약

메모리: 3496 KB, 시간: 24 ms

### 분류

자료 구조, 그리디 알고리즘, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 5월 4일 23:01:43

### 문제 설명

<p>Although Farmer John has no problems walking around the fair to collect prizes or see the shows, his cows are not in such good shape; a full day of walking around the fair leaves them exhausted. To help them enjoy the fair, FJ has arranged for a shuttle truck to take the cows from place to place in the fairgrounds.</p>

<p>FJ couldn't afford a really great shuttle, so the shuttle he rented traverses its route only once (!) and makes N (1 <= N <= 20,000) stops (conveniently numbered 1..N) along its path. A total of K (1 <= K <= 50,000) groups of cows conveniently numbered 1..K wish to use the shuttle, each of the M_i (1 <= M_i <= N) cows in group i wanting to ride from one stop S_i (1 <= S_i < E_i) to another stop E_i (S_i < E_i <= N) farther along the route.</p>

<p>The shuttle might not be able to pick up an entire group of cows (since it has limited capacity) but can pick up partial groups as appropriate.</p>

<p>Given the capacity C (1 <= C <= 100) of the shuttle truck and the descriptions of the groups of cows that want to visit various sites at the fair, determine the maximum number of cows that can ride the shuttle during the fair.</p>

### 입력 

 <p>* Line 1: Three space-separated integers: K, N, and C</p>

<p>* Lines 2..K+1: Line i+1 describes group i of the cows with three space-separated integers: S_i, E_i, and M_i</p>

### 출력 

 <p>* Line 1: The maximum number of cows that can ride the shuttle at the fair.</p>

