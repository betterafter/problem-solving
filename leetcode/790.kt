class Solution790 {

    val dp = mutableListOf<Int>(1, 1, 2)
    val mod = 1000000007
    
    fun numTilings(n: Int): Int {
        for(i in 3..n+1) {
            dp.add(((dp[i-1] * 2 % mod + dp[i-3]) % mod).toInt())
        }
        return dp[n]
    }
}