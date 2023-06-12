# [Gold II] Icy Land - 16576 

[문제 링크](https://www.acmicpc.net/problem/16576) 

### 성능 요약

메모리: 3020 KB, 시간: 0 ms

### 분류

애드 혹, 많은 조건 분기

### 문제 설명

<p>You are given a board of R rows and C columns where each cell is either a dry land (‘#’) or an icy land (‘.’). You can move to either one of the four directions (north, south, east, or west) in the board.</p>

<p>You can walk or standstill on any dry land without any problem; however, an icy land is very slippery. If you stand at cell (r, c) and decide to move on a particular direction, then you will move on that direction continuously until you reach a dry land or the border of the board.</p>

<p>For example, consider the following board of 6 rows and 7 column.</p>

<pre>#......
.#.....
..##...
..##...
.......
.#.....</pre>

<ul>
	<li>From (1, 3), the 1st row and 3rd column, if you move to the south, then you will end up at (3, 3).</li>
	<li>From (4, 4), if you move to the north, then you will end up at (3, 4).</li>
	<li>From (1, 1), if you move to the east, then you will end up at (1, 7).</li>
	<li>From (6, 5), if you move to the west, then you will end up at (6, 2).</li>
</ul>

<p>Supposed your initial position is at cell (3, 7) and your moves are west, west, west, south, east, north, west, and west, respectively. Then your positions are (3, 7) → (3, 4) → (3, 3) → (3, 1) → (6, 1) → (6, 2) → (2, 2) → (2, 1) → (2, 1), thus, visiting 8 different cells. Note that cell (2, 1) is visited twice. Cells in which you only passed through are also not considered as visited, e.g., in the example above, if you move south from (3, 1), then you will pass through (4, 1) and (5, 1), and arrive at (6, 1); thus, (4, 1) and (5, 1) are not considered as visited from that particular move, only (3, 1) and (6, 1) are.</p>

<p>You are allowed to change any icy land into a dry land, and your goal is to make sure that you can always visit all the cells in the board regardless of your initial starting position; in other words, you do not know your starting position yet, but given the board, you want to make sure that you can achieve your goal. What is the minimum number of cells you need to change to ensure that your goal can be achieved?</p>

### 입력 

 <p>Input begins with a line containing two integers: R C (1 ≤ R, C ≤ 500) representing the number of rows and columns of the board, respectively. The next R lines, each contains C characters representing the given board. Each character is either ‘#’ which represents a dry land or ‘.’ which represents an icy land.</p>

### 출력 

 <p>Output contains an integer in a line representing the minimum number of cells you need to change to ensure that you can visit all the cells in the board regardless of your initial starting position.</p>

