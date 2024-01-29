# [Platinum V] 이항계수 - 3651 

[문제 링크](https://www.acmicpc.net/problem/3651) 

### 성능 요약

메모리: 5340 KB, 시간: 8 ms

### 분류

이분 탐색, 조합론, 수학

### 제출 일자

2024년 1월 29일 18:15:52

### 문제 설명

<p>Gunnar is quite an old and forgetful researcher. Right now he is writing a paper on security in social networks and it actually involves some combinatorics. He wrote a program for calculating binomial coefﬁcients to help him check some of his calculations.</p>

<p>A binomial coefﬁcient is a number</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/daum_equation_1358305217093.png" style="height:60px; opacity:0.9; width:177px"></p>

<p>where n and k are non-negative integers.</p>

<p>Gunnar used his program to calculate c(n, k) and got a number m as a result. Unfortunately, since he is forgetful, he forgot the numbers n and k he used as input. These two numbers were a result of a long calculation and they are written on one of many papers lying on his desk. Instead of trying to search for the papers, he tried to reconstruct the numbers n, k from the output he got. Can you help him and ﬁnd all possible candidates?</p>

### 입력 

 <p>On the first line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with an integer m (2 ≤ m ≤ 10<sup>15</sup>): the output of Gunnar’s program.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with an integer: the number of ways of expressing m as a binomial coefﬁcient.</li>
	<li>one line with all pairs (n, k) that satisfy c(n, k) = m. Order them in increasing order of n and, in case of a tie, order them in increasing order of k. Format them as in the sample output.</li>
</ul>

