# [Gold III] 소가 길을 건너간 이유 8 - 14462 

[문제 링크](https://www.acmicpc.net/problem/14462) 

### 성능 요약

메모리: 5944 KB, 시간: 600 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p> </p>

<p>Farmer John raises N breeds of cows (1 ≤ N ≤ 1000), conveniently numbered 1…N. Some pairs of breeds are friendlier than others, a property that turns out to be easily characterized in terms of breed ID: breeds a and b are friendly if |a−b| ≤ 4, and unfriendly otherwise.</p>

<p>A long road runs through FJ's farm. There is a sequence of N fields on one side of the road (one designated for each breed), and a sequence of N fields on the other side of the road (also one for each breed). To help his cows cross the road safely, FJ wants to draw crosswalks over the road. Each crosswalk should connect a field on one side of the road to a field on the other side where the two fields have friendly breed IDs (it is fine for the cows to wander into fields for other breeds, as long as they are friendly). Each field can be accessible via at most one crosswalk (so crosswalks don't meet at their endpoints).</p>

<p>Given the ordering of N fields on both sides of the road through FJ's farm, please help FJ determine the maximum number of crosswalks he can draw over his road, such that no two intersect.</p>

<p> </p>

### 입력 

 <p>The first line of input contains N. The next N lines describe the order, by breed ID, of fields on one side of the road; each breed ID is an integer in the range 1…N. The last N lines describe the order, by breed ID, of the fields on the other side of the road. Each breed ID appears exactly once in each ordering.</p>

<p> </p>

### 출력 

 <p>Please output the maximum number of disjoint "friendly crosswalks" Farmer John can draw across the road.</p>

<p> </p>

