fin = open("brackets.in", "r")
fout = open("brackets.out", "w")

def check(text):
	brackets_open = ('(', '[')
	brackets_closed = (')', ']')
	storage = []
	for i in text:
		if i in brackets_open:
			storage.append(brackets_open.index(i))
		elif i in brackets_closed:
			if storage and storage[-1] == brackets_closed.index(i):
				storage.pop()
			else:
				return False
	return not storage
	
for line in fin:
	if check(line):
		fout.write('YES\n')
	else:
		fout.write('NO\n')
fin.close()
fout.close()
