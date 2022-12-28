# [Gold IV] 인접한 비트의 개수 - 2698 

[문제 링크](https://www.acmicpc.net/problem/2698) 

### 성능 요약

메모리: 10068 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>For a string of n bits x<sub>1</sub>, x<sub>2</sub>, x<sub>3</sub>, …, x<sub>n</sub>, the adjacent bit count of the string (AdjBC(x)) is given by </p>

<pre>x<sub>1</sub>*x<sub>2</sub> + x<sub>2</sub>*x<sub>3</sub> + x<sub>3</sub>*x<sub>4</sub> + … + x<sub>n-1</sub>*x<sub>n</sub></pre>

<p>which counts the number of times a 1 bit is adjacent to another 1 bit. For example: </p>

<pre>AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0</pre>

<p>Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2: </p>

<pre>11100, 01110, 00111, 10111, 11101, 11011</pre>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100 and the parameters n and k will be chosen so that the result will fit in a signed32-bit integer. </p>

### 출력 

 <p>For each data set there is one line of output. It contains the number of n-bit strings with adjacent bit count equal to k. </p>

