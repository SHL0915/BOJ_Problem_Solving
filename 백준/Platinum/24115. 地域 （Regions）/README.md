# [Platinum I] 地域 (Regions) - 24115 

[문제 링크](https://www.acmicpc.net/problem/24115) 

### 성능 요약

메모리: 5712 KB, 시간: 92 ms

### 분류

이분 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그리디 알고리즘, 매개 변수 탐색, 트리

### 문제 설명

<p>JOI 国には N 個の都市があり，1 から N の番号がついている．これらの都市は，双方向に通行可能な道 でツリー状に接続されている．すなわち，任意の 2 つの都市は道をたどって行き来が可能であり，かつそ の経路は一意である．このとき，道は N − 1 本である．</p>

<p>都市を，M 個の地域に分けることにした．全ての地域は 1 つ以上の都市を含み，全ての都市はちょうど 1 つの地域に含まれるようにしなければならない．また，同じ地域に含まれる任意の 2 つの都市は，その 地域に含まれない都市を通らずに道をたどって行き来が可能でなければならない．</p>

<p>各地域の直径の最大値 d<sub>max</sub> ができるだけ小さくなるように地域分けをしたい．ある地域の直径とは，そ の地域に含まれる 2 つの都市間の距離の最大値である．2 つの都市間の距離とは，2 つの都市を結ぶ経路に 含まれる道路の長さの和である．地域に 1 つしか都市が含まれない時，その地域の直径は 0 とする．</p>

<p>道の情報と地域の数が与えられると，d<sub>max</sub> の最小値を計算するプログラムを作成せよ．</p>

### 입력 

 <p>標準入力から以下の入力を読み込め．</p>

<ul>
	<li>1 行目には整数 N, M が空白を区切りとして書かれている．</li>
	<li>続く N − 1 行には，1 行につき 1 つの道について記述している．これらの行のうちの i 行目は道 i に ついて記述しており，整数 A<sub>i</sub>, B<sub>i</sub> ,C<sub>i</sub> が空白を区切りとして書かれている．</li>
</ul>

### 출력 

 <p>標準出力に d<sub>max</sub> の最小値を表す 1 つの整数を出力せよ．</p>

