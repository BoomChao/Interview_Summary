
package main

import (
	"fmt"
)


type CombinationIterator struct {
	Words []string
	Iterator int
}


func Combination(str string, len int) []string {

	res, comb, mask := []string, []byte{}, 1 << len(str)

	for no := 1; no < mask; no++ {
		num, i := no, 0

		for num > 0 {
			if num & 1 > 0 {
				comb = append(comb, str[i])
			}
			i++
			num >>= 1
		}

		if len(comb) == len {
			res = append(res, string(comb))
		}
		
		comb = []byte{}
	}

	sort.Slice(res, func(i, j int) bool {
		return res[i] < res[j]
	})

	return res
}


