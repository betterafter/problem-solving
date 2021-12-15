import java.util.Scanner
fun main(args: Array<String>) {
	val T = readLine()!!.toInt()
	
	for (case in 0..T-1) {
        val nk =  readLine()!!.split(" ")
        val n = nk[0].toInt()
        val k = nk[1].toInt()
		val arr = mutableListOf<List<Int>>()
        var minTrash = 10000000
		for (i in 0..n-1) {
			val li = mutableListOf<Int>()
            val line = readLine()!!.split(" ")
            line.forEach {
                li.add(it.toInt())
            }
			arr.add(li)
		}
        println(arr)
		
		for (i in 0..n-k) {
            for (j in 0..n-k) {
                var currTrash = 0
                for (y in i..i+k-1) {
                    for (x in j..j+k-1) {
                        if (arr[y][x] == 1) {
                            currTrash += 1
                        }
                    }
                }
                minTrash = Math.min(currTrash, minTrash)
            }
        }
        println(minTrash)
	}
}