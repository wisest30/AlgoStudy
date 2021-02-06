class Solution {
    public String maximumTime(String time) {
        StringBuilder s = new StringBuilder(time);
        if(s.charAt(0) == '?' && s.charAt(1) == '?')
        {
            s.setCharAt(0, '2');
            s.setCharAt(1, '3');
        }
        else if(s.charAt(0) == '?') {
            if(s.charAt(1) <= '3') s.setCharAt(0, '2');
            else s.setCharAt(0, '1');
        }
        else if(s.charAt(1) == '?') {
            if(s.charAt(0) == '2') s.setCharAt(1, '3');
            else s.setCharAt(1, '9');
        }
        
        if(s.charAt(3) == '?') s.setCharAt(3, '5');
        if(s.charAt(4) == '?') s.setCharAt(4, '9');
        
        return s.toString();
    }
}
