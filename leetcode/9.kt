class Solution9 {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) return false
        
        val xx = x.toString()

        for (i in 0..xx.length / 2 - 1) {
            if (xx[i] != xx[xx.length - i - 1]) return false
        }

        return true
    }
}