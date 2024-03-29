# [Platinum V] 쇼핑몰 - 5551 

[문제 링크](https://www.acmicpc.net/problem/5551) 

### 성능 요약

메모리: 40460 KB, 시간: 68 ms

### 분류

데이크스트라, 그래프 이론

### 문제 설명

<p>JOI 国には N 個の町があり，それらの間は M 本の双方向に通行可能な道路で結ばれている．K 個の町にはショッピングモールがあり，国民は道路を通ってそれらの町のいずれかに行き買い物をする．</p>

<p>家の場所によっては，買い物に行くために長い距離を移動する必要があり，それは非常に不便である．国王はこの実情を把握するため，ショッピングモールのある町までの最短距離が家の場所によってどれだけ長くなりうるのかを調べることにした．家は道路の途中に建てられることもあるので (入力例 1 の説明を参照)，この調査は非常に大変である．そこで国王は，優秀なプログラマーであるあなたに，調査を行うプログラムの作成を依頼した．</p>

<p>道路の情報とショッピングモールのある町の情報が与えられるとき，ショッピングモールのある町からもっとも遠い道路上の点 (端点も含む) までの距離を求めるプログラムを作成せよ．町の中を移動するのにかかる距離は無視してよい．</p>

### 입력 

 <p>標準入力から以下の入力を読み込め．</p>

<ul>
	<li>1 行目には整数 N, M, K が空白区切りで書かれている．N は JOI 国の町の個数を，M は JOI 国の道路の本数を，K はショッピングモールがある町の個数をそれぞれ表す．町には 1, 2, ... , N の番号がつけられている．</li>
	<li>続く M 行は道路の情報を表す．i + 1 行目 (1 ≤ i ≤ M) には整数 a<sub>i</sub>, b<sub>i</sub>, l<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ N, 1 ≤ b<sub>i</sub> ≤ N, 1 ≤ l<sub>i</sub> ≤ 1000) が空白区切りで書かれている．これは，i 本目の道路が町 a<sub>i</sub> と町 b<sub>i</sub> を結んでおり，長さがli であることを表す．道路の両端が同じ町であることはない．また，任意の 2 つの町 p, q に対し，pと q を結ぶ道路は 2 本以上存在しない．どの町からどの町へもいくつかの道路をたどって行くことができる．</li>
	<li>続く K 行はショッピングモールの情報を表す．i+M+1 行目 (1 ≤ i ≤ K) には 1 つの整数 s<sub>i</sub> (1 ≤ s<sub>i</sub> ≤ N)が書かれている．これは町 s<sub>i</sub> にショッピングモールがあることを表す．s<sub>1</sub>, ..., s<sub>K</sub> の中に同じ値が 2回以上現れることはない．</li>
</ul>

### 출력 

 <p>標準出力に，ショッピングモールのある町までの最短距離の最大値の小数点以下を四捨五入した整数 1つを出力せよ．</p>

