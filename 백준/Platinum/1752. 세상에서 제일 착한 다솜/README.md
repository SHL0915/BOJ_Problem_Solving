# [Platinum II] 세상에서 제일 착한 다솜 - 1752 

[문제 링크](https://www.acmicpc.net/problem/1752) 

### 성능 요약

메모리: 51492 KB, 시간: 404 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 1월 23일 23:40:54

### 문제 설명

<p>In Korea, the naughtiness of the cheonggaeguri, a small frog, is legendary.  This is a well-deserved reputation, because the frogs jump through your rice paddy at night, flattening rice plants.  In the morning, after noting which plants have been flattened, you want to identify the path of the frog which did the most damage.  A frog always jumps through the paddy in a straight line, with every hop the same length:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/25fbcb20-9955-4bf8-9263-1a5a8c7096b4/-/preview/" style="width: 424px; height: 29px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f476a40f-d2b7-48e1-a770-d604e2215693/-/preview/" style="width: 203px; height: 29px;"></p>

<p>Different frogs can jump with different hop lengths</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5214c998-7033-4b11-805e-958a8db938aa/-/preview/" style="width: 222px; height: 122px;"></p>

<p>And in different directions</p>

<p>Your rice paddy has plants arranged on the intersection points of a grid as shown in Figure-1, and the troublesome frogs hop completely through your paddy, starting outside the paddy on one side and ending outside the paddy on the other side as shown in Figure-2:</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/edcb2604-d9c1-4d32-a975-4baaea367a27/-/crop/346x298/0,0/-/preview/" style="width: 173px; height: 149px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/edcb2604-d9c1-4d32-a975-4baaea367a27/-/crop/443x298/535,0/-/preview/" style="width: 221px; height: 149px;"></td>
		</tr>
		<tr>
			<td>Figure-1</td>
			<td>Figure-2</td>
		</tr>
	</tbody>
</table>

<p>Many frogs can jump through the paddy, hopping from rice plant to rice plant.  Every hop lands on a plant and flattens it, as in Figure-3.  Note that some plants may be landed on by more than one frog during the night.  Of course, you can not see the lines showing the paths of the frogs or any of their hops outside of your paddy – for the situation in Figure-3, what you can see is shown in Figure-4:</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/1942a92a-e6b8-449f-93cb-f9380d7e22e5/-/crop/400x298/0,0/-/preview/" style="width: 200px; height: 149px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/1942a92a-e6b8-449f-93cb-f9380d7e22e5/-/crop/349x298/587,0/-/preview/" style="width: 175px; height: 149px;"></td>
		</tr>
		<tr>
			<td>Figure-3</td>
			<td>Figure-4</td>
		</tr>
	</tbody>
</table>

<p>From Figure-4, you can reconstruct all the possible paths which the frogs may have followed across your paddy.  You are only interested in frogs which have landed on at least 3 of your rice plants in their voyage through the paddy.  Such a path is said to be a frog path.  In this case, that means that the three paths shown in Figure-3 are frog paths (there are also other possible frog paths). The vertical path down column 1 might have been a frog path with hop length 4 except there are only 2 plants flattened so we are not interested; and the diagonal path including the plants on row 2 col. 3, row 3 col. 4, and row 6 col. 7 has three flat plants but there is no regular hop length which could have spaced the hops in this way while still landing on at least 3 plants, and hence it is not a frog path.  Note also that along the line a frog path follows there may be additional flattened plants which do not need to be landed on by that path (see the plant at (2, 6) on the horizontal path across row 2 in Figure-4), and in fact some flattened plants may not be explained by any frog path at all. </p>

<p>Your task is to write a program to determine the maximum number of landings in any single frog path (where the maximum is taken over all possible frog paths).  In Figure-4 the answer is 7, obtained from the frog path across row 6.</p>

<p> </p>

### 입력 

 <p>Your program is to read from standard input. The first line contains two integers R and C, respectively the number of rows and columns in your rice paddy, 1 ≤ R,C ≤ 5000.  The second line contains the single integer N, the number of flattened rice plants, 3 ≤ N ≤ 5000.  Each of the remaining N lines contains two integers, the row number (1≤ row number ≤ R) and the column number (1≤ column number ≤ C) of a flattened rice plant, separated by one blank. Each flattened plant is only listed once.</p>

### 출력 

 <p>Your program is to write to standard output. The output contains one line with a single integer, the number of plants flattened along a frog path which did the most damage if there exists at least one frog path, otherwise, 0.</p>

