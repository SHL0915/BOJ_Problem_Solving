# [Platinum IV] 터보소트 - 3006 

[문제 링크](https://www.acmicpc.net/problem/3006) 

### 성능 요약

메모리: 3584 KB, 시간: 32 ms

### 분류

자료 구조, 세그먼트 트리

### 문제 설명

<p>Frane has been given the task of sorting an array of numbers. The array consists of N integers, each between 1 and N (inclusive), with each of those appearing exactly once in the array. Frane has come up with the following sorting algorithm which operates in N phases, and named it turbosort: </p>

<ul>
	<li>In the first phase, the number 1 is moved to position 1 by repeatedly swapping consecutive elements. </li>
	<li>In the second phase, the number N is moved to position N in the same manner. </li>
	<li>In the third phase, the number 2 is moved to position 2. </li>
	<li>In the fourth phase, the number N−1 is moved to position N−1. </li>
	<li>And so on. </li>
</ul>

<p>In other words, when the number of the phase is odd, Frane will choose the smallest number not yet chosen, and move it to its final position. In even phases he chooses the largest number not yet chosen. </p>

<p>Write a program which, given the initial array, output the number of swaps in each phase of the algorithm. </p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 100000), the number of elements in the array. </p>

<p>Each of the following N lines contains an integer between 1 and N (inclusive), the array to be sorted. The array will contain no duplicates. </p>

### 출력 

 <p>For each of the N phases, output the number of swaps on a single line. </p>

<p> </p>

