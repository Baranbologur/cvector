# Vector in C

This is a vector implementation in C, using separate compilation method. Functions are implemented in c_vector.c and prototypes are in c_vector.h header file. You can see example usage in c_vector_example.c file as well as in this README file.

```
+----------+------+--------------+------------+--------------------+
| capacity | size | element size | desturctur | vector(data) ..... |
+----------+------+--------------+------------+--------------------+
^                                             ^
| vector metadata                             | user's pointer
```

The vector (which is a pointer) points to the end of the metadata where our dynamic vector begins. Once the vector becomes large enough, new address space is allocated using realloc. Since the vector metadata pointer is located at the beginning of all information, the realloc function is applied through this pointer. In such cases, the vector pointer given as input may change and therefore, after using addition functions, it may sometimes be necessary to set the vector equal to the function result. I recomment to make this equalization at every 'vector_push_back()' and 'vector_insert()' call.

Following is an example usage of this c vector implementation

```c
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
```

The result is:
```
george, 7, 411
baran, 4, 1
steve, 9, 25
```