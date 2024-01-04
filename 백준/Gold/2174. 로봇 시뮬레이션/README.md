# [Gold V] 로봇 시뮬레이션 - 2174 

[문제 링크](https://www.acmicpc.net/problem/2174) 

### 성능 요약

메모리: 2064 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2024년 1월 4일 16:47:54

### 문제 설명

<p>In a modernized warehouse, robots are used to fetch the goods. Careful planning is needed to ensure that the robots reach their destinations without crashing into each other. Of course, all warehouses are rectangular, and all robots occupy a circular floor space with a diameter of 1 meter. Assume there are N robots, numbered from 1 through N. You will get to know the position and orientation of each robot, and all the instructions, which are carefully (and mindlessly) followed by the robots. Instructions are processed in the order they come. No two robots move simultaneously; a robot always completes its move before the next one starts moving. A robot crashes with a wall if it attempts to move outside the area of the warehouse, and two robots crash with each other if they ever try to occupy the same spot.</p>

### 입력 

 <p>The first line of input is K, the number of test cases. Each test case starts with one line consisting of two integers, 1 ≤ A, B ≤ 100, giving the size of the warehouse in meters. A is the length in the EW-direction, and B in the NS-direction.</p>

<p>The second line contains two integers, 1 ≤ N, M ≤ 100, denoting the numbers of robots and instructions respectively.</p>

<p>Then follow N lines with two integers, 1 ≤ Xi ≤ A, 1 ≤ Yi ≤ B and one letter (N, S, E or W), giving the starting position and direction of each robot, in order from 1 through N. No two robots start at the same position.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/upload/201008/robot.PNG" style="height:279px; opacity:0.9; width:516px"></p>

<p style="text-align: center;">Figure 1: The starting positions of the robots in the sample warehouse</p>

<p>Finally there are M lines, giving the instructions in sequential order. An instruction has the following format:</p>

<pre><robot #> <action> <repeat></pre>

<p>Where <action> is one of</p>

<ul>
	<li>L: turn left 90 degrees,</li>
	<li>R: turn right 90 degrees, or</li>
	<li>F: move forward one meter,</li>
</ul>

<p>and 1 ≤ <repeat> ≤ 100 is the number of times the robot should perform this single move.</p>

### 출력 

 <p>Output one line for each test case:</p>

<ul>
	<li>Robot i crashes into the wall, if robot i crashes into a wall. (A robot crashes into a wall if Xi = 0, Xi = A + 1, Yi = 0 or Yi = B + 1.)</li>
	<li>Robot i crashes into robot j, if robots i and j crash, and i is the moving robot.</li>
	<li>OK, if no crashing occurs.</li>
</ul>

<p>Only the ﬁrst crash is to be reported.</p>

