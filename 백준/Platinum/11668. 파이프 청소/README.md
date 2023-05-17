# [Platinum IV] 파이프 청소 - 11668 

[문제 링크](https://www.acmicpc.net/problem/11668) 

### 성능 요약

메모리: 10308 KB, 시간: 44 ms

### 분류

기하학, 그래프 이론, 그래프 탐색, 선분 교차 판정

### 문제 설명

<p>Linköping has a quite complex water transport system. Around Linköping there are several wells from which water is drawn. The water is then transported to other locations using pipes. Each pipe is a straight canal from one of the wells to some location in the city.</p>

<p>All the pipes are at the same depth under ground. Therefore, whenever two pipes cross, they form an intersection. Luckily the pipe system was constructed in such a way that exactly two pipes meet at each such intersection. The wells do not count as intersections. Any number of pipes (including zero or more than two) may originate at each well.</p>

<p>The intersections pose a problem, since dirt (a mixture of lime and other “remains”) tends to get stuck there. This dirt causes the pipes to degrade and collapse, leading to the formation of large sink holes. Such sink holes have a mesmerising effect on the students in Linköping, causing them to neglect their studies and remain uneducated, which in the long run will lead to a collapse of not just the pipe system but of the very fabric of society. Therefore it is imperative that the pipes are regularly cleaned. The Nordic Water Extraction and Redistribution Company (NWERC) – which is in charge of Linköping’s waterpipes – has an ample fleet of robots to perform this task. A robot can be inserted into a pipe at the well where the pipe begins. The robot then goes through the pipe all the way to its end and cleans all intersections along the way. After reaching the end, the robot turns around and returns back to the well where it started. In order to prevent robot collisions, government regulations stipulate that whenever two pipes intersect, at most one of them may contain a robot.</p>

<p>Since the whole water system has to be shut down while it is being cleaned (another government regulation), the NWERC would like to do the cleaning quickly, by using a single batch of cleaning robots, all started at the same time.</p>

<p>Your task is to verify whether this can be done – i.e., whether we can simultaneously insert robots into a subset of the pipes in such a way that the robots will clean all intersections and there will be no risk of two robots colliding.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers w (1 ≤ w ≤ 1 000), the number of wells, and p (1 ≤ p ≤ 1 000), the number of pipes;</li>
	<li>w lines, the ith of which contains two integers x<sub>i</sub> and y<sub>i</sub> (−10 000 ≤ x, y ≤ 10 000), the position of well number i (the wells are numbered from 1 to w);</li>
	<li>p lines each with three integers s (1 ≤ s ≤ w), the well at which the pipe starts, and x and y (−10 000 ≤ x, y ≤ 10 000), the position at which the pipe ends.</li>
</ul>

<p>Each pipe will contain exactly one well, the one at which it starts. Any point shared by more than two pipes will be a well. Any two pipes share at most one common point. The common point of two pipes may be the endpoint of one or both of them. All pipes have positive length.</p>

### 출력 

 <p>If it is possible to clean all intersections as described above, output “possible”. Otherwise, output “impossible”.</p>

