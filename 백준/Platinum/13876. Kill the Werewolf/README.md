# [Platinum II] Kill the Werewolf - 13876 

[문제 링크](https://www.acmicpc.net/problem/13876) 

### 성능 요약

메모리: 2248 KB, 시간: 0 ms

### 분류

최대 유량

### 문제 설명

<p>In the popular board game One Night Werewolf, players are distributed randomly in the roles of villagers and Werewolves. The goal of the villagers is to decide together on one person to kill during the night – hopefully they will kill a Werewolf. Werewolves pose as villagers in the hope that the person killed is a villager, not a Werewolf.</p>

<p>In the variation Uncertain Werewolf, only one Werewolf exists and the game consists of two phases. During the first phase the players are still uncertain about who they should vote to kill, so each of them chooses two other players as possible victims. After the first phase the Werewolf reveals himself, and then in the second phase each player has to decide which one of their two initial choices they will vote to kill. The Werewolf is the last one to decide between his two initial choices, doing so after all the other players have decided already.</p>

<p>The Werewolf then loses the game if he has more votes than anyone else. If there is a draw, the Werewolf wins.</p>

<p>You are given the votes of N players after the first phase of the game. You should answer how many players could reveal themselves at this point as the Werewolf and still win the game if the other players chose their votes optimally to kill the Werewolf.</p>

### 입력 

 <p>The first line contains an integer N (3 ≤ N ≤ 50), the number of players in the game. Each of the following N lines contains two integers, a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub> , b<sub>i</sub> ≤ N, a<sub>i</sub> ≠ b<sub>i</sub>), the index of the players the i-th player decided to kill in the first voting phase. No player will try to kill himself.</p>

### 출력 

 <p>Output a line with one integer representing the number of players that could win the game if they were the Werewolf and everyone played optimally.</p>

