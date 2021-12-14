class Solution67257 {

    fun calcurator(c: String, a: Long, b: Long): Long {
        return if (c == "+") {
            a + b
        } else if (c == "-") {
            a - b
        } else a * b
    }
    
    fun calc(a: String, str: MutableList<String>): MutableList<String> {
        var list = mutableListOf<String>()
        var idx = 0

        while (idx <= str.size - 1) {
            if (str[idx] == a) {
                var num = list.removeAt(list.size - 1)
                list.add(calcurator(a, num.toLong(), str[idx + 1].toLong()).toString())
                idx += 2
            } else {
                list.add(str[idx])
                idx +=  1
            }
        }

        return list
    }

    fun solution(expression: String): Long {
        var list = mutableListOf<String>()
        var answer: Long = 0
        var curr = ""
        expression.forEach { 
            if (it == '+' || it == '-' || it == '*') {
                list.add(curr)
                list.add(it.toString())
                curr = ""
            } else {
                curr += it
            }
        }
        list.add(curr)

        answer = Math.max(Math.abs(calc("*", calc("+", calc("-", list))).first().toLong()), answer)
        answer = Math.max(Math.abs(calc("*", calc("-", calc("+", list))).first().toLong()), answer)
        answer = Math.max(Math.abs(calc("+", calc("*", calc("-", list))).first().toLong()), answer)
        answer = Math.max(Math.abs(calc("+", calc("-", calc("*", list))).first().toLong()), answer)
        answer = Math.max(Math.abs(calc("-", calc("*", calc("+", list))).first().toLong()), answer)
        answer = Math.max(Math.abs(calc("-", calc("+", calc("*", list))).first().toLong()), answer)
        
        return answer
    }
}