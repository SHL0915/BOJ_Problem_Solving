# [Platinum V] XOR Pairs - 26850 

[문제 링크](https://www.acmicpc.net/problem/26850) 

### 성능 요약

메모리: 6776 KB, 시간: 524 ms

### 분류

수학

### 제출 일자

2024년 3월 5일 16:19:14

### 문제 설명

<p>XOR is a bitwise operator that evaluates the resulting bit into 1 if and only if their corresponding input bits differ (one of them is 1 while the other is 0). XOR operator is usually written with a symbol ⊕, or in most programming languages, the character ^(caret). For example, (10 ⊕ 6) = 12.</p>

<pre>10 =>  1010
 6 =>  0110
      ----- ⊕
       1100   => 12
</pre>

<p>In this problem, you are given an integer N and a set of integers S<sub>1..</sub>M. Your task is to count how many pairs of integers <A, B> such that 1 ≤ A, B ≤ (A ⊕ B) ≤ N, and (A ⊕ B) ∉ S.</p>

<p>For example, let N = 10 and S<sub>1..4</sub> = {4, 6, 7, 10}. There are 6 pairs of <A, B> that satisfy the condition.</p>

<ul>
	<li><1, 2> → (1 ⊕ 2) = 3</li>
	<li><1, 4> → (1 ⊕ 4) = 5</li>
	<li><1, 8> → (1 ⊕ 8) = 9</li>
	<li><2, 1> → (2 ⊕ 1) = 3</li>
	<li><4, 1> → (4 ⊕ 1) = 5</li>
	<li><8, 1> → (8 ⊕ 1) = 9</li>
</ul>

<p>Observe that a pair such as <2, 4> does not satisfy the condition for this example as (2 ⊕ 4) = 6 but 6 ∈ S. Another pair such as <5, 1> also does not satisfy the condition as it violates the requirement A, B ≤ (A ⊕ B).</p>

### 입력 

 <p>Input begins with a line containing two integers N M (1 ≤ N ≤ 10<sup>6</sup>; 1 ≤ M ≤ 100 000) representing the given N and the size of the set of integers S<sub>1..M</sub>. The next line contains M integers S<sub>i</sub> (1 ≤ S<sub>i</sub> ≤ 10<sup>6</sup>) representing the set of integers S<sub>1..M</sub>.</p>

### 출력 

 <p>Output contains an integer in a line representing the number of <A, B> such that 1 ≤ A, B ≤ (A ⊕ B) ≤ N and (A ⊕ B) ∉ S<sub>1..M</sub>.</p>

