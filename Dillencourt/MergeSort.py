def merge(arr, first1, last1, first2, last2):
	index1 = first1
	index2 = first2

	temp = []
	while (index1 <= last1) and (index2 <= last2):
		if arr[index1] <= arr[index2]:
			temp.append(arr[index1])
			index1 += 1
		else:
			temp.append(arr[index2])
			index2 += 1

	while index1 <= last1:
		temp.append(arr[index1])
		index1 += 1

	while index2 <= last2:
		temp.append(arr[index2])
		index2 += 1

	tempIndex = 0
	index = first1

	while index <= last2:
		arr[index] = temp[tempIndex]
		index += 1
		tempIndex += 1

def merge_sort(arr, first, last):
	if first < last:
		mid = (first + last) // 2
		merge_sort(arr, first, mid)
		merge_sort(arr, mid+1, last)
		merge(arr, first, mid, mid+1, last)

def main():
	test_cases = [
			[1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
			[10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
			[2, 1, 4, 3, 6, 5, 8, 7, 10, 9],
			[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
			[1, 2, 3, 4, 1, 2, 3, 4, 1, 2]
			]

	for case in test_cases:
		print("Unsorted Case: ", case)

		n = len(case)
		merge_sort(case, 0, n-1)

		print("Sorted Case: ", case,end='\n\n')

if __name__ == "__main__":
	main()
