# [Platinum II] Triumphal arch - 8243 

[문제 링크](https://www.acmicpc.net/problem/8243) 

### 성능 요약

메모리: 37044 KB, 시간: 416 ms

### 분류

이분 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 매개 변수 탐색, 트리

### 제출 일자

2024년 1월 1일 20:25:36

### 문제 설명

<p>The king of Byteotia, Byteasar, is returning to his country after a victorious battle. In Byteotia, there are n towns connected with only n-1 roads. It is known that every town can be reached from every other town by a unique route, consisting of one or more (direct) roads. (In other words, the road network forms a tree).</p>

<p>The king has just entered the capital. Therein a triumphal arch, i.e., a gate a victorious king rides through, has been erected. Byteasar, delighted by a warm welcome by his subjects, has planned a triumphal procession to visit all the towns of Byteotia, starting with the capital he is currently in.</p>

<p>The other towns are not ready to greet their king just yet - the constructions of the triumphal arches in those towns did not even begin! But Byteasar's trusted advisor is seeing to the issue. He desires to hire a number of construction crews. Every crew can construct a single arch each day, in any town. Unfortunately, no one knows the order in which the king will visit the towns. The only thing that is clear is that every day the king will travel from the city he is currently in to a neighboring one. The king may visit any town an arbitrary number of times (but as he is not vain, one arch in each town will suffice).</p>

<p>Byteasar's advisor has to pay each crew the same flat fee, regardless of how many arches this crew builds. Thus, while he needs to ensure that every town has an arch when it is visited by the king, he wants to hire as few crews as possible. Help him out by writing a program that will determine the minimum number of crews that allow a timely delivery of the arches.</p>

### 입력 

 <p>The first line of the standard input contains a single integer n (1 ≤ n ≤ 300,000), the number of towns in Byteotia. The towns are numbered from 1 to , where the number 1 corresponds to the capital.</p>

<p>The road network is described in n-1 lines that then follow. Each of those lines contains two integers, a,b (1 ≤ a,b ≤ n), separated by a single space, indicating that towns a and b are directly connected with a two way road.</p>

### 출력 

 <p>The first and only line of the standard output is to hold a single integer, the minimum number of crews that Byteasar's advisor needs to hire.</p>

