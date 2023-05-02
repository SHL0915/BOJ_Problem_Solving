# [Platinum III] 형제 게임 - 11749 

[문제 링크](https://www.acmicpc.net/problem/11749) 

### 성능 요약

메모리: 3400 KB, 시간: 132 ms

### 분류

게임 이론, 그래프 이론

### 문제 설명

<p>You are playing a game with your elder brother.</p>

<p>First, a number of circles and arrows connecting some pairs of the circles are drawn on the ground. Two of the circles are marked as the start circle and the goal circle.</p>

<p>At the start of the game, you are on the start circle. In each turn of the game, your brother tells you a number, and you have to take that number of steps. At each step, you choose one of the arrows outgoing from the circle you are on, and move to the circle the arrow is heading to. You can visit the same circle or use the same arrow any number of times.</p>

<p>Your aim is to stop on the goal circle after the fewest possible turns, while your brother’s aim is to prevent it as long as possible. Note that, in each single turn, you must take the exact number of steps your brother tells you. Even when you visit the goal circle during a turn, you have to leave it if more steps are to be taken.</p>

<p>If you reach a circle with no outgoing arrows before completing all the steps, then you lose the game. You also have to note that, your brother may be able to repeat turns forever, not allowing you to stop after any of them.</p>

<p>Your brother, mean but not too selfish, thought that being allowed to choose arbitrary numbers is not fair. So, he decided to declare three numbers at the start of the game and to use only those numbers.</p>

<p>Your task now is, given the configuration of circles and arrows, and the three numbers declared, to compute the smallest possible number of turns within which you can always finish the game, no matter how your brother chooses the numbers.</p>

### 입력 

 <p>The input consists of a single test case, formatted as follows.</p>

<pre>n m a b c
u<sub>1</sub> v<sub>1</sub>
.
.
.
u<sub>m</sub> v<sub>m</sub></pre>

<p>All numbers in a test case are integers. n is the number of circles (2 ≤ n ≤ 50). Circles are numbered 1 through n. The start and goal circles are numbered 1 and n, respectively. m is the number of arrows (0 ≤ m ≤ n(n − 1)). a, b, and c are the three numbers your brother declared (1 ≤ a, b, c ≤ 100). The pair, u<sub>i</sub> and v<sub>i</sub>, means that there is an arrow from the circle u<sub>i</sub> to the circle v<sub>i</sub>. It is ensured that u<sub>i</sub> ≠ v<sub>i</sub> for all i, and u<sub>i</sub> ≠ u<sub>j</sub> or v<sub>i</sub> ≠ v<sub>j</sub> if i ≠ j.</p>

### 출력 

 <p>Print the smallest possible number of turns within which you can always finish the game. Print IMPOSSIBLE if your brother can prevent you from reaching the goal, by either making you repeat the turns forever or leading you to a circle without outgoing arrows.</p>

