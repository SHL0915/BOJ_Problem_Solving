# [Gold II] Permutation Descent Counts - 13881 

[문제 링크](https://www.acmicpc.net/problem/13881) 

### 성능 요약

메모리: 2060 KB, 시간: 16 ms

### 분류

조합론(combinatorics), 다이나믹 프로그래밍(dp), 수학(math)

### 문제 설명

<p>Given a positive integer, N, a permutation of order N is a one-to-one (and thus onto) function from the set of integers from 1 to N to itself. If p is such a function, we represent the function by a list of its values:</p>

<p style="text-align: center;">[ p(1) p(2) … p(N) ]</p>

<p>For example,</p>

<p>[5 6 2 4 7 1 3] represents the function from { 1 … 7 } to itself which takes 1 to 5, 2 to 6, … , 7 to 3.</p>

<p>For any permutation p, a descent of p is an integer k for which p(k) > p(k+1). For example, the permutation [5 6 2 4 7 1 3] has a descent at 2 (6 > 2) and 5 (7 > 1).</p>

<p>For permutation p, des(p) is the number of descents in p. For example, des([5 6 2 4 7 1 3]) = 2. The identity permutation is the only permutation with des(p) = 0. The reversing permutation with p(k) = N+1-k is the only permutation with des(p) = N-1.</p>

<p>The permutation descent count (PDC) for given order N and value v is the number of permutations p of order N with des(p) = v. For example:</p>

<ul>
	<li>PDC(3, 0) = 1 { [ 1 2 3 ] }</li>
	<li>PDC(3, 1) = 4 { [ 1 3 2 ], [ 2 1 3 ], [ 2 3 1 ], 3 1 2 ] }</li>
	<li>PDC(3, 2) = 1 { [ 3 2 1 ] }</li>
</ul>

<p>Write a program to compute the PDC for inputs N and v. To avoid having to deal with very large numbers, your answer (and your intermediate calculations) will be computed modulo 1001113.</p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set should be processed identically and independently.</p>

<p>Each data set consists of a single line of input. It contains the data set number, K, followed by the integer order, N (2 ≤ N ≤ 100), followed by an integer value, v (0 ≤ v ≤ N-1).</p>

### 출력 

 <p>For each data set there is a single line of output. The single output line consists of the data set number, K, followed by a single space followed by the PDC of N and v modulo 1001113 as a decimal integer.</p>

