# [Diamond V] 지사 배정 - 12766 

[문제 링크](https://www.acmicpc.net/problem/12766) 

### 성능 요약

메모리: 199672 KB, 시간: 644 ms

### 분류

그래프 이론, 데이크스트라, 분할 정복, 다이나믹 프로그래밍, 분할 정복을 사용한 최적화, 누적 합, 최단 경로

### 제출 일자

2024년 4월 16일 11:17:36

### 문제 설명

<p>The Innovative Consumer Products Company (ICPC) is planning to start a top-secret project. This project consists of s subprojects. There will be b ≥ s branches of ICPC involved in this project and ICPC wants to assign each branch to one of the subprojects. In other words, the branches will form s disjoint groups, with each group in charge of a subproject.</p>

<p>At the end of each month, each branch will send a message to every other branch in its group (a different message to each branch). ICPC has a particular protocol for its communications. Each branch i has a secret key k<sub>i</sub> known only to the branch and the ICPC headquarters. Assume branch i wants to send a message to branch j. Branch i encrypts its message with its key k<sub>i</sub>. A trusted courier picks up this message from this branch and delivers it to the ICPC headquarters. Headquarters decrypts the message with key k<sub>i</sub> and re-encrypts it with key k<sub>j</sub>. The courier then delivers this newly encrypted message to branch j, which decrypts it with its own key k<sub>j</sub>. For security reasons, a courier can carry only one message at a time.</p>

<p>Given a road network and the locations of branches and the headquarters in this network, your task is to determine the minimum total distance that the couriers will need to travel to deliver all the end-of-month messages, over all possible assignments of branches to subprojects.</p>

### 입력 

 <p>The first line of input contains four integers n, b, s, and r, where n (2 ≤ n ≤ 5 000) is the number of intersections, b (1 ≤ b ≤ n − 1) is the number of branches, s (1 ≤ s ≤ b) is the number of subprojects, and r (1 ≤ r ≤ 50 000) is the number of roads. The intersections are numbered from 1 through n. The branches are at intersections 1 through b, and the headquarters is at intersection b + 1. Each of the next r lines contains three integers u, v, and ℓ, indicating a one-way road from intersection u to a different intersection v (1 ≤ u, v ≤ n) of length ℓ (0 ≤ ℓ ≤ 10 000). No ordered pair (u, v) appears more than once, and from any intersection it is possible to reach every other intersection.</p>

### 출력 

 <p>Display the minimum total distance that the couriers will need to travel.</p>

