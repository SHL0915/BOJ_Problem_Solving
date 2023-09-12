# [Diamond V] Darts - 3858 

[문제 링크](https://www.acmicpc.net/problem/3858) 

### 성능 요약

메모리: 6020 KB, 시간: 248 ms

### 분류

이분 탐색, 조합론, 다이나믹 프로그래밍, 게임 이론, 수학, 매개 변수 탐색

### 문제 설명

<p>After a long week of work at the ICPC Headquarters, Bill and his friends usually go to a small pub on Friday evenings to have a couple of beers and play darts. All of them are well aware of the fact that their ability at darts decreases at the same rate as the amount of beer left in their mugs.</p>

<p>They always play 501, one of the easiest games. Players start with a score of N points (typically, N = 501, hence the name) and take turns throwing darts. The score of each player decreases by the value of the section hit by the dart, unless the score becomes negative, in which case it remains unchanged. The first player to reach a score of 0 wins. The figure below shows the dartboard with which the game is played.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images2/dart.png" style="height:170px; width:182px"></p>

<p style="text-align: center;">Figure 1: Dartboard</p>

<p>As the clock ticks closer to midnight and they start running out of beer, everyone wonders the same: is it worth trying to aim the dart at a specific section? Or is it better just to throw the dart at a random section on the dartboard? You are asked to deal with the question by finding out what would happen if two players (A and B) applying these two different strategies were to play against each other:</p>

<p>Player A throws the darts at random, and consequently they land with equal probability in each of the sections of the dartboard.<br>
If Player B aims at a certain section, the dart has the same probability of landing in the correct one as in each of the two adjacent ones (the neighbouring regions to the left and right). Moreover, he is completely aware of his ability and sober enough to aim at the section that maximizes his probability of winning.</p>

<p>Given the initial score of both players, can you determine the probability that the first player wins? Of course, being the first to throw a dart might be advantageous, so the answer depends on who plays first.</p>

### 입력 

 <p>The input consists of a series of lines, each containing an integer N (1 ≤ N ≤ 501), the initial score of both players. A case with N = 0 marks the end of the input and must not be processed.</p>

### 출력 

 <p>For each number in the input, your program should output a line containing two real numbers: the probability that A wins if A throws the first dart, and the probability that B wins if B throws the first dart. Your answers should be accurate to within an absolute or relative error of 10<sup>−8</sup>.</p>

