# [Platinum IV] 마법의 약 - 10428 

[문제 링크](https://www.acmicpc.net/problem/10428) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2024년 5월 9일 15:11:27

### 문제 설명

<p>귀여운 민균이는 오늘도 어떻게 하면 귀여움을 받을 수 있는지 연구하느라 바쁘다. 그러던 중 신비의 나라 라는 곳에 가면 귀여움을 무한정으로 받을 수 있다고 BJ로부터 들었다. 하지만 BJ는 민균이에게 힘들게 알아낸 이 방법을 그냥 알려 줄 수 없다고 하면서 민균이에게 다음과 같은 게임을 제안했다.</p>

<p>N개의 가방이 있고, 정확히 하나의 가방에만 신비의 나라로 가는 마법의 약이 무한히 많이 들어 있고, 나머지 가방에는 먹어도 아무 효과가 없는 약이 무한히 많이 들어 있다. 각각의 가방은 서로 구분이 가능하지만, 가방에 든 약들은 모두 동일하게 생겨서 서로 구분이 불가능하다.</p>

<p>만약, 마법의 약을 먹었을 때에는 즉시 신비의 나라로 이동한다.</p>

<p>민균이는 이제 마법의 약이 어느 가방에 들어있는지 알아내기 위해 하나의 실험을 하려고 한다.</p>

<p>실험을 시작하기 전에 앞서 먼저 원하는 수만큼의 친구들을 부른다. 그 다음에 실험을 여러 단계로 나누어서 진행을 한다. 각 실험 단계에서는 먼저, 현재 신비의 나라로 가지 않은 친구들 중 원하는 친구들을 선택하고, 민균이가 원하는 대로 그 친구들에게 약물을 먹어보게 하려고 한다. 물론 어떤 친구한테는 아무 약도 먹지 않게 할 수 있고 어떤 친구한테는 여러 개의 약을 먹게 할 수 있다. 만약 어떤 친구가 마법의 약을 먹어서 신비의 나라로 가버렸다면 그 친구는 다음 단계에서부터 실험에 참여할 수 없다.</p>

<p>이제 여러분이 할 일은 민균이를 도와 가방의 개수 N, 가능한 실험의 단계 E 이 주어 졌을 때, E 번만의 실험으로 마법의 약물을 알아낼 수 있게 하는 가장 적은 친구의 수 F의 값을 구하는 것이다. 만약 가장 적은 친구의 수를 제대로 구하지 않았을 경우에는 BJ가 이 게임을 즉시 중단해버릴 것이므로 정확히 최소의 친구의 수를 구해야 한다.</p>

<p>예를 들어, 가방이 10개고 가능한 실험의 단계가 2번일 때, 가장 간단한 방법은 친구를 10명을 부른 뒤 각자 한 가방을 맡아 약물을 먹어보게 하면 1번만의 실험으로 마법의 약을 알아낼 수 있다. 하지만, 친구를 3명만 부른 뒤 첫 번째 단계의 실험에서 1, 2, 3 의 가방에 있는 약물을 친구 1에게 주고 4, 5, 6 의 가방에 있는 약물을 친구 2에게 주고 7, 8, 9 의 가방에 있는 약물을 친구 3에게 준다. 만약 아무도 사라지지 않았다면 가방 10에 있는 약물이 마법의 약이라는 것을 알 수 있다. 만약 친구 한 명이 사라졌다고 하자, 그리고 그 친구가 1번 친구라고 하자. 그러면 두 번째 실험 단계에서 1의 가방에 있는 약물을 친구 2에게 주고 2의 가방에 있는 약물을 친구 3에게 준다. 그렇게 하게 되면, 가능한 경우는 친구2 또는 친구 3이 사라지거나 아무도 사라지지 않는 경우가 있고, 두 단계의 실험으로 어느 가방에 마법의 약이 들어있는지 알아낼 수 있다. </p>

<p>하지만, 친구를 두 명만 부른다면 어떻게 해도 2단계의 실험으로 마법의 약이 들어있는 가방을 알아낼 수 없다.</p>

### 입력 

 <p>먼저 친구의 수가 궁금한 경우의 수 T (1 ≤ T ≤ 100) 가 주어지고 이어서 T 개의 줄에 N (1 ≤ N ≤ 1,000,000) 과 E (1 ≤ E ≤ 10) 가 차례대로 주어진다.</p>

### 출력 

 <p>각각의 N 과 E에 대해 가장 작은 F의 값을 출력한다.</p>

