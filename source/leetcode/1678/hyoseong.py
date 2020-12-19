class Solution:
    def interpret(self, command: str) -> str:
        i = 0
        ret = ""
        while i < len(command) :
            for s in [["G", "G"], ["()", "o"], ["(al)", "al"]] :
                if command[i:i+len(s[0])] == s[0] :
                    ret += s[1]
                    i += len(s[0])
                    break

        return ret
