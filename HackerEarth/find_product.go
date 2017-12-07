package main

import "fmt"

func main() {

	var n int
	fmt.Scan(&n)

	var myslice = make([]int , n)
	var i int
	var p int
	var mod int64 = 1000000007
	var ans int64 = 1

	for i = 0; i < n; i++ {
		fmt.Scan(&p)
		myslice[i] = p
		ans = ans * int64(p)
		ans %= mod
	}


	fmt.Println(ans)
}