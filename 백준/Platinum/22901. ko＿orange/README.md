# [Platinum II] ko_orange - 22901 

[문제 링크](https://www.acmicpc.net/problem/22901) 

### 성능 요약

메모리: 13948 KB, 시간: 352 ms

### 분류

애드 혹, 이분 탐색

### 제출 일자

2023년 11월 30일 19:45:51

### 문제 설명

<p>이 문제는 <strong>인터랙티브</strong> 문제이다.</p>

<p>'코드포스'는 유저의 레이팅에 따라 닉네임의 색깔을 바꿔준다. <a href="https://codeforces.com/profile/ko_osaga"><strong><span style="color:#000000;">k</span><span style="color:#e74c3c;">o_osaga</span></strong></a>님을 제외한 <span style="color:#f39c12;"><strong>Orange Cup</strong></span>의 운영진과 검수진들은 전부 2100 이상 2399 이하의 코드포스 레이팅을 가지고 있어서 오렌지색 닉네임을 갖는다. <a href="http://codeforces.com/profile/ko_osaga"><strong><span style="color:#000000;">k</span><span style="color:#e74c3c;">o_osaga</span></strong></a>의 코드포스 레이팅은 3000이 넘지만, 실력은 오렌지이기 때문에 이 대회의 검수진으로 참여할 수 있었다.</p>

<p style="text-align: center;"><a href="https://cdn.discordapp.com/attachments/804185565028548669/867632211327189042/unknown.png"><img alt="" src="https://cdn.discordapp.com/attachments/804185565028548669/867632211327189042/unknown.png" style="width: 250px; height: 110px;"></a></p>

<p><a href="http://codeforces.com/profile/ko_osaga"><strong><span style="color:#000000;">k</span><span style="color:#e74c3c;">o_osaga</span></strong></a>의 실력은 가상의 코드포스 계정인 <span style="color:#f39c12;"><strong>ko_orange</strong></span>의 레이팅 $x$이다. 당신은 다음과 같은 질문을 최대 $q$번 할 수 있다.</p>

<ul>
	<li><span style="color:#f39c12;"><strong>ko_orange</strong></span>의 레이팅은 $y$ 이상인가요? ($2100 \leq y \leq 2399$)</li>
</ul>

<p><span style="color:#f39c12;"><strong>ko_orange</strong></span>는 대부분의 경우 정확한 답변을 하지만 <strong>최대 1번</strong> <a href="http://codeforces.com/profile/ko_osaga"><strong><span style="color:#000000;">k</span><span style="color:#e74c3c;">o_osaga</span></strong></a>의 레이팅과 헷갈려서 레이팅이 $y$ 미만이더라도 이상이라고 대답한다. 이 질문을 이용해 당신은 $x$를 구해야 한다. 단, 질문의 개수를 최소화할 필요는 없으며, 모든 레이팅은 정수이다.</p>

### 입력 

 <p>당신은 한 번의 프로그램 실행에서 $T$개의 테스트 데이터를 처리하여야 한다. 입력의 첫 줄에는 테스트 데이터의 수 $T$가 주어진다.</p>

### 출력 

 <p>각 테스트 데이터에 대해 아래와 같은 과정으로 채점 프로그램과의 소통이 진행된다.</p>

<p>당신은 하나의 테스트 데이터에서 총 $q$번, <span style="color:#f39c12;"><strong>ko_orange</strong></span>의 레이팅이 정수 $y$ 이상인지를 질문할 수 있다. 이때 $2100 \le y \le 2399$를 만족해야 한다. 질문은 "$? \ y$"과 줄 바꿈을 (따옴표 없이) 출력하는 것으로 이루어진다. 질문을 한 뒤, 당신은 정수 하나를 입력받아서 질문의 답을 알 수 있다. 이 답이 1인 경우 <span style="color:#f39c12;"><strong>ko_orange</strong></span>의 레이팅이 $y$ 이상이라는 것이고, 답이 0인 경우 $y$ 미만이라는 것이다.</p>

<p>만약 <span style="color:#f39c12;"><strong>ko_orange</strong></span>의 레이팅을 알아냈다면, "$! \ x$"와 줄 바꿈을 출력한다. $x$는 <span style="color:#f39c12;"><strong>ko_orange</strong></span>의 실제 레이팅과 같은 값이어야 한다.</p>

<p>모든 출력 뒤에 출력 버퍼를 비우지 않거나, 올바르지 않은 답을 출력하거나, 출력 형식을 어길 경우 예상하지 못한 채점 결과를 받을 수 있다.</p>

