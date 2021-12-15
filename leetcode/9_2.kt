class Solution9_2 {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) return false
        var list = mutableListOf<Int>()
        var xx = x

        while (xx != 0) {
            list.add(xx % 10)
            xx /= 10
        }

        list = list.reversed().toMutableList()
        while (list.isNotEmpty()) {
            if (list.size == 1) return true
            var first = list.removeAt(0)
            var last = list.removeAt(list.lastIndex)
            if (first != last) return false
        }

        return true
    }
}