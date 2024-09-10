# [Platinum V] 한동이는 영업사원! - 8012 

[문제 링크](https://www.acmicpc.net/problem/8012) 

### 성능 요약

메모리: 6360 KB, 시간: 16 ms

### 분류

최소 공통 조상, 트리

### 제출 일자

2024년 9월 10일 13:03:40

### 문제 설명

<p>A salesman Byteasar works hard travelling over Byteotia. In past times travelling salesmen could choose on their own towns they wanted to visit and order to do so, but those times are now gone forever. From the time the Central Controlling Office for Travelling Salesmen was established every salesman gets from the Office a list of towns to visit and the order of his tour. As it usually happens with central offices, the imposed order of visiting towns has not much in common with an optimal order. Before leaving for his tour Byteasar would like to know at least how much time it will take him to visit all the towns. It is your task to compute this.</p>

<p>The towns of Byteotia are numbered from 1 to n. The capital of Byteotia has the number 1, and this is the place Byteasar starts on his journey from. The towns are connected by a network of two-way roads. A trip between two towns directly connected by a road always takes 1 unit of time. From the capital one can reach any other Byteotian town. However, the road network had been designed very thriftily, so the roads never form cycles.</p>

<p>
Write a program which:</p>

<ul>
	<li>reads from the standard input the description of the road network in Byteotia and the list of towns that Byteasar has to visit,</li>
	<li>computes the total time of Byteasar's trip,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is one integer n equal to the number of towns in Byteotia, 1 ≤ n ≤ 30,000. In the following n-1 lines the network of roads is described. In each of these lines there are two integers a and b (1 ≤ a,b ≤ n; a≠b), meaning that the towns a and b are connected by a road. In the line n+1 there is one integer m equal to the number of towns Byteasar should visit, 1 ≤ m ≤ 5,000. In the following m lines there are numbers of successive towns on Byteasar's route - one number per line.</p>

<p> </p>

### 출력 

 <p>In the first and only line of the standard output there should be one integer equal to the total time of Byteasar's trip.</p>

<p> </p>

