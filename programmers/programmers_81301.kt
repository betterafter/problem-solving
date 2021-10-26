


class Solution_81301 {

    val m = mapOf<String, Int>(
        "zero" to 0, "one" to 1, "two" to 2, "three" to 3, "four" to 4, 
        "five" to 5, "six" to 6, "seven" to 7, "eight" to 8, "nine" to 9
        )

    fun solution(s: String): Int {
        var number = s;
        m.keys.forEach { key ->
            number = number.replace(key, m[key].toString())
        }

        return number.toInt()
    }
}