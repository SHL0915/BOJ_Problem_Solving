# [Platinum III] 보안 업체 - 4243 

[문제 링크](https://www.acmicpc.net/problem/4243) 

### 성능 요약

메모리: 2180 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>Today most shopkeepers employ a security service. On a famous street, there are several shops. The shops are protected by a guard belonging to a security company, which is also located on the street.</p>

<p>For simplicity, we consider the shops and the company as points p<sub>i</sub> on a line, running in order from left to right. The company is located at a point p<sub>a</sub> for some a, denote by s. Starting at the point s, the guard should visit each point p<sub>i</sub> at least once a day to protect the shops. For each i, it takes t[p<sub>i</sub>,p<sub>i+1</sub>] time for the guard to move between p<sub>i</sub> and p<sub>i+1</sub>. The latency ℓ<sub>i</sub> of p<sub>i</sub> is considered to be the time when the guard first visits p<sub>i</sub> after leaving s. Obviously the latency ℓ<sub>a</sub> of the starting point s = p<sub>a</sub> is 0. The guard shall travel to minimize the sum of latencies, which is Σ<sub>i</sub>ℓ<sub>i</sub>.</p>

<p>For example, in Figure 1, there are six points p<sub>1</sub> to p<sub>6</sub>, where the starting point s is p<sub>3</sub>. Alsot[p<sub>1</sub>,p<sub>2</sub>] = 7, t[p<sub>2</sub>,p<sub>3</sub>] = 4, t[p<sub>3</sub>,p<sub>4</sub>] = 1, t[p<sub>4</sub>,p<sub>5</sub>] = 2, t[p<sub>5</sub>,p<sub>6</sub>] = 9. When the guard first walks right from s, the latency ℓ<sub>4</sub> and ℓ<sub>5</sub> are determined as 1 and 3, respectively. if the guard travels as in Figure 1, then the sum of all the latencies is 71. It is minimum for all possible travels of the guard.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images/security.png" style="height:100px; width:415px"></p>

<p style="text-align: center;">Figure 1.</p>

<p>Give an integer N, the number of points, and the times t[p<sub>i</sub>,p<sub>i+1</sub>] for the guard to move between p<sub>i</sub> and p<sub>i+1</sub>. i = 1, ..., N-1, write a program to minimize the sum of latencies of points when traveling from a starting point.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with an integer N (1 ≤ N ≤ 100), the number of points. The second line contains an integer a (1 ≤ a ≤ N), saying that the a-th point is the starting point, that is, p<sub>a</sub> = s. The i-th line of the following N-1 lines contains an integer t (1 ≤ t ≤ 15,000,000), representing the time t[p<sub>i</sub>,p<sub>i+1</sub>] for i=1,...,N-1.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the minimum of the sum of latencies for all possible movements of the guard.</p>

