# OOP345_2018

## week 1 note

#### Encapsulation

* Each object methods manage it's own data.
* This is also know as hiding.

#### Message Passing & Associations

#### Inheritance Concept: Classes form a Hierarchy
* Class are arranged in a treelike structire call a inheritance.

#### Public, Private and Protected
* Attributes can be public or private.
* Methods can be public, private and protected:

#### Method signature

#### Polymorphism
* Means that the same method will behave differetly when it is applied to the objects of different class.
* It also means that different methods associated with different classes can interpert the same message in different way.
* E.X: an object can send message PRINT to several object, and each one will use it's own PRINT method to execute the message.

#### Binding 
* Associating a method call with the method code to run.
* Resolving ambiguity in the context of overloaded methods.
* Choices for binding time.
* Static: Compile-time.

#### C++ Data Types
* There are 6 atomic data types:
1. Character (character, char);
2. Integer (integer, int, short, long, byte) with a variety of precisions;
3. Floating-point number (float, double, real, double precision);
4. Fixed-point number (fixed) with a variety of precisions and a programmer-selected scale.
5. Boolean, logical values true and false.
6. Reference (also called a pointer or handle), a small value referring to another object's address in memory, possibly a much larger one.

#### C++: Statements

#### C++: Arrays and Strings
* Arrays indexed collections of identical-type objects.
* Arrays index always start on 0
* Arrays can be used in two differnt ways: primitive arrays and vectors
* Arrys can be Single Dimensional or Multi-Dimentional.

#### C++: Pointers Cont'd
``` c++
int x =10;
int *ptr = &x;
*ptr = 15;
```
#### Pointer to Structure
```c++
StudentRecord *sptr;
sptr = &stu;
cout << "Name is" << sptr-> name;
or cout << "Name is " << (*sptr).name;
```
