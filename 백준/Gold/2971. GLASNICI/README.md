# [Gold III] GLASNICI - 2971 

[문제 링크](https://www.acmicpc.net/problem/2971) 

### 성능 요약

메모리: 3460 KB, 시간: 80 ms

### 분류

이분 탐색, 그리디 알고리즘

### 제출 일자

2024년 4월 12일 16:40:01

### 문제 설명

<p>A long straight road connects two villages. Along the road, N messengers are stationed and, when needed, they exchange messages using mostly their legs, but also their vocal cords and ears. The first messenger (the closest to the first village) has a radio-receiver which he uses to keep track of current ongoings in the country. When he finds out who has been evicted from whichever reality show is currently popular, he starts running as fast as he can to share the unfortunate (or fortunate) news with everyone else. While running, he shouts the name of the evicted person so that any fellow messengers that are close enough can hear him. Meanwhile, the remaining messengers do not merely sit and wait, but also run themselves, all with the selfless goal of sharing the news with everyone as fast as possible.</p>

<p>The running and shouting proceeds as follows:</p>

<ul>
	<li>Each of the messengers may run whenever, in either direction, at a speed of at most 1 unit per second, or may decide not to run at all and stand still.</li>
	<li>All messengers that know the news shout it at all times. One messenger can hear another messenger shouting (and learn the news) if the distance between them is at most K units.</li>
</ul>

<p>Write a program that, given the initial locations of the messengers, determines the least amount of time (in seconds) needed for all messengers to learn the news. The location of every messenger is given with a positive real number – the distance from the first village. As mentioned above, initially only the first messenger knows the news.</p>

### 입력 

 <p>The first line contains the real number K (0 ≤ K ≤ 106 ), the largest distance at which two messengers can hear each other.</p>

<p>The second line contains the integer N (1 ≤ N ≤ 100000), the number of messengers.</p>

<p>Each of the following N lines contains one real number D (0 ≤ D ≤ 10<sup>9</sup>), the distance of one messenger from the first village. The distances will be sorted in ascending order. It is possible for multiple messengers to be at the same location.</p>

### 출력 

 <p>Output a real number, the least time for all messengers to learn the news. Your output will be accepted if it differs from the official output by no more than ±0.001.</p>

