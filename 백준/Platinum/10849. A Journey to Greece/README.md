# [Platinum III] A Journey to Greece - 10849 

[문제 링크](https://www.acmicpc.net/problem/10849) 

### 성능 요약

메모리: 18280 KB, 시간: 256 ms

### 분류

비트마스킹, 데이크스트라, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 그래프 이론, 외판원 순회 문제

### 문제 설명

<p>For a long time Tim wanted to visit Greece. He has already purchased his flight to and from Athens. Tim has a list of historical sites he wants to visit, e.g., Olympia and Delphi. However, due to recent political events in Greece, the public transport has gotten a little complicated. To make the Greek happy and content with their new government, many short-range bus and train lines have been created. They shall take the citizens around in their neighborhoods, to work or to their doctor. At the same time, long-range trains that are perfect for tourists have been closed down as they are too expensive. This is bad for people like Tim, who really likes to travel by train. Moreover, he has already purchased the Greece’ Card for Public Conveyance (GCPC) making all trains and buses free for him.</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10849/1.png" style="height:266px; width:290px"></p>

<p>Figure A.1: Visual representation of the Sample Input: Tim’s tour has length 18.</p>

<p>Despite his preferred railway lines being closed down, he still wants to make his travel trough Greece. But taking all these local bus and train connections is slower than expected, so he wants to know whether he can still visit all his favorite sites in the timeframe given by his flights. He knows his schedule will be tight, but he has some emergency money to buy a single ticket for a special Greek taxi service. It promises to bring you from any point in Greece to any other in a certain amount of time.</p>

<p>For simplicity we assume, that Tim does never have to wait for the next bus or train at a station. Tell Tim, whether he can still visit all sites and if so, whether he needs to use this taxi ticket.</p>

### 입력 

 <p>The first line contains five integers N, P, M, G and T, where N denotes the number of places in Greece, P the number of sites Tim wants to visit, M the number of connections, G the total amount of time Tim can spend in Greece, and T the time the taxi ride takes (1 ≤ N ≤ 2·10<sup>4</sup>; 1 ≤ P ≤ 15; 1 ≤ M, G ≤ 10<sup>5</sup>; 1 ≤ T ≤ 500).</p>

<p>Then follow P lines, each with two integers p<sub>i</sub> and t<sub>i</sub>, specifying the places Tim wants to visit and the time Tim spends at each site (0 ≤ p<sub>i</sub> < N; 1 ≤ t<sub>i</sub> ≤ 500). The sites p<sub>i</sub> are distinct from each other.</p>

<p>Then follow M lines, each describing one connection by three integers s<sub>i</sub>, d<sub>i</sub> and t<sub>i</sub>, where s<sub>i</sub> and d<sub>i</sub> specify the start and destination of the connection and t<sub>i</sub> the amount of time it takes (0 ≤ s<sub>i</sub>, d<sub>i</sub> < N; 1 ≤ t<sub>i</sub> ≤ 500).</p>

<p>All connections are bi-directional. Tim’s journey starts and ends in Athens, which is always the place 0.</p>

### 출력 

 <p>Print either “impossible”, if Tim cannot visit all sites in time, “possible without taxi”, if he can visit all sites without his taxi ticket, or “possible with taxi”, if he needs the taxi ticket.</p>

