# [Gold III] 서로 다른 소수의 합 - 3908 

[문제 링크](https://www.acmicpc.net/problem/3908) 

### 성능 요약

메모리: 45972 KB, 시간: 108 ms

### 분류

다이나믹 프로그래밍(dp), 수학(math), 정수론(number_theory), 소수 판정(primality_test), 에라토스테네스의 체(sieve)

### 문제 설명

<p>A positive integer may be expressed as a sum of different prime numbers (primes), in one way or another. Given two positive integers n and k, you should count the number of ways to express n as a sum of k different primes. Here, two ways are considered to be the same if they sum up the same set of the primes. For example, 8 can be expressed as 3 + 5 and 5 + 3 but they are not distinguished.</p>

<p>When n and k are 24 and 3 respectively, the answer is two because there are two sets {2, 3, 19} and {2, 5, 17} whose sums are equal to 24. There are no other sets of three primes that sum up to 24. For n = 24 and k = 2, the answer is three, because there are three sets {5, 19}, {7, 17} and {11, 13}. For n = 2 and k = 1, the answer is one, because there is only one set {2} whose sum is 2. For n = 1 and k = 1, the answer is zero. As 1 is not a prime, you shouldn't count {1}. For n = 4 and k = 2, the answer is zero, because there are no sets of two different primes whose sums are 4.</p>

<p>Your job is to write a program that reports the number of such ways for the given n and k.</p>

### 입력 

 <p>The input is a sequence of datasets followed by a line containing two zeros separated by a space. A dataset is a line containing two positive integers n and k separated by a space. You may assume that n ≤ 1120 and k ≤ 14</p>

<p> </p>

### 출력 

 <p>The output should be composed of lines, each corresponding to an input dataset. An output line should contain one non-negative integer indicating the number of ways for n and k specified in the corresponding dataset. You may assume that it is less than 2<sup>31</sup>.</p>

<p> </p>

