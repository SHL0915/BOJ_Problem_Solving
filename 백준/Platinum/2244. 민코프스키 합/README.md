# [Platinum IV] 민코프스키 합 - 2244 

[문제 링크](https://www.acmicpc.net/problem/2244) 

### 성능 요약

메모리: 26764 KB, 시간: 208 ms

### 분류

볼록 껍질, 기하학

### 문제 설명

<p>A polygon consists of all points on or enclosed by its border. A convex polygon has the property that for any two points X and Y of the polygon, the line segment connecting X and Y is inside the polygon. All polygons in this task are convex polygons with at least two vertices, and all vertices in a polygon are different and have integer coordinates. No three vertices of the polygon are collinear. The word "polygon" below always refers to such polygons. </p>

<p>Given two polygons A and B, the Minkowski sum of A and B consists of all the points of the form (x1+x2, y1+y2) where (x1, y1) is a point in A and (x2, y2) is a point in B. It turns out that the Minkowski sum of polygons is also a polygon. The figure below shows an example: two triangles and their Minkowski sum.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/task1a.jpg" style="height:156px; width:478px"></p>

<p>We study a reverse operation to the Minkowski sum. For a given polygon P, we are looking for two polygons A and B such that: </p>

<ul>
	<li>P is the Minkowski sum of A and B,</li>
	<li>A has from 2 to 4 different vertices, i.e. it is a segment (2 vertices), a triangle (3 vertices) or a quadrilateral (4 vertices),</li>
	<li>A should have as many vertices, as possible, i.e.:
	<ul>
		<li>A should be a quadrilateral, if possible,</li>
		<li>if A cannot be a quadrilateral, it should be a triangle, if possible,</li>
		<li>otherwise it should be a segment.</li>
	</ul>
	</li>
</ul>

<p>Clearly, neither A nor B can be equal to P because then the other summand would have to be a point, which is not a valid polygon. </p>

<p>You are given a set of input files, each containing a description of a polygon P. For each input file you should find the polygons A and B, as required above, and create an output file containing descriptions of A and B. For the given input files such polygons A and B can always be found. If there are many correct results, you should find and output one of them. You should not submit any programs, just the output files. </p>

### 입력 

 <p>You are given 10 problem instances in the text files named polygon1.in to polygon10.in, where the number after polygon is the input number. Each input file is organized as follows. The first line contains one integer N: the number of vertices of the polygon P. The following N lines describe the vertices in a counter-clockwise order, one vertex per line. Line I+1 (for I = 1, 2, ..., N) contains two integers XI and YI, separated by a space: coordinates of the Ith vertex of the polygon. All input coordinates are non-negative integers.</p>

### 출력 

 <p>You are to submit 10 output files corresponding to the given input files which describe the required polygons A and B. The first line is to contain the text: #FILE polygon I where integer I (1≤ I ≤10)is the number of the respective input file. </p>

<p>The output format is similar to the input format. The second line is to contain one integer NA: the number of vertices in A (2 ≤NA ≤4). The following NA lines describe the vertices of A in the counter-clockwise order, one vertex per line. Line I+2 (for I = 1, 2, ..., NA) contains two integers X and Y, separated by a space: coordinates of the Ith vertex of the polygon A. </p>

<p>Line NA+3 should contain one integer NB: the number of vertices in B, (2 ≤NB). The following NB lines describe the vertices of B in the counter-clockwise order, one vertex per line. Line NA+J+3 (for J = 1, 2, ..., NB) contains two integers X and Y, separated by a space: coordinates of the Jth vertex of the polygon B. </p>

