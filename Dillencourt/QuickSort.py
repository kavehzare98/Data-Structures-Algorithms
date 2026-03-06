def swap(arr, index1, index2):
	temp = arr[index1]
	arr[index1] = arr[index2]
	arr[index2] = temp

def split(arr, first: int, last: int) -> int:
	splitpoint = first
	x = arr[first]

	for k in range(first+1, last+1):
		if arr[k] < x:
			splitpoint += 1
			swap(arr, splitpoint, k)
	swap(arr, splitpoint, first)
	return splitpoint

def quick_sort(arr, first, last):
	if first < last:
		splitpoint = split(arr, first, last)
		quick_sort(arr, first, splitpoint-1)
		quick_sort(arr, splitpoint+1, last)

def main():
	test = [10, 9, 8, 7, 6, 5, 4, 3, 1, 2]
	print("Unsorted array: ", test)
	n = len(test)
	quick_sort(test, 0, n-1)
	print("Sorted array: ", test)

if __name__ == "__main__":
	main()



