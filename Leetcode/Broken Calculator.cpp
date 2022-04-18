class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target>startValue)
        {
            target = (target%2>0?target+1:target/2);
            ans++;
        }
        
        return ans+(startValue-target);
    }
};