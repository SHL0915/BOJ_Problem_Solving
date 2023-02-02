# [Platinum IV] 단순 다각형 - 3679 

[문제 링크](https://www.acmicpc.net/problem/3679) 

### 성능 요약

메모리: 2076 KB, 시간: 12 ms

### 분류

볼록 껍질(convex_hull), 기하학(geometry), 정렬(sorting)

### 문제 설명

<p>Write a program that constructs a polygon from a given set of points in the plane. Each point of the set has to be a vertex of the polygon, and the polygon must not have any other vertices. No two line segments of the polygon may have any point in common, except for the middle vertex of two consecutive line segments. For example, given the points on the left-hand side, a valid polygon is shown on the right-hand side:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/spolygon.png" style="height:192px; width:441px"></p>

<p>A valid polygon is guaranteed to exist, and any valid polygon will be accepted as a correct answer. Moreover, no two points will share the same location, and not all points will be collinear.</p>

<p> </p>

### 입력 

 <p>The first line of the input consists of an integer c (1 ≤ c ≤ 200), the number of test cases. Then follow the test cases, one per line.</p>

<p>Each test case starts with an integer n (3 ≤ n ≤ 2 000), the number of given points. Then follow, on the same line, the coordinates of the points. Each point is specified by two integers x and y in the range -10 000 to 10 000, inclusively.</p>

### 출력 

 <p>For each test case, print a single line containing a permutation of the numbers 0 to n-1. Each of these numbers represents the index of a point, in the same order as given in the input. When drawing line segments between consecutive points in the order given by this permutation, the result must be a valid polygon.</p>

