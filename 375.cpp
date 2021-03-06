/*
375. Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Hint:

The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
Take a small example (n = 3). What do you end up paying in the worst case?
Check out this article if you're still stuck.
The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?
Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> u(n + 2, vector<int>(n + 2));
        for (int b = 2; b <= n; ++b) {
            int k0 = b - 1;
            deque<pair<int, int>> v;
            for (int a = b - 1; a; --a) {
                while (u[a][k0 - 1] > u[k0 + 1][b]) {
                    if (!v.empty() && v.front().second == k0) v.pop_front();
                    --k0;
                }
                int vn = a + u[a + 1][b];
                while (!v.empty() && vn < v.back().first) v.pop_back();
                v.emplace_back(vn, a);
                int u1 = u[a][k0] + k0 + 1;
                int u2 = v.front().first;
                u[a][b] = u1 < u2 ? u1 : u2;
            }
        }
        return u[1][n];
    }
};
