# [Platinum V] 정렬하기 - 10923 

[문제 링크](https://www.acmicpc.net/problem/10923) 

### 성능 요약

메모리: 2412 KB, 시간: 4 ms

### 분류

애드 혹, 해 구성하기, 순열 사이클 분할

### 문제 설명

<p>Aizhan has a sequence of N integers S[0], S[1], ..., S[N-1]. The sequence consists of distinct numbers from 0 to N-1. She is trying to sort this sequence in ascending order by swapping some pairs of elements. Her friend Ermek is also going to swap some pairs of elements — not necessarily in a helpful way.</p>

<p>Ermek and Aizhan are going to modify the sequence in a series of rounds. In each round, first Ermek makes a swap and then Aizhan makes another swap. More precisely, the person making a swap chooses two valid indices and swaps the elements at those indices. Note that the two indices do not have to be distinct. If they are equal, the current person swaps an element with itself, which does not change the sequence.</p>

<p>Aizhan knows that Ermek does not actually care about sorting the sequence S. She also knows the exact indices Ermek is going to choose. Ermek plans to take part in M rounds of swapping. We number these rounds from 0 to M-1. For each between 0 and M-1 inclusive, Ermek will choose the indices X[i] and Y[i] in round i.</p>

<p>Aizhan wants to sort the sequence S. Before each round, if Aizhan sees that the sequence is already sorted in ascending order, she will terminate the entire process. Given the original sequence S and the indices Ermek is going to choose, your task is to find a sequence of swaps, which Aizhan can use to sort the sequence S. In addition, in some subtasks you are required to find a sequence of swaps that is as short as possible. You may assume that it is possible to sort the sequence S in M or fewer rounds.</p>

<p>Note that if Aizhan sees that the sequence S is sorted after Ermek’s swap, she can choose to swap two equal indices (e.g., 0 and 0). As a result the sequence S is also sorted after the entire round, so Aizhan reaches her goal. Also note that if the initialsequence S is already sorted, the minimal number of rounds needed to sort it is 0.</p>

<p>Example 1</p>

<p>Suppose that:</p>

<ul>
	<li>The initialsequence is S = 4, 3, 2, 1, 0.</li>
	<li>Ermek is willing to make M = 6 swaps.</li>
	<li>The sequences and that describe the indices Ermek is going to choose are X = 0, 1, 2, 3, 0, 1 and Y = 1, 2, 3, 4, 1, 2. In other words, the pairs of indices that Ermek plans to choose are (0, 1), (1, 2), (2, 3), (3, 4), (0, 1), and (1, 2).</li>
</ul>

<p>In this setting Aizhan can sort the sequence S into the order 0, 1, 2, 3, 4 in three rounds. She can do so by choosing the indices (0, 4), (1, 3), and then (3, 4).</p>

<p>The following table shows how Ermek and Aizhan modify the sequence.</p>

<table class="table table-bordered" style="width:30%">
	<thead>
		<tr>
			<th>Round</th>
			<th>Player</th>
			<th>Piar of swapped indices</th>
			<th>Sequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>beginning</td>
			<td> </td>
			<td> </td>
			<td>4, 3, 2, 1, 0</td>
		</tr>
		<tr>
			<td>0</td>
			<td>Ermek</td>
			<td>(0, 1)</td>
			<td>3, 4, 2, 1, 0</td>
		</tr>
		<tr>
			<td>0</td>
			<td>Aizhan</td>
			<td>(0, 4)</td>
			<td>0, 4, 2, 1, 3</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Ermek</td>
			<td>(1, 2)</td>
			<td>0, 2, 4, 1, 3</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Aizhan</td>
			<td>(1, 3)</td>
			<td>0, 1, 4, 2, 3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Ermek</td>
			<td>(2, 3)</td>
			<td>0, 1, 2, 4, 3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Aizhan</td>
			<td>(3, 4)</td>
			<td>0, 1, 2, 3, 4</td>
		</tr>
	</tbody>
</table>

<p>Example 2</p>

<p>Suppose that:</p>

<ul>
	<li>The initialsequence is S = 3, 0, 4, 2, 1.</li>
	<li>Ermek is willing to make M = 5 swaps.</li>
	<li>The pairs of indices that Ermek plans to choose are (1, 1), (4, 0), (2, 3), (1, 4), and (0, 4).</li>
</ul>

<p>In this setting Aizhan can sort the sequence Sin three rounds, for example by choosing the pairs of indices (1, 4), (4, 2), and then (2, 2). The following table shows how Ermek and Aizhan modify the sequence.</p>

<table class="table table-bordered" style="width:30%">
	<thead>
		<tr>
			<th>Round</th>
			<th>Player</th>
			<th>Pair of swapped indices</th>
			<th>Sequence</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>초기</td>
			<td> </td>
			<td> </td>
			<td>3, 0, 4, 2, 1</td>
		</tr>
		<tr>
			<td>0</td>
			<td>Ermek</td>
			<td>(1, 1)</td>
			<td>3, 0, 4, 2, 1</td>
		</tr>
		<tr>
			<td>0</td>
			<td>Aizhan</td>
			<td>(1, 4)</td>
			<td>3, 1, 4, 2, 0</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Ermek</td>
			<td>(4, 0)</td>
			<td>0, 1, 4, 2, 3</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Aizhan</td>
			<td>(4, 2)</td>
			<td>0, 1, 3, 2, 4</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Ermek</td>
			<td>(2, 3)</td>
			<td>0, 1, 2, 3, 4</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Aizhan</td>
			<td>(2, 2)</td>
			<td>0, 1, 2, 3, 4</td>
		</tr>
	</tbody>
</table>

<p>You are given the sequence S, the number M, and the sequences of indices X and Y. Compute a sequence of swaps, which Aizhan can use to sort the sequence S.</p>

<p>You need to implement the function findSwapPairs:</p>

<ul>
	<li>findSwapPairs(N, S, M, X, Y, P, Q) — This function will be called by the grader exactly once.
	<ul>
		<li>N: the length of the sequence S.</li>
		<li>S: an array of integers containing the initial sequence S.</li>
		<li>M: the number of swaps Ermek plans to make.</li>
		<li>X, Y: arrays of integers of length M. For 0 ≤ i ≤ M-1, in round i Ermek plans to swap numbers at indices X[i] and Y[i].</li>
		<li>P, Q: arrays of integers. Use these arrays to report one possible sequence of swaps Aizhan can make to sort the sequence S. Denote by R the length of the sequence of swaps that your program has found. For each i between 0 and R-1 inclusive, the indices Aizhan should choose in round i should be stored into P[i] and Q[i]. You may assume that the arrays P and Q have already been allocated to M elements each.</li>
		<li>This function should return the value of R (defined above).</li>
	</ul>
	</li>
</ul>

### 입력 

 <ul>
	<li>line 1: N</li>
	<li>line 2: S[0] … S[N - 1]</li>
	<li>line 3: M</li>
	<li>lines 4, …, M + 3: X[i] Y[i]</li>
</ul>

### 출력 

 <p>The sample grader prints the following output:</p>

<ul>
	<li>line 1: the return value R of findSwapPairs</li>
	<li>line 2+i, for 0 ≤ i < R: P[i] Q[i]</li>
</ul>

