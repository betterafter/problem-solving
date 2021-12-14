class Solution3 {

    var maxLen = 0
    fun lengthOfLongestSubstring(s: String): Int {
        for (i in 0..s.length-1) {
            var ss = mutableListOf<Char>(s[i])
            for (j in i+1..s.length-1) {
                if (s[j] !in ss) {
                    ss.add(s[j])
                } else {
                    break
                }
            }
            maxLen = Math.max(maxLen, ss.size)
        }
        return maxLen
    }
}