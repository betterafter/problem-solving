class Solution11 {

    var left = 0
    var right = 0
    var cont = 0

    fun maxArea(height: IntArray): Int {
        right = height.size - 1
        while (left < right) {
            cont = Math.max(cont, Math.min(height[left], height[right]) * (right - left))
            if (height[left] < height[right]) { 
                left += 1
            } else {
                right -= 1
            }
        }
        
        return cont
    }
}