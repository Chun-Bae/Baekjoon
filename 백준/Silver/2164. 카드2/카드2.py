
front, rear = -1, -1
N = int(input())
arr = [0] * N


def enqueue(x):
    global rear
    rear = (rear+1) % N
    arr[rear] = x


def dequeue():
    global front
    front = (front+1) % N
    return arr[front]


def print_q():
    i = front + 1
    while i % N != rear:
        print(arr[i % N], end=" ")
        i = (i+1) % N
    print(arr[rear])


rear = N-1
for i in range(N):
    arr[i] = i+1

while True:
    dequeue()
    if (front+1) % N == rear:
        print(arr[rear])
        break
    enqueue(dequeue())
