# [Platinum IV] 부분 수열의 길이 - 9623 

[문제 링크](https://www.acmicpc.net/problem/9623) 

### 성능 요약

메모리: 18264 KB, 시간: 532 ms

### 분류

이분 탐색(binary_search), 값 / 좌표 압축(coordinate_compression), 자료 구조(data_structures), 누적 합(prefix_sum), 세그먼트 트리(segtree)

### 문제 설명

<p>You are given an integer sequence of length N and another value X. You have to find a contiguous subsequence of the given sequence such that the sum is greater or equal to X. And you have to find that segment with minimal length. </p>

### 입력 

 <p>First line of the input file contains T the number of test cases. Each test case starts with a line containing 2 integers N(1≤N≤500000) and X(-10<sup>9</sup>≤X≤10<sup>9</sup>). Next line contains N integers denoting the elements of the sequence. These integers will be between -10<sup>9</sup> to 10<sup>9</sup> inclusive. </p>

### 출력 

 <p>For each test case output the minimum length of the sub array whose sum is greater or equal to X. If there is no such array, output -1. </p>

