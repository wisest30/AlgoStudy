class Solution:
    def interpret(self, command: str) -> str:
        i = 0
        ret = ""
        while i < len(command) :
            if command[i] == 'G' :
                ret += "G"
                i += 1
            elif command[i] == '(' and command[i+1] == ')' :
                ret += 'o'
                i += 2
            else :
                ret += 'al'
                i += 4
        return ret
