class Solution {
    public boolean halvesAreAlike(String s) {
        String vowel = "aeiouAEIOU";
        
        int cmp = 0;
        for(int i = 0; i < s.length() / 2; ++i)
            if(vowel.contains("" + s.charAt(i)))
                cmp++;
        for(int i = s.length() / 2; i < s.length(); ++i)
            if(vowel.contains("" + s.charAt(i)))
                cmp--;
        
        return cmp == 0;
    }
}
