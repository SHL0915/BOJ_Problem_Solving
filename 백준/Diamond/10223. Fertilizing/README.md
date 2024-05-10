# [Diamond V] Fertilizing - 10223 

[문제 링크](https://www.acmicpc.net/problem/10223) 

### 성능 요약

메모리: 3708 KB, 시간: 904 ms

### 분류

자료 구조, 그리디 알고리즘, 느리게 갱신되는 세그먼트 트리, 수학, 세그먼트 트리

### 제출 일자

2024년 5월 10일 17:57:46

### 문제 설명

<p>경근이는 세계에서 제일가는 콩나무 농부가 꿈이다. 오늘도 꿈을 이루기 위해서 고군분투 하던 경근이는 마침내 식물에게 뿌리기만 하면 식물이 쑥쑥 자라게 하는 비료X를 개발하는데 성공했다. 다만 비료X의 너무나도 강력한 효과를 잘 제어할 자신이 없었던 경근이는 비료X의 강도를 서서히 높여가면서 콩나무 기르기에 익숙해지고자 마음먹었다.</p>

<p>경근이는 현재 N개의 콩나무 씨앗을 가지고 있으며, 이제 막 씨앗들을 땅에 심었기 때문에 높이가 0이다. 경근이는 앞으로 D일에 걸쳐 하루에 한 번씩 콩나무들에게 비료를 주고자 한다.</p>

<p>i (1 ≤ i ≤ D)번째 날에는 비료를 흡수하면 높이가 i만큼 자라도록 비료X를 주려고 하는데, 이때 비료를 주는 대상은 현재 높이가 가장 낮은 C<sub>i</sub>개의 나무이다.</p>

<p>또한 경근이는 비료가 콩나무들이 얼마나 잘 자라는지 알고 싶기 때문에 매일매일 비료를 주고 나서 현재 K<sub>i</sub>번째로 작은 나무의 높이가 무엇인지를 알고 싶다.</p>

<p>하지만 꿈이 너무 컸던 경근이는 감당할 수 없는 수의 콩나무를 심어버리고 말았다. 당신은 경근이를 도와 비료를 주면서 콩나무를 관찰하는 일을 해야한다.</p>

### 입력 

 <p>입력 파일의 첫 번째 줄에 테스트 케이스의 수를 의미하는 자연수 T가 주어진다. 그 다음에는 T개의 테스트 케이스가 주어진다.</p>

<p>각 테스트 케이스는 5개의 정수로 나타내어지며, 이를 나타내는 N, D (1 ≤ N, D ≤ 100,000), s, a, b (0 ≤ s, a, b ≤ 100,000) 가 공백으로 구분되어 주어진다.</p>

<p>C<sub>i</sub>와 K<sub>i</sub>는 s, a, b를 이용해서 생성할 수 있으며 그 방법은 아래와 같다.</p>

<div><div id="highlighter_454679" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div><div class="line number5 index4 alt2">5</div><div class="line number6 index5 alt1">6</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c keyword bold">for</code> <code class="c plain">(</code><code class="c color1 bold">int</code> <code class="c plain">i=1; i<=D; i++) {</code></div><div class="line number2 index1 alt1"><code class="c spaces">    </code><code class="c plain">Ci = s % N + 1;</code></div><div class="line number3 index2 alt2"><code class="c spaces">    </code><code class="c plain">s = (s * a + b) % 1000000007;</code></div><div class="line number4 index3 alt1"><code class="c spaces">    </code><code class="c plain">Ki = s % N + 1;</code></div><div class="line number5 index4 alt2"><code class="c spaces">    </code><code class="c plain">s = (s * a + b) % 1000000007;</code></div><div class="line number6 index5 alt1"><code class="c plain">}</code></div></div></td></tr></tbody></table></div></div>

### 출력 

 <p>각 테스트 케이스당 한 줄에 D일 동안 측정된 나무 높이들의 합을 출력한다.</p>

