


//Leetcode第739题：每日温度

//思路：使用单调栈

type Tuple struct {
	Val int
	Index int
}


func dailyTemperatures(nums []int) []int {
	res := make([]int, len(nums))

	var stack []Tuple

	for i := len(nums)-1; i >= 0; i-- {
		tmp := nums[i]

		for len(stack) > 0 && tmp >= stack[len(stack)-1].Val {
			stack = stack[:len(stack)-1]
		}

		if len(stack) > 0 {
			res[i] = stack[len(stack)-1].Index - i
		}

		stack = append(stack, Tuple{tmp, i})
	}

	return res
}



