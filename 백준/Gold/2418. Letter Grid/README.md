# [Gold V] Letter Grid - 2418 

[문제 링크](https://www.acmicpc.net/problem/2418) 

### 성능 요약

메모리: 33944 KB, 시간: 24 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색

### 문제 설명

<p>Consider the following letter grid:</p>

<p><img alt="" src="https://www.acmicpc.net/JudgeOnline/upload/201105/Screen%20shot%202011-05-10%20at%2012_14_03%20AM.png" style="height:81px; width:137px"></p>

<p>There are 7 ways to read the word TARTU from the grid:</p>

<p><img alt="" src="https://www.acmicpc.net/JudgeOnline/upload/201105/Screen%20shot%202011-05-10%20at%2012_14_46%20AM.png" style="height:144px; width:588px"></p>

<p>Given a letter grid and a word, your task is to determine the number of ways the word can be read from the grid. The ﬁrst letter of the word can be in any cell of the grid, and after each letter, the next letter has to be in one of the neighbour cells (horizontally, vertically or diagonally). A cell can be used multiple times when reading the word.</p>

### 입력 

 <p>The ﬁrst line of the ﬁle grid.in contains three integers: H (1 ≤ H ≤ 200), the height of the grid, W (1 ≤ W ≤ 200), the width of the grid, and L (1 ≤ L ≤ 100), the length of the word. The following H lines each containing W letters describe the grid. The last line containing L letters describes the word. All letters in the grid and in the word are uppercase English letters (A. . . Z).</p>

### 출력 

 <p>The only line of the ﬁle grid.out should contain one integer: the number of ways the word can be read from the grid. You may assume that the answer is always at most 10<sup>18</sup>.</p>

