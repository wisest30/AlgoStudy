class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int r = matrix.length;
        int c = matrix[0].length;

        ArrayList<Integer> values = new ArrayList<Integer>();
        int[][] A = new int[r][c];
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                A[i][j] = matrix[i][j];
                if(i > 0) A[i][j] ^= A[i-1][j];
                if(j > 0) A[i][j] ^= A[i][j-1];
                if(i > 0 && j > 0) A[i][j] ^= A[i-1][j-1];
                
                values.add(A[i][j]);
            }
        }
        
        Collections.sort(values);
        Collections.reverse(values);
        
        return values.get(k-1);
    }
}
