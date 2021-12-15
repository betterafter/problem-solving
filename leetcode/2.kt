/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution2 {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? { 
        var root: ListNode? = ListNode(0)
        var curr: ListNode? = root
        var li1 = mutableListOf<Int>()
        var li2 = mutableListOf<Int>()
        var li3 = mutableListOf<Int>()
        var size1 = 0
        var size2 = 0
        var curr1 = l1 
        var curr2 = l2
        var adder = 0

        while (curr1 != null) {
            size1 += 1
            li1.add(curr1.`val`)
            curr1 = curr1.next
        }

        while (curr2 != null) {
            size2 += 1
            li2.add(curr2.`val`)
            curr2 = curr2.next
        }

        if (size1 < size2) {
            li3.clear()
            li3.addAll(li1)

            li1.clear()
            li1.addAll(li2)

            li2.clear()
            li2.addAll(li3)

            li3.clear()
        }

        for(i in 0..Math.min(size1, size2) - 1) {
            val add = li1[i] + li2[i] + adder
            if (add >= 10) {
                li3.add(add % 10)
                adder = 1
            } else {
                li3.add(add)
                adder = 0
            }
        }

        for (i in Math.min(size1, size2)..Math.max(size1, size2) - 1) {
            val add = li1[i] + adder
            if (add >= 10) {
                li3.add(add % 10)
                adder = 1
            } else {
                li3.add(add)
                adder = 0
            }
        }
        if (adder == 1) li3.add(adder)

        li3.forEachIndexed { idx, it ->
            curr!!.`val` = it
            if (idx < li3.size - 1) curr!!.next = ListNode(0)
            curr = curr!!.next 
        }

        return root
    }
}