# [Gold IV] 사탕 가게 - 4781 

[문제 링크](https://www.acmicpc.net/problem/4781) 

### 성능 요약

메모리: 2100 KB, 시간: 456 ms

### 분류

다이나믹 프로그래밍(dp), 배낭 문제(knapsack)

### 문제 설명

<p>You are walking with a friend, when you pass a candy store. You make a comment about how unhealthy their wares are. Your friend issues an interesting challenge: who can be the unhealthiest? Both of you will go into the store with the same amount of money. Whoever buys candy with the most total calories wins!</p>

<p>Since you're a smart computer scientist, and since you have access to the candy store's inventory, you decide not to take any chances. You will write a program to determine the most calories you can buy. The inventory tells you the price and calories of every item. It also tells you that there is so much in stock that you can buy as much of any kind of candy as you want. You can only buy whole pieces of candy.</p>

### 입력 

 <p>There will be multiple test cases in the input. Each test case will begin with a line with an integer n (1≤n≤5,000), and an amount of money m (<mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c2E"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0.01</mn><mo>≤</mo><mi>m</mi><mo>≤</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0.01≤m≤$</span></mjx-container>100.00), separated by a single space, where n is the number of different types of candy for sale, and m is the amount of money you have to spend. The monetary amount m will be expressed in dollars with exactly two decimal places, and with no leading zeros unless the amount is less than one dollar. There will be no dollar sign. Each of the next n lines will have an integer c (1≤c≤5,000) and an amount of money p (<mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c2E"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45D TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0.01</mn><mo>≤</mo><mi>p</mi><mo>≤</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0.01≤p≤$</span></mjx-container>100.00), separated by a single space, where c is the number of calories in a single piece of candy, and p is the price of a single piece of candy, in dollars and in the same format as m. The input will end with a line containing '0 0.00'</p>

### 출력 

 <p>For each test case, output a single integer, indicating the maximum amount of calories you can buy with up to m dollars. Output no spaces, and do not separate answers with blank lines.</p>

