# [Platinum III] 교수님은 기다리지 않는다 - 3830 

[문제 링크](https://www.acmicpc.net/problem/3830) 

### 성능 요약

메모리: 3848 KB, 시간: 372 ms

### 분류

자료 구조(data_structures), 분리 집합(disjoint_set)

### 문제 설명

<p>In a laboratory, an assistant, Nathan Wada, is measuring weight diﬀerences between sample pieces pair by pair. He is using a balance because it can more precisely measure the weight difference between two samples than a spring scale when the samples have nearly the same weight.</p>

<p>He is occasionally asked the weight differences between pairs of samples. He can or cannot answer based on measurement results already obtained.</p>

<p>Since he is accumulating a massive amount of measurement data, it is now not easy for him to promptly tell the weight differences. Nathan asks you to develop a program that records measurement results and automatically tells the weight differences.</p>

### 입력 

 <p>The input consists of multiple datasets. The fi rst line of a dataset contains two integers N and M. N denotes the number of sample pieces (2 ≤ N ≤ 100, 000). Each sample is assigned a unique number from 1 to N as an identifi er. The rest of the dataset consists of M lines (1 ≤ M ≤ 100, 000), each of which corresponds to either a measurement result or an inquiry. They are given in chronological order.</p>

<p>A measurement result has the format,</p>

<pre>! a b w</pre>

<p>which represents the sample piece numbered b is heavier than one numbered a by w micrograms (a ≠ b). That is, w = w<sub>b</sub> - w<sub>a</sub>, where w<sub>a</sub> and w<sub>b</sub> are the weights of a and b, respectively. Here, w is a non-negative integer not exceeding 1,000,000.</p>

<p>You may assume that all measurements are exact and consistent.</p>

<p>An inquiry has the format,</p>

<pre>? a b</pre>

<p>which asks the weight difference between the sample pieces numbered a and b (a ≠ b).</p>

<p>The last dataset is followed by a line consisting of two zeros separated by a space.</p>

### 출력 

 <p>For each inquiry, <code>? a b</code>, print the weight difference in micrograms between the sample pieces numbered a and b, w<sub>b</sub> - w<sub>a</sub>, followed by a newline if the weight difference can be computed based on the measurement results prior to the inquiry. The difference can be zero, or negative as well as positive. You can assume that its absolute value is at most 1,000,000. If the difference cannot be computed based on the measurement results prior to the inquiry, print UNKNOWN followed by a newline.</p>

