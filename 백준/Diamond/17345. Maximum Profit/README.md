# [Diamond IV] Maximum Profit - 17345 

[문제 링크](https://www.acmicpc.net/problem/17345) 

### 성능 요약

메모리: 10768 KB, 시간: 80 ms

### 분류

최대 유량, 최대 유량 최소 컷 정리

### 문제 설명

<p>New technology is bombarding the mobile communications market. For major cellphone carriers, this is both an opportunity and a challenge. The THU Group's CS&T communications company is at the eve of a bloody battle in a new generation of communication technology. So much preparatory work needs to be done. For the site-selection aspect alone, they will need to complete prior market research, site investigation, optimization, and other projects.</p>

<p>After the market research and site investigation, the company has determined a total of <var>N</var> sites for relay stations of cellular signals. Due to geographical factors of these sites, establishing relay stations at different places require different principal costs. Luckily this cost data is already known after the prior market research: establishing the <var>i</var>-th relay station requires a principal cost of <var>P<sub>i</sub></var> (1 ≤ <var>i</var> ≤ <var>N</var>).</p>

<p>The company also researched the expected user base, consisting of <var>M</var> total customer groups. The <var>i</var>-th group's information can be summarized using the values <var>A<sub>i</sub></var>, <var>B<sub>i</sub></var>, and <var>C<sub>i</sub></var>. Users in this group will use relay stations <var>A<sub>i</sub></var> and <var>B<sub>i</sub></var> for communication, allowing the company to receive <var>C<sub>i</sub></var> in revenue (1 ≤ <var>i</var> ≤ <var>M</var>, 1 ≤ <var>A<sub>i</sub></var>, <var>B<sub>i</sub></var> ≤ <var>N</var>).</p>

<p>The THU Group's CS&T company can select a group of relay stations to establish (thus paying the necessary principal cost), servicing certain customer groups (thus receiving revenue). How must they select which relay stations to establish so that the company can receive the maximum possible profit? (Profit = total revenue − total principal cost)</p>

### 입력 

 <p>The first line of input contains two integers <var>N</var> and <var>M</var>.</p>

<p>The second line contains <var>N</var> integers describing the principal cost to build each relay station, respectively <var>P</var><sub>1</sub>, <var>P</var><sub>2</sub>, …, <var>P<sub>N</sub></var>.</p>

<p>There will be <var>M</var> lines to follow. Line (<var>i</var> + 2) of input will contain 3 integers <var>A<sub>i</sub></var>, <var>B<sub>i</sub></var>, and <var>C<sub>i</sub></var> describing the information about the <var>i</var>-th customer group.</p>

### 출력 

 <p>Your program should output a single integer, representing the maximum profit that the company can obtain.</p>

