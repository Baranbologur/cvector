#include "c_vector.h"

/* Can use any type of object where the size 
of the object is constant and the destructor 
function is implemented */

typedef struct student{
    char* name;
    int age;
    int student_id;
}student;

void free_student(void *inp){
    student *student = inp;
    free(student->name);
    return;
}

/* This type of a constructor-like function is not necessary */
student create_student(char* name, int age, int student_id){
    student new_student;
    new_student.name = strdup(name); 
    new_student.age = age;
    new_student.student_id = student_id;
    return new_student;
}

int main(void){
    student *vector;
    vector = vector_initialize(vector, sizeof(*vector), free_student); /* Initialize the vector to set the metadata */

    student student1 = create_student("mia", 5, 125); 
    student student2 = create_student("george", 7, 411);
    student student3 = create_student("steve", 9, 25);
    student student4 = create_student("baran", 4, 1);
    vector = vector_push_back(vector, &student1); /* Don't forget to map the result to vector */
    vector = vector_push_back(vector, &student2);
    vector = vector_push_back(vector, &student3);
    vector = vector_insert(vector, &student4, 0);
    vector_erase(vector, 1);

    student *x = vector_at(vector, 1);
    printf("%s, %d, %d\n", x->name, x->age, x->student_id);

    student *y = vector_front(vector);
    printf("%s, %d, %d\n", y->name, y->age, y->student_id);

    student *z = vector_back(vector);
    printf("%s, %d, %d\n", z->name, z->age, z->student_id);

    vector_free(vector); /* Free all elements and metadata of vector to prevent memory leaks */
}