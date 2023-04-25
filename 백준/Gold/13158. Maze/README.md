# [Gold I] Maze - 13158 

[문제 링크](https://www.acmicpc.net/problem/13158) 

### 성능 요약

메모리: 4372 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>Bob is the Captain of the USS Spacey McSpaceface, the pride of the space fleet of the Human Empire. Unfortunately, Bob is also the last one alive on his ship.</p>

<p>Because of an unrecognized virus, the ship’s AI “Alpha 5” went rampant and killed everyone by funelling neurotoxin into the crew’s quarters. Bob was the only one on the bridge at that time, where he could grab a handy detoxication kit and a gas mask. But alas, Alpha 5 also blocked the ships’ controls, so Bob was now drifting in space, alone, caged with a rampant AI that just initiated the self-destruction mechanism.</p>

<p>Bob remembered that some engineer once told him there was an override switch somewhere near the fusion reactor that powered the ship, so he started to make his way down into the engine quarters. Soon he noticed that the virus had also taken over the automatic door system — all doors seemed to open and close seemingly at random.</p>

<p>At least, Bob does know three things:</p>

<ul>
	<li>every door is labeled with a single big white letter;</li>
	<li>there is a huge display in every room which explains which doors will open and which will close (for example, if the displays show a big “A”, all doors labeled with “A” will open next, and all other doors will slam shut);</li>
	<li>every door will stay open for about half a second, just enough for Bob to dash into the next room.</li>
</ul>

<p>Bob wants to stay on the move (neurotoxin and all), so he will use a door whenever possible. However, Bob does not know the exact way to the core, so if there are multiple possible doors he could take, he just chooses one at random. Given the sequence of letters until the explosion, how high is the probability that Bob can reach the reactor core and shut it all down?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers n (1 ≤ n ≤ 10<sup>3</sup>) and m (1 ≤ m ≤ 5 · 10<sup>3</sup>), where n is the amount of rooms in the engine quarters and m is the amount of doors between them;</li>
	<li>m lines describing the doors. Each door is described by:
	<ul>
		<li>one line with two integers a and b (1 ≤ a, b ≤ n, a ≠ b) and a letter l between “A” and “Z” indicating a door from room a to room b labeled with l (on both sides);<br>
		There may be several doors between the same pair of rooms, which may or may not have the same letter written on them;</li>
	</ul>
	</li>
	<li>one line with the sequence the doors will open in. The sequence consists of of at most 200 letters from “A” to “Z”.</li>
</ul>

<p>After the last letter, all doors slam shut and the ship will explode if Bob has not reached the switch yet. Bob starts on the bridge, room 1, and the override switch is in room n.</p>

### 출력 

 <p>Output the percentage that Bob will reach the override switch in time.</p>

<p>The answer should be correct up to an absolute or relative error of at most 10<sup>−3</sup>.</p>

