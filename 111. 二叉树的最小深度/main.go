/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 递归
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := minDepth(root.Left)
	right := minDepth(root.Right)
	if left == 0 || right == 0 {
		return max(left, right) + 1
	}
	return min(left, right) + 1
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

// BFS
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	queue := []*TreeNode{}
	count := []int{}
	queue = append(queue, root)
	count = append(count, 1)
	for i := 0; i < len(queue); i++ {
		cur := queue[i]
		depth := count[i]
		if cur.Left == nil && cur.Right == nil {
			return depth
		}
		if cur.Left != nil {
			queue = append(queue, cur.Left)
			count = append(count, depth+1)
		}
		if cur.Right != nil {
			queue = append(queue, cur.Right)
			count = append(count, depth+1)
		}
	}
	return 0
}