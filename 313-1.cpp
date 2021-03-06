/*
313. Super Ugly Number

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> result(n, 0);
        int k = primes.size();
        vector<int> index(k, 0);
        result[0] = 1;

        for(int i = 1; i < n; i++){
            result[i] = result[index[0]] * primes[0];
            for(int j = 1; j < k; j++) {
                result[i] = min(result[i], result[index[j]] * primes[j]);
            }

            for(int j = 0; j < k; j++) {
                if(result[i] == result[index[j]] * primes[j]) {
                    index[j]++;
                }
            }
        }

        return result[n - 1];
    }
};
