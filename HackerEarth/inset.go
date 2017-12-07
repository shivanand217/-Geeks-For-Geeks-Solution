package main
 
import (
	"fmt"
	"os"
	"bufio"
)

func main() {
	
	in := bufio.NewReader(os.Stdin)	
	var n, q, tmp int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &q)
 
	a := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &tmp)
		a[i] = tmp
	}

	for i := 0; i < q; i++ {
		var t, l, r int
		
		fmt.Fscan(in, &t)
		fmt.Fscan(in, &l)
		fmt.Fscan(in, &r)

		switch t {

		case 1:
			a[l] = r
		case 2:

			sum := 0
			for j := l; j < r+1; j++ {
				sum += a[j]
			}

			fmt.Println(sum)
		}
	}

}