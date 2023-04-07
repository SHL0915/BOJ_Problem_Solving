# [Platinum IV] Cheering up the Cows - 1185 

[문제 링크](https://www.acmicpc.net/problem/1185) 

### 성능 요약

메모리: 4536 KB, 시간: 32 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 문제 설명

<p>Farmer John has grown so lazy that he no longer wants to continue maintaining the cow paths that currently provide a way to visit each of his N (5 <= N <= 10,000) pastures (conveniently numbered 1..N). Each and every pasture is home to one cow. FJ plans to remove as many of the P (N-1 <= P <= 100,000) paths as possible while keeping the pastures connected. You must determine which N-1 paths to keep.</p>

<p>Bidirectional path j connects pastures S_j and E_j (1 <= S_j <= N; 1 <= E_j <= N; S_j != E_j) and requires L_j (0 <= L_j <= 1,000) time to traverse. No pair of pastures is directly connected by more than one path.</p>

<p>The cows are sad that their transportation system is being reduced. You must visit each cow at least once every day to cheer her up. Every time you visit pasture i (even if you're just traveling through), you must talk to the cow for time C_i (1 <= C_i <= 1,000).</p>

<p>You will spend each night in the same pasture (which you will choose) until the cows have recovered from their sadness. You will end up talking to the cow in the sleeping pasture at least in the morning when you wake up and in the evening after you have returned to sleep.</p>

<p>Assuming that Farmer John follows your suggestions of which paths to keep and you pick the optimal pasture to sleep in, determine the minimal amount of time it will take you to visit each cow at least once in a day.</p>

<p>For your first 10 submissions, you will be provided with the results of running your program on a part of the actual test data.</p>

### 입력 

 <p>* Line 1: Two space-separated integers: N and P</p>

<p>* Lines 2..N+1: Line i+1 contains a single integer: C_i</p>

<p>* Lines N+2..N+P+1: Line N+j+1 contains three space-separated integers: S_j, E_j, and L_j</p>

### 출력 

 <p>* Line 1: A single integer, the total time it takes to visit all the cows (including the two visits to the cow in your sleeping-pasture)</p>

