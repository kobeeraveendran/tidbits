# calculate quartiles, percentiles, and z-scores of a data set

def quartiles(input_list):
    input_list.sort()

    total = len(input_list)

    if total % 2 != 0:
        mid = (total - 1) // 2
        q2 = input_list[mid]
        q1 = input_list[mid // 2]
        q3 = input_list[(mid + total) // 2]

        mid2 = mid // 2
        mid3 = (mid + total) // 2
        
        if mid % 2 == 0:
            q1 = (input_list[mid2] + input_list[mid2 - 1]) / 2
            q3 = (input_list[mid3] + input_list[mid3 - 1]) / 2

        else:
            q1 = input_list[mid2]
            q3 = input_list[mid3]

    else:
        mid = total // 2
        q2 = (input_list[mid] + input_list[mid - 1]) / 2

        mid2 = mid // 2
        mid3 = (mid + total) // 2
        
        if mid % 2 == 0:
            q1 = (input_list[mid2] + input_list[mid2 - 1]) / 2
            q3 = (input_list[mid3] + input_list[mid3 - 1]) / 2

        else:
            q1 = input_list[mid2]
            q3 = input_list[mid3]

    print('Q1: {}\nQ2: {}\nQ3: {}'.format(q1, q2, q3))

if __name__ == '__main__':

    input_list = input('Enter list separated by spaces: \n')
    input_list = [int(x) for x in input_list.split()]
    '''
    input_list = []
    curr_num = input('Enter values\n')

    while not str.isalpha(curr_num):
        input_list.append(curr_num)
        curr_num = input()

    input_list = [float(x) for x in input_list]
    '''

    quartiles(input_list)