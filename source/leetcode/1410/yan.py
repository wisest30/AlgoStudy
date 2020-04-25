class Solution:
    def entityParser(self, text: str) -> str:
        def parse(text):
            specials = {
                '&gt;': '>',
                '&lt;': '<',
                '&amp;': '&',
                '&quot;': '"',
                '&apos;': "'",
                '&frasl;': '/',
            }
            i = 0
            while i < len(text):
                c = text[i]
                if c == '&':
                    s = next((s for s in specials if text[i:].startswith(s)), c)
                    yield specials.get(s, c)
                    i += len(s)
                else:            
                    yield c
                    i += 1   
        
        return ''.join(parse(text))
