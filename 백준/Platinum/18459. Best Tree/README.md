# [Platinum II] Best Tree - 18459 

[문제 링크](https://www.acmicpc.net/problem/18459) 

### 성능 요약

메모리: 2800 KB, 시간: 16 ms

### 분류

해 구성하기, 차수열, 그래프 이론, 트리

### 제출 일자

2024년 8월 30일 01:55:49

### 문제 설명

<p>You are given the degree sequence of a tree (degrees of all its vertices, in arbitrary order).</p>

<p>Among all trees with the given degree sequence, find a tree with the largest maximum matching.</p>

### 입력 

 <p>The first line of input contains one integer t (1 ≤ t ≤ 100 000): the number of testcases.</p>

<p>Next lines contain t descriptions of a test case.</p>

<p>The first line of each test case contains one integer n (2 ≤ n ≤ 200 000): the number of vertices.</p>

<p>The next line contains n integers d<sub>1</sub>, d<sub>2</sub>, . . . , d<sub>n</sub> (1 ≤ d<sub>i</sub> ≤ n − 1), the degree sequence of a tree.</p>

<p>It is guaranteed that Σd<sub>i</sub> = 2(n − 1) and that there is at least one tree with the given degree sequence.</p>

<p>Also, it is guaranteed that the total sum of n in all test cases is at most 200 000.</p>

### 출력 

 <p>For each test case, print one integer: the largest maximum matching among all trees with the given degree sequence.</p>

