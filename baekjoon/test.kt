import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main() {

    val bw = BufferedWriter(OutputStreamWriter(System.out))

    bw.write("hello")
    bw.flush()
    bw.close()
}