class Solution {
    private int f(String a, String b) {
        int ret = Integer.MAX_VALUE;
        for(char c = 'a'; c < 'z'; ++c) {
            int candi = 0;
            for(char x : a.toCharArray()) if(x > c) candi++;
            for(char x : b.toCharArray()) if(x <= c) candi++;
            ret = Math.min(ret, candi);
        }
        
        return ret;
    }
    
    private int g(String a, String b) {
        int ret = Integer.MAX_VALUE;
        for(char c = 'a'; c <= 'z'; ++c) {
            int candi = 0;
            for(char x : a.toCharArray()) if(x != c) candi++;
            for(char x : b.toCharArray()) if(x != c) candi++;
            ret = Math.min(ret, candi);
        }
        
        return ret;
    }
    
    public int minCharacters(String a, String b) {
        int ret = Math.min(f(a, b), f(b, a));
        ret = Math.min(ret, g(a, b));
        return ret;
    }
}
