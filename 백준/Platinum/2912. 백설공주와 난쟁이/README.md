# [Platinum II] 백설공주와 난쟁이 - 2912 

[문제 링크](https://www.acmicpc.net/problem/2912) 

### 성능 요약

메모리: 3392 KB, 시간: 248 ms

### 분류

자료 구조, mo's, 오프라인 쿼리, 무작위화, 세그먼트 트리

### 제출 일자

2024년 4월 2일 23:36:31

### 문제 설명

<p>Snow White and the N dwarfs live in the forest. While the dwarfs mine away Snow White hangs around social networks.</p>

<p>Each morning the dwarfs form a long line and go whistling away to the mine. Snow White runs around them and snaps pictures to upload onto her favorite social network.</p>

<p>When dwarfs enter the mine, Snow White goes back to their house and goes through the pictures, selecting pretty ones. Each dwarf has a colored cap, and there are C different colors. A picture is pretty if more than half caps on it are of the same color. In other words, if there are K dwarfs on the picture, it is pretty if strictly more than K / 2 dwarfs have same colored caps.</p>

<p>Write a program that will check for a set of M pictures if they are pretty, and what color is dominating if they are.</p>

### 입력 

 <p>First line contains two integers N and C (3 ≤ N ≤ 300 000, 1 ≤ C ≤ 10 000) number of dwarfs and number of colors.</p>

<p>Second line contains N integers between 1 and C (inclusive), colors of dwarves hats, ordered the way they formed the line that morning.</p>

<p>Third line contains M (1 ≤ M ≤ 10000), number of pictures.</p>

<p>Next M lines contain two integers A and B (1 ≤ A ≤ B ≤ N). Each line describes one picture. On it there are all dwarves starting from A-th all the way to the B-th.</p>

### 출력 

 <p>Output M lines. For each picture output “no” if Snow White doesn't think the picture is pretty, and “yes X”, where X is the color dominating on the picture, if she does.</p>

