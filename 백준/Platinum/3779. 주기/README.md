# [Platinum IV] 주기 - 3779 

[문제 링크](https://www.acmicpc.net/problem/3779) 

### 성능 요약

메모리: 8020 KB, 시간: 44 ms

### 분류

KMP(kmp), 문자열(string)

### 문제 설명

<p>For each prefix of a given string S with N characters (each character has an ASCII code between 97 and 126, inclusive), we want to know whether the prefix is a periodic string. That is, for each i (2 ≤ i ≤ N) we want to know the largest K > 1 (if there is one) such that the prefix of S with length i can be written as A<sup>K</sup>, that is A concatenated K times, for some string A. Of course, we also want to know the period K.</p>

### 입력 

 <p>The input file consists of several test cases. Each test case consists of two lines. The first one contains N (2 <= N <= 1 000 000) – the size of the string S. The second line contains the string S. The input file ends with a line, having the number zero on it.</p>

### 출력 

 <p>For each test case, output “Test case #” and the consecutive test case number on a single line; then, for each prefix with length i that has a period K > 1, output the prefix size i and the period K separated by a single space; the prefix sizes must be in increasing order. Print a blank line after each test case.</p>

