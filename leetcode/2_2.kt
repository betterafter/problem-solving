class Solution2_2 {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? { 
        var root: ListNode? = ListNode(0)
        var curr: ListNode? = root
        var size1 = 0
        var size2 = 0
        var curr1 = l1 
        var curr2 = l2
        var adder = 0

        while (curr1 != null) {
            size1 += 1
            curr1 = curr1.next
        }

        while (curr2 != null) {
            size2 += 1
            curr2 = curr2.next
        }

        if (size1 < size2) {
            curr1 = l2
            curr2 = l1
        } else {
            curr1 = l1
            curr2 = l2
        }

        for (i in 0..Math.max(size1, size2) - 2) {
            curr!!.next = ListNode(0)
            curr = curr.next
        }
        curr = root

        for (i in 0..Math.max(size1, size2) - 1) {
            var add: Int
            if (curr1 == null) break 
            if (curr2 == null) add = curr1.`val` + adder
            else add = curr1.`val` + curr2.`val` + adder

            curr!!.`val` = add % 10
            adder = add / 10
            
            curr1 = curr1.next
            curr2?.let { curr2 = it.next }
            if (i == Math.max(size1, size2) - 1 && adder == 1) {
                curr.next = ListNode(adder)
            } 
            curr = curr.next
        }

        return root
    }
}