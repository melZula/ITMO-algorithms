fin = open("stack.in", "r")
fout = open("stack.out", "w")

stack = []
n = int(fin.readline())

for line in fin:
	if (line[0] == '+'):
		stack.append(int(line.split("+ ")[-1]))
	else:
		fout.write(str(stack[-1])+'\n')
		stack.pop()
fin.close()
fout.close()
