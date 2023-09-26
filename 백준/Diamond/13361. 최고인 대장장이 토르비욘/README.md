# [Diamond V] 최고인 대장장이 토르비욘 - 13361 

[문제 링크](https://www.acmicpc.net/problem/13361) 

### 성능 요약

메모리: 22804 KB, 시간: 212 ms

### 분류

값 / 좌표 압축, 자료 구조, 분리 집합, 그래프 이론, 그래프 탐색

### 문제 설명

<p>Oni loved to build tall towers of blocks. Her parents were not as amused though. They were on the verge of going crazy over that annoying loud noise whenever a tower fell to the ground, not to mention having to pick up blocks from the floor all the time. Oni’s mother one day had an idea. Instead of building the tower out of physical blocks, why couldn’t Oni construct a picture of a tower using two-dimensional rectangles that she montaged on a board on the wall? Oni’s mother cut out rectangles of various sizes and colors, drew a horizontal line representing the ground at the bottom of the board, and explained the rules of the game to Oni: every rectangle must be placed immediately above another rectangle or the ground line. For every rectangle you can choose which of its two orientations to use. I.e., if a rectangle has sides of length s and t, you can either have a side of length s horizontally or a side of length t horizontally. You may place exactly one rectangle immediately above another one if its horizontal side is strictly smaller than the horizontal side of the rectangle beneath. Exactly one rectangle must be placed on the ground line. Now try to build as tall a tower as possible!</p>

<p>Oni’s mother took extra care to make sure that it was indeed possible to use all rectangles in a tower in order not to discourage Oni. But of course Oni quickly lost interest anyway and returned to her physical blocks. After all, what is the point of building a tower if you cannot feel the suspense before the inevitable collapse? Her father on the other hand got interested by his wife’s puzzle as he realized this is not a kids’ game.</p>

### 입력 

 <p>The first line of input contains an integer n (1 ≤ n ≤ 250 000), the number of rectangles. Then follow n lines, each containing two integers s and t (1 ≤ s ≤ t ≤ 10<sup>9</sup> nm), the dimensions of a rectangle.</p>

<p>You may safely assume that there is a way to build a tower using all n rectangles.</p>

### 출력 

 <p>Output a single line containing the height in nm of the tallest possible tower using all the rectangles while having the horizontal side lengths strictly decreasing from bottom to top.</p>

