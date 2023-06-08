# [Gold IV] Drawing - 11324 

[문제 링크](https://www.acmicpc.net/problem/11324) 

### 성능 요약

메모리: 2212 KB, 시간: 0 ms

### 분류

오일러 경로, 그래프 이론, 그래프 탐색

### 문제 설명

<p>One day, the Artful Coder saw an interesting shape. He immediately started wondering if it would be possible to draw it on a piece of paper using a pencil via one continuous line. After trying for several minutes, he eventually gave up and started writing a program to automate the procedure.</p>

<p>Now, despite his name, the Artful Coder really isn't that good a programmer. He doesn't know if his own program produces correct output, so he's looking for a second opinion. Given a description of a shape, determine if it can be drawn in one continuous motion of a pencil, without backtracking over any already-drawn line segments. The shape will be given as a collection of straight line segments, in no particular order, that can only touch at their endpoints.</p>

### 입력 

 <p>The input consists of multiple shapes. Each shape begins with a single number 0 < <strong>N</strong> < 1000, which is the number of line segments in the shape. There are then <strong>N</strong> lines following, each with four integers <strong>a</strong>, <strong>b</strong>, <strong>c</strong>, and <strong>d</strong>, describing a line from <strong>(a, b)</strong> to <strong>(c, d)</strong>. You may assume that at most one of <strong>a = c</strong> or <strong>b = d</strong> will be true, and that -1000 < <strong>a</strong>,<strong>b</strong>,<strong>c</strong>,<strong>d</strong> < 1000.</p>

<p>The input will be terminated with a shape that has <strong>N = 0</strong>, which should not be processed.</p>

### 출력 

 <p>Output one line for each input shape, containing either "Impossible" or "Possible" (without quotes).</p>

