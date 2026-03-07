def binary_search(arr, x, first, last):
	if first > last:
		return None
	mid = (first + last) // 2
	if x == arr[mid]:
		return mid
	elif x < arr[mid]:
		return binary_search(arr, x, first, mid-1)
	else:
		return binary_search(arr, x, mid+1, last)

# function main
def main():
	test = [1, 2, 3, 4, 5, 6, 7, 18, 20, 25, 33, 45, 99, 100]

	print("Here is the Array: ", test, end='\n\n')

	for i in range(0, 101, 5):
		search_result = binary_search(test, i, 0, len(test))
		if search_result:
			print(f"FOUND {i} in array at index: {search_result}!\n")
		else:
			print(f"{i} NOT FOUND in array!\n")

if __name__ == "__main__":
	main()

def myFunc():
	return
