# [Platinum I] 완전 중요한 간선 - 5651 

[문제 링크](https://www.acmicpc.net/problem/5651) 

### 성능 요약

메모리: 3412 KB, 시간: 112 ms

### 분류

최대 유량

### 문제 설명

<p>You would like to broadcast the ACM ICPC Regional Contest event in Phuket in real time. To do so, you have to transmit the video data from the recording machine to the broadcasting server in Bangkok. You have the map of the entire network of Thailand. There are N routers and M one-directional links. Each link i, for 1 <= i <= M, can transmit data from Router F<sub>i</sub> to Router T<sub>i</sub>, with bandwidth B<sub>i</sub>. It is possible that there are more than one link that transmits data from a particular router to another particular router.</p>

<p>The recording machine is connected to Router 1 with an unlimited-bandwidth link, and the broadcasting server is connected to Router N also with an unlimited-bandwidth link.</p>

<p>To transmit video data from Router 1 to Router N, you split the video data and transmit them using many transmission paths. A transmission path is a path from Router 1 to Router N. Each path can transmit data with some bandwidth b and utilize bandwidth b from every link used by this path.</p>

<p>It is possible to use many transmission paths with various bandwidths and many paths can share a link. However, the total bandwidth of all paths using any link i must not exceed the bandwidth B<sub>i</sub>. The total video bandwidth is the sum of all transmission bandwidths of all transmission paths.</p>

<p>Given the network map, you can calculate the best possible scheme to maximize the transmission bandwidth from Router 1 to Router N. However, you are afraid that some link might fail to transmit data as fast as the claimed bandwidth. For some link i, it is still possible to obtain the best transmission bandwidths even when the link bandwidth drops from B<sub>i</sub> to B<sub>i</sub>–1. But for some link i, if this occurs, the best video transmission bandwidth also drops; call this link a crucial link. Note that when considering if an edge i is crucial, we only consider only edge i, while assuming that all bandwidths of all other links remain unchanged. i.e., we consider each edge separately. </p>

<p>For each test case, write a program that compute the number of crucial links.</p>

### 입력 

 <p>The first line of the input contains an integer K, the number of test cases (1 <= K <= 15). Each test case is in the following format. The first line of each test case contains a pair of integers N and M (2 <= N <= 300; 2 <= M <= 5,000). The next M lines contain link information. For 1 <= i <= M, line 1 + i contains 3 integers F<sub>i</sub>, T<sub>i</sub>, and B<sub>i</sub> (1 <= F<sub>i</sub> <= N; 1 <= T<sub>i</sub> <= N; 1 <= B<sub>i</sub> <= 1,000). The sum of all bandwidths B<sub>i</sub> is at most 20,000.</p>

### 출력 

 <p>Your program must output K integers, each on a separate line. For each test case, your program must output the number of crucial links.</p>

