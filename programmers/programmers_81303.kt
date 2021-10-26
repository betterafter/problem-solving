class Solution_81303 {

    var list = mutableListOf<String>()
    var table = mutableListOf<String>()
    var del = mutableListOf<Pair<String, Int>>()

    fun solution(n: Int, k: Int, cmd: Array<String>): String {
        var curr = k
        (0..n - 1).forEach { it ->
            table.add(it.toString())
            list.add("X")
        }

        cmd.forEach { order ->
            when(order[0]) {
                'U' -> {
                    curr -= order.substring(2).toInt()
                }
                'D' -> {
                    curr += order.substring(2).toInt()
                }
                'C' -> {
                    del.add(Pair(table[curr], curr))
                    table.removeAt(curr)
                    if (curr == table.size) curr -= 1
                }
                'Z' -> {
                    val data = del.last()
                    del.remove(data)
                    if (data.second <= curr) curr += 1
                    table.add(data.second, data.first)
                }
            }
        }

        table.forEach { 
            list[it.toInt()] = "O"
        }
        val answer = list.joinToString("") 

        return answer
    }
}