import java.util.Scanner
fun main(args: Array<String>) {
	val lines = readLine()!!.toInt()
	
	for (i in 0..(lines / 2 - 1)) {
		val list = readLine()!!.split(',')
		val target = readLine()!!
		val s = mutableSetOf<Pair<Int, Int>>()
		
		for (i in 0..list.size - 1) {
			for (j in 0..list.size - 1) {
				if (i != j) {
					if (list[i] + list[j] == target) {
						s.add(Pair(i, j))
					}
				}
			}
		}
		println(s.size)
	}
}