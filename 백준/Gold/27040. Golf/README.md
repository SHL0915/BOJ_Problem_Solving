# [Gold IV] Golf - 27040 

[문제 링크](https://www.acmicpc.net/problem/27040) 

### 성능 요약

메모리: 5856 KB, 시간: 264 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 너비 우선 탐색

### 문제 설명

<p>Like everyone else, the cows love the relaxation and challenge of a good game of golf.  Bessie plays extraordinarily well and can aim her shot perfectly toward the hole, every time.  Furthermore, every club drives the ball precisely the distance specified for that club, every time.</p>

<p>Bessie is a smart cow.  She knows that she can overshoot and then hit back toward the hole, and she uses this fact to her advantage.</p>

<p>For those who don't play golf, every time the ball is hit, a 'stroke' is accrued.  The object of golf is to hit the ball from the tee and subsequently into the hole in the fewest number of strokes. The lowest score wins.</p>

<p>Bessie needs a program to select the best combination of clubs to reach a given hole in the fewest strokes. She is especially interested to hear if this task is impossible, in which case she graciously acknowledges the loss. Cows are sturdier than humans, so Bessie can carry C (1 ≤ C ≤ 32) clubs, and the total distance, D, from the tee to the hole does not exceed 10,000 yards (1 ≤ D ≤ 10,000).</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, D and C.</li>
	<li>Lines 2..C+1: Each line describes a single club by with a single integer R (1 ≤ R ≤ 400) that is the number of yards that club will drive.  No two clubs share the same distance specification.</li>
</ul>

### 출력 

 <p>A single line with the integer that is the minimum number of strokes required to move the ball from the tee to the hole.  Output 0 if it is impossible to get to the hole using the given clubs.</p>

