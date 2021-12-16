class Solution {
    var list = mutableListOf<MutableSet<Int>>()
    var mheight = 0

    fun iterate(order: Int, pOrder: Int, height: Int) {
        list[order].forEach {
            if (pOrder != it) {
                mheight = Math.max(mheight, height)
                if (height > mheight + 1) return
                iterate(it, order, height + 1)
            }
        }
    }

    fun findMinHeightTrees(n: Int, edges: Array<IntArray>): List<Int> {
        if (n == 1) return listOf(0)
        var max = 1000000000
        var rlist = mutableListOf<Int>()
        for (i in 0..n) list.add(mutableSetOf<Int>())

        for (i in 0..edges.size-1) {
            list[edges[i][0]].add(edges[i][1])
            list[edges[i][1]].add(edges[i][0])
        }

        for (it in 0..n-1) {
            mheight = 0
            iterate(it, -1, 1)
            if (max > mheight) {
                max = mheight
                rlist = mutableListOf(it)
            } else if (max == mheight) {
                rlist.add(it)
            }
        }

        return rlist.toList()
    }
}