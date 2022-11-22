# [Gold II] Arbitrage - 6598 

[문제 링크](https://www.acmicpc.net/problem/6598) 

### 성능 요약

메모리: 2040 KB, 시간: 8 ms

### 분류

플로이드–와샬(floyd_warshall), 그래프 이론(graphs)

### 문제 설명

<p>Arbitrage is the use of discrepancies in currency exchange rates to transform one unit of a currency into more than one unit of the same currency. For example, suppose that 1 US Dollar buys 0.5 British pound, 1 British pound buys 10.0 French francs, and 1 French franc buys 0.21 US dollar. Then, by converting currencies, a clever trader can start with 1 US dollar and buy 0.5 * 10.0 * 0.21 = 1.05 US dollars, making a profit of 5 percent.</p>

<p>Your job is to write a program that takes a list of currency exchange rates as input and then determines whether arbitrage is possible or not.</p>

### 입력 

 <p>The input file will contain one or more test cases. Om the first line of each test case there is an integer <em>n</em> (1 ≤ <em>n</em> ≤ 30), representing the number of different currencies. The next n lines each contain the name of one currency. Within a name no spaces will appear. The next line contains one integer <em>m</em>, representing the length of the table to follow. The last <em>m</em> lines each contain the name <em>c<sub>i</sub></em> of a source currency, a real number <em>r<sub>ij</sub></em> which represents the exchange rate from <em>c<sub>i</sub></em> to <em>c<sub>j</sub></em> and a name <em>c<sub>j</sub></em> of the destination currency. Exchanges which do not appear in the table are impossible.</p>

<p>Test cases are separated from each other by a blank line. Input is terminated by a value of zero (0) for <em>n</em>.</p>

### 출력 

 <p>For each test case, print one line telling whether arbitrage is possible or not in the format "Case <em>case</em>: Yes" respectively "Case <em>case</em>: No".</p>

