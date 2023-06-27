# [Gold I] 혼란 - 3037 

[문제 링크](https://www.acmicpc.net/problem/3037) 

### 성능 요약

메모리: 2176 KB, 시간: 56 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 문제 설명

<p>Consider a sequence of N integers where each integer between 1 and N appears exactly once. </p>

<p>A pair of numbers in the sequence is confused if the number that comes earlier in the sequence is larger than the later number. </p>

<p>The confusion of the sequence is the number of confused pairs in it. For example, the confusion of the sequence (1, 4, 3, 2) is 3 because there are 3 confused pairs: (4, 3), (4, 2) and (3, 2). </p>

<p>Write a program that calculates the number of sequences of length N whose confusion is exactly C. </p>

### 입력 

 <p>The first and only line of input contains two integers, N (1 ≤ N ≤ 1000) and C (0 ≤ C ≤ 10000). </p>

<p> </p>

### 출력 

 <p>Output the number of sequences modulo 1000000007. </p>

<p> </p>

