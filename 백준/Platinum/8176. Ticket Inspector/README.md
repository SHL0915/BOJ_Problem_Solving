# [Platinum IV] Ticket Inspector - 8176 

[문제 링크](https://www.acmicpc.net/problem/8176) 

### 성능 요약

메모리: 89500 KB, 시간: 332 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2024년 5월 22일 15:53:03

### 문제 설명

<p>Byteasar works as a ticket inspector in a Byteotian National Railways (BNR) express train that connects Byteburg with Bitwise. The third stage of the BNR reform (The never ending saga of BNR reforms and the Bitwise hub was presented in the problems Railway from the third stage of XIV Polish OI and Station from the third stage of XV Polish OI. Their knowledge, however, is not required at all in order to solve this problem.) has begun. In particular, the salaries system has already been changed. For example, to encourage Byteasar and other ticket inspectors to efficient work, their salaries now depend on the number of tickets (passengers) they inspect. Byteasar is able to control all the passengers on the train in the time between two successive stations, but he is not eager to waste his energy in doing so. Eventually he decided he would check the tickets exactly k times per ride.</p>

<p>Before setting out, Byteasar is given a detailed summary from which he knows exactly how many passengers will travel from each station to another. Based on that he would like to choose the moments of control in such a way that the number of passengers checked is maximal. Obviously, Byteasar is not paid extra for checking someone multiple times - that would be pointless, and would only disturb the passengers. Write a programme that will determine for Byteasar when he should check the tickets in order to maximise his revenue.</p>

### 입력 

 <p>In the first line of the standard input two positive integers n and k (1 ≤ k < n ≤ 600, k ≤ 50) are given. These are separated by a single space and denote, respectively, the number of stations en route and the number of controls Byteasar intends to make. The stations are numbered from 1 to n in the order of appearance on the route.</p>

<p>In the next n-1 lines the summary on passengers is given. The (i+1)-th line contains information on the passengers who enter the train on the station i - it is a sequence of n-i nonnegative integers x<sub>i.i+1</sub>,x<sub>i.i+2</sub>,…,x<sub>i.n</sub> separated by single spaces. The number x<sub>ij</sub> (for i ≤ i < j ≤ n) denotes the number of passengers who enter the train on station i and leave it on station j. The total number of passengers (i.e. the sum of all x<sub>ij</sub>) does not exceed 2,000,000,000.</p>

### 출력 

 <p>Your programme should print out (in a single line) an increasing sequence of k integers from the interval from 1 to n-1 separated by single spaces to the standard output. These numbers should be the numbers of stations upon leaving which Byteasar should control the tickets.</p>

<p> </p>

