# [Silver I] 소수 사이 수열 - 3896 

[문제 링크](https://www.acmicpc.net/problem/3896) 

### 성능 요약

메모리: 11496 KB, 시간: 16 ms

### 분류

수학(math), 정수론(number_theory), 소수 판정(primality_test), 에라토스테네스의 체(sieve)

### 문제 설명

<p>The sequence of n−1 consecutive composite numbers (positive integers that are not prime and not equal to 1) lying between two successive prime numbers p and p + n is called a prime gap of length n. For example, <24,25,26,27,28> between 23 and 29 is a prime gap of length 6.</p>

<p>Your mission is to write a program to calculate, for a given positive integer k, the length of the prime gap that contains k. For convenience, the length is considered 0 in case no prime gap contains k.</p>

### 입력 

 <p>The input is a sequence of lines each of which contains a single positive integer. Each positive integer is greater than 1 and less than or equalto the 100000th prime number, which is 1299709. The end of the input is indicated by a line containing a single zero.</p>

### 출력 

 <p>The output should be composed of lines each of which contains a single non-negative integer. It is the length of the prime gap that contains the corresponding positive integer in the input if it is a composite number, or 0 otherwise. No other characters should occur in the output.</p>

