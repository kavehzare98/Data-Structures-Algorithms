def find_predecessors(S, Q):
	n, k = len(S), len(Q)
	curpred = None
	index_q, index_s = 0, 0
	pairlist = []

	while (index_q < n):
		if (index_s < k) and (S[index_s] <= Q[index_q]):
			curpred = S[index_s]
			index_s += 1
		else:
			pairlist.append((Q[index_q], curpred))
			index_q += 1
	return pairlist

def main():
	S = [2, 3, 5, 7, 11]
	Q = [1, 3, 8, 9, 20]
	final_answer = find_predecessors(S, Q)

	print(final_answer)


if __name__ == "__main__":
	main()


