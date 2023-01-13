# [Gold V] Bessie Slows Down - 9878 

[문제 링크](https://www.acmicpc.net/problem/9878) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

자료 구조(data_structures), 구현(implementation), 수학(math), 우선순위 큐(priority_queue), 정렬(sorting)

### 문제 설명

<p>Bessie the cow is competing in a cross-country skiing event at the winter Moolympic games.  She starts out at a speed of 1 meter per second. However, as she becomes more tired over time, she begins to slow down. Each time Bessie slows down, her speed decreases: she moves at 1/2 meter per second after slowing down once, then 1/3 meter per second after slowing down twice, and so on.</p><p>You are told when and where Bessie slows down, in terms of a series of events.  An event like this:</p><p>T 17</p><p>means that Bessie slows down at a specific time -- here, 17 seconds into the race.  An event like this:</p><p>D 10</p><p>means that Bessie slows down at a specific distance from the start -- in this case, 10 meters.</p><p>Given a list of N such events (1 <= N <= 10,000), please compute the amount of time, in seconds, for Bessie to travel an entire kilometer.  Round your answer to the nearest integer second (0.5 rounds up to 1).</p>

### 입력 

 <ul><li>Line 1: The value of N.</li><li>Lines 2..1+N: Each line is of the form "T x" or "D x", indicating a time event or a distance event.  In both cases, x is an integer that is guaranteed to place the event before Bessie reaches one kilometer of total distance.  It is possible for multiple events to occur simultaneously, causing Bessie to slow down quite a bit all at once.  Events may not be listed in order.</li></ul>

### 출력 

 <ul><li>Line 1: The total time required for Bessie to travel 1 kilometer.</li></ul>

