# [Platinum IV] 감옥 건설 - 2254 

[문제 링크](https://www.acmicpc.net/problem/2254) 

### 성능 요약

메모리: 2160 KB, 시간: 4 ms

### 분류

볼록 껍질(convex_hull), 기하학(geometry), 볼록 다각형 내부의 점 판정(point_in_convex_polygon)

### 문제 설명

<p>After the Bovine Uprising of 2002, the cows must keep watch over the large number of human prisoners they captured.</p>

<p>They have a prison at coordinate (Px, Py) (where -100,000 <= Px <= 100,000 and -100,000 <= Py <= 100,000) and they want to construct as many layers of fences as possible around the prison to make escape as difficult as possible. It is unfortunate that, for this problem, the prison is modeled as a single point.</p>

<p>In order to accomplish this, they have placed N (3 <= N <= 1000) fence posts in the vicinity of the prison.  Each fence completely surrounds the prison and all fences inside it (i.e., no fence crossing). Among the set of all fence post locations and the prison location, no three points are collinear.  Given the locations of these fence posts, you must compute the maximum number of layers of non-intersecting nested fences the cows can construct around the prison by placing straight fence rails between the fence posts they have constructed.  A guard must be able to patrol between each pair of nested fences (and between the inner fence and the prison), so leave at least a small amount of space in the nestings (i.e., don't share a vertex between two nested fences).</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, Px, and Py.</li>
	<li>Lines 2..N+1: Two space-separated integers, Xi and Yi (-100000 <= Xi, Yi <= 100000) specifying the coordinates of a fence post.</li>
</ul>

### 출력 

 <p>A single line with a single integer that is the maximum number of layers of fences.</p>

