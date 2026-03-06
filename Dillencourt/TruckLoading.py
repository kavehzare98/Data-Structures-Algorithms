import random as rand

def generate_input(n, seed):
	rng = rand.Random(seed)
	result = [rng.randint(1,11) for i in range(n)]
	return result

def OPT(weights, cap, j):
	if j < 0:
		return 0
	else:
		box_w = weights[j]
		if box_w <= cap:
			return max(box_w+OPT(weights,cap-box_w, j-1), OPT(weights,cap,j-1))
		else:
			return OPT(weights,cap,j-1)

def Iterative_OPT(weights, cap):
	optimal = 0
	for j in range(len(weights)):
		box_w = weights[j]
		if box_w <= cap:
			optimal = max()

def main():
	lst = generate_input(10,1)
	print("List of Weights: ", lst)
	solu = OPT(lst, 20, len(lst)-1)
	print("Solution: ", solu)

if __name__ == '__main__':
	main()
