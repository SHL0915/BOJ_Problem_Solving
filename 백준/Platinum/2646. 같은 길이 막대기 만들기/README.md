# [Platinum II] 같은 길이 막대기 만들기 - 2646 

[문제 링크](https://www.acmicpc.net/problem/2646) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

백트래킹

### 문제 설명

<p>승연이는 길이가 정수인 동일한 막대기를 여러 개 가지고 있는데, 이 막대기들을 각각 정수의 길이를 갖는 여러 개의 토막으로 아무렇게나 잘랐다. 단, 어떤 막대기는 자르지 않을 수도 있다.</p>

<p>승연이는 이렇게 잘려진 토막들을 다시 붙여서 원래 상태의 막대기로 만들려고 하는데 원래 자기가 가지고 있던 막대기의 수와 막대기의 길이를 잊어버렸다. 그래서 승연이는 길이가 모두 같은 가장 짧은 막대기들로 복원하기로 하였다.</p>

<p>문제는 잘려진 모든 토막으로부터 구성될 수 있는 같은 길이의 막대기 중에서 가장 짧은 길이를 계산하는 프로그램을 작성하는 것이다.</p>

<p>아래 <그림>의 예에서 보듯이 같은 막대기 몇 개를 잘라서 길이가 {5,2,1,1,2,5,2,5,1}인 토막으로 만들었다. 문제는 이 토막들로부터 구할 수 있는 같은 길이의 막대기 중에서 가장 짧은 것을 구하는 것이다.</p>

<p>아래 그림의 예에서 길이가 12인 긴 막대기 2개를 만들 수도 있으나 가장 짧은 동일한 막대기들의 길이는 6이 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/016f265e-e9fe-43ac-8277-ba7325c1eb4e/-/preview/" style="width: 235px; height: 128px;"></p>

### 입력 

 <p>입력은 두 줄로 구성된다. 첫째 줄에는 잘려진 토막들의 총 수를 나타낸다. 이 수는 최대 50이다. 두 번째 줄에는 작게 잘라진 토막들의 각 길이를 나타내는 정수가 나열된다. 각 토막의 길이를 나타내는 숫자 사이에는 하나씩의 공백이 있다. 각 토막의 길이 l 은 1 ≤ l ≤ 1,000 인 정수이다.</p>

### 출력 

 <p>첫째 줄에 복구된 막대기들의 길이를 나타내는 정수를 출력한다. 그 다음 줄에는 각 토막들이 연결된 상태를 아래 출력 파일의 예와 같이 각 줄에 임의의 순서로 표시한다.</p>

