def get_nums():

    num1 = input('Enter the three numbers: ', end = ' ')
    num2 = input('', end = ' ')
    num3 = input('')

    return [num1, num2, num3]

# print the two highest numbers
def option1(num1, num2, num3):

    min_num = min([num1, num2, num3])

    print('Two highest numbers: ')

    for num in [num1, num2, num3]:
        if num != min_num:
            print(num)

# product of the three numbers
def option2(num1, num2, num3):
    return num1 * num2 * num3

def option3(num2, num3):
    return num2 / num3 if num3 != 0 else 'Sorry cannot divide {} by zero!'.format(num2)


if __name__ == '__main__':

    num1, num2, num3 = get_nums()

    print('Choose from the following options:\n')

    