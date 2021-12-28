import java.io.BufferedReader
import java.io.InputStreamReader

val sb = StringBuilder()

fun blanker(arr: Array<CharArray>, n: Int, x1: Int, y1: Int, x2: Int, y2: Int): Array<CharArray> {
    if (n == 1) return arr
    val curr = n / 3
    val sx = x1 + (x2 - x1 + 1) / 3
    val sy = y1 + (y2 - y1 + 1) / 3

    for (i in 0..n / 3 - 1) {
        for (j in 0..n / 3 - 1) {
            arr[sy + i][sx + j] = ' '
        }
    }

    var a: Array<CharArray> = arr
    for (i in 0..n / curr - 1) {
        for (j in 0..n / curr - 1) {
            if (i != n / 3 && j != n / 3) {
                a = blanker(a, curr, y1 + curr * i, x1 + curr * j, y1 + curr * i + curr - 1, x1 + curr * j + curr - 1)
            }
        }
    }

    return a
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine()!!.toInt()
    var arr = Array(n, { CharArray(n, { '*' }) })
    val a = blanker(arr, n, 0, 0, n - 1, n - 1)

    for (i in 0..n - 1) {
        for (j in 0..n - 1) {
            sb.append(a[i][j])
        }
        sb.append('\n')
    } 
    println(sb)
}