# random commen
def SiftDown(H: list[int], i: int, size: int) -> list[int]:
	# n = len(H)  <-- REMOVED. Use 'size' passed in instead.
	left, right = 2 * i + 1, 2 * i + 2

	# Use 'size' here instead of 'n' or 'len(H)'
	if (right < size) and (H[right] > H[left]):
		largerChild = right
	else:
		largerChild = left

	# Use 'size' here as well
	if (largerChild < size) and (H[i] < H[largerChild]):
		temp = H[i]
		H[i] = H[largerChild]
		H[largerChild] = temp
		SiftDown(H, largerChild, size) # Pass the size down recursively
	return H

def Heapify(H: list[int]) -> list[int]:
	n = len(H)
	# Start from the last non-leaf node (n // 2 - 1)
	for i in range(n // 2 - 1, -1, -1):
		# Initial Heapify uses the full size 'n'
		H = SiftDown(H, i, n)
	return H

def HeapSort(A: list[int]):
	A = Heapify(A)
	n = len(A)

	# Loop backwards from the end of the array
	for k in range(n - 1, 0, -1):
		# Swap the root (max element) with the last unsorted element (index k)
		temp = A[0]
		A[0] = A[k]
		A[k] = temp

		# SiftDown the new root, but only consider the array up to size 'k'
		# This effectively "hides" the sorted element at A[k]
		A = SiftDown(A, 0, k)

	return A

def main():
	lst = [10, 7, 8, 9, 1, 2, 3]
	print("Original List: ", lst)
	sorted_lst = HeapSort(lst)
	print("Sorted List: ", sorted_lst)

if __name__ == "__main__":
	main()
