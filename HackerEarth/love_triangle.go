package main
 
import (
	"fmt"
	"os"
	"bufio"
)
 
func main() {

	in := bufio.NewReader(os.Stdin)	
	for {
	    var t int
	    m, p := fmt.Fscan(in, &t)
	    if m == 0 || p != nil {
	        break
	    }
	    fmt.Printf("%d\n", f(t))
	}
}

func f(n int) int {
    if n < 9 {
        return n
    } else {
        return n%9+10*f(n/9)
    }
}