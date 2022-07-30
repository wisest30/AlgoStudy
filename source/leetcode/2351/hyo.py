class Solution:
    def repeatedCharacter(self, s: str) -> str:
        st = set()
        for c in s :
            if c in st :
                return c
            st.add(c)
