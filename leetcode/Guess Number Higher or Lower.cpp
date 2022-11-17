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
        long long st = 1, en = n, ans=0;
        while(st<=en)
        {
            int temp = (st+en)/2;
            if(guess(temp)>0)
            {
                st = temp+1;
            }
            else if(guess(temp)<0)
            {
                en = temp-1;
            }
            else
            {
                ans = temp;
                break;
            }
        }
        
        return ans;
    }
};