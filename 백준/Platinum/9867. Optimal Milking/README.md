# [Platinum II] Optimal Milking - 9867 

[문제 링크](https://www.acmicpc.net/problem/9867) 

### 성능 요약

메모리: 7020 KB, 시간: 40 ms

### 분류

자료 구조, 분할 정복, 세그먼트 트리

### 문제 설명

<p>Farmer John has recently purchased a new barn containing N milking machines (1 <= N <= 40,000), conveniently numbered 1..N and arranged in a row.</p><p>Milking machine i is capable of extracting M(i) units of milk per day (1 <= M(i) <= 100,000).  Unfortunately, the machines were installed so close together that if a machine i is in use on a particular day, its two neighboring machines cannot be used that day (endpoint machines have only one neighbor, of course).  Farmer John is free to select different subsets of machines to operate on different days.</p><p>Farmer John is interested in computing the maximum amount of milk he can extract over a series of D days (1 <= D <= 50,000).  At the beginning of each day, he has enough time to perform maintenance on one selected milking machine i, thereby changing its daily milk output M(i) from that day forward. Given a list of these daily modifications, please tell Farmer John how much milk he can produce over D days (note that this number might not fit into a 32-bit integer).</p>

### 입력 

 <ul><li>Line 1: The values of N and D.</li><li>Lines 2..1+N: Line i+1 contains the initial value of M(i).</li><li>Lines 2+N..1+N+D: Line 1+N+d contains two integers i and m, indicating that Farmer John updates the value of M(i) to m at the beginning of day d.</li></ul>

### 출력 

 <ul><li>Line 1: The maximum total amount of milk FJ can produce over D days.</li></ul>

