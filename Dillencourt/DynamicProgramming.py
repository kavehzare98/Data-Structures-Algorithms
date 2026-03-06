import random

IntervalData = list[tuple[int, int, int]]

def generate_intervals(size: int, seed: int) -> IntervalData:
	# Input generation
	rng = random.Random(seed)
	interval_lst = []

	for i in range(size):
		choice_a = rng.randint(1,21)
		choice_b = rng.randint(1,21)
		while choice_b == choice_a:
			choice_b = rng.randint(1,21)
		choice_c = rng.randint(1,10)

		interval = (min(choice_a, choice_b), max(choice_a, choice_b), choice_c)
		interval_lst.append(interval)

	return interval_lst

def preprocess_intervals(lst: IntervalData, index: int) -> IntervalData:
	sorted_lst = sorted(lst, key=lambda x: x[index])
	return sorted_lst

def display_intervals(lst: IntervalData) -> None:
	print("Intervals:")
	for i in range(len(lst)):
		interval = lst[i]
		print(f"{i+1}:\t", interval)

def create_predecessor_arr(lst: IntervalData) -> list[int]:
	predecessors = [-1]
	for i in range(1, len(lst)):
		curr_interval = lst[i]
		j = i - 1
		found = False

		while j >= 0 and not found:
			prev_interval = lst[j]
			if prev_interval[1] <= curr_interval[0]:
				predecessors.append(j)
				found = True
			j -= 1

		if not found:
			predecessors.append(-1)
	return predecessors

def OPT(preds: list[int], lst: IntervalData, j: int) -> int:
	if j <= 0:
		return 0
	else:
		interval = lst[j]
		val = interval[2]
		pred = preds[j]
		return max( val + OPT(preds, lst, pred), OPT(preds, lst, j-1) )

def Memoized_OPT(M, preds: list[int], lst: IntervalData, j: int) -> int:
	if j < 0:
		return 0

	if j not in M.keys():
		interval = lst[j]
		val = interval[2]
		pred = preds[j]
		M[j] = max( val+Memoized_OPT(M,preds,lst,pred),
			  		Memoized_OPT(M,preds,lst,j-1))
	return M[j]

def Iterative_OPT(preds: list[int], lst: IntervalData) -> int:
	optimal_solution = 0
	M = {-1:0}
	for j in range(len(lst)):
		val = lst[j][2]
		pred = preds[j]
		M[j] = max(val+M[pred], M[j-1])
		optimal_solution = M[j]
	return optimal_solution

def Iterative_keep_OPT(preds: list[int], lst: IntervalData) -> (int, dict[int,bool]):
	optimal_solution = 0
	M = {-1: 0}
	keep = {-1: False}
	for j in range(len(lst)):
		val = lst[j][2]
		pred = preds[j]
		if val+M[pred] > M[j-1]:
			M[j] = val+M[pred]
			keep[j] = True
		else:
			M[j] = M[j-1]
			keep[j] = False
		optimal_solution = M[j]
	return (optimal_solution, keep)

def display_solution(keep, intervals, preds):
	i = len(intervals) - 1
	while i >= 0:
		if keep[i]:
			print(f"Interval {i+1}: {intervals[i]}")
			i = preds[i]
		else:
			i -= 1

def main():
	random_seed = 5
	num = 10
	intervals = generate_intervals(num, random_seed)
	sorted_intervals = preprocess_intervals(intervals, 1)
	display_intervals(sorted_intervals)
	predecessors = create_predecessor_arr(sorted_intervals)
	optimal_val, keep = Iterative_keep_OPT(predecessors, sorted_intervals)
	print("Optimal Solution: ", optimal_val)
	display_solution(keep, sorted_intervals, predecessors)


if __name__ == '__main__':
	main()
