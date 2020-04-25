class Solution:
    def entityParser(self, text: str) -> str:
        specials = {
            # 4
            '&gt;': '>',
            '&lt;': '<',
            # 5
            '&amp;': '&',
            # 6
            '&quot;': '"',
            '&apos;': "'",
            # 7
            '&frasl;': '/',
        }
        def find(i):
            for j in range(4, 8):
                s = text[i: i + j]
                if s in specials:
                    return specials[s], j
            return None, 0  
        
        result = ''
        i = 0
        while i < len(text):
            c = text[i]
            if c == '&':
                s, j = find(i)
                if s:
                    i += j
                    result += s 
            else:        
                result += c
                i += 1
        
        return result
