func numberOfLines(widths []int, s string) []int {
	const maxWidth = 100
	lines := 1
	width := 0
	for _, c := range s {
		temp := widths[c-'a']
		width += temp
		if width > maxWidth {
			lines++
			width = temp
		}
	}
	return []int{lines, width}
}