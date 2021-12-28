import java.util.Scanner
fun main(args: Array<String>) {
	val word1 = readLine()!!.split(',').joinToString("")
	val word2 = readLine()!!.split(',').joinToString("")
	
	if (word1 == word2) println("True")
	else println("False")
}