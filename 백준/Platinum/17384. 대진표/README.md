# [Platinum V] 대진표 - 17384 

[문제 링크](https://www.acmicpc.net/problem/17384) 

### 성능 요약

메모리: 395236 KB, 시간: 36 ms

### 분류

구성적(constructive), 분할 정복(divide_and_conquer)

### 문제 설명

<p>수빈이는 예전부터 UCPC의 대회 형식이 ICPC와 같다는 것이 마음에 들지 않았다. 그래서 전대프연의 회장이 되자마자 UCPC를 ICPC와 차별화된 토너먼트 방식의 대회로 바꾸겠다고 선언했다.</p>

<p>수빈이가 바꾼 새로운 UCPC의 진행 방식은 다음과 같다.</p>

<ol>
	<li>참가한 팀의 수보다 크거나 같은 가장 작은 2의 거듭제곱 꼴의 수를 찾고, 그 수만큼 빈 슬롯을 일렬로 나열한다.</li>
	<li>참가한 팀들을 슬롯들에 적절히 배정한다. 이때 두 개 이상의 팀을 같은 슬롯에 배정할 수는 없다.</li>
	<li>슬롯들을 앞에서부터 두 개씩 짝짓는다. 만약 짝지어진 두 슬롯 모두에 팀이 배정되어 있다면 두 팀이 경기를 치르고, 패배한 팀의 슬롯이 삭제된다. 그렇지 않다면 경기를 치르지 않고, 비어 있는 슬롯 하나가 삭제된다.</li>
	<li>마지막 한 팀이 남을 때까지 3번 과정을 반복한다. 마지막으로 남은 팀이 우승팀이 된다.</li>
</ol>

<p>수빈이는 팀을 배정할 때 가장 앞의 슬롯부터 차례대로 한 팀씩 배정하려고 했으나, 이러면 공평하지 않은 대진표가 만들어진다는 것을 발견했다. 예를 들어 5개의 팀이 대회에 참가했을 때, 첫 번째 슬롯에 배정된 팀은 우승하기 위해 세 번의 경기를 치러야 하지만 5번째 슬롯에 배정된 팀은 한 경기만 이기면 우승을 차지할 수 있다.</p>

<p style="margin-top: 30px;"><img alt="bracket" src="https://upload.acmicpc.net/d3c1e02b-bbe5-445e-b77f-43e934ab2576/-/preview/" style="display: block; margin-left: auto; margin-right: auto; width: 100%; max-width: 800px;"></p>

<p style="margin-bottom: 30px; text-align: center;">공평하지 않은 대진표와 공평한 대진표</p>

<p>수빈이는 우승하기 위해 가장 많은 경기를 치러야 하는 팀과 가장 적은 경기를 치러야 하는 팀의 경기 수가 많아야 한 경기 차이가 나도록 팀을 배정하려고 한다. 또한, 그런 배치가 여러 개 있다면 팀이 배정된 슬롯들의 번호를 <b>내림차순으로</b> 정렬했을 때 이 수열이 사전 순으로 가장 앞서는 배치를 고르려고 한다. 즉 마지막 팀이 배정된 슬롯의 번호가 작을수록 좋은 배치이다.</p>

<p>그러나 대회를 열기 위해서는 대진표를 짜는 것 외에도 할 일이 너무나도 많다! UCPC가 원활히 진행될 수 있도록 바쁜 수빈이 대신 좋은 대진표를 만들어 주자.</p>

### 입력 

 <p>첫 줄에 대회에 참가한 팀의 수를 의미하는 정수 <em>N</em>(1 ≤ <em>N</em> ≤ 1,000,000)이 주어진다.</p>

### 출력 

 <p>첫 줄에 수빈이가 원하는 대로 팀을 배정한 결과를 나타내는 문자열을 출력한다. 문자열의 길이는 슬롯의 개수와 같아야 하며, 팀이 배정된 슬롯은 <code>#</code>, 비어 있는 슬롯은 <code>.</code> 로 나타낸다.</p>

