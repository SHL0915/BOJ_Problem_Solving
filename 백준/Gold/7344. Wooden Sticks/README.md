# [Gold II] Wooden Sticks - 7344 

[문제 링크](https://www.acmicpc.net/problem/7344) 

### 성능 요약

메모리: 2064 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 정렬

### 문제 설명

<p>There is a pile of n wooden sticks. The length and weight of each stick are known in advance. The sticks are to be processed by a woodworking machine in one by one fashion. It needs some time, called setup time, for the machine to prepare processing a stick. The setup times are associated with cleaning operations and changing tools and shapes in the machine. The setup times of the woodworking machine are given as follows:</p>

<ol style="list-style-type:lower-alpha">
	<li>The setup time for the first wooden stick is 1 minute.</li>
	<li>Right after processing a stick of length l and weight w , the machine will need no setup time for a stick of length l' and weight w' if l ≤ l' and w ≤ w'. Otherwise, it will need 1 minute for setup.</li>
</ol>

<p>You are to find the minimum setup time to process a given pile of n wooden sticks. For example, if you have five sticks whose pairs of length and weight are (4,9) , (5,2), (2,1) , (3,5) , and (1,4) , then the minimum setup time should be 2 minutes since there is a sequence of pairs (1,4) , (3,5) , (4,9) , (2,1) , (5,2).</p>

### 입력 

 <p>The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case consists of two lines: The first line has an integer n , 1 ≤ n ≤ 5000 , that represents the number of wooden sticks in the test case, and the second line contains 2n positive integers l<sub>1</sub>, w<sub>1</sub>, l<sub>2</sub>, w<sub>2</sub>, ... ,l<sub>n</sub>, w<sub>n</sub>, each of magnitude at most 10000 , where l<sub>i</sub> and w<sub>i</sub> are the length and weight of the i th wooden stick, respectively. The 2n integers are delimited by one or more spaces.</p>

### 출력 

 <p>The output should contain the minimum setup time in minutes, one per line.</p>

