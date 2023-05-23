# [Gold III] 선그리기 - 2013 

[문제 링크](https://www.acmicpc.net/problem/2013) 

### 성능 요약

메모리: 2412 KB, 시간: 628 ms

### 분류

자료 구조, 분리 집합, 기하학, 선분 교차 판정

### 문제 설명

<p>Irv Kenneth Diggit works for a company that excavates trenches, digs holes and generally tears up people’s yards. Irv’s job is to make sure that no underground pipe or cable is underneath where excavation is planned. He has several diﬀerent maps, one for each utility company, showing where their conduits lie, and he needs to draw one large, consolidated map combining them all. One approach would be to simply draw each of the smaller maps one at a time onto the large map. However, this often wastes time, not to mention ink for the pen-plotter in the oﬃce, since in many cases portions of the conduits overlap with each other (albeit at diﬀerent depths underground). What Irv wants is a way to determine the minimum number of line segments to draw given all the line segments from the separate maps.</p>

### 입력 

 <p>Input will consist of multiple input sets. Each set will start with a single line containing a positive integer n indicating the total number of line segments from all the smaller maps. Each of the next n lines will contain a description of one segment in the format</p>

<p>x1 y1 x2 y2</p>

<p>where (x1, y1) are the coordinates of one endpoint and (x2, y2) are the coordinates of the other. Coordinate values are ﬂoating point values in the range 0... 1000 speciﬁed to at most two decimal places. The maximum number of line segments will be 10000 and all segments will have non-zero length. Following the last input set there will be a line containing a 0 indicating end of input; it should not be processed.</p>

### 출력 

 <p>For each input set, output on a single line the minimum number of line segments that need to be drawn on the larger, consolidated map.</p>

