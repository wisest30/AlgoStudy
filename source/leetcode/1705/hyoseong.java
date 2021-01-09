class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });
        
        int ret = 0;
        for(int i = 0;; ++i) {
            if(i < days.length)
                q.add(new int[]{i + days[i], apples[i]});
            if(i >= days.length && q.isEmpty())
                break;

            while(!q.isEmpty() && (q.peek()[0] <= i || q.peek()[1] == 0))
                q.poll();
            
            if(!q.isEmpty()) {
                ret++;
                q.peek()[1]--;
            }
        }
        
        return ret;
    }
}
