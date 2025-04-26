import sys

def main():
    input = sys.stdin.readline
    while True:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break

        cds1 = [int(input()) for _ in range(n)]
        cds2 = [int(input()) for _ in range(m)]

        i = j = count = 0
        while i < n and j < m:
            if cds1[i] == cds2[j]:
                count += 1
                i += 1
                j += 1
            elif cds1[i] < cds2[j]:
                i += 1
            else:
                j += 1
        print(count)

if __name__ == "__main__":
    main()