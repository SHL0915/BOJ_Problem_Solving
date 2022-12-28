# [Gold IV] 단어 섞기 - 9177 

[문제 링크](https://www.acmicpc.net/problem/9177) 

### 성능 요약

메모리: 2184 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍(dp), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but each must stay in its original order.</p>

<p>For example, consider forming "tcraete" from "cat" and "tree":</p>

<ul>
	<li>String A: cat</li>
	<li>String B: tree</li>
	<li>String C: tcraete</li>
</ul>

<p>As you can see, we can form the third string by alternating characters from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree":</p>

<ul>
	<li>String A: cat</li>
	<li>String B: tree</li>
	<li>String C: catrtee</li>
</ul>

<p>Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".</p>

### 입력 

 <p>The first line of input file contains a single positive integer from 1 through1000. It represents the number of data sets to follow. The processing for each data set is identical. The data sets appear on the following lines, one data set per line.For each data set, the line of input consists of three strings, separated by a single space. All strings are composed of upper and lower case letters only. The length of the third string is always the sum of the lengths of the first two strings. The first two strings will have lengths between 1 and 200 characters, inclusive.</p>

### 출력 

 <p>For each data set, print:</p>

<pre>Data set n: yes</pre>

<p>if the third string can be formed from the first two, or</p>

<pre>Data set n: no</pre>

<p>if it cannot. Of course n should be replaced by the data set number. See the sample output below for an example.</p>

