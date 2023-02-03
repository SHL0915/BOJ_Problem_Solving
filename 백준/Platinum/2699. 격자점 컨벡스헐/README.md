# [Platinum V] 격자점 컨벡스헐 - 2699 

[문제 링크](https://www.acmicpc.net/problem/2699) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

볼록 껍질(convex_hull), 기하학(geometry)

### 문제 설명

<p>A lattice point is a point with integer coordinates. A lattice polygon is a polygon with all vertices lattice points. </p>

<p>A polygon is convex if any line segment between two points of the polygon is inside (or on the boundary of) the polygon. Equivalently, the interior angle at each polygon vertex is less than 180 degrees. </p>

<p>For a set S, of lattice points, the convex hull is the smallest convex (lattice) polygon which contains all points of the set. (The vertices of the convex hull must be members of the set of lattice points). If all the points are on a single straight line, the convex hull will be a line segment (a degeneratepolygon – see rightmost diagram below). In the diagrams below, the points of the set are indicated by solid dots, the vertices of the convex hull by X’s and the convex hull is drawn connecting the vertices. </p>

<p>Note that not all points on the convex hull polygon are vertices.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/latice.png" style="height:249px; width:584px"></p>

<p>The vertices of a lattice polygon are in standard order if: </p>

<ol>
	<li>The first vertex is the one with the largest y value. If two vertices have the same y value, the one with the smaller x value is the first. </li>
	<li>Vertices are given in clockwise order around the polygon. </li>
</ol>

<p>Write a program that reads a set of lattice points and outputs the vertices of the convex hull of the points in standard order. </p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. The first line of each data set contains a decimal integer giving the number of points N, (3 ≤ N ≤ 50), in the set. The remaining lines in the data set contain the points in the set, at most 5 points per line (the last line may have fewer). Each point consists of 2 space separated decimal integer values representing the x and y coordinates respectively. </p>

### 출력 

 <p>For each data set there are multiple lines of output. The first line contains a decimal integer giving a decimal integer giving the total number of vertices of the convex hull. The vertices of the convex hull follow, one per line in standard order. Each line contains the decimal integer x coordinate, a single space and the decimal integer y coordinate. </p>

