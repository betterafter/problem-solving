class Solution11_2 {

    var maxCont = 0
    fun maxArea(height: IntArray): Int {
        for (i in 0..height.size - 1) {
            var cont = 0
            for (j in 0..height.size - 1) {
                cont = Math.max(cont, Math.min(height[i], height[j]) * (j - i))
            }
            maxCont = Math.max(cont, maxCont)
        }
        return maxCont
    }
}