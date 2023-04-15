# [Platinum III] DUGOVI - 2861 

[문제 링크](https://www.acmicpc.net/problem/2861) 

### 성능 요약

메모리: 22620 KB, 시간: 88 ms

### 분류

그래프 이론, 그리디 알고리즘, 위상 정렬

### 문제 설명

<p>In a little town called Križ live N people. Each of them has borrowed some money from exactly one other inhabitant. Now the time has come to pay back all the debts, but the problem is that everybody has spent all of their money! </p>

<p>The major of Križ has decided to solve this problem. The town will give money to a few people so that they can pay back their debts. When some people get their money back, a chain reaction is started - for example: person A gets money from the city. Person A uses that money to pay the debt toward person B. Person B then uses that money to pay the debt towards person C etc. If person B didn’t have enough money to pay back the debt, they wait until they get enough. If they have more than enough money, person B will keep what is left after payback. </p>

<p>Another example: if two people live in Križ, and they owe <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D452 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D450 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D452 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c210E TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D452 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D461 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45C TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D464 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D464 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D459 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D459 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D454 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D463 TEX-I"></mjx-c></mjx-mi><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D452 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>100</mn><mi>t</mi><mi>o</mi><mi>e</mi><mi>a</mi><mi>c</mi><mi>h</mi><mi>o</mi><mi>t</mi><mi>h</mi><mi>e</mi><mi>r</mi><mo>,</mo><mi>t</mi><mi>h</mi><mi>e</mi><mi>t</mi><mi>o</mi><mi>w</mi><mi>n</mi><mi>w</mi><mi>i</mi><mi>l</mi><mi>l</mi><mi>g</mi><mi>i</mi><mi>v</mi><mi>e</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$100 to each other, the town will give $</span></mjx-container>100 to one of them so they can pay back the debt to the other one. </p>

<p>Your task is to calculate the minimum total amount of money the town has to give to some subset of the inhabitants so that after the payback protocol described above all debts are payed. </p>

### 입력 

 <p>First line of input contains one integer N (2 ≤ N ≤ 200 000), number of inhabitants of Križ. They are numbered from 1 to N. </p>

<p>The following N lines contain two integers, separated by space. In i-th of those lines, first number - A<sub>i</sub> represents the id of the person i-th person owes money to (1 ≤ A<sub>i</sub> ≤ N, Ai ≠ i), and second B<sub>i</sub> represents the ammount of the debt in $ (1 ≤ B<sub>i</sub> ≤ 10 000). </p>

### 출력 

 <p>First and only line of output should contain one integer - the minimum total ammount of money town has to give to its inhabitants so all debts are returned. </p>

