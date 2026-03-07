import random

def generate_input(n,seed):
	rng = random.Random(seed)
	A = []
	low = 1
	high = 10
	for i in range(n):
		row = []
		for j in range(n):
			rand_num = rng.randint(low, high)
			while rand_num in row:
				rand_num = rng.randint(low, high)
			row.append(rand_num)
		low += 10
		high += 10
		row = sorted(row)
		A.append(row)
	return A

def matrixBinSearch(matrix, top, bottom, left, right, x):
	if top > bottom:
		return (-1,-1)

	mid_row = (top+bottom) // 2

	if top == bottom:
		if left > right:
			return (-1,-1)
		mid_col = (left+right) // 2
		curr = matrix[mid_row][mid_col]
		if x == curr:
			return (mid_row,mid_col)
		elif x < curr:
			return matrixBinSearch(matrix, top, bottom, left, mid_col-1, x)
		else:
			return matrixBinSearch(matrix, top, bottom, mid_col+1, right, x)
	else:
		n = len(matrix[0])
		if x < matrix[mid_row][0]:
			return matrixBinSearch(matrix, top, mid_row-1, left, right, x)
		elif x > matrix[mid_row][n-1]:
			return matrixBinSearch(matrix, mid_row+1, bottom, left, right, x)
		else:
			return matrixBinSearch(matrix, mid_row, mid_row, left, right, x)

def main():
	n = 5
	seed = 0
	matrix = generate_input(n, seed)
	for row in matrix:
		print(row)

	user_input = input("Please enter a number to search for (q to quit): ")
	while user_input != "q":
		integer_input = int(user_input)
		row, col = matrixBinSearch(matrix, 0, n-1, 0, n-1, integer_input)
		print(f"Row: {row}, Col: {col}")
		user_input = input("Please enter a number to search for (q to quit): ")
	print("Goodbye...")

if __name__ == '__main__':
	main()

def myFunc():
	return
