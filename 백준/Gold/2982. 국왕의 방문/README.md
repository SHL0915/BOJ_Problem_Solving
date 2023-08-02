# [Gold II] 국왕의 방문 - 2982 

[문제 링크](https://www.acmicpc.net/problem/2982) 

### 성능 요약

메모리: 13996 KB, 시간: 4 ms

### 분류

데이크스트라, 그래프 이론

### 문제 설명

<p>Last week Mister George visited Croatia. Since Mister George is a very important person, while he was in a street, the police disallowed entry to that street, but vehicles that entered the street before Mister George could continue driving. </p>

<p>While Mister George was visiting, Luka drove his truck around town. But because of some of the streets being closed off, he couldn't make his delivery in time and almost lost his job. Although it is late now, he is wondering how he could have planned his delivery better i.e. what would have been the least time needed to make his delivery while Mister George was visiting. He knows the route mister George took. </p>

<p>The city is modeled with intersections and two-way streets connecting them. For each street, Luka knows how much time he needs to traverse it (mister George needs the same amount of time). </p>

<p>For example, if Mister George starts traversing a street during minute 10 and needs 5 minutes to exit it, this street will be blocked during minutes 10, 11, 12, 13 and 14. Luka can enter the street during minutes 9 and earlier, or 15 and later. </p>

<p>Write a program that calculates the least amount of time Luka needs to make his delivery, if he starts driving K minutes after the arrival of Mister George. </p>

### 입력 

 <p>The first line contains two integers N and M (2 ≤ N ≤ 1000, 2 ≤ M ≤ 10 000), the number of intersections and the number of streets. The intersections are numbered 1 to N. </p>

<p>The second line contains four integers A, B, K and G (1 ≤ A, B ≤ N, 0 ≤ K ≤ 1000, 0 ≤ G ≤ 1000). These are, in order: </p>

<ul>
	<li>The intersection where Luka starts; </li>
	<li>The intersection Luka must get to; </li>
	<li>The difference in starting times between mister George and Luka (Luka starts at intersection A exactly K minutes after mister George starts his route); </li>
	<li>The number of intersections on Mister George's route. </li>
</ul>

<p>The third line contains G integers, the labels of intersections mister George will visit. Every pair of adjacent integers denotes a street he will traverse. That street will exist and Mister George will traverse every street at most once. </p>

<p>Each of the following M lines contains three integers A, B and L, meaning that there is a street between intersection A and B, and it takes L minutes to traverse. L will be between 1 and 1000. </p>

### 출력 

 <p>Output the least amount of time (in minutes) Luka needs to make his delivery.</p>

