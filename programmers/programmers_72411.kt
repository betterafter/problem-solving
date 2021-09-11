
class Solution_72411 {

    var m = mutableMapOf<String, Int?>()

    fun ordering(order: String, visit: Array<Int>, idx: Int, size: Int) {
        val nOrder = order.toMutableList().sorted().joinToString("")

        var check = 0
        var res = ""
        for (i in 0 until order.length) {
            if (visit[i] == 1){ 
                check++
                res += order[i]
            }
            if (check == size) {
                m[res]?.let { 
                    m[res] = (m[res] as Int) + 1
                } ?: run {
                    m[res] = 1
                }
                return
            }
        }

        for (i in idx until nOrder.length) {
            if (visit[i] == 0) {
                visit[i] = 1
                ordering(nOrder, visit, i, size)
                visit[i] = 0
            }
        }
    }

    fun solution(orders: Array<String>, course: IntArray): Array<String> {
        var answer: Array<String> = arrayOf<String>()

        for (order in orders) {
            for (i in 0..order.length) {
                var visit = Array(order.length, {0}) 
                ordering(order, visit, 0, i)
            } 
        }

        var res = mutableListOf<String>()
        var maxSize = mutableMapOf<Int, Int>()
        for (c in course) {
            maxSize.put(c, 0)
        }

        for (key in m.keys) {
            if (key.length >= 2 && m[key]!! >= 2 && key.length in course) {
                if (m[key]!! >= maxSize[key.length]!!) {
                    maxSize[key.length] = m[key]!!
                }
                res.add(key)
            }
        }

        val ans = mutableListOf<List<String>>()
        val result = res.groupBy { it.length }.forEach { li ->
            ans.add(li.value.filter { 
                m[it]!! == maxSize[it.length]!!
            } )
        }
        answer = ans.flatten().sorted().toTypedArray()
        return answer
    }
}