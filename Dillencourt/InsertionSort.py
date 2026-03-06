def insertion_sort(arr):
	for k in range(1, len(arr)):
		x = arr[k]
		j = k - 1
		while (j >= 0) and (arr[j] > x):
			arr[j + 1] = arr[j]
			j -= 1
		arr[j + 1] = x
	return arr

def main():
	test_cases = [
			[1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
			[10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
			[2, 1, 4, 3, 6, 5, 8, 7, 10, 9],
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
			[1, 2, 3, 4, 1, 2, 3, 4, 1, 2]
			]

	sorted_cases = []

	i = 0
	for case in test_cases:
		sorted_cases.append(insertion_sort(case.copy()))
		print("Unsorted Case: ", case)
		print("Sorted Case: ", sorted_cases[i], end='\n\n')
		i += 1

if __name__ == "__main__":
	main()
