package main

import "fmt"

func main() {
	var T int
	fmt.Scanf("%d", &T)
	fmt.Println(T)

	for i := 1; i <= T; i++ {
		var N, M int
		// fmt.Scanf("%d, %d", &N, &M)
		fmt.Scanf("%d", &N)
		fmt.Scanf("%d", &M)
		arr := make([]int, N)
		for j := 0; j < N; j++ {
			fmt.Scanf("%d", &arr[j])
		}
		res := 0
		for _, v := range arr {
			res += v
		}
		res = res % M
		// fmt.Println("Case #", i, ":", res)
		// fmt.Printf("Case #%d: %d\n", i, res)
		s := fmt.Sprintf("Case #%d: %d\n", i, res)
		fmt.Println(s)
	}
}