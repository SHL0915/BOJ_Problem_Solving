# [Platinum V] 부분배열 고르기 2 - 1989 

[문제 링크](https://www.acmicpc.net/problem/1989) 

### 성능 요약

메모리: 3584 KB, 시간: 20 ms

### 분류

자료 구조, 분할 정복, 누적 합, 세그먼트 트리, 스택

### 문제 설명

<p>Bill is developing a new mathematical theory for human emotions. His recent investigations are dedicated to studying how good or bad days inﬂuent people’s memories about some period of life.</p>

<p>A new idea Bill has recently developed assigns a non-negative integer value to each day of human life. Bill calls this value the emotional value of the day. The greater the emotional value is, the better the day was. Bill suggests that the value of some period of human life is proportional to the sum of the emotional values of the days in the given period, multiplied by the smallest emotional value of the day in it. This schema reﬂects that good on average period can be greatly spoiled by one very bad day.</p>

<p>Now Bill is planning to investigate his own life and find the period of his life that had the greatest value. Help him to do so.</p>

### 입력 

 <p>The first line of the input file contains n — the number of days of Bill’s life he is planning to investigate (1 ≤ n ≤ 100 000). The rest of the file contains n integer numbers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> ranging from 0 to 10<sup>6</sup> — the emotional values of the days. Numbers are separated by spaces and/or line breaks.</p>

### 출력 

 <p>On the first line of the output file print the greatest value of some period of Bill’s life.</p>

<p>On the second line print two numbers l and r such that the period from l-th to r-th day of Bill’s life (inclusive) has the greatest possible value. If there are multiple periods with the greatest possible value, then print any one of them.</p>

