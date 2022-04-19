# @param {Integer[]} nums
# @return {String[]}
def summary_ranges(nums)
    n = nums.length
    x = nums
    ans = []
    if(n==0)
        return ans
    end
    first = x[0]
    last = x[0]
    for i in 1..n-1
        if (x[i]-x[i-1]==1)
            last = x[i]
        else
            if(first==last)
                ans<<"#{first}"
            else
                ans<<"#{first}->#{last}"
            end
            first = x[i]
            last = x[i]
        end
    end
    if(first==last)
        ans<<"#{first}"
    else
        ans<<"#{first}->#{last}"
    end
end