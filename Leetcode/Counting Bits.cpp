# @param {Integer} n
# @return {Integer[]}

def to_bin(n)
    bin = ""
    while n>0
        bin+=(n%2).to_s
        n/=2
    end
    bin.reverse
    return bin
end


def count_bits(n)
    ans = []
    for i in 0..n
       ans<<(to_bin(i).count("1"))
    end
    
    return ans
end