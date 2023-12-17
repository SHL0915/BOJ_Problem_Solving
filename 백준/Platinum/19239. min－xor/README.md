# [Platinum II] min-xor - 19239 

[문제 링크](https://www.acmicpc.net/problem/19239) 

### 성능 요약

메모리: 6256 KB, 시간: 64 ms

### 분류

자료 구조, 그리디 알고리즘, 트리를 사용한 집합과 맵

### 제출 일자

2023년 7월 4일 02:39:41

### 문제 설명

<p>Consider two integers a and b. Their bitwise xor (exclusive or) is computed as it follows:</p>

<ul>
	<li>Write each of them in binary: a=a<sub>k-1</sub>a<sub>k-2</sub>...a<sub>0</sub> and b = b<sub>k-1</sub>b<sub>k-2</sub>...b<sub>0</sub>;</li>
	<li>Their bitwise xor, denoted by a ^ b, has a bit equals to 1 in the position p if and only if exactly one of a<sub>p</sub> and b<sub>p</sub> has a value of 1.</li>
</ul>

<p>For example, 9 ^ 3 = 10 because 9 = 1001<sub>(2)</sub>, 3 = 0011<sub>(2)</sub> and 10 = 1010<sub>(2)</sub>.</p>

<p>You are given a sequence of N operations on a set of integers. The set is initially empty. Each operation can be one of the following:</p>

<ol>
	<li>insert(x): append integer x to the set;</li>
	<li>delete(x): remove integer x from the set;</li>
	<li>min-xor(): print the smallest bitwise xor between any two integers currently in the set.</li>
</ol>

<p>You must print the output from every min-xor() operation.</p>

### 입력 

 <p>The first line of the input contains the number of operations N. Each of the following lines describes an operation using the following syntax:</p>

<ul>
	<li>1 x for insert(x)</li>
	<li>2 x for delete(x)</li>
	<li>3 for min-xor()</li>
</ul>

### 출력 

 <p>The output must contain a number of lines equals to the number of min-xor() operations. Each line must contain a single number, the answer to the corresponding min-xor() operation.</p>

