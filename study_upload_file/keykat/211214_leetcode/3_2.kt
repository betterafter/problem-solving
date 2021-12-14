class Solution3_2kt {

    var m = mutableMapOf<Char, Int>()
    var curr =  0
    var maxLen = 0

    fun lengthOfLongestSubstring(s: String): Int {
        for (i in 0..s.length - 1) {
            if (s[i] in m && curr <= m[s[i]]!!) {
                curr = m[s[i]]!! + 1
            } else {
                maxLen = Math.max(maxLen, i - curr + 1)
            }

            m[s[i]] = i
        }

        return maxLen
    }
}