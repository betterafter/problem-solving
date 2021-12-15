
class Solution147 {
    fun insertionSortList(head: ListNode?): ListNode? {
        if (head!!.next == null) return head

        var root: ListNode = ListNode(head.`val`)
        var order = head.next

        while (order != null) {
            val node = ListNode(order.`val`)

            if (order.`val` <= root.`val`) {
                node.next = root
                root = node
                order = order.next
                continue
            }

            var curr = root.next
            var prev = root

            if (curr == null) {
                root.next = node
                order = order.next
                continue
            }

            while (curr != null) {
                if (order.`val` >= prev.`val` && order.`val` <= curr.`val`) {
                    prev.next = node
                    node.next = curr
                    break
                }

                if (curr.next == null && order.`val` >= curr.`val`) {
                    curr.next = node
                    break
                }

                curr = curr.next
                prev = prev.next!!
            }

            order = order.next
        }
        return root
    }
}