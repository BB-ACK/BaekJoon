import sys
input = sys.stdin.readline

class Stack():
    def __init__(self, capacity=10000):
        self.capacity = capacity
        self.top = 0
        self.stack = [0] * capacity

    def isEmpty(self):
        return 1 if self.top == 0 else 0
    
    def push(self, e):
        self.stack[self.top] = e
        self.top += 1

    def pop(self):
        if self.isEmpty():
            return -1
        self.top -= 1
        return self.stack[self.top]
    
    def isSize(self):
        return self.top
    
    def isTop(self):
        if self.isEmpty():
            return -1
        return self.stack[self.top - 1]

if __name__ == "__main__":
    S = Stack()
    num = int(input())
    result = []

    for _ in range(num):
        instruction = input().strip().split()
        cmd = instruction[0]

        if cmd == 'push':
            S.push(int(instruction[1]))
        elif cmd == 'pop':
            result.append(str(S.pop()))
        elif cmd == 'size':
            result.append(str(S.isSize()))
        elif cmd == 'empty':
            result.append(str(S.isEmpty()))
        elif cmd == 'top':
            result.append(str(S.isTop()))
    
    print('\n'.join(result))
