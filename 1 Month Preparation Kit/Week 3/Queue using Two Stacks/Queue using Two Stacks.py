# Enter your code here. Read input from STDIN. Print output to STDOUT

q = int(input())
stack=[]
for i in range(q):
    l = input().split()
    if len(l)==2:
        stack.append(l[1])
    elif l[0]=='2':
        stack.pop(0)
    else:
        print(stack[0])