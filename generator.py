from random import shuffle as s

try:
	start = input("Start: ")
	if start == "":
		start = 0
	else:
		start = int(start)
	stop = input("Stop: ")
	if stop == "":
		stop = 100
	else:
		stop = int(stop)
	step = input("Steps: ")
	if step == "":
		step = 1
	else:
		step = int(step)
	l = list(range(start, stop, step))
	s(l)
	print(" ".join(str(e) for e in l))
except ValueError:
	print("Invalid input.")
except Error:
	print("Something went wrong.")
