func maxSpending(values [][]int) (ans int64) {
	m, n := len(values), len(values[0])
	a := make([]int, 0, m * n) // reserve space
	for _, row := range values {
		a = append(a, row...)
	}
	slices.Sort(a)

	for i, x := range a {
		ans += int64(x) * int64(i + 1)
	}
	return
}
