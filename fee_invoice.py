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
    6997: ('gol 127', 1), 
    9494: ('COP 101', 3)
}

std_id = input("Enter the student's ID: ")
num_courses = input("Enter the number of courses (up to 3): ")
course_numbers = input("Enter the {} course number(s): ".format(int(num_courses)))

print('std_id: ', std_id)
print('num_courses: ', num_courses)
print('course_numbers: ', course_numbers)