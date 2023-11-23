# [Diamond V] Cleaning Robots - 19156 

[문제 링크](https://www.acmicpc.net/problem/19156) 

### 성능 요약

메모리: 14808 KB, 시간: 104 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 수학, 누적 합, 트리

### 제출 일자

2023년 11월 23일 13:13:39

### 문제 설명

<p>The new ICPC town has N junctions (numbered from 1 to N) which are connected by N − 1 roads. It is possible from one junction to go to any other junctions by going through one or more roads. To make sure all the junctions are well-maintained, the government environment agency is planning to deploy their newest advanced cleaning robots. In addition to its cleaning ability, each robot is also equipped with a movement ability such that it can move from one junction to any other junctions connected by roads. However, as you might have guessed, such robots are not cheap. Therefore, the agency is considering the following deployment plan.</p>

<p>Let T<sub>k</sub> be the set of junctions which should be cleaned by the k<sup>th</sup> robot (also known as, the robot’s task), and |T<sub>k</sub>| ≥ 1 be the number of junctions in T<sub>k</sub>. The junctions in T<sub>k</sub> form a path, i.e. there exists a sequence of v<sub>1</sub>, v<sub>2</sub>, . . . , v<sub>|T<sub>k</sub>|</sub> where v<sub>i</sub> ∈ T<sub>k</sub> and v<sub>i</sub> ≠ v<sub>j</sub> for all i ≠ j such that each adjacent junction in this sequence is connected by a road. The union of T for all robots is equal to the set of all junctions in ICPC town. On the other hand, no two robots share a common junction, i.e. T<sub>i</sub> ∩ T<sub>j</sub> = ∅ if i ≠ j.</p>

<p>To avoid complaints from citizens for an inefficient operation, the deployment plan should be irreducible; in other words, there should be no two robots, i and j, such that T<sub>i</sub> ∪ T<sub>j</sub> forms a (longer) path. Note that the agency does not care whether the number of robots being used is minimized as long as all the tasks are irreducible. Your task in this problem is to count the number of feasible deployment plan given the town’s layout. A plan is feasible if and only if it satisfies all the above-mentioned requirements.</p>

<p>For example, let N = 6 and the roads are {(1, 3),(2, 3),(3, 4),(4, 5),(4, 6)}. There are 5 feasible deployment plans as shown in the following figure.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5c3f9004-926d-4cd8-8336-d33f08e5aa7b/-/preview/" style="width: 613px; height: 159px;"></p>

<ul>
	<li>The first plan uses 2 robots (labeled as A and B in the figure) to clean {1, 2, 3} and {4, 5, 6}.</li>
	<li>The second plan uses 3 robots (labeled as A, B, and C in the figure) to clean {1, 3, 4, 6}, {2}, and {5}.</li>
	<li>The third plan uses 3 robots to clean {1, 3, 4, 5}, {2}, and {6}.</li>
	<li>The fourth plan uses 3 robots to clean {1}, {2, 3, 4, 6}, and {5}.</li>
	<li>The fifth plan uses 3 robots to clean {1}, {2, 3, 4, 5}, and {6}.</li>
</ul>

<p>No other plans are feasible in this case. For example, the plan {{1, 3}, {2}, {4, 5, 6}} is not feasible as the task {1, 3} and {2} can be combined into a longer path {1, 3, 2}. The plan {{1, 2, 3, 4}, {5}, {6}} is also not feasible as {1, 2, 3, 4} is not a path.</p>

### 입력 

 <p>Input begins with a line containing an integer: N (1 ≤ N ≤ 100 000) representing the number of junctions. The next N − 1 lines each contains two integers: u<sub>i</sub> v<sub>i</sub> (1 ≤ u<sub>i</sub> < v<sub>i</sub> ≤ N) representing a road connecting junction u<sub>i</sub> and junction v<sub>i</sub>. It is guaranteed that it is possible from one junction to go to any other junctions by going through one or more roads.</p>

### 출력 

 <p>Output in a line an integer representing the number of feasible deployment plans. As this output can be large, you need to modulo the output by 1 000 000 007.</p>

