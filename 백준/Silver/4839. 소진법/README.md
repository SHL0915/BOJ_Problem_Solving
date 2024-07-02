# [Silver IV] 소진법 - 4839 

[문제 링크](https://www.acmicpc.net/problem/4839) 

### 성능 요약

메모리: 7596 KB, 시간: 8 ms

### 분류

구현, 수학, 정수론, 소수 판정

### 제출 일자

2024년 7월 2일 13:44:17

### 문제 설명

<p>Given any integer base b ≥ 2, it is well known that every positive integer n can be uniquely represented in base b. That is, we can write </p>

<p>n = a<sub>0</sub> + a<sub>1</sub>*b + a<sub>2</sub>*b*b + a<sub>3</sub>*b*b*b + ...</p>

<p>where the coefficients a<sub>0</sub>, a<sub>1</sub>, a2, a<sub>3</sub>, ... are between 0 and b-1 (inclusive).</p>

<p>What is less well known is that if p<sub>0</sub>, p<sub>1</sub>, p<sub>2</sub>, ... are the first primes (starting from 2, 3, 5, ...), every positive integer n can be represented uniquely in the "mixed" bases as: </p>

<p>n = a<sub>0</sub> + a<sub>1</sub>*p<sub>0</sub> + a<sub>2</sub>*p<sub>0*</sub>p<sub>1</sub> + a<sub>3</sub>*p<sub>0</sub>*p<sub>1</sub>*p<sub>2</sub> + ...</p>

<p>where each coefficient ai is between 0 and p<sub>i</sub>-1 (inclusive). Notice that, for example, a<sub>3</sub> is between 0 and p<sub>3</sub>-1, even though p<sub>3</sub> may not be needed explicitly to represent the integer n.</p>

<p>Given a positive integer n, you are asked to write n in the representation above. Do not use more primes than it is needed to represent n, and omit all terms in which the coefficient is 0. </p>

### 입력 

 <p>Each line of input consists of a single positive 32-bit signed integer. The end of input is indicated by a line containing the integer 0.</p>

### 출력 

 <p>For each integer, print the integer, followed by a space, an equal sign, and a space, followed by the mixed base representation of the integer in the format shown below. The terms should be separated by a space, a plus sign, and a space. The output for each integer should appear on its own line.</p>

