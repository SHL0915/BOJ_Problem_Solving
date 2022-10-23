# [Gold V] Hamming Ellipses - 13346 

[문제 링크](https://www.acmicpc.net/problem/13346) 

### 성능 요약

메모리: 2184 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>In geometry, ellipses are defined by two focal points f<sub>1</sub>, f<sub>2</sub> and a length D. The ellipse consists of all points p such that distance(f<sub>1</sub>, p) + distance(f<sub>2</sub>, p) = D.</p>

<p>When one normally thinks of ellipses, it is in the context of the Euclidean 2D plane, with the Euclidean distance as a distance measure.</p>

<p>This problem explores a different kind of ellipse. The space we will work in is the space of words of length n using an alphabet of q different symbols, often denoted as F<sup>n</sup><sub>q</sub>. As you can probably see, for given values of q and n, there are q<sup>n</sup> different words (points) in the space F<sup>n</sup><sub>q</sub>.</p>

<p>For a distance measure, we use the Hamming distance. The Hamming distance between two words x, y ∈ F<sup>n</sup><sub>q</sub> is simply the number of positions where the symbols that make up the words x and y differ. For example, the Hamming distance between words 01201 and 21210 is 3 because there are 3 positions where the words have different symbols. The Hamming distance between any two words in F<sup>n</sup><sub>q</sub> will always be an integer between 0 and n, inclusive.</p>

<p>Within the space F<sup>n</sup><sub>q</sub>, we now define the Hamming ellipse as the set of all points p such that hammingdistance(f<sub>1</sub>, p) + hammingdistance(f<sub>2</sub>, p) = D. Given values q and n, focal points f<sub>1</sub> and f<sub>2</sub> and distance D, we ask you to determine the number of points p ∈ F<sup>n</sup><sub>q</sub> that lie on this Hamming ellipse.</p>

### 입력 

 <p>The first line contains three integers q (2 ≤ q ≤ 10), n (1 ≤ n ≤ 100) and D (1 ≤ D ≤ 2n).</p>

<p>The second and third lines specify the two focal points f1 and f2, each formatted as a string of length n using digits {0, 1 . . . q − 1}</p>

### 출력 

 <p>Output one line containing a single integer, denoting the number of points on the ellipse. The input is chosen such that the answer is less than 2<sup>63</sup>.</p>

