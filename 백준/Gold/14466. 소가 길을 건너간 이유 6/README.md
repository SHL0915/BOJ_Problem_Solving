# [Gold IV] 소가 길을 건너간 이유 6 - 14466 

[문제 링크](https://www.acmicpc.net/problem/14466) 

### 성능 요약

메모리: 3580 KB, 시간: 12 ms

### 분류

너비 우선 탐색(bfs), 깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Why did the cow cross the road? Well, one reason is that Farmer John's farm simply has a lot of roads, making it impossible for his cows to travel around without crossing many of them.</p>

<p>FJ's farm is arranged as an N×N square grid of fields (2 ≤ N ≤ 100), Certain pairs of adjacent fields (e.g., north-south or east-west) are separated by roads, and a tall fence runs around the external perimeter of the entire grid, preventing cows from leaving the farm. Cows can move freely from any field to any other adjacent field (north, east, south, or west), although they prefer not to cross roads unless absolutely necessary.</p>

<p>There are K cows (1 ≤ K ≤ 100,K ≤ N<sup>2</sup>) on FJ's farm, each located in a different field. A pair of cows is said to be "distant" if, in order for one cow to visit the other, it is necessary to cross at least one road. Please help FJ count the number of distant pairs of cows.</p>

### 입력 

 <p>The first line of input contains N, K, and R. The next R lines describe R roads that exist between pairs of adjacent fields. Each line is of the form r c r′ c′ (integers in the range 1…N), indicating a road between the field in (row r, column c) and the adjacent field in (row r′, column c′). The final K lines indicate the locations of the K cows, each specified in terms of a row and column.</p>

### 출력 

 <p>Print the number of pairs of cows that are distant.</p>

