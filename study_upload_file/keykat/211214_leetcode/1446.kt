class Solution1446kt {

    fun maxPower(s: String): Int {

        var max = 1
        var currMax = 1
        var curr = s[0]
        
        for (i in 1..s.length - 1) {
            if (curr == s[i]) {
                currMax += 1
            } else {
                curr = s[i]
                max = Math.max(currMax, max)
                currMax = 1
            }
        }
        return Math.max(currMax, max)
    }
}