// import java.io.BufferedReader
// import java.io.InputStreamReader

// val sb = StringBuilder()

// fun blanker(i: Int, j: Int, n: Int) {
//     if (i / n % 3 == 1 && j / n % 3 == 1) {
//         sb.append(" ")
//     } else if (n / 3 == 0) {
//         sb.append("*")
//     } else {
//         blanker(i, j, n / 3)
//     }
// }

// fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
//     val n = readLine().toInt()
//     for (i in 0..n - 1) {
//         for (j in 0..n - 1) {
//             blanker(i, j, n)
//         }
//         sb.append('\n')
//     }
//     println(sb)
// }