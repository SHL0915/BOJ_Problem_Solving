# [Diamond V] Flip and Combos - 21039 

[문제 링크](https://www.acmicpc.net/problem/21039) 

### 성능 요약

메모리: 66844 KB, 시간: 212 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 문제 설명

<p>A binary array is an array which each element can be either 0 or 1. Aleka has a binary array <em>B</em> or length <em>N</em>. The elements of <em>B</em> are indexed from 1 to <em>N</em>.</p>

<p>Aleka will play with her array. She will run <em>Q</em> queries one after another. Each query can be one of the following type :</p>

<ul>
	<li><code>FLIP</code> <em>L</em> <em>R</em>: Flip all bits of <em>B</em> from index <em>L</em> to <em>R</em>, inclusive. Flipping bit is changing the value of a bit from 0 to 1, or from 1 to 0.</li>
	<li><code>COMBO</code> <em>L</em> <em>R</em>: Let <em>B</em>' be the subarray of <em>B</em> only containing bits which indexed between <em>L</em> to <em>R</em>, inclusive. Find the length of the longest contiguous subarray of <em>B</em>' such that all elements in that subarray have the same value.</li>
</ul>

<p>All the queries should be executed as in the input order, and for every <code>COMBO</code>-type query, output the answer for that query.</p>

### 입력 

 <p>The first line contains two integers: <em>N</em> <em>Q</em> (1 ≤ <em>N</em>, <em>Q</em> ≤ 100,000) in a line denoting the length of the array and the number of queries. The second line contains a string of <em>N</em> characters (of '0' or '1') representing the binary array <em>B</em>. The i-th character in the string corresponds to the i-th element of the binary array <em>B</em> ('0' represents 0, while '1' represents 1). The next <em>Q</em> lines each contains three integers <em>T</em> <em>L</em> <em>R</em> (1 ≤ <em>T</em> ≤ 2; 1 ≤ <em>L</em> ≤ <em>R</em> ≤ <em>N</em>) denoting the query. If <em>T</em> = 1, then this query is a <code>FLIP</code> query, otherwise this query is a <code>COMBO</code> query.</p>

### 출력 

 <p>For each <code>COMBO</code>-type query, print the answer of the query in the same order of the queries running order.</p>

