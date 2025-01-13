# [Platinum IV] Door of the Ancient - 21023 

[문제 링크](https://www.acmicpc.net/problem/21023) 

### 성능 요약

메모리: 84056 KB, 시간: 20 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 1월 13일 20:23:37

### 문제 설명

<p>Pandy is at the last stage of “Door of the Ancients”, his favorite video game. His objective is to pass through a sacred door. There are two ways to do this: By defeating a mighty guardian and snatch the key to the sacred door, or by destroying the sacred door (with brute force) directly.</p>

<p>Pandy has no confidence in fighting the mighty guardian, thus Pandy opts to use the second method. Pandy has N items which can be thrown to the sacred door. Each item originally has a power of P<sub>i</sub> and a value of V<sub>i</sub>. If Pandy throws the i<sup>th</sup> item to the sacred door, then the following will happen in order:</p>

<ol>
	<li>The sacred door’s durability will be decreased (damaged) by the i<sup>th</sup> item’s current power.</li>
	<li>The i<sup>th</sup> item’s power will be doubled.</li>
	<li>The i<sup>th</sup> item’s value will be halved (rounded down).</li>
</ol>

<p>The same item can be thrown to the sacred door repeatedly as long as its value is not zero.</p>

<p>Originally, the sacred door has a durability of H. Pandy should decrease this durability to be non-positive (H ≤ 0) by throwing one or more items to destroy the sacred door.</p>

<p>Unfortunately, the player’s score in this game is also determined by the total value of all items belong to the player at the end of the game (that is why fighting the mighty guardian is popular among other players). Therefore, help Pandy to determine the minimum loss of the total value of all items to destroy the sacred door.</p>

<p>For example, let H = 100, N = 3, P<sub>1..3</sub> = {10, 75, 50}, and V<sub>1..3</sub> = {2, 10, 50}.</p>

<p>To destroy the sacred door, Pandy can throw the second item to the sacred door twice:</p>

<ul>
	<li>Throw the 2<sup>nd</sup> item: H is decreased by 75, P<sub>2</sub> is doubled to 150, and V<sub>2</sub> is halved to 5 (loss by 5).</li>
	<li>Throw the 2<sup>nd</sup> item: H is decreased by 150, P<sub>2</sub> is doubled to 300, and V<sub>2</sub> is halved to 2 (loss by 3).</li>
</ul>

<p>The total damage to the sacred door is 75 + 150 = 225, more than enough to destroy the sacred door (of original H = 100). The loss of the total value of all items is 5 + 3 = 8.</p>

<p>Alternatively, Pandy can throw the first item twice and the second item once:</p>

<ul>
	<li>Throw the 1<sup>st</sup> item: H is decreased by 10, P<sub>1</sub> is doubled to 20, and V<sub>1</sub> is halved to 1 (loss by 1).</li>
	<li>Throw the 1<sup>st</sup> item: H is decreased by 20, P<sub>1</sub> is doubled to 40, and V<sub>1</sub> is halved to 0 (loss by 1)—this item cannot be used anymore.</li>
	<li>Throw the 2<sup>nd</sup> item: H is decreased by 75, P<sub>2</sub> is doubled to 150, and V<sub>2</sub> is halved to 5 (loss by 5).</li>
</ul>

<p>The total damage to the sacred door is 10 + 20 + 75 = 105, and the loss of the total value of all items is 1 + 1 + 5 = 7. In this example, there is no way to destroy the sacred door with a loss of the total value of all items less than 7.</p>

### 입력 

 <p>Input begins with a line containing two integers: N H (1 ≤ N ≤ 100; 1 ≤ H ≤ 10<sup>9</sup>) representing the number of available items and the sacred door’s original durability, respectively. The next N lines each contains two integers: P<sub>i</sub> V<sub>i</sub> (1 ≤ P<sub>i</sub> ≤ 10<sup>9</sup>; 1 ≤ V<sub>i</sub> ≤ 100) representing the original power and value of the i<sup>th</sup> item, respectively.</p>

### 출력 

 <p>Output in a line an integer representing the minimum loss of the total value of all items to destroy the sacred door, or output -1 if it is not possible to destroy the sacred door.</p>

