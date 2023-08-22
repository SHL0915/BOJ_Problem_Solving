# [Platinum I] 삼각 분할 - 3351 

[문제 링크](https://www.acmicpc.net/problem/3351) 

### 성능 요약

메모리: 44692 KB, 시간: 384 ms

### 분류

자료 구조, 작은 집합에서 큰 집합으로 합치는 테크닉, 트리

### 문제 설명

<p>A triangulation of a polygon is a set of triangles with vertices at the vertices of a polygon. These triangles must not overlap and must cover the whole polygon.</p>

<p>We define a polygon cut as a straight line separating the polygon into two pieces.</p>

<p>Given a triangulated convex polygon, where each triangle has some color, find the maximal number of cuts one can do so that no two points of the same color end up in two different pieces.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/31b97f69-07d9-4a0b-b4f4-b2b931073000/-/preview/" style="width: 455px; height: 208px;"></p>

### 입력 

 <p>The input is read from standard input. The first line contains the number of vertices, n. Vertices are numbered with unique integers between 1 and n. Each of the next n − 2 lines contains four integer numbers a, b, c and d (1 ≤ a, b, c, d ≤ n), meaning that the triangle which has its vertices in a, b and c has the color d. a, b and c are three different vertices. The input always contains data about a proper triangulation of a polygon and all triangles are colored.</p>

### 출력 

 <p>The program should write one line to standard output, containing one integer — the maximal number of cuts.</p>

