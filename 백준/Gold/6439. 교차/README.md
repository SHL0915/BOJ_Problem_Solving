# [Gold I] 교차 - 6439 

[문제 링크](https://www.acmicpc.net/problem/6439) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

기하학, 선분 교차 판정

### 문제 설명

<p>You are to write a program that has to decide whether a given line segment intersects a given rectangle.</p>

<p>An example:</p>

<ul>
	<li>line: start point: (4,9)</li>
	<li>end point: (11,2)</li>
	<li>rectangle: left-top: (1,5)</li>
	<li>right-bottom: (7,1)</li>
</ul>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/Intersection.gif" style="height:190px; line-height:20.7999992370605px; width:217px"></p>

<p>Figure 1: Line segment does not intersect rectangle</p>

<p>The line is said to intersect the rectangle if the line and the rectangle have at least one point in common. The rectangle consists of four straight lines and the area in between. Although all input values are integer numbers, valid intersection points do not have to lay on the integer grid.</p>

### 입력 

 <p>The input consists of n test cases. The first line of the input file contains the number n. Each following line contains one test case of the format: xstart ystart xend yend xleft ytop xright ybottom where (xstart, ystart) is the start and (xend, yend) the end point of the line and (xleft, ytop) the top left and (xright, ybottom) the bottom right corner of the rectangle. The eight numbers are separated by a blank. The terms top left and bottom right do not imply any ordering of coordinates.</p>

### 출력 

 Empty

