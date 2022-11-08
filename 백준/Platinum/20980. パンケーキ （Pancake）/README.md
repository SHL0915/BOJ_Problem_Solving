# [Platinum V] パンケーキ (Pancake) - 20980 

[문제 링크](https://www.acmicpc.net/problem/20980) 

### 성능 요약

메모리: 24200 KB, 시간: 2376 ms

### 분류

너비 우선 탐색(bfs), 비트마스킹(bitmask), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 문자열(string)

### 문제 설명

<p>ビ太郎はパンケーキ店で働いている．</p>

<p>この店で最も人気のあるメニューは <var>N</var> 枚のパンケーキが積み重なったパンケーキタワーである．店で作られているパンケーキには <var>3</var> 種類の味があり，それぞれ <code>A</code>，<code>B</code>，<code>C</code> と呼ぶことにする．</p>

<p>ここで，パンケーキの並び方が次の条件を満たすようになっているパンケーキタワーを<strong>良いパンケーキタワー</strong>と呼ぶことにする．</p>

<ul>
	<li>すべての味 <code>A</code> のパンケーキと味 <code>B</code> のパンケーキの組において，味 <code>A</code> のパンケーキが味 <code>B</code> のパンケーキより上にある．</li>
	<li>すべての味 <code>A</code> のパンケーキと味 <code>C</code> のパンケーキの組において，味 <code>A</code> のパンケーキが味 <code>C</code> のパンケーキより上にある．</li>
	<li>すべての味 <code>B</code> のパンケーキと味 <code>C</code> のパンケーキの組において，味 <code>B</code> のパンケーキが味 <code>C</code> のパンケーキより上にある．</li>
</ul>

<p>例えば，パンケーキの味がそれぞれ上から順に <code>AABBBC</code>，<code>ACC</code>，<code>BBBB</code> となっているパンケーキタワーはどれも良いパンケーキタワーであるが，<code>AABABCC</code>，<code>CA</code> となっているパンケーキタワーはどれも良いパンケーキタワーではない．</p>

<p>盛り付け担当のビ太郎はパンケーキタワーに対して次の操作を行うことができる．</p>

<ul>
	<li>操作 <var>k</var> (<var>2 ≦ k ≦ N</var>)：上から <var>k</var> 枚目のパンケーキの下側にフライ返しを差し込み，そこから上のパンケーキをひっくり返す．すなわち，上から <var>k</var> 枚のパンケーキの並び方を反転させる．</li>
</ul>

<p>例えば，パンケーキの味が上から順に <code>ABCB</code> となっているパンケーキタワーに操作 <var>2</var>，操作 <var>3</var>，操作 <var>4</var> をそれぞれ行った場合，パンケーキの並び方は <code>BACB</code>，<code>CBAB</code>，<code>BCBA</code> となる．</p>

<p>今，<var>Q</var> 皿のパンケーキタワーがあり，<var>i</var> 皿目 (<var>1 ≦ i ≦ Q</var>) のパンケーキタワーはパンケーキの味が上から順に <var>S<sub>i,1</sub> S<sub>i,2</sub> … S<sub>i,N</sub></var> となっている．ビ太郎はそれぞれのパンケーキタワーについて，できる限り少ない回数の操作で良いパンケーキタワーにしたい．</p>

<p><var>Q</var> 皿のパンケーキタワーの並び方の情報が与えられるので，それぞれのパンケーキタワーについて，良いパンケーキタワーにするのに必要な操作の回数の最小値を求めるプログラムを作成せよ．</p>

### 입력 

 <p>入力は以下の形式で標準入力から与えられる．</p>

<p><var>N</var> <var>Q</var><br>
<var>S<sub>1</sub></var><br>
<var>S<sub>2</sub></var><br>
<var>:</var><br>
<var>S<sub>Q</sub></var></p>

<p>ただし，<var>S<sub>i</sub></var> (<var>1 ≦ i ≦ Q</var>) は長さ <var>N</var> の文字列で，その <var>j</var> 文字目 (<var>1 ≦ j ≦ N</var>) は <var>S<sub>i,j</sub></var> である．</p>

### 출력 

 <p>標準出力に <var>Q</var> 行出力せよ．<var>i</var> 行目 (<var>1 ≦ i ≦ Q</var>) には，<var>i</var> 皿目のパンケーキタワーについて，良いパンケーキタワーにするのに必要な操作の回数の最小値を出力せよ．</p>

