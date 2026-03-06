from BinarySearch import binary_search
from InsertionSort import insertion_sort
from MergeSort import merge_sort

def main():
	test_arr = [10, 5, 7, 3, 2, 1, 8, 12, 14, 15]
	print("Unsorted array: ", test_arr)
	n = len(test_arr)
	merge_sort(test_arr, 0, n-1)
	insertion_sort(test_arr)
	print("Sorted array: ", test_arr)

	n = len(test_arr)
	search_element = 7
	result = binary_search(test_arr, search_element, 0, n-1)
	if result:
		print(f"FOUND element {search_element} at location {result}")
	else:
		print(f"FAILED to FIND element {search_element} in array")

if __name__ == "__main__":
	main()


