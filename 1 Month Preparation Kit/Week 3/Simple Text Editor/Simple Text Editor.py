# Enter your code here. Read input from STDIN. Print output to STDOUT

if __name__ == '__main__':
    q = int(input())
    
    stack = []
    state = ''
    
    for i in range(q):
        query = input().split()
        if query[0] == '1':
            stack.append(state)
            state += query[1]
        elif query[0] == '2':
            stack.append(state)
            state = state[:len(state) - int(query[1])]
        elif query[0] == '3':
            print(state[int(query[1]) - 1])
        elif query[0] == '4':
            state = stack.pop()
