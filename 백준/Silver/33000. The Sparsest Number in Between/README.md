# [Silver I] The Sparsest Number in Between - 33000 

[문제 링크](https://www.acmicpc.net/problem/33000) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹, 비트마스킹, 그리디 알고리즘, 수학

### 제출 일자

2025년 1월 1일 01:54:43

### 문제 설명

<p>You are given a pair of positive integers $a$ and $b$ ($a ≤ b$). Among those integers between $a$ and $b$, inclusive, your task is to find the <em>sparsest</em> one, that is, the one with the least number of <code>1</code>’s in its binary representation. If there are two or more such integers, you should find the smallest among them.</p>

<p>Suppose, for instance, that $a = 10$ and $b = 13$. The integers between $a$ and $b$, inclusive, are $10$, $11$, $12$, and $13$, and their binary representations are <code>1010</code>, <code>1011</code>, <code>1100</code>, and <code>1101</code>, respectively. Thus, in this case, the answer is $10$, since $10$ and $12$ have the least number of <code>1</code>’s in their binary representations and $10$ is smaller than $12$.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$a$ $b$</p>
</blockquote>

<p>Here, $a$ and $b$ ($a ≤ b$) are integers between $1$ and $10^{18}$, inclusive.</p>

### 출력 

 <p>Output a line containing the smallest among the sparsest integers between $a$ and $b$, inclusive.</p>

