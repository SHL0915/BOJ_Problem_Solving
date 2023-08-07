# [Platinum IV] 초등 수학 - 11670 

[문제 링크](https://www.acmicpc.net/problem/11670) 

### 성능 요약

메모리: 3276 KB, 시간: 12 ms

### 분류

이분 매칭

### 문제 설명

<p>Ellen is teaching elementary math to her students and the time for the final exam has come. The exam consists of n questions. In each question the students have to add (+), subtract (−) or multiply (∗) a pair of numbers.</p>

<p>Ellen has already chosen the n pairs of numbers. All that remains is to decide for each pair which of the three possible operations the students should perform. To avoid students getting bored, Ellen wants to make sure that the n correct answers to her exam are all different.</p>

<p>Please help Ellen finish constructing the exam by automating this task.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with one integer n (1 ≤ n ≤ 2 500), the number of pairs of numbers;</li>
	<li>n lines each with two integers a and b (−10<sup>6</sup> ≤ a, b ≤ 10<sup>6</sup>), a pair of numbers used.</li>
</ul>

### 출력 

 <p>For each pair of numbers (a, b) in the same order as in the input, output a line containing a valid equation. Each equation should consist of five parts: a, one of the three operators, b, an equals sign (=), and the result of the expression. All the n expression results must be different.</p>

<p>If there are multiple valid answers you may output any of them. If there is no valid answer, output a single line with the string “impossible” instead.</p>

