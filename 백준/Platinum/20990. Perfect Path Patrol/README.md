# [Platinum V] Perfect Path Patrol - 20990 

[문제 링크](https://www.acmicpc.net/problem/20990) 

### 성능 요약

메모리: 116508 KB, 시간: 492 ms

### 분류

그리디 알고리즘, 트리

### 문제 설명

<p>Pleasantville is a community that appreciates simplicity. We can view the road network in Pleasantville as a collection of junctions that are connected by two-way streets. This has been done in a simple manner: there is precisely one way to travel between any two junctions in Pleasantville without traversing any street more than once.</p>

<p>Citizens have formed a community watch program to ensure the streets are safe to walk at night. So, some citizens patrol certain regions of the neighborhood. These patrols are also simple: a single citizen simply patrols all streets lying on the unique path between two junctions assigned to them.</p>

<p>Each street e also has a simple criterion: exactly p<sub>e</sub> patrollers must include street e in their patrol path. If fewer than p<sub>e</sub> patrollers were assigned to cover street e, then it might not be safe. If more than p<sub>e</sub> patrollers were assigned to cover street e, the citizens themselves might become uneasy with the heightened presence of patrollers.</p>

<p>You have been tasked with organizing this community watch program. Of course, it is ideal to minimize the number of patrollers you use. Thus, you must enlist the fewest possible patrollers and assign each to a path between two junctions in the neighborhood such that any street e lies on exactly p<sub>e</sub> patrollers’ paths.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/64fcbb2c-bc5f-4033-8b3e-0dadec9a4f18/-/preview/" style="width: 313px; height: 98px;"></p>

<p style="text-align: center;">Figure B.1: An illustration of the first sample. The numbers by the solid black edges indicate how many patrollers must include that edge in their paths. The dashed red curves indicate one possible way to select 10 patrol paths so every edge lies on exactly the required number of patrol paths. That is, one solution is to use 10 patroller paths with endpoints:</p>

<p style="text-align: center;">(5, 2),(6, 0),(6, 3),(4, 2),(4, 0),(4, 0),(4, 0),(1, 2),(2, 3),(2, 3)</p>

<p style="text-align: center;">It is impossible to use fewer than 10 patrollers while ensuring each street is patrolled by exactly the required number of patrol paths.</p>

### 입력 

 <p>The first line of input contains a single value N (2 ≤ N ≤ 500 000) indicating the number of junctions in the neighborhood, which are numbered 0 through N − 1.</p>

<p>Then N − 1 lines follow, each containing three integers u, v, p (0 ≤ u, v < N, 0 ≤ p ≤ 10<sup>9</sup>). This indicates there is a street connecting junction u to junction v and that this street must lie on exactly p patrol paths.</p>

<p>You are guaranteed there is a unique way to travel between any two junctions using the provided streets.</p>

### 출력 

 <p>Output a single line with a single integer indicating the minimum number of patrollers you need to enlist for the community watch program.</p>

