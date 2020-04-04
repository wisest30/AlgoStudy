package leetcode;

public class JiHaeng {
	public String longestPrefix(String s) {
		int[] m = new int[s.length()];
		int j = 0;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) == s.charAt(j)) {
				m[i] = ++j;
			} else if (j > 0) {
				j = m[j - 1];
				--i;
			}
		}
		return s.substring(0, j);
	}
}