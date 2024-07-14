# [Gold IV] Parentheses - 15532 

[문제 링크](https://www.acmicpc.net/problem/15532) 

### 성능 요약

메모리: 2380 KB, 시간: 0 ms

### 분류

해 구성하기

### 제출 일자

2024년 7월 14일 20:25:04

### 문제 설명

<p>Dave loves strings consisting only of ‘(’ and ‘)’. Especially, he is interested in balanced strings. Any balanced strings can be constructed using the following rules:</p>

<ul>
	<li>A string “()” is balanced.</li>
	<li>Concatenation of two balanced strings are balanced.</li>
	<li>If T is a balanced string, concatenation of ‘(’, T, and ‘)’ in this order is balanced. For example, “()()” and “(()())” are balanced strings. “)(” and “)()(()” are not balanced strings.</li>
</ul>

<p>Dave has a string consisting only of ‘(’ and ‘)’. It satisfies the followings:</p>

<ul>
	<li>You can make it balanced by swapping adjacent characters exactly A times.</li>
	<li>For any non-negative integer B (B < A), you cannot make it balanced by B swaps of adjacent characters.</li>
	<li>It is the shortest of all strings satisfying the above conditions.</li>
</ul>

<p>Your task is to compute Dave’s string. If there are multiple candidates, output the minimum in lexicographic order. As is the case with ASCII, ‘(’ is less than ‘)’.</p>

### 입력 

 <p>The input consists of a single test case, which contains an integer A (1 ≤ A ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>Output Dave’s string in one line. If there are multiple candidates, output the minimum in lexicographic order.</p>

