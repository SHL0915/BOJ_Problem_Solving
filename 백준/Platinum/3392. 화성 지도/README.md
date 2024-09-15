# [Platinum II] 화성 지도 - 3392 

[문제 링크](https://www.acmicpc.net/problem/3392) 

### 성능 요약

메모리: 3864 KB, 시간: 8 ms

### 분류

자료 구조, 세그먼트 트리, 스위핑

### 제출 일자

2023년 3월 28일 10:43:21

### 문제 설명

<p>In the year 2051, several Mars expeditions have explored different areas of the red planet and produced maps of these areas. Now, the BaSA (Baltic Space Agency) has an ambitious plan: they would like to produce a map of the whole planet. In order to calculate the necessary effort, they need to know the total size of the area for which maps already exist. It is your task to write a program that calculates this area.</p>

<p>Write a program that:</p>

<ul>
	<li>reads the description of map shapes from the input.</li>
	<li>computes the total area covered by the maps,</li>
	<li>writes the result to the output.</li>
</ul>

### 입력 

 <p>The input starts with a line containing a single integer N (1 ≤ N ≤ 10 000), the number of available maps. Each of the following N lines describes a map. Each of these lines contains four integers x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub> and y<sub>2</sub> (0 ≤ x<sub>1</sub> < x<sub>2</sub> ≤ 30 000, 0 ≤ y<sub>1</sub> < y<sub>2</sub> ≤ 30 000). The values (x<sub>1</sub>, y<sub>1</sub>) and (x<sub>2</sub>, y<sub>2</sub>) are the coordinates of, respectively, the bottom-left and the top-right corner of the mapped area. Each map has rectangular shape, and its sides are parallel to the x- and y-axis of the coordinate system.</p>

### 출력 

 <p>The output should contain one integer A, the total explored area (i.e. the area of the union of all rectangles).</p>

