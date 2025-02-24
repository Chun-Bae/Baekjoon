def minimize_expression(expression):
    parts = expression.split('-')

    result = sum(map(int, parts[0].split('+')))

    for part in parts[1:]:
        result -= sum(map(int, part.split('+')))

    return result

expression = input().strip()
print(minimize_expression(expression))