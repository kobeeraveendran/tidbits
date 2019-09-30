# Kobee Raveendran
# tidbits
import time

courses = {
    4587: ('MAT 236', 4), 
    4599: ('COP 220', 3), 
    8997: ('GOL 124', 1), 
    9696: ('COP 100', 5), 
    4580: ('MAT 230', 3), 
    4581: ('MAT 231', 4), 
    4582: ('MAT 232', 2), 
    4583: ('MAT 233', 2), 
    3587: ('MAT 256', 4), 
    4519: ('COP 420', 3), 
    6997: ('GOL 127', 1), 
    9494: ('COP 101', 3)
}

state = True

while state:

    std_id = int(input("Enter the student's ID: "))
    num_courses = int(input("Enter the number of courses (up to 3): "))

    while num_courses > 3:
        num_courses = int(input('Incorrect number of courses entered (max. 3). Please enter a valid number: '))

    course_numbers = input("Enter the {} course number(s) as a space-separated list: ".format(int(num_courses)))

    course_numbers = course_numbers.split(' ')

    while len(course_numbers) is not num_courses:
        print('Incorrect number of courses entered.')
        course_numbers = input("Enter the {} course number(s) as a space-separated list: ".format(int(num_courses)))
        course_numbers = course_numbers.split(' ')

    course_numbers = [int(x) for x in course_numbers]

    print('\nVALENCE COMMUNITY COLLEGE\nORLANDO FL 10101')
    print('----------------------------')
    
    print('\nFee Invoice Prepared for Student V{}'.format(std_id))
    
    print('\n1 Credit Hour = $120.25')

    print('CRN\tCR_PREFIX\tCR_HOURS')

    total = 35

    for course in course_numbers:
        curr_cost = courses[course][1]
        print('{}\t{}\t{}\t$ {:.2f}'.format(course, courses[course][0], curr_cost, curr_cost * 120.25))
        total += curr_cost * 120.25

    print('\nHealth & ID fees\t$  35.00')

    print('\n---------------------------------\n')

    print('\tTotal Payments\t$ {:.2f}\n'.format(total))

    #time.sleep(5)

    next_iter = input('Would you like to print out another invoice? Y = yes, N = no\n')
    
    while next_iter.lower() not in ['y', 'n']:
        next_iter = input('Invalid character (must be Y or N): ')

    state = next_iter.lower() == 'y'

print('Goodbye.')