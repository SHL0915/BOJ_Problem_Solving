# [Platinum IV] 영화 수집 - 3653 

[문제 링크](https://www.acmicpc.net/problem/3653) 

### 성능 요약

메모리: 5144 KB, 시간: 108 ms

### 분류

자료 구조(data_structures), 세그먼트 트리(segtree)

### 문제 설명

<p>Mr. K. I. has a very big movie collection. He has organized his collection in a big stack. Whenever he wants to watch one of the movies, he locates the movie in this stack and removes it carefully, ensuring that the stack doesn’t fall over. After he ﬁnishes watching the movie, he places it at the top of the stack.</p>

<p>Since the stack of movies is so big, he needs to keep track of the position of each movie. It is sufﬁcient to know for each movie how many movies are placed above it, since, with this information, its position in the stack can be calculated. Each movie is identiﬁed by a number printed on the movie box.</p>

<p>Your task is to implement a program which will keep track of the position of each movie. In particular, each time Mr. K. I. removes a movie box from the stack, your program should print the number of movies that were placed above it before it was removed.</p>

### 입력 

 <p>On the ﬁrst line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with two integers n and m (1 ≤ n, m ≤ 100 000): the number of movies in the stack and the number of locate requests.</li>
	<li>one line with m integers a<sub>1</sub>, ..., a<sub>m</sub> (1 ≤ a<sub>i</sub> ≤ n) representing the identification numbers of movies that Mr. K. I. wants to watch.</li>
</ul>

<p>For simplicity, assume the initial stack contains the movies with identiﬁcation numbers 1, 2, ..., n in increasing order, where the movie box with label 1 is the top-most box.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with m integers, where the i-th integer gives the number of movie boxes above the box with label a<sub>i</sub>, immediately before this box is removed from the stack.</li>
</ul>

<p>Note that after each locate request a<sub>i</sub>, the movie box with label ai is placed at the top of the stack.</p>

