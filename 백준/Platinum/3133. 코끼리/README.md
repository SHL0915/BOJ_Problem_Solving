# [Platinum I] 코끼리 - 3133 

[문제 링크](https://www.acmicpc.net/problem/3133) 

### 성능 요약

메모리: 31004 KB, 시간: 328 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열: O(n log n), 세그먼트 트리

### 문제 설명

<p>An elephant lives by a lake with N plants on the surface. The lake can be modeled by a coordinate plane, with plants at points with integer coordinates. </p>

<p>Every morning after waking up, the elephant performs his morning exercise, happily jumping from plant to plant. For reasons best left undiscussed, the elephant can always jump only to another plant with both coordinates larger than the coordinates of the plant it is currently on. In other words, from plant (x1, y1) the elephant can jump to plant (x2, y2) only if x2 > x1 and y2 > y1. The elephant can start his exercise at any plant on the lake. </p>

<p>Write a program that, given the coordinates of all plants, calculates the length of the longest sequence of plants the elephant can visit. Additionally, calculate the number of different such longest sequences. Because this second number can be large, calculate it modulo 1000000007. </p>

### 입력 

 <p>The first line contains the integer N (1 ≤ N ≤ 300000), the number of plants. </p>

<p>Each of the following N lines contains the coordinates of one plant, two integers between 0 and 10<sup>9</sup>. No two plants will have the same pair of coordinates. </p>

### 출력 

 <p>On the first line output the length of the longest sequence of plants the elephant can jump on. </p>

<p>On the second line output the number of such sequences of maximum length, modulo 1000000 007. </p>

