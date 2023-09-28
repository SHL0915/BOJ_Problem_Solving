# [Diamond V] 내가 어렸을 때 가지고 놀던 장난감 - 2803 

[문제 링크](https://www.acmicpc.net/problem/2803) 

### 성능 요약

메모리: 26596 KB, 시간: 836 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 부분집합의 합 다이나믹 프로그래밍, 포함 배제의 원리

### 문제 설명

<p>Mirko found N boxes with various forgotten toys at his attic. There are M different toys, numbered 1 through M, but each of those can appear multiple times across various boxes.</p>

<p>Mirko decided that he will choose some boxes in a way that there is at least one toy of each kind present, and throw the rest of the boxes away.</p>

<p>Determine the number of ways in which Mirko can do this.</p>

### 입력 

 <p>The first line of input contains two integers N and M (1 ≤ N ≤ 1 000 000, 1 ≤ M ≤ 20).</p>

<p>Each of the following N lines contains an integer K<sub>i</sub> (0 ≤ K<sub>i</sub> ≤ M) followed by K<sub>i</sub> distinct integers from interval [1, M], representing the toys in that box.</p>

### 출력 

 <p>The first and only line of output should contain the requested number of ways modulo 1 000 000 007.</p>

<p> </p>

