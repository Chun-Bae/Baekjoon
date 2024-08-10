# [Gold V] Game Dice - 7670 

[문제 링크](https://www.acmicpc.net/problem/7670) 

### 성능 요약

메모리: 2216 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2024년 8월 11일 08:29:40

### 문제 설명

<p>In the game of Dungeons & Dragons, players often roll multi-sided dice to generate random numbers which determine the outcome of actions in the game. These dice come in various flavors and shapes, ranging from a 4-sided tetrahedron to a 20-sided isocahedron. The faces of an n-sided die, called dn for short, are numbered from 1 to n. Ideally, it is made in such a way that the probabilities that any of its n faces shows up are equal. The dice used in the game are d4, d6, d8, d10, d12, and d20.</p>

<p>When generating random numbers to fit certain ranges, it is sometimes necessary or desirable to roll several dice in conjunction and sum the values on their faces. However, we may notice that although different combinations of dice yield numbers in the same range, the probabilities of rolling each of the numbers within the range differ entirely. For example, a d6 and a d10 afford a range of 2 to 16 inclusive, as does two d8s, but the probability of rolling a 9 differs in each circumstance.</p>

<p>Your task in this problem is to determine the probability of rolling a certain number, given the set of dice used.</p>

### 입력 

 <p>The input test file will contain multiple cases, with each case on a single line of input. The line begins with an integer d (where 1 ≤ d ≤ 13), the number of dice rolled. Following are d descriptors of dice, which can be any of “d4”, “d6”, “d8”, “d10”, “d12”, or “d20”. The last number on each line is an integer x (where 0 ≤ x ≤ 1000), the number for which you are to determine the probability of rolling with the given set of dice. End-of-input is marked by a single line containing 0; do not process this line.</p>

### 출력 

 <p>For each test case, output on a single line the probability of rolling x with the dice, accurate to five decimal places. Note that even if there trailing zeros, you must show them (see Test problem for an example of decimal formatting).</p>

