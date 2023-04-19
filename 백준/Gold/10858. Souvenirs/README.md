# [Gold III] Souvenirs - 10858 

[문제 링크](https://www.acmicpc.net/problem/10858) 

### 성능 요약

메모리: 10228 KB, 시간: 124 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 문제 설명

<p>You are on vacation in a country, where only two types of coins are used: silver and gold. The relative value of one gold coin compared to the number of silver coins has to be big, because there are only these two coin types. Although this is quite unhandy for the merchants, they do not want to deal with a third coin type.</p>

<p>Their idea is that the value of the silver coins is changed in a way that a gold coin is worth less silver coins. To make a statement they tie up silver coins in packages and will give change only in gold coins and packaged silver coins but no single silver coins. However, they do not change their prices to multiples of the silver package values.</p>

<p>So the merchants have to round the change. Different merchants use different rounding methods. Honest merchants round to the nearest value and up if equal. Greedy merchants always round downwards. Generous merchants round always upwards. The merchants also did not negotiate on one package size, so they might all be different. But they are always an integral factor of the current gold coin value in silver coins.</p>

<p>You have some gold coins left and want to buy as many souvenirs as possible. You already know the different prices of all merchants at the market (the price is lower than what one gold coin is worth) and which merchant is greedy, generous and honest as well as their silver coin package sizes. You only have time to go over the market once, so you need to visit the merchants in the given order. Furthermore, you do not want to exploit generous merchants. Thus, if you can pay the exact price, you do so; otherwise you pay with exactly one gold coin. You pay the other merchants either the exact prize or with exactly one gold coin. You buy at most one souvenir at each merchant. Then, you unpack the change, i.e. the silver coin packages, so you can use the coins separately.</p>

<p>For example in the third test case you skip the first merchant and buy at the second one with a gold coin. Because you cannot pay the third merchant exactly, you use a gold coin again. With the change of the two purchases (six and eight silver coins) you can pay the souvenirs at the remaining three merchants.</p>

### 입력 

 <p>The first line contains three integers g, c, and n, where g denotes the value of one gold coin in silver coins, c denotes the number of gold coins you have and n the number of merchants on the market (1 < g ≤ 100, 1 ≤ c, n ≤ 100).</p>

<p>Then follow n lines each describing one merchant. Each of these lines starts with a string “greedy”, “honest” or “generous” describing the rounding habit of the merchant. The string is followed by two integers p<sub>i</sub> and s<sub>i</sub>, where p<sub>i</sub> denotes the package size of silver coins the merchant uses and s<sub>i</sub> specifies the prices of the souvenir at that merchant in silver coins (1 ≤ p<sub>i</sub> ≤ g, 1 ≤ s<sub>i</sub> < g).</p>

### 출력 

 <p>One line containing the maximal number of souvenirs you can buy.</p>

