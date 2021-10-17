function twoOutOfThree(nums1: number[], nums2: number[], nums3: number[]): number[] {
    let m = new Map<number, number>();
    nums1.forEach(num => m.set(num, 1));
    nums2.forEach(num => {
        const val = m.get(num);
        m.set(num, val !== undefined ? val | 2 : 2);
    });
    nums3.forEach(num => {
        const val = m.get(num);
        m.set(num, val !== undefined ? val | 4 : 4);
    });
    
    let result = [];
    m.forEach((value, key) => {
        let containCnt = value & 1 ? 1 : 0;
        containCnt += value & 2 ? 1 : 0;
        containCnt += value & 4 ? 1 : 0;
        if (containCnt >= 2) {
            result.push(key);
        }
    })
    
    return result;
};
