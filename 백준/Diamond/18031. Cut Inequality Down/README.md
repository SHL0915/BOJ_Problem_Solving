# [Diamond V] Cut Inequality Down - 18031 

[문제 링크](https://www.acmicpc.net/problem/18031) 

### 성능 요약

메모리: 23116 KB, 시간: 572 ms

### 분류

자료 구조, 세그먼트 트리, 희소 배열

### 제출 일자

2024년 9월 5일 10:04:38

### 문제 설명

<p>Complejidonia has not always been the peaceful and egalitarian land we all know today. The wealthy Constantones were the owners of the local media and plunged Complejidonia into the tyranny of their ruthless economic system: Nlogonialism, a system that promoted extreme unfairness which, strangely enough, always benefited the Constantones.</p>

<p>While the Constantones owned most of the wealth, Cuadradones lived in extreme poverty, and inequality was justified by tagging Cuadradones as lazy and inefficient. The Nlogones would usually look down on Cuadradones, despite working as much as they did, believing they were better off thanks to their mix of hard work and cunning. For the Cubiones and Cuaterniones it was even worse, coming from neighboring countries they were seen as criminals and, at the same time, accused of stealing Complejidonian jobs.</p>

<p>Everything changed after the International Collectivist and Popular Congress (ICPC) managed to overthrown the Constantones and put a new economic system in place, a system which strives for fairness and takes into account that each inhabitant might go through good and bad economic periods in life.</p>

<p>In the new system an upper limit U on how much wealth an individual can accumulate and a lower bound L representing the minimum wealth required in order for an individual to keep a decent lifestyle were established. At the end of each month every inhabitant will evaluate their wealth. Those with more than U will donate what they own above the upper limit to the ICPC while the ones who sadly have less than L will receive enough from ICPC to reach the established lower bound.</p>

<p>The Cuadradones, which are very good farmers, need your help managing their finance. The long era of Nlogonialism has seriously harmed the environment and now the weather in Complejidonia is very volatile. This has a big impact on its agriculture that fluctuates between good and bad periods.</p>

<p>A farmer keeps a long record A<sub>1</sub>, A<sub>2</sub>, . . . , A<sub>N</sub> of their net income (income minus expenses) on a sequence of N months. Based on this data the farmer wants to plan how to invest their wealth in order to avoid being a burden to the ICPC in the future. The farmer wants to be able to know, given an initial wealth X at the beginning of a month B, how much they would own at the end of a month E (considering that at the end of each month they might either donate or receive a donation to ensure their wealth is between L and U, inclusive).</p>

### 입력 

 <p>The first line contains three integers N (1 ≤ N ≤ 10<sup>5</sup>), L and U (1 ≤ L ≤ U ≤ 2 × 10<sup>6</sup>), indicating respectively the number of months for which the farmer has net income records, the wealth lower bound and the wealth upper bound. The second line contains N integers A<sub>1</sub>, A<sub>2</sub>, . . . , A<sub>N</sub> (−10<sup>6</sup> ≤ A<sub>i</sub> ≤ 10<sup>6</sup> for i = 1, 2, . . . , N), where Ai is the net income on the i-th month. The third line contains an integer Q (1 ≤ Q ≤ 10<sup>5</sup>) representing the number of scenarios the farmer is interested in. Each of the next Q lines describes a scenario with three integers B, E (1 ≤ B ≤ E ≤ N) and X (L ≤ X ≤ U), indicating that the farmer would like to know how much they would own at the end of month E if they start owning X at the beginning of month B, and each month j = B, B + 1, . . . , E their net income is A<sub>j</sub>.</p>

### 출력 

 <p>Output Q lines, each line with an integer indicating how much the farmer would own at the end of the period described in the corresponding scenario.</p>

