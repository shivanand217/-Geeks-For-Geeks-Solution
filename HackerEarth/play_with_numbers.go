package main

import (
	"fmt"
	//"io/ioutil"
	"os"
	"bufio"
)

func main() {

	in := bufio.NewReader(os.Stdin)

	var n int32
	var q , i int32
	var l int64
	var r int64
	var ans int64
	var p int64
	
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &q)

//	fmt.Scan(&n)
//	fmt.Scan(&q)

	var a = make([]int64 , n+10)
	for i = 1; i <= n; i++ {
		fmt.Fscan(in, &p)
		//fmt.Scan(&p)
		a[i] = p
	}

	var pr = make([]int64,n+10)
	pr[0] = int64(0)
	pr[1] = a[1]

	for i = 2; i <= n; i++ {
		pr[i] = pr[i-1] + a[i]
	}

	for i = 0; i < q; i++ {
		fmt.Fscan(in, &l)
		fmt.Fscan(in, &r)
		//fmt.Scan(&l)
		//fmt.Scan(&r)
		ans = pr[r] - pr[l-1];
		ans = (ans/int64(r - l + int64(1)))
		fmt.Println(ans)
	} 
}


func getInts() [] int {

	//assuming POSITIVE INTEGERS. Check v for '-' if have negative.
	var buf []byte
	buf , _ = ioutil.ReadAll(os.Stdin)
	var ints []int
	num := int(0)
	var found bool = false

	for _ , v := range buf {
		if '0' <= v && v <= '9' {
			num = 10*num + int(v - '0')
			found = true
		} else if found == true {
			ints = append(ints, num)
			found = false
			num = 0
		}
	}

	if found == true {
		ints = append(ints, num)
		found = false
		num = 0
	}
	
	return ints
}

