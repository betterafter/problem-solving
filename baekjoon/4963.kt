import java.io.BufferedReader
import java.io.InputStreamReader


val sb = StringBuilder()
val dir = arrayOf(arrayOf(1, 0), arrayOf(-1, 0), arrayOf(0, 1), arrayOf(0, -1), 
arrayOf(1, 1), arrayOf(1, -1), arrayOf(-1, 1), arrayOf(-1, -1))

fun main() = with(BufferedReader(InputStreamReader(System.`in`)))  {

    while (true) {
        // 입력 1
        val wh = readLine()!!.split(' ')
        val width = wh[0].toInt()
        val height = wh[1].toInt()
        if (width == 0 &&  height == 0) break

        val arr = Array(height, { IntArray(width, { 0 } ) } )
        val visited = Array(height, { IntArray(width, { 0 } ) } )
        var count = 0

        // 입력2 
        for (i in 0..height - 1) {
            val w = readLine()!!.split(' ')
            for (j in 0..w.size - 1) {
                arr[i][j] = w[j].toInt()
            }
        }

        for (i in 0..height - 1) {
            for (j in 0..width - 1) {
                if (visited[i][j] == 0 && arr[i][j] == 1) {
                    visited[i][j] = 1
                    count += 1
                    val list = mutableListOf<Pair<Int, Int> >()
                    list.add(Pair(j, i))
                    while (list.isNotEmpty()) {
                        val p = list.removeAt(0)
                        val x = p.first
                        val y = p.second
                        for (d in 0..dir.size - 1) {
                            val nx = x + dir[d][0]
                            val ny = y + dir[d][1]
                            if (nx >= 0 && nx < width && ny >= 0 && ny < height && arr[ny][nx] == 1 && visited[ny][nx] == 0) {
                                visited[ny][nx] = 1
                                list.add(Pair(nx, ny))
                            }
                        }
                    }
                }
            }
        }

        sb.append(count)
        sb.append('\n')
    }
    print(sb)
}

