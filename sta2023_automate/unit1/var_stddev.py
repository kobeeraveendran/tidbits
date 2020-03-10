def find_range(input_list):
    print('Range: ', max(input_list) - min(input_list))

def variance(input_list):
    total = 0

    mean = sum(input_list) / len(input_list)

    num = sum([(x - mean) ** 2 for x in input_list])
    
    pop_var = num / len(input_list)
    sample_var = num / (len(input_list) - 1)

    print('Population variance: ', pop_var)
    print('Sample variance: ', sample_var)

    return pop_var, sample_var

def std_dev(input_list):

    pop_var, sample_var = variance(input_list)

    print('Population standard deviation: ', pop_var ** 0.5)
    print('Sample standard deviation: ', sample_var ** 0.5)

    return pop_var ** 0.5, sample_var ** 0.5

if __name__ == '__main__':
    #input_list = input('Enter data set as space-separated list:')
    input_list = []
    curr_num = input('Enter values\n')

    while not str.isalpha(curr_num):
        input_list.append(curr_num)
        curr_num = input()

    input_list = [float(x) for x in input_list]

    print(input_list)

    find_range(input_list)
    pop_var, sample_var = variance(input_list)
    std_dev(input_list)
