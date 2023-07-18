# [Diamond V] Balls - 5254 

[문제 링크](https://www.acmicpc.net/problem/5254) 

### 성능 요약

메모리: 24140 KB, 시간: 160 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍

### 문제 설명

<p>There is one standard coordinate system with n balls and n holes in it: balls are located at positions (1, h), (2, h), …, (n, h), for some h > 0, and holes are located at (1, 0), (2, 0), …, (n, 0). At a given moment, all balls start falling down (along the y-axis, in the negative direction). For each ball that falls into the i-th hole, we get ci points. Of course, in order to avoid trivial c<sub>1</sub> + c<sub>2</sub> + … + c<sub>n</sub> score, it is allowed to put an obstacle.</p>

<p>A left obstacle is a segment (x<sub>1</sub>, y<sub>1</sub>) - (x<sub>2</sub>, y<sub>2</sub>) with properties: x<sub>1</sub>, x<sub>2</sub> ∈ N, 1 ≤ x<sub>1</sub> < x<sub>2</sub> ≤ n and 0 < y<sub>1</sub> < y<sub>2</sub> < h (i.e. obstacle is tilted to the left). A right obstacle is a segment (x<sub>1</sub>, y<sub>1</sub>) - (x<sub>2</sub>, y<sub>2</sub>) with properties: x<sub>1</sub>, x<sub>2</sub> ∈ N, 1 ≤ x<sub>1</sub> < x<sub>2</sub> ≤ n and h > y<sub>1</sub> > y<sub>2</sub> > 0 (i.e. obstacle is tilted to the right). If a ball, during its fall, hits an obstacle (segment), the ball temporarily stops, then slides to the obstacle’s lower end and, finally, falls directly into the hole under the obstacle’s lower end.</p>

<p>The left image shows trajectories of balls when the left obstacle is set, while on the right image we can see ball’s trajectories when a right obstacle is set. Notice that when an obstacle is set, there are holes with multiple balls in them and holes with no balls in them; however, every ball falls into one of the holes.</p>

<p style="text-align:center"><img alt="" src="https://upload.acmicpc.net/81887adb-7fc5-4036-9cbb-a92b2b009955/-/preview/" style="width: 607px; height: 155px;"></p>

<p>The value of each hole is known. Your task is to answer the following two questions:</p>

<ul>
	<li>What is the highest possible score you can achieve if you must set exactly one right obstacle?</li>
	<li>What is the highest possible score you can achieve if you must set exactly one left obstacle?</li>
</ul>

### 입력 

 <p>The first line of input contains one integer n - the number of balls and holes. The second line of input contains n integers c<sub>i</sub> delimited by spaces - the values of the holes, ordered from left to right.</p>

### 출력 

 <p>In the first line of output write a single integer – the answer to the first question. In the second line of output write a single integer – the answer to the second question. You should use a 64-bit integer data type.</p>

