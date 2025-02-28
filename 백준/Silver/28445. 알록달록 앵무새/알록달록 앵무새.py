import sys
from itertools import product

def main():
    dad_body, dad_tail = sys.stdin.readline().strip().split()
    mom_body, mom_tail = sys.stdin.readline().strip().split()
    
    body_colors = sorted(set([dad_body, dad_tail, mom_body, mom_tail]))
    tail_colors = sorted(set([dad_body, dad_tail, mom_body, mom_tail]))
    
    result = sorted(product(body_colors, tail_colors))
    for body, tail in result:
        print(body, tail)

if __name__ == "__main__":
    main()
