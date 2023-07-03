# [Platinum III] Game Design - 16607 

[문제 링크](https://www.acmicpc.net/problem/16607) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기, 그리디 알고리즘, 구현

### 문제 설명

<p>Carol enjoys playing with wooden games. The objective of the game that fascinates her the most is to tilt a maze, made out of 1 cm-by-1 cm blocks, in any of the four cardinal directions to move a ball to a hole in the centre at (0, 0). As shown in Figure G.1, once the 1 cm wide ball starts moving, it keeps going until either it runs into a wooden block, or it falls into the hole—whichever comes first.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ff434cb1-0332-44b1-992e-ce10015475af/-/preview/" style="width: 581px; height: 226px;"></p>

<p style="text-align: center;">Figure G.1: Illustration of Sample Output 1.</p>

<p>Carol is interested in designing a maze of her own, and like any good game designer she already has a fixed solution in mind. This is given as a sequence of tilt moves which must all be followed in order. If any move causes nothing to happen, for example because the ball is up against a block in that direction or already in the hole, the solution does not count.</p>

<p>The ball can be placed anywhere to start. Carol will take care of adding a square border of blocks covering the rows and columns 10<sup>9</sup> + 1 cells away from the centre in each direction.</p>

<p>Design a board which can be won by applying her sequence of moves.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with a string s consisting of only the characters “LRUD” (1 ≤ |s| ≤ 20), the sequence of moves. These characters correspond to the directions −x, +x, +y, −y respectively. No two consecutive characters in s are the same.</li>
</ul>

### 출력 

 <p>If it is possible to create a maze with the given solution, first output x and y, the integer coordinates for the ball to start at. Then on the next line, output n, the number of blocks to use. On each of the remaining n lines, output s and t, the integer coordinates of a block.</p>

<p>Otherwise, output “impossible”.</p>

<p>You may use at most n ≤ 104 blocks. All coordinates used must be at most 10<sup>9</sup> in absolute value. No coordinate pair may be the same as the centre or any other coordinate pair. If there are multiple valid solutions, you may output any one of them.</p>

