package main

import (
	"fmt"
	"os"
	"bufio"
)

var prime [1000006]bool
var pre [1000006]int

func seive() {
	var i,j int
	for i = 0 ; i < 1000006; i++ {
		prime[i] = false
	}
	prime[1] = true
	for i = 2 ; i < 1000006; i++ {
		for j = i*i ; j < 1000006; j += i {
			prime[j]=true
		}   
	}
	for i = 0 ; i < 1000006; i++ {
		pre[i] = 0
	}
	for i=1 ; i < 1000006; i++ {
		if prime[i] == false{
			pre[i]++;
			pre[i] += pre[i-1]
		}
	}
}

func main() {
	seive()
	var q int

	in := bufio.NewReader(os.Stdin)
	var x,y int

	fmt.Fscan(in, &q)
	var ans int

	for i := 0 ; i < q ; i++ {

		fmt.Fscan(in, &x)
		fmt.Fscan(in, &y)

		if x > y {
			ans = pre[y] - pre[x-1]	
		} else {
			ans = pre[y] - pre[x-1]
		}

		fmt.Println(ans)
	} 
}