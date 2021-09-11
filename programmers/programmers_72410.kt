
class Solution_72410 {
    fun solution(new_id: String): String {
        var answer: String = ""

        answer = new_id.toLowerCase()
        answer = answer.filter { 
            it in ('0'..'9') + ('a'..'z') + '-' + '_' + '.'
        }.toList().joinToString("")
        answer = answer.replace("[.]{2,}".toRegex(), ".")
        if (answer.length > 0) 
            if (answer.first() == '.') answer = answer.substring(1)
        
        if (answer.length > 0) 
            if (answer.last() == '.') answer = answer.substring(0, answer.lastIndex)
        
        if (answer.length == 0) answer = "a"
        if (answer.length >= 16) { 
            answer = answer.substring(0, 15)
            if (answer.last() == '.') answer = answer.substring(0, answer.lastIndex)
        }
        if (answer.length <= 2) {
            val c = answer.last()
            while (answer.length != 3) {
                answer += c
            }
        }


        return answer
    }
}