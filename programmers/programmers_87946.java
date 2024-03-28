import java.util.Arrays;

class Solution {
    public int solution(int k, int[][] dungeons) {
        int[] max = { 0 }; 
        
        Boolean[] used = new Boolean[dungeons.length];
        Arrays.fill(used, false);
        for (int i = 0; i < dungeons.length; i++) {
            search(k, i, dungeons.length - 1, 0, dungeons, used, max);
        }

        return max[0];
    }

    void search(int k, int idx, int left, int count, int[][] dungeons, Boolean[] used, int[] max) {
        used[idx] = true;

        int currentCount = count;
        int currentK = k;
        if (dungeons[idx][0] <= k) {
            currentCount++;
            currentK = k - dungeons[idx][1];
        } 
        
        if (left <= 0) {
            max[0] = Math.max(max[0], currentCount);
            used[idx] = false;
            return;
        }

        for (int i = 0; i < dungeons.length; i++) {
            if (!used[i]) {
                search(currentK, i, left - 1, currentCount, dungeons, used, max);  
            }
        }

        used[idx] = false;
    }
}