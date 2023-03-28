# [Diamond III] Kingdom - 1841 

[문제 링크](https://www.acmicpc.net/problem/1841) 

### 성능 요약

메모리: 2816 KB, 시간: 44 ms

### 분류

그래프 이론, 이분 탐색, 데이크스트라, 최대 유량, 최대 유량 최소 컷 정리

### 문제 설명

<p>King Kong is the feared but fair ruler of Transylvania. The kingdom consists of two cities and N < 150 towns, with nonintersecting roads between some of them. The roads are bidirectional, and it takes the same amount of time to travel them in both directions. Kong has G < 353535 soldiers.</p>

<p>Due to increased smuggling of goat cheese between the two cities, Kong has to place his soldiers on some of the roads in such a way that it is impossible to go from one city to the other without passing a soldier. The soldiers must not be placed inside a town, but may be placed on a road, as close as Kong wishes, to any town. Any number of soldiers may be placed on the same road. However, should any of the two cities be attacked by a foreign army, the king must be able to move all his soldiers fast to the attacked city. Help him place the soldiers in such a way that this mobilizing time is minimized.</p>

<p>Note that the soldiers cannot be placed in any of the cities or towns. The cities have ZIP-codes 95050 and 104729, whereas the towns have ZIPcodes from 0 to N − 1. There will be at most one road between any given pair of towns or cities.</p>

### 입력 

 <p>The input contains several test cases. The ﬁrst line of each test case is N, G and E, where N and G are as deﬁned above and E < 5000 is the number of roads. Then follow E lines, each of which contains three integers: A and B, the ZIP codes of the endpoints, and ∅, the time required to travel the road, ∅ < 1000. The last line of the input is a line containing a single 0.</p>

### 출력 

 <p>For each test case in the input, print the best mobilizing time possible, with one decimal. If the given number of soldiers is not enough to stop the goat cheese, print “Impossible” instead.</p>

