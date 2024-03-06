# [Platinum IV] Not One - 26855 

[문제 링크](https://www.acmicpc.net/problem/26855) 

### 성능 요약

메모리: 35864 KB, 시간: 988 ms

### 분류

자료 구조, 깊이 우선 탐색, 분리 집합, 그래프 이론, 그래프 탐색, 수학, 정수론, 트리

### 제출 일자

2024년 3월 6일 16:34:20

### 문제 설명

<p>The greatest common divisor (GCD) of a set of positive integers S is defined as the largest positive integer d such that d is a divisor for all elements in S, e.g., GCD(10) = 10, GCD(6, 9) = 3, GCD(20, 12, 16, 36) = 4.</p>

<p>In this problem, you are given a tree of N nodes where each node is numbered from 1 to N and has a positive integer Ai assigned to it. Your task is to find the size of the largest subtree such that the GCD of the weight of all nodes in that subtree is not 1, or output 0 if there is no such a subtree. A tree T' is a subtree of T if and only if T' is connected and is a subset of T. The size of a subtree is the number of nodes in that subtree.</p>

<p>For example, consider the following tree of N = 7 nodes where A<sub>1..7</sub> = {10, 5, 8, 6, 10, 6, 4}.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d4b1f28b-b6db-4012-a97f-94f46ab6230e/-/preview/" style="width: 300px; height: 213px;"></p>

<p>In this example, there are 15 subtrees where the GCD of all its nodes’ weight is not 1, i.e. seven subtrees of size 1, four subtrees of size 2, three subtrees of size 3, and one subtree of size 4 (the largest). The largest subtree contains nodes 4, 5, 6, and 7, and the GCD of their weights is GCD(A<sub>4</sub>, A<sub>5</sub>, A<sub>6</sub>, A<sub>7</sub>) = GCD(6, 10, 6, 4) = 2.</p>

### 입력 

 <p>Input begins with a line containing an integer N (2 ≤ N ≤ 100 000) representing the number of nodes in the given tree. The next line contains N integers A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ 10<sup>6</sup>) representing the weight of the i<sup>th</sup> node. The next N − 1 line each contains two integers u<sub>j</sub> v<sub>j</sub> (1 ≤ u<sub>j</sub> < v<sub>j</sub> ≤ N) representing an edge connecting node u<sub>j</sub> and node v<sub>j</sub>. It is guaranteed that the given tree is connected.</p>

### 출력 

 <p>Output contains an integer in a line representing the size of the largest subtree such that the GCD of all its nodes’ weight is not 1. If there is no such a subtree, output 0 in a line.</p>

