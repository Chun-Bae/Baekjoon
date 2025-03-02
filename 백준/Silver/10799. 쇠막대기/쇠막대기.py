def count_cut_pieces(brackets):
    stack = []
    total_pieces = 0  
    for i in range(len(brackets)):
        if brackets[i] == '(': 
            stack.append('(')
        else:  
            stack.pop()  
            if brackets[i-1] == '(':  
                total_pieces += len(stack)
            else:  
                total_pieces += 1
    return total_pieces

brackets = input().strip()
print(count_cut_pieces(brackets))