class Solution:
    def totalStrength(self, strength: List[int]) -> int:
        m = 1000000007
        n = len(strength)
        
        left, right = [0] * n, [n] * n
        st = []
        for i in range(n) :
            while st and strength[st[-1]] > strength[i] :
                right[st[-1]] = i
                st.pop()
            if st :
                left[i] = st[-1] + 1
            st.append(i)
        
        ps = [0] + list(accumulate(strength))
        ips = [0] + list(accumulate([(i + 1) * strength[i] for i in range(n)]))
        lsum = lambda l, r : ips[r] - ips[l] - l * (ps[r] - ps[l])
        rsum = lambda l, r : -(ips[r] - ips[l] - (r + 1) * (ps[r] - ps[l]))
        
        return sum(strength[i] * 
                   (lsum(left[i], i+1) * (right[i] - i) + \
                   rsum(i+1, right[i]) * (i - left[i] + 1)) \
                   for i in range(n)) % m
