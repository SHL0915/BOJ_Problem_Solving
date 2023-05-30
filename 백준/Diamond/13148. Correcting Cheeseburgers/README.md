# [Diamond IV] Correcting Cheeseburgers - 13148 

[문제 링크](https://www.acmicpc.net/problem/13148) 

### 성능 요약

메모리: 44392 KB, 시간: 932 ms

### 분류

너비 우선 탐색, 양방향 탐색, 그래프 이론, 그래프 탐색, 중간에서 만나기

### 문제 설명

<p>Cheeseburgers are serious business. They are the most delicious food on earth, but there is a lot of room for error when making a cheeseburger. Even otherwise capable cooks often mess up the order of the assembled ingredients.</p>

<p>The only correct order of ingredients between the buns is, of course, as following from top to bottom:</p>

<ol>
	<li>Ketchup & Mustard</li>
	<li>Beef Tomato</li>
	<li>Pickles</li>
	<li>Red Onions</li>
	<li>Cheddar Cheese</li>
	<li>Garlic</li>
	<li>Salt & Pepper</li>
	<li>Beef Patty, medium grilled</li>
	<li>Corn Salad</li>
	<li>Mayonnaise</li>
</ol>

<p>Any deviation from this order is completely unacceptable. Therefore it is sometimes necessary to reassemble a cheeseburger.</p>

<p>Space on an average plate and social norms are rather restrictive when it comes to operating on a cheeseburger. The only feasible operation is the bit-shuffle (burger-ineptly-transformed). The bit-shuffle separates the entire burger into four parts of contiguous ingredients a, b, c and d and arranges them in the new order c a d b. The size of each of the four parts is selectable and may be zero.</p>

<p>Since the burger cools rapidly we are interested in the minimum required bit-shuffles to arrive at an acceptable burger.</p>

<p>Each given cheeseburger consists of n unique ingredients labeled from 1 to n. The correct order is always the natural order 1 2 . . . n.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13148/1.png" style="height:98px; width:531px"></p>

<p style="text-align: center;">Figure B.1: Illustration of the first sample input.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13148/2.png" style="height:94px; width:513px"></p>

<p style="text-align: center;">Figure B.2: Illustration of the second sample input.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with an integer n (1 ≤ n ≤ 10), where n is the number of ingredients used;</li>
	<li>one line with n integers describing the order of the ingredients of the given cheeseburger. The ingredients are numbered from 1 to n.</li>
</ul>

### 출력 

 <p>Output the minimum number of bit-shuffles to correct the given cheeseburger.</p>

