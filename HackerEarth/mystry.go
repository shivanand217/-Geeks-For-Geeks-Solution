package main

import (
	"fmt"
	"os"
	"bufio"
)

var a [100010]int
var seive[100010]bool
var v[]int

func main() {

	in := bufio.NewReader(os.Stdin)	
	var t int
	var tmp int
	var i int
	var ans int64

	prime()

	fmt.Fscan(in, &t)

	for i = 0; i < t ; i++ {
		fmt.Fscan(in, &tmp)

		ans = solve(tmp)
		fmt.Println(ans)
	}
}

func prime() {
	for i := 0 ; i < 100010; i++ {
		seive[i] = false
	}

	for i := 2 ; i < 100010; i++ {
		if seive[i] == false {
			v = append(v, i)

			var p  int = i + i
			for ; p < 100010 ; p +=i {
				seive[p] = true 
			}
		}
	} 
}

func solve(n int) int64 {
	var i int
	var tp int64 = int64(0)
	var cnt int64 = int64(1) 

	for i = 0 ; i < len(v) ; i++ {
		tp = int64(0)
		if n % v[i] == 0 {
			for ; ; {
				if n % v[i] != 0 {
					break;
				}
				n /= v[i];
				tp++
			}
		}

		cnt = cnt * (tp + int64(1))
		if n <= 2 {
			break
		}
	}

	if n > 2 {
		cnt *= 2
	}

	return cnt
}


