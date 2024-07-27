while True:
    expression = []
    question = input("Enter the postfix expression: ")
    for letter in question:
        if letter == ' ':
            continue
        if letter in "123456789":
            expression.append(int(letter))
        elif letter in '+-*/%^':
            last = expression.pop()
            first = len(expression) -1
            if letter == '+':
                expression[first] += last
            elif letter == '-':
                expression[first] -= last
            elif letter == '*':
                expression[first] *= last
            elif letter == '/':
                expression[first] = int(expression[first] / last)
            elif letter == '%':
                expression[first] %= last
            elif letter == '^':
                expression[first] = pow(expression[first],last)
    print(f'The value of the expression is: {expression.pop()}\nContinue?')
    again = input('Y/y')
    if again not in 'Yy':
        exit(0)

            

