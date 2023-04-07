# [Platinum V] Corporative Network - 3780 

[문제 링크](https://www.acmicpc.net/problem/3780) 

### 성능 요약

메모리: 2256 KB, 시간: 36 ms

### 분류

자료 구조, 분리 집합

### 문제 설명

<p>A very big corporation is developing its corporative network. In the beginning each of the N enterprises of the corporation, numerated from 1 to N, organized its own computing and telecommunication center. Soon, for amelioration of the services, the corporation started to collect some enterprises in clusters, each of them served by a single computing and telecommunication center as follow. The corporation chose one of the existing centers I (serving the cluster A) and one of the enterprises J in some other cluster B (not necessarily the center) and link them with telecommunication line. The length of the line between the enterprises I and J is |I – J|(mod 1000). In such a way the two old clusters are joined in a new cluster, served by the center of the old cluster B. Unfortunately after each join the sum of the lengths of the lines linking an enterprise to its serving center could be changed and the end users would like to know what is the new length. Write a program to keep trace of the changes in the organization of the network that is able in each moment to answer the questions of the users.</p>

### 입력 

 <p>Your program has to be ready to solve more than one test case. The first line of the input file will contains only the number T of the test cases. Each test will start with the number N of enterprises (5≤N≤20000). Then some number of lines (no more than 200000) will follow with one of the commands:</p>

<ul>
	<li>E I – asking the length of the path from the enterprise I to its serving center in the moment; </li>
	<li>I I J – informing that the serving center I is linked to the enterprise J.</li>
</ul>

<p>The test case finishes with a line containing the word O. The I commands are less than N.</p>

### 출력 

 <p>The output should contain as many lines as the number of E commands in all test cases with a single number each – the asked sum of length of lines connecting the corresponding enterprise with its serving center.</p>

