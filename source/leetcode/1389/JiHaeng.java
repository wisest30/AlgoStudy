package leetcode;

import java.util.LinkedList;
import java.util.List;

public class JiHaeng {
	public int[] createTargetArray(int[] nums, int[] index) {
		List<Integer> target = new LinkedList<>();
		for (int i = 0; i < nums.length; i++) {
			target.add(index[i], nums[i]);
		}
		return target.stream()
			.mapToInt(i -> i)
			.toArray();
	}
}