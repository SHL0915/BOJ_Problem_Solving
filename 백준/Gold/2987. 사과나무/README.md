# [Gold IV] 사과나무 - 2987 

[문제 링크](https://www.acmicpc.net/problem/2987) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

기하학, 구현, 수학, 볼록 다각형 내부의 점 판정, 다각형의 넓이

### 문제 설명

<p>Ante bought a piece of land. The land contains N apple trees, but his piece is triangular and it is not easy for him to determine which apple trees belong to him. </p>

<p>Your program will be given the coordinates of the vertices of the triangle forming Ante's piece, and the coordinates of all apple trees. Determine the area of land belonging to Ante, and the number of trees belonging to him. We consider apple trees on the very border of his piece to belong to him. </p>

<p>The area of a triangle with vertices (x<sub>A</sub>, y<sub>A</sub>), (x<sub>B</sub>, y<sub>B</sub>) and (x<sub>C</sub>, y<sub>C</sub>) is given by the following formula: </p>

<p>|x<sub>A</sub>(y<sub>B</sub>-y<sub>C</sub>)+x<sub>B</sub>(y<sub>C</sub>-y<sub>A</sub>)+x<sub>C</sub>(y<sub>A</sub>-y<sub>B</sub>)| / 2</p>

### 입력 

 <p>The first three lines contain the coordinates of the vertices of the triangle. </p>

<p>The following line contains the integer N (1 ≤ N ≤ 100), the number of apple trees. </p>

<p>Each of the following N lines contains the coordinates of one apple tree. </p>

<p>All coordinates are pairs of positive integers less than 1000, separated by a space. </p>

### 출력 

 <p>Output the area of land belonging to Ante on the first line, with one digit after the decimal point. </p>

<p>Output the number of tree belonging to Ante on the second line.</p>

