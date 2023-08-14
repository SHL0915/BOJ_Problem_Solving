# [Platinum III] Running Away From the Barn - 5862 

[문제 링크](https://www.acmicpc.net/problem/5862) 

### 성능 요약

메모리: 73444 KB, 시간: 256 ms

### 분류

자료 구조, 작은 집합에서 큰 집합으로 합치는 테크닉

### 문제 설명

<p>It's milking time at Farmer John's farm, but the cows have all run away! Farmer John needs to round them all up, and needs your help in the search.</p><p>FJ's farm is a series of N (1 <= N <= 200,000) pastures numbered 1...N connected by N - 1 bidirectional paths. The barn is located at pasture 1, and it is possible to reach any pasture from the barn.</p><p>FJ's cows were in their pastures this morning, but who knows where they ran to by now. FJ does know that the cows only run away from the barn, and they are too lazy to run a distance of more than L. For every pasture, FJ wants to know how many different pastures cows starting in that pasture could have ended up in.</p><p>Note: 64-bit integers (int64 in Pascal, long long in C/C++ and long in Java) are needed to store the distance values.</p>

### 입력 

 <ul><li>Line 1: 2 integers, N and L (1 <= N <= 200,000, 1 <= L <= 10^18)</li><li>Lines 2..N: The ith line contains two integers p_i and l_i. p_i (1 <= p_i < i) is the  first pasture on the shortest path between pasture i and the barn, and l_i  (1 <= l_i <= 10^12) is the length of that path.</li></ul>

### 출력 

 <ul><li>Lines 1..N: One number per line, the number on line i is the number pastures that can be  reached from pasture i by taking roads that lead strictly farther away from  the barn (pasture 1) whose total length does not exceed L.</li></ul>

