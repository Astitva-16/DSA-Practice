/*
Problem - Guess Number Higher or Lower
LeetCode - https://leetcode.com/problems/guess-number-higher-or-lower/
*/

//APPROACH - 1 Brute Force -> Linear Search
//Time Complexity - O(N)
//Space Complexity - O(1)

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {

        for(int i = 1; i <= n; i++){

            if(guess(i) == 0){
                return i;
            }
        }

        return -1;
    }
};



//APPROACH - 2 Optimised Way -> Binary Search
//Time Complexity - O(log n)
//Space Complexity - O(1)

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int val = guess(mid);

            if(val == 1) low = mid + 1;

            else if(val == -1) high = mid - 1;

            else return mid;
        }

        return 0;
    }
};
