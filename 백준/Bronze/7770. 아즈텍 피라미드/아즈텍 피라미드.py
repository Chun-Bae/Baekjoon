def max_t(n):
    total = 0
    height = 0
    current_layer_blocks = 1  

    while total + current_layer_blocks <= n:
        total += current_layer_blocks
        height += 1
        current_layer_blocks = current_layer_blocks + 4 * height

    return height
n = int(input())
print(max_t(n))