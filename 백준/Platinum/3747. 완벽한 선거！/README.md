# [Platinum IV] 완벽한 선거! - 3747 

[문제 링크](https://www.acmicpc.net/problem/3747) 

### 성능 요약

메모리: 16292 KB, 시간: 504 ms

### 분류

2-sat(2_sat), 그래프 이론(graphs), 강한 연결 요소(scc)

### 문제 설명

<p>In a country (my memory fails to say which), the candidates {1, 2 ... N} are running in the parliamentary election. An opinion poll asks the question "For any two candidates of your own choice, which election result would make you happy?". The accepted answers are shown in the table below, where the candidates i and j are not necessarily different, i.e. it may happen that i=j. There are M poll answers, some of which may be similar or identical. The problem is to decide whether there can be an election outcome1 that conforms to all M answers. We say that such an election outcome is perfect. The result of the problem is 1 if a perfect election outcome does exist and 0 otherwise.</p>

<p>Write a program that reads sets of data from an input text file. </p>

<table class="table table-bordered" style="width:65%">
	<thead>
		<tr>
			<th>Accepted answers to the poll question</th>
			<th>Encoding</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>I would be happy if at least one from i and j is elected.</td>
			<td>+i +j</td>
		</tr>
		<tr>
			<td>I would be happy if at least one from i and j is not elected.</td>
			<td>-i -j</td>
		</tr>
		<tr>
			<td>I would be happy if i is elected or j is not elected or both events happen.</td>
			<td>+i -j</td>
		</tr>
		<tr>
			<td>I would be happy if i is not elected or j is elected or both events happen.</td>
			<td>-i +j</td>
		</tr>
	</tbody>
</table>

### 입력 

 <p>Each data set corresponds to an instance of the problem and starts with two integral numbers: 1≤N≤1000 and 1≤M≤1000000. The data set continues with M pairs ±i ±j of signed numbers, 1≤i,j≤N. Each pair encodes a poll answer as follows: </p>

<p>The input data are separated by white spaces, terminate with an end of file, and are correct. </p>

### 출력 

 <p>For each data set the program prints the result of the encoded election problem. The result, 1 or 0, is printed on the standard output from the beginning of a line. There must be no empty lines on output. An example of input/output is shown below.</p>

