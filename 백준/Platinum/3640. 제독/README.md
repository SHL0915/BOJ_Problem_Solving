# [Platinum II] 제독 - 3640 

[문제 링크](https://www.acmicpc.net/problem/3640) 

### 성능 요약

메모리: 96688 KB, 시간: 368 ms

### 분류

최대 유량(flow), 최소 비용 최대 유량(mcmf)

### 문제 설명

<p>Michiel Adriaenszoon de Ruyter is the most famous admiral in Dutch history and is well known for his role in the Anglo-Dutch Wars of the 17th century. De Ruyter personally commanded a ﬂagship and issued commands to allied warships during naval battles.</p>

<p>In De Ruyter’s time, graph theory had just been invented and the admiral used it to his great advantage in planning his naval battles. Waypoints at sea are represented by vertices, and possible passages from one waypoint to another are represented as directed edges. Given any two waypoints W1 and W2, there is at most one passage W1 → W2. Each directed edge is marked with the number of cannonballs that need to be ﬁred in order to safely move a ship along that edge, sinking the enemy ships encountered along the way.</p>

<p>One of De Ruyter’s most successful tactics was the De Ruyter Manoeuvre. Here, two warships start at the same waypoint, and split up and ﬁght their way through the enemy ﬂeet, joining up again at a destination waypoint. The manoeuvre prescribes that the two warships take disjunct routes, meaning that they must not visit the same waypoint (other than the start and end-points), or use the same passage during the battle.</p>

<p>Being Dutch, Admiral De Ruyter did not like to waste money; in 17th century naval warfare, this meant ﬁring as few expensive cannonballs as possible.</p>

### 입력 

 <p>For each test case, the input consists of:</p>

<ul>
	<li>A line containing two integers v (3 ≤ v ≤ 1000) and e (3 ≤ e ≤ 10000), the number of waypoints and passages, respectively.</li>
	<li>Then, e lines follow: for each passage, a line containing three integers:
	<ol>
		<li>a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ v), the starting-point of a passage, which is represented by a waypoint;</li>
		<li>b<sub>i</sub> (1 ≤ b<sub>i</sub> ≤ v) and (a<sub>i</sub> ≠ b<sub>i</sub>), the end-point of a passage, which is represented by a waypoint. All passages are directed passages;</li>
		<li>c<sub>i</sub> (1 ≤ c<sub>i</sub> ≤ 100), the number of cannonballs that are ﬁred when travelling along this passage.</li>
	</ol>
	</li>
</ul>

<p>The starting waypoint is 1 and the destination waypoint is v. There are always at least two disjunct routes from waypoint 1 to waypoint v.</p>

### 출력 

 <p>For each test case, the output consists of a single positive integer: the smallest possible sum of cannonballs ﬁred by both ships when reaching the destination waypoint.</p>

