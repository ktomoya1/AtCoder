package main

import (
	"fmt"
)

func main () {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	S := make([]int, N + 1)
	for i := 0; i <	N; i++ {
		S[i + 1] = S[i] + A[i]
	}

	ans := 0
	for l := 0; l < N; l++ {
		for r := l; r < N; r++ {
			sum := S[r + 1] - S[l]
			is_ok := true
			for k := l; k <= r; k++ {
				if sum % A[k] == 0 {
					is_ok = false
					break
				}
			}
			if is_ok {
				ans++
			}
		}
	}
	fmt.Println(ans)
}