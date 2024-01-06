/*

Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.


Example 1:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for(int i=0;i<n;i++){
            jobs[i] = new int[]{startTime[i],endTime[i],profit[i]};
        }
        
        Arrays.sort(jobs,(a,b) -> a[1] - b[1]);
        
        TreeMap<Integer,Integer> dp = new TreeMap<>();
        dp.put(0,0);
        
        for(int[] job:jobs){
            int val = job[2] + dp.floorEntry(job[0]).getValue();
            if(val>dp.lastEntry().getValue()){
                dp.put(job[1],val);
            }
        }
        
        return dp.lastEntry().getValue();
        
    }
}
