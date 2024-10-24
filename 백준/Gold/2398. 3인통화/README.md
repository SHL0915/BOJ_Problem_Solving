# [Gold I] 3인통화 - 2398 

[문제 링크](https://www.acmicpc.net/problem/2398) 

### 성능 요약

메모리: 5244 KB, 시간: 1328 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2024년 10월 24일 20:02:06

### 문제 설명

<p>A telecom company would like to offer a three-party conference call service. This service enables three customers to participate in a telephone conversation simultaneously. A customer accesses the interconnection network of the telephone system via a switch. The network consists of switches linked by bidirectional lines. Over the existing network, the three participants accessing the network via three different switches, must be connected with the minimum cost. Note that it is possible to connect any two switches. You will be given all the links between the switches of the network along with their associated costs. You are requested to find the connections which will minimize the total cost of interconnecting the three switches to which the participants in a conference call are connected.</p>

### 입력 

 <p>The input is a text file named conf.inp. The first line contains two numbers : The number of switches, designated by (N <= 1000) and the number of switch-to-switch links in the network, designated by E, separated by a blank. Each of the following E input lines contains three integers, designated by i, j and c<sub>i,j</sub> where i and j are the numbers of two different switches and ci,jis the cost of using the link between i and j in a conference call (1 <= c<sub>i,j</sub><= 100), each separated by one blank. The last line of input contains three integers, which designate the three switches that participate in the conference call, each separated by one blank. The switches are identified with integers 1 through N consecutively</p>

<p> </p>

### 출력 

 <p>The output must be a text file named conf.out. The first line must contain the total (minimal) cost of establishing a conference call among the given three switches and the number R of switch-to-switch connections needed to establish this conference call, separated by a blank. Each of the following R lines must contain two integers, which denote that the link between the switch numbered by the first integer and the switch numbered by the second integer is included in the solution -ordering of between the two switches is not important. The ordering among the last R lines of the output is also not important.</p>

