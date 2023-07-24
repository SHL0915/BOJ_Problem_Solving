# [Platinum I] 작은 새 - 10129 

[문제 링크](https://www.acmicpc.net/problem/10129) 

### 성능 요약

메모리: 18268 KB, 시간: 600 ms

### 분류

자료 구조, 덱, 다이나믹 프로그래밍, 덱을 이용한 다이나믹 프로그래밍

### 문제 설명

<p>In the Byteotian Line Forest there are n trees in a row. On top of the first one, there is a little bird who would like to fly over to the top of the last tree. Being in fact very little, the bird might lack the strength to fly there without any stop. If the bird is sitting on top of the tree no. i, then in a single flight leg it can fly to any of the trees no. i+1,i+2,…,i+k, and then has to rest afterward.</p>

<p>Moreover, flying up is far harder to flying down. A flight leg is tiresome if it ends in a tree at least as high as the one where is started. Otherwise the flight leg is not tiresome.</p>

<p>The goal is to select the trees on which the little bird will land so that the overall flight is least tiresome, i.e., it has the minimum number of tiresome legs. We note that birds are social creatures, and our bird has a few bird-friends who would also like to get from the first tree to the last one. The stamina of all the birds varies, so the bird's friends may have different values of the parameter k. Help all the birds, little and big!</p>

### 입력 

 <p>There is a single integer n(2 ≤ n ≤ 1,000,000) in the first line of the standard input: the number of trees in the Byteotian Line Forest. The second line of input holds n integers d<sub>1</sub>,d<sub>2</sub>,…,d<sub>n</sub>(1 ≤ d<sub>i</sub> ≤ 10<sup>9</sup>) separated by single spaces: d<sub>i</sub> is the height of the i-th tree.</p>

<p>The third line of the input holds a single integer q(1 ≤ q ≤ 25): the number of birds whose flights need to be planned. The following q lines describe these birds: in the i-th of these lines, there is an integer k<sub>i</sub>(1 ≤ k<sub>i</sub> ≤ n-1) specifying the -th bird's stamina. In other words, the maximum number of trees that the i-th bird can pass before it has to rest is k<sub>i</sub>-1.</p>

<p>In test worth at least l of total score, the condition n ≤ 100,000 holds. In a subset of those worth 1 ≤ y<sub>i</sub> ≤ k of total score, it even holds that n ≤ 1,000.</p>

### 출력 

 <p>Your program should print exactly q lines to the standard output. In the i-th line, it should specify the minimum number of tiresome flight legs of the i-th bird.</p>

<p> </p>

