import java.util.Scanner
fun main(args: Array<String>) {
	val input = readLine()!!
	val c = readLine()!!.get(0)
	
	var list = mutableListOf<Int>()
	var clist = mutableListOf<Int>()
	for (i in 0..input.length - 1) list.add(-1)
	
	for (i in 0..input.length - 1) {
		if (input[i] == c) {
			clist.add(i)
		}
	}
	
	for (j in 0..input.length - 1) {
		for (k in 0..clist.size - 1) {
			if (list[j] == -1) list[j] = Math.abs(clist[k] - j)
			else list[j] = Math.min(list[j], Math.abs(clist[k] - j))
		}
	}
	
	var res = ""
	for (i in 0..list.size - 1) {
		res = res + list[i] + ","
	}
	
	res = res.substring(0, res.lastIndex)
	println(res)
}