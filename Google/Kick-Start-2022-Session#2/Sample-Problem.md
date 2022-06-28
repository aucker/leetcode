## [Problem](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b5503a)

You have gathered **N** bags of candy and you want to distribute the candy amongst **M** kids. The *i*-th bag contains **Ci** pieces of candy. You want to make sure that every kid get the same amount of candy and that the number of pieces of candy they receive is the greatest possible. You can open each bag and mix all pieces of candy before distributing them to the kids.

How many pieces of candy will remain after you share the candy amongst kids, based on the rules described above?

## Solution

### Cpp version
```cpp
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; // T for test cases 
    // int N, M;
    for (int i = 1; i <= T; i++) {
        int N, M;
        cin >> N >> M; // N for candy bags and M for kids numbers
        int res = 0;
        int C[N];
        for (int k = 0; k < N; k++) {
            cin >> C[k];
        }
        // cin >> C[N];
        for (int j = 0; j < N; j++) {
            res += C[j];
        }
        res = res % M;
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
```

### Go version
```go
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
		fmt.Printf("Case # %d: %d\n", i, res)
	}
}
```