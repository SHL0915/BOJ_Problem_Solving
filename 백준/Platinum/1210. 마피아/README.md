# [Platinum I] 마피아 - 1210 

[문제 링크](https://www.acmicpc.net/problem/1210) 

### 성능 요약

메모리: 5132 KB, 시간: 28 ms

### 분류

최대 유량(flow), 최대 유량 최소 컷 정리(mfmc)

### 문제 설명

<p>The police in Byteland got an anonymous tip that the local maﬁa bosses are planning a big transport from the harbour to one of the secret warehouses in the countryside. The police knows the date of the transport and they know that the transport will use the national highway network.</p>

<p>The highway network consists of two-way highway segments, each segment directly connecting two distinct toll stations. A toll station may be connected with many other stations. A vehicle can enter or exit the highway network at toll stations only. The maﬁa transport is known to enter the highways at the toll station closest to the harbour and leave it at the toll station closest to the warehouse (it will not leave and re-enter the highways in between). Special police squads are to be located in selected toll stations. When the transport enters a toll station under surveillance, it will be caught by the police.</p>

<p>From this point of view, the easiest choice would be to place the police squad either at the entry point or the exit point of the transport. However, controlling each toll station has a certain cost, which may vary from station to station. The police wants to keep the overall cost as low as possible, so they need to identify a minimal controlling set of toll stations, which satisﬁes the two conditions:</p>

<ul>
	<li>all traﬃc from the harbour to the warehouse must pass through at least one station from that set,</li>
	<li>the cost of monitoring these stations (i.e. the sum of their individual monitoring costs) is minimal.</li>
</ul>

<p>You may assume that it is possible to get from the harbour to the warehouse using the highways.</p>

<p>Write a program, that:</p>

<ul>
	<li>reads the description of the highway network, the monitoring costs and the locations of the entry and exit points of the transport from the standard input,</li>
	<li>ﬁnds a minimal controlling set of toll stations,</li>
	<li>writes this set to the standard output.</li>
</ul>

### 입력 

 <p>The ﬁrst line of the standard input contains two integers n and m (2 ≤ n ≤ 200 , 1 ≤ m ≤ 20000) — the number of toll stations and the number of direct highway segments. The toll stations are numbered from 1 to n.</p>

<p>The second line contains two integers a and b (1 ≤ a, b ≤ n, a ≠ b) — the numbers of the toll stations closest to the harbour and to the warehouse, respectively.</p>

<p>The following n lines describe the monitoring costs. The i-th of these lines (for 1 ≤ i ≤ n) contains one integer — the monitoring cost of the i-th station (which is positive number not exceeding 10 000 000 ).</p>

<p>The following m lines describe the highway network. The j-th of these lines (for 1 ≤ j ≤ m) contains two integers x and y (1 ≤ x < y ≤ n), indicating that there is a direct highway segment between toll stations numbered x and y. Each highway segment is listed once.</p>

### 출력 

 <p>The only line of the output should contain the numbers of toll stations in a minimal controlling set, given in increasing order, separated by single spaces. If there is more than one minimal controlling set, your program may output anyone of them.</p>

