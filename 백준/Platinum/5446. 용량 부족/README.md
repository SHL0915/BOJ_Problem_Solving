# [Platinum III] 용량 부족 - 5446 

[문제 링크](https://www.acmicpc.net/problem/5446) 

### 성능 요약

메모리: 7444 KB, 시간: 72 ms

### 분류

자료 구조, 문자열, 트리, 트라이

### 문제 설명

<p>It happens to all of us. While you are happily downloading a movie or copying a file, a warning appears on your computer screen: “disk full,” or “disk quota exceeded.”</p>

<p>There are several ways to deal with this. You may simply accept the fact that you will never watch the movie you were downloading, or that you have to live the rest of your life with a single copy of the file. You may also install a larger disk or try to acquire a larger disk quota.</p>

<p>A third option is to create some space on the disk by removing files that you do not really need anymore. Under Linux, you can use the command rm for this. The syntax is simple: "rm filename" removes the file with name "filename". You may use a separate rm-command for every single file, but you may also use a wildcard ’*’ to remove multiple files in one step. For example, "rm BAPC*" removes all files that start with "BAPC". This way, you have to type fewer commands.</p>

<p>Of course, you must not remove files that you want to keep. Hence, "rm *", which is allowed, and which removes all files in the current directory, is often not desirable.</p>

<p>Now, given the names of the files you want to remove, and given the names of the files you want to keep, you have to determine the minimum number of rm-commands to get the job done. You may only use wildcards at the end of your commands. For example, "rm *.txt" (which would remove all ".txt" files) is not allowed.</p>

### 입력 

 <p>The first line of the input file contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with an integer N<sub>1</sub>, satisfying 1 ≤ N<sub>1</sub> ≤ 1000: the number of files that must be removed.</li>
	<li>N<sub>1</sub> lines, each with the name of one file that must be removed.</li>
	<li>One line with an integer N<sub>2</sub>, satisfying 0 ≤ N<sub>2</sub> ≤ 1000: the number of files that must not be removed.</li>
	<li>N<sub>2</sub> lines, each with the name of one file that must not be removed.</li>
</ul>

<p>Each filename is a string x with 1 ≤ Length(x) ≤ 20, consisting of alphabetic characters (upper case and lower case), digits and/or periods. That is, characters from the set { A, B, C, ... , Z, a, b, c, ... , z, 0, 1, 2, ..., 9,. }. All N<sub>1</sub> + N<sub>2</sub> file names for a test case are different.</p>

### 출력 

 <p>For every test case in the input, the output should contain a single number, on a single line: the smallest number of rm-commands to remove exactly the right files.</p>

