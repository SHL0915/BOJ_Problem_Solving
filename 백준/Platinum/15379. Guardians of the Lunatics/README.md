# [Platinum I] Guardians of the Lunatics - 15379 

[문제 링크](https://www.acmicpc.net/problem/15379) 

### 성능 요약

메모리: 2272 KB, 시간: 2404 ms

### 분류

분할 정복, 분할 정복을 사용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2024년 4월 17일 10:47:06

### 문제 설명

<p>You are in charge of assigning guards to a prison where the craziest criminals are sent. The L cells form a single row and are numbered from 1 to L. Cell i houses exactly one lunatic whose craziness level is C<sub>i</sub>.</p>

<p>Each lunatic should have one guard watching over him/her. Ideally, you should have one guard watching over each lunatic. However, due to budget constraints, you only have G guards to assign. You have to assign which lunatics each guard should watch over in order to minimize the total risk of having someone escape.</p>

<p>Of course, you should assign each guard to a set of adjacent cells. The risk level R<sub>i</sub> that the lunatic in cell i can escape is given by the product of his/her craziness level C<sub>i</sub> and the number of lunatics the guard assigned to him/her is watching over. Getting the sum of the R<sub>i</sub>’s from i = 1 to i = L will give us the total amount of risk, R, that a lunatic might escape.</p>

<p>Given L lunatics and G guards, what is the minimum possible value of R?</p>

### 입력 

 <p>The first line of input contains a single integer, T, denoting the number of test cases.</p>

<p>The first line of each test case contains two space-separated positive integers: L and G, the number of lunatics and the number of guards respectively. The next L lines describe the craziness level of each of the lunatics. The ith of these L lines describe the craziness level of the lunatic in cell block i.</p>

<p>Constraints</p>

<ul>
	<li>1 ≤ T ≤ 22</li>
	<li>1 ≤ L ≤ 8000</li>
	<li>1 ≤ G ≤ 800</li>
	<li>1 ≤ C<sub>i</sub> ≤ 10<sup>9</sup></li>
</ul>

### 출력 

 <p>For each test case, output a line containing the minimum possible value of R.</p>

