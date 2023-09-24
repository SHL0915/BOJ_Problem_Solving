# [Platinum IV] 물 채우기 - 2276 

[문제 링크](https://www.acmicpc.net/problem/2276) 

### 성능 요약

메모리: 3456 KB, 시간: 20 ms

### 분류

자료 구조, 그래프 이론, 그래프 탐색, 우선순위 큐

### 문제 설명

<p>Farmer John's cows have taken a side job designing interesting punch-bowl designs. The designs are created as follows: </p>

<ul>
	<li>A flat board of size W cm x H cm is procured (3 <= W <= 300, 3 <= H <= 300) </li>
	<li>On every 1 cm x 1 cm square of the board, a 1 cm x 1 cm block is placed. This block has some integer height B (1 <= B <= 1,000,000,000)</li>
</ul>

<p>The blocks are all glued together carefully so that punch will not drain through them. They are glued so well, in fact, that the corner blocks really don't matter!</p>

<p>FJ's cows can never figure out, however, just how much punch their bowl designs will hold. Presuming the bowl is freestanding (i.e., no special walls around the bowl), calculate how much juice the bowl can hold. Some juice bowls, of course, leak out all the juice on the edges and will hold 0.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, W and H </li>
	<li>Lines 2..H+1: Line i+1 contains row i of bowl heights: W space-separated integers each of which represents the height B of a square in the bowl. The first integer is the height of column 1, the second integers is the height of column 2, and so on.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of cc's the described bowl will hold.</li>
</ul>

