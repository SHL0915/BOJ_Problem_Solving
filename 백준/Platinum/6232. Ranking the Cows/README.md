# [Platinum IV] Ranking the Cows - 6232 

[문제 링크](https://www.acmicpc.net/problem/6232) 

### 성능 요약

메모리: 2184 KB, 시간: 12 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 5월 22일 17:11:03

### 문제 설명

<p>Each of Farmer John's N cows (1 <= N <= 1,000) produces milk at a different positive rate, and FJ would like to order his cows according to these rates from the fastest milk producer to the slowest.</p>

<p>FJ has already compared the milk output rate for M (1 <= M <= 10,000) pairs of cows.  He wants to make a list of C additional pairs of cows such that, if he now compares those C pairs, he will definitely be able to deduce the correct ordering of all N cows.  Please help him determine the minimum value of C for which such a list is possible.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..M+1: Two space-separated integers, respectively: X and Y. Both X and Y are in the range 1...N and describe a comparison where cow X was ranked higher than cow Y.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the minimum value of C.</li>
</ul>

