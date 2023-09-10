# [Platinum III] 색상의 길이 - 8902 

[문제 링크](https://www.acmicpc.net/problem/8902) 

### 성능 요약

메모리: 100628 KB, 시간: 1932 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>Cars painted in different colors are moving in a row on the road as shown in Figure 1. The color of each car is represented by a single character and the distance of two adjacent cars is assumed to be 1. Figure 1 shows an example of such cars on the road. For convenience, the numbers in Figure 1 represent the locations of each car. </p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images/cl1.png" style="height:69px; text-align:center; width:460px"></p>

<p style="text-align:center">Figure 1. Cars in different colors on the road </p>

<p>For any color c, location(c) represents set of the locations of the cars painted in color c and color length L(c) is defined as follows: </p>

<p style="text-align: center;"><mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mrow space="2"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7B"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D459 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c7D"></mjx-c></mjx-mo></mjx-mrow><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mrow space="2"><mjx-mo class="mjx-n"><mjx-c class="mjx-c7B"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D459 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c7D"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi><mo stretchy="false">(</mo><mi>c</mi><mo stretchy="false">)</mo><mo>=</mo><mi>m</mi><mi>a</mi><mi>x</mi><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">{</mo><mi>l</mi><mi>o</mi><mi>c</mi><mi>a</mi><mi>t</mi><mi>i</mi><mi>o</mi><mi>n</mi><mo stretchy="false">(</mo><mi>c</mi><mo stretchy="false">)</mo><mo data-mjx-texclass="CLOSE">}</mo></mrow><mo>−</mo><mi>m</mi><mi>i</mi><mi>n</mi><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">{</mo><mi>l</mi><mi>o</mi><mi>c</mi><mi>a</mi><mi>t</mi><mi>i</mi><mi>o</mi><mi>n</mi><mo stretchy="false">(</mo><mi>c</mi><mo stretchy="false">)</mo><mo data-mjx-texclass="CLOSE">}</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(L(c) = max \left\{location(c)\right\} - min \left\{location(c)\right\}\)</span> </mjx-container></p>

<p>For example, according to Figure 1, location(G) = {1,5,6}, location(Y) = {2,7}, location(B) = {3}, and location(R) ={4, 8}. Hence the color length of each color and the sum of the color lengths are as follows. </p>

<table class="table table-bordered" style="width:25%">
	<thead>
		<tr>
			<th>Color</th>
			<th>G</th>
			<th>Y</th>
			<th>B</th>
			<th>R</th>
			<th>Sum</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>L(c)</th>
			<td>5</td>
			<td>5</td>
			<td>0</td>
			<td>4</td>
			<td>14</td>
		</tr>
	</tbody>
</table>

<p>In Gyeongju City, almost all the roads including the main street of the city were constructed more than 500 years ago. The roads are so old that there are a lot of puddles after rain. Visitors have complained about the bad condition of the roads for many years. Due to the limited budget, the mayor of the city decided to repair firstly the main street of the city, which is a four-lane road, two lanes for each direction. </p>

<p>However, since the main street is a backbone of the city, it should not be blocked completely while it is under repair, or it is expected that serious traffic jams will occur on almost all the other roads in the city. To allow cars to use the main street during the repair period, the city decided to block only two lanes, one lane for each direction. Hence, the cars in the two lanes for each direction should merge into a single lane before the blocked zone. </p>

<p>For instance, as shown in Figure 2, cars in the two lanes merge into a single lane as shown in Figure 3. To differentiate the cars in the same color, a unique identifier is assigned to each car. </p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images/cl2.png" style="height:117px; text-align:center; width:323px"></p>

<p style="text-align:center">Figure 2. Cars moving in two lanes before merging </p>

<p>Figure 3 shows two different merging scenarios after merging the cars from the two lanes. As shown in Figure 3, cars in the two lanes do not necessarily merge one by one from each lane. The distance between two adjacent cars after merging is also assumed 1. </p>

<p>After merging (Scenario 1): </p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images/cl31.png" style="height:55px; text-align:center; width:576px"></p>

<p>After merging (Scenario 2): </p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images/cl32.png" style="height:51px; text-align:center; width:573px"></p>

<p style="text-align:center">Figure 3. Two different merging scenarios </p>

<p>For each merging scenario shown in Figure 3, the color length for each color and the sum of the color lengths are as follows: </p>

<table class="table table-bordered" style="width:35%">
	<thead>
		<tr>
			<th>Color</th>
			<th>G</th>
			<th>Y</th>
			<th>B</th>
			<th>R</th>
			<th>Sum</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>L(c): Scenario 1</th>
			<td>7</td>
			<td>3</td>
			<td>7</td>
			<td>2</td>
			<td>19</td>
		</tr>
		<tr>
			<th>L(c): Scenario 2</th>
			<td>1</td>
			<td>7</td>
			<td>3</td>
			<td>1</td>
			<td>12</td>
		</tr>
	</tbody>
</table>

<p>As you can imagine, there are many different ways of merging other than the two examples shown in Figure 3. </p>

<p>Given two character strings which represent the color information of the cars in the two lanes before merging, write a program to find the sum of color lengths obtained from the character string, which is the color information of cars after merging, such that the sum of color lengths is minimized. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case consists of two lines. In the first line, a character string of length n (1 ≤ n ≤ 5,000) that is the color information of the cars in one lane before merging is given. In the second line, a character string of length m (1 ≤ m ≤ 5,000) that is the color information of the cars in the other lane is given. Every color is represented as an uppercase letter in English, hence the number of colors is less than or equal to 26. </p>

### 출력 

 <p>Your program is to read from standard input. Print exactly one line for each test case. The line should contain the sum of color lengths after merging the cars in the two lanes optimally as described above.</p>

