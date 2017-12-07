package main
import (
	"fmt"
	"os"
	"bufio"
)
var a [100010]int
func main() {
	in := bufio.NewReader(os.Stdin)	
	var q int
	var tmp int
	fmt.Fscan(in, &q)
	var p int = 0
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &tmp)
		a[p] = solve(tmp)	
		p++
	}
	for i := 0; i < q; i++ {
		fmt.Println(a[i])
	}
}
func solve(p int) int {
	var i int
	var sum int = 0 
		for i = 1; i <= p/2 ;  i++ {
			if p % i == 0 {
				sum += i
			}
		}
	return sum
}



