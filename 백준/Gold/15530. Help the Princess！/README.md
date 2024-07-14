# [Gold IV] Help the Princess! - 15530 

[문제 링크](https://www.acmicpc.net/problem/15530) 

### 성능 요약

메모리: 2352 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 7월 14일 19:40:16

### 문제 설명

<p>The people of a certain kingdom make a revolution against the bad government of the princess. The revolutionary army invaded the royal palace in which the princess lives. The soldiers of the army are exploring the palace to catch the princess. Your job is writing a program to decide that the princess can escape from the royal palace or not.</p>

<p>For simplicity, the ground of the palace is a rectangle divided into a grid. There are two kinds of cells in the grid: one is a cell that soldiers and the princess can enter, the other is a cell that soldiers or the princess cannot enter. We call the former an empty cell, the latter a wall. The princess and soldiers are in different empty cells at the beginning. There is only one escape hatch in the grid. If the princess arrives the hatch, then the princess can escape from the palace. There are more than or equal to zero soldiers in the palace.</p>

<p>The princess and all soldiers take an action at the same time in each unit time. In other words, the princess and soldiers must decide their action without knowing a next action of the other people. In each unit time, the princess and soldiers can move to a horizontally or vertically adjacent cell, or stay at the current cell. Furthermore the princess and soldiers cannot move out of the ground of the palace. If the princess and one or more soldiers exist in the same cell after their move, then the princess will be caught. It is guaranteed that the princess can reach the escape hatch via only empty cells if all soldiers are removed from the palace.</p>

<p>If there is a route for the princess such that soldiers cannot catch the princess even if soldiers make any moves, then the princess can escape the soldiers. Note that if the princess and a soldier arrive the escape hatch at the same time, the princess will be caught. Can the princess escape from the palace?</p>

### 입력 

 <p>Each dataset is formatted as follows.</p>

<pre>H W
map<sub>1</sub>
.
.
.
map<sub>H</sub></pre>

<p>The first line of a dataset contains two positive integers H and W delimited by a space, where H is the height of the grid and W is the width of the grid. (2 ≤ H, W ≤ 200)</p>

<p>The i-th line of the subsequent H lines gives a string map<sub>i</sub>, which represents situation in the ground of palace.</p>

<p>map<sub>i</sub> is a string of length W, and the j-th character of map<sub>i</sub> represents the state of the cell of the i-th row and the j-th column.</p>

<p>‘@’, ‘<mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mi class="mjx-n"></mjx-mi><mjx-script style="vertical-align: 0.363em;"><mjx-mo class="mjx-var" size="s"><mjx-c class="mjx-c2032"></mjx-c></mjx-mo></mjx-script></mjx-msup><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c2035 TEX-A"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mi></mi><mo data-mjx-alternate="1">′</mo></msup><mo>,</mo><mo data-mjx-pseudoscript="true">‘</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$’, ‘%’, ‘.’, and ‘#’ represent the princess, a soldier, the escape hatch, an empty cell, and a wall, respectively. It is guaranteed that there exists only one ‘@’, only one ‘%’, and more than or equal to zero ‘$</span></mjx-container>’ in the grid.</p>

### 출력 

 <p>Output a line containing a word “Yes”, if the princess can escape from the palace. Otherwise, output “No”.</p>

