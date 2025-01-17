<header>

<!--
  <<< Author notes: Course header >>>
  Include a 1280×640 image, course title in sentence case, and a concise description in emphasis.
  In your repository settings: enable template repository, add your 1280×640 social image, auto delete head branches.
  Add your open source license, GitHub uses MIT license.
-->

# The Millionaire Problem

_This is the my solution just for reference_

This problem is from the first local onsite final of the 2008 Code Jam, which had four problems with different styles.

Problem C, the Millionaire, is one of the rare gems in the programming contests that, at first glance, is continuous and offers an infinite search space.

</header>

## Problem Statement

You have been invited to the popular TV show "Would you like to be a millionaire?". Of course you would!

The rules of the show are simple:

Before the game starts, the host spins a wheel of fortune to determine P, the probability of winning each bet.
You start out with some money: X dollars.
There are M rounds of betting. In each round, you can bet any part of your current money, including none of it or all of it. The amount is not limited to whole dollars or whole cents.
If you win the bet, your total amount of money increases by the amount you bet. Otherwise, your amount of money decreases by the amount you bet.
After all the rounds of betting are done, you get to keep your winnings (this time the amount is rounded down to whole dollars) only if you have accumulated $1000000 or more. Otherwise you get nothing.
Given M, P and X, determine your probability of winning at least $1000000 if you play optimally (i.e. you play so that you maximize your chances of becoming a millionaire).

---

__Input__

The first line of input gives the number of cases, N.

Each of the following N lines has the format "M P X", where:

- M is an integer, the number of rounds of betting.
- P is a real number, the probability of winning each round.
- X is an integer, the starting number of dollars.

---

__Output__

For each test case, output one line containing "Case #X: Y", where:

- X is the test case number, beginning at 1.
- Y is the probability of becoming a millionaire, between 0 and 1.
Answers with a relative or absolute error of at most 10^-6 will be considered correct.

---

__Limits__

Time limit: 30 seconds per test set.
Memory limit: 1GB.
1 ≤ N ≤ 100
0 ≤ P ≤ 1.0, there will be at most 6 digits after the decimal point.
1 ≤ X ≤ 1000000

Small dataset (Test set 1 - Visible)
1 ≤ M ≤ 5

Large dataset (Test set 2 - Hidden)
1 ≤ M ≤ 15

---

__Sample__

Sample Input

>_2_
>
>_1 0.5 500000_
>
>_3 0.75 600000_


Sample Output

>_Case #1: 0.500000_
>
>_Case #2: 0.843750_

In the first case, the only way to reach $1000000 is to bet everything in the single round.

In the second case, you can play so that you can still reach $1000000 even if you lose a bet. Here's one way to do it:

You have $600000 on the first round. Bet $150000.
- If you lose the first round, you have $450000 left. Bet $100000.
- If you lose the first round and win the second round, you have $550000 left. Bet $450000.
- If you win the first round, you have $750000 left. Bet $250000.
- If you win the first round and lose the second round, you have $500000 left. Bet $500000.



<footer>

[Reference](https://zibada.guru/gcj/2008r4a/problems/#C)
  
</footer>
