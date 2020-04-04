package leetcode;

public class JiHaeng {
	public int sumFourDivisors(int[] nums) {
		int rs = 0;

		for (int num : nums) {
			int midDivisor = 0;
			for (int i = 2; (i * i) <= num; i++) {
				if (num % i == 0) {
					if (midDivisor == 0) {
						midDivisor = i;
					} else {
						midDivisor = 0;
						break;
					}
				}
			}
			if (midDivisor != 0 && midDivisor != num / midDivisor) {
				rs += 1 + midDivisor + (num / midDivisor) + num;
			}
		}
		return rs;
	}
}