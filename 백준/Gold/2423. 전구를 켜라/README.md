# [Gold I] 전구를 켜라 - 2423 

[문제 링크](https://www.acmicpc.net/problem/2423) 

### 성능 요약

메모리: 25844 KB, 시간: 80 ms

### 분류

0-1 너비 우선 탐색(0_1_bfs), 다익스트라(dijkstra), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Casper is designing an electronic circuit on a N × M rectangular grid plate. There are N × M square tiles that are aligned to the grid on the plate. Two (out of four) opposite corners of each tile are connected by a wire.</p>

<p>A power source is connected to the top left corner of the plate. A lamp is connected to the bottom right corner of the plate. The lamp is on only if there is a path of wires connecting power source to lamp. In order to switch the lamp on, any number of tiles can be turned by 90° (in both directions).</p>

<p style="text-align: center;"><img alt="" src="" style="width: 289px; height: 195px;"></p>

<p>In the picture above the lamp is off. If any one of the tiles in the second column from the right is turned by 90°, power source and lamp get connected, and the lamp is on.</p>

<p>Write a program to ﬁnd out the minimal number of tiles that have to be turned by 90° to switch the lamp on.</p>

### 입력 

 <p>The ﬁrst line of input contains two integer numbers N and M, the dimensions of the plate. In each of the following N lines there are M symbols – either <code>\</code> or <code>/</code> – which indicate the direction of the wire connecting the opposite vertices of the corresponding tile.</p>

### 출력 

 <p>There must be exactly one line of output. If it is possible to switch the lamp on, this line must contain only one integer number: the minimal number of tiles that have to be turned to switch on the lamp. If it is not possible, output the string: NO SOLUTION</p>

