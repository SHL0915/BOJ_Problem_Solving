# [Platinum IV] 검열 - 3111 

[문제 링크](https://www.acmicpc.net/problem/3111) 

### 성능 요약

메모리: 3060 KB, 시간: 12 ms

### 분류

자료 구조(data_structures), 덱(deque), 구현(implementation), 스택(stack), 문자열(string)

### 문제 설명

<p>Censorship is suppression of free speech common to authoritarian regimes, but not uncommon in democratic ones. </p>

<p>Mirko was hired by the secret service and his very first assignment involved censorship. Given a text T he is required to remove all occurrences of the word A, using the following simple algorithm: </p>

<ol>
	<li>If A does not appear in T, end the algorithm. </li>
	<li>Find the first occurrence of A in T and remove it. </li>
	<li>If A does not appear in T, end the algorithm. </li>
	<li>Find the last occurrence of A in T and remove it. </li>
	<li>Go to step 1. </li>
</ol>

<p>Help Mirko perform his task quickly so that he can continue fantasising about actual spy work.</p>

### 입력 

 <p>The first line contains a string of at most 25 lowercase letters, the word A. </p>

<p>The first line contains a string of at most 300000 lowercase letters, the text T.</p>

### 출력 

 <p>Output the text after censorship. </p>

<p> </p>

