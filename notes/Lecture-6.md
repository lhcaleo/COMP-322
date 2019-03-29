#Lecture 6 (Classes in C++)

[TOC]

## Outline

● Review of OO concept

● C structs

● C++ Classes

● Constructors

● Destructors

## OO Programming: Quick review

● Approach to design modular and reusable systems

● Programming is about manipulating data through code (methods or algorithms) 

​	○ Object: is a coupling of both data and methods

● Extension to the concept of structures ○ Not only we group multiple data elements but we also attach the intelligence needed to manipulate the data (also called encapsulation)  

## C structs

### Compound data type

```c++
struct person{
  int age;
  char sex;
};
// main function
int main(){
  person Mike;
  Mike.age = 24;
  Mike.sex = 'M';
  
  cout << Mike.age << endl;
  return 0
}
```

### Data and code are seperated

```c++
struct person{
  int age;
  char sex;
};

bool canVote(int age){
  if(age >= 18)
  	return true;
  return false;
}

// main function
int main(){
  person Mike;
  Mike.age = 24;
  Mike.sex = 'M';
  if(canVote(Mike.age))
  	cout << "Mike can vote" << endl;
  else
    cout << "Too bad for Mike" << endl;
  return 0
}
```



## C++ Classes

### Introduction

- Class is a user defined type
- It has data and methods
  - Referred to as members of the class
  - Methods are functions which are part of the class
- Members may have different access levels
  - public, private or protected
  - **private** by default if not specified
  - Public members are called interface of the class
- Instances of a class are called **objects**
  - Mike is an object of class Person

```c++
class person
{
public:
	bool canVote(int age)
	{
  	if(age >= 18)
  		return true;
  	return false;
	}
  int age;
  char sex;
};

// main function
int main(){
  person Mike;
  Mike.age = 24;
  Mike.sex = 'M';
  if(canVote(Mike.age))
  	cout << "Mike can vote" << endl;
  else
    cout << "Too bad for Mike" << endl;
  return 0
}
```

###Access levels(public)

- Access levels are also called access specifier or access modifiers
- Public:
  - Accessible from anywhere (inside and outside the class)
  - Public is not a default mode, so you need to explicitly specify it
  - Public methods are the interface of the class
    - This is what the clients can use to manipulate the inner state of the object 

### Access levels(private)

- Private:
  - Accessible only from within the class
  - Private is a default mode so you don't necessarily need to explicitly specify it
  - Friend functions are allowed to access private members (discuss later)
  - Best practice is to define data as private and provide a public interface to access the data
  - Used to achieve data hiding

```c++
class person
{
public:
	bool canVote(int age)
	{
  	if(age >= 18)
  		return true;
  	return false;
	}
private:
  int age;
  char sex;
};

// main function
int main(){
  person Mike;
  Mike.age = 24; //ERROR
  Mike.sex = 'M'; //ERROR
  if(canVote(Mike.age))
  	cout << "Mike can vote" << endl;
  else
    cout << "Too bad for Mike" << endl;
  return 0
}
```



```c++
class Person
{
public:
  bool canVote()
  {
    if(age >= 18)
      return true;
    return false;
  }
  void setAge(int age)
  {
    this->age = age;
  }
  void setSex(char sex)
  {
    this->sex = sex;
  }
private:
  	int age;
  	char sex;
};

//main function
int main()
{
  Person Mike;
  Mike.setAge(24);
  Mike.setSex('M');
  
  if(Mike.canVote())
    cout << "Mike can vote" << endl;
  else
    cout << "Too bad for Mike" << endl;
  return 0
}
```

### Access levels (protected)

- Protected
  - Accessible from within the class
  - Accessible also from derived classes (we will discuss this later)
  - Protected is not a default mode so you need to explicitly specify it
  - Friend functions are allowed to access protected member (discuss later)
  - Used to achieve data hiding

```c++
class Person
{
public:
  bool canVote()
  {
    if(age >= 18)
      return true;
    return false;
  }
  void setAge(int age)
  {
    this->age = age;
  }
  void setSex(char sex)
  {
    this->sex = sex;
  }
protected:
  	int age;
  	char sex;
};
```



### Method definition

- Member methods can be defined within the class definition or outside of the class
- Methods defined inside the class declaration are considered "inline" methods even without the use of the "inline" keyword.
- To define a method outside of the class, we need to declare it within he class, then we provide the implementation outside of the class using the `scope operator ::`
- Methods defined outside of the class declaration can still be declared "inline" but with the explicit use of the "inline" keyword.

```c++
class Person
{
public:
	bool canVote();
	void setAge(int age);
	void setSex(char sex);
protected:
	int age;
	char sex;
};
// Example of using scope operator
bool Person::canVote(){
  if(age >= 18)
  	return true;
  return false
}
```



## Constructors

- When instantiating a class, a special method is implicitly called first
  - This method is the `constructor`
- Every class has a constructor (at least one)
- If a constructor is not provided by the programmer, the compiler will provide a **default implicit constructor** (that does basically nothing)
  - This is how the construction of the Person class from the previous example was possible



- The Constructor method:
  - is used to initialize the data members of a class
  - must have the same name as the class
  - must be declared public in general 
    - There are some exceptions when implementing advanced design patterns
  - does not have a return type
    - Constructors don’t return values

```c++
class Person
{
public:
	Person();
	int getAge();
protected:
	int age;
	char sex;
};
// Default Constructor for class Person
Person::Person()
{
  this->age = 0;
  this->sex = 'U';
}

int Person::getAge(){
  return age;
}

//main function
int main()
{
  Person Mike;
  
  cout << Mike.getAge() << endl;
}
```

- Constructor without parameters is called the **default constructor**
- Usually used to initialize the data members to default values

```c++
class Person
{
public:
	Person();
  Person(int age, char sex)
	int getAge();
protected:
	int age;
	char sex;
};
// Default Constructor for class Person
Person::Person()
{
  this->age = 0;
  this->sex = 'U';
}
//Customize Constructor
Person::Person(int age, char sex)
{
  this->age = age;
  this->sex = sex;
}

int Person::getAge(){
  return age;
}

//main function
int main()
{
  Person Mike(24,'M');
  
  cout << Mike.getAge() << endl;
}
```

- Constructor can be **personalized using parameters**
- User can define as many different constructors as needed

### Constructor: Initialization list

- Initialization is listed outside of the body of a constructor

  ● **Initialization list is preferred** to regular initialization because it yields better performance

```c++
class Person
{
public:
	Person();
	Person(int age, char sex);
	int getAge(){return age;};
protected:
	int age;
	char sex;
};

Person::Person():age(0),sex('U')
{
}
Person::Person(int age, char sex):age(age),sex(sex)
{
}
```

## Destructors

- When an object gets out of scope, a special method is implicitly called 
  - This method is the destructor
- Every class has a destructor (and only one)
- If a destructor is not provided by the programmer, the compiler will provide a default implicit destructor ( that usually calls the destructor for each data member but will **not delete dynamically allocated memory for you**)



- Destructor method:
  - is used to clean and liberate any resource that was being held by the object
  - must have the same name as the class preceded by the tilde ~ operator
  - must be declared public in general
    - There are some exceptions when implementing advanced design patterns
  - does not have a return type nor does it take parameters
    - Destructors don’t return values

### delete operator

- `delete` is an operator in C++ programming language, it is used to free the run time allocated memory.
- The `delete` operator deallocates memory and calls the destructor for a single object created with `new`.
- The `delete []` operator deallocates memory and calls destructors for an array of objects created with `new []`.
- Using `delete` on a pointer returned by `new []` or `delete []` on a pointer returned by `new` results in undefined behavior.

```c++
class Person
{
public:
	//Constructor
	Person();
	Person(int age, char sex);
	Person(int age, char sex, char *name);
	//Destructor
	~Person();
	int getAge();
	char* getName();
protected:
	int age;
	char sex;
	char *name;
};

Person::Person(int age, char sex, char *name)
{
  cout << "Constructor got called" << endl;
  this->age = age;
  this->sex = sex;
  this->name = new char[strlen(name)];
  strcpy(this->name, name);
}

Person::~Person()
{
  cout << "Destructor got called" << endl;
  delete [] this->name;
}

char* Person::getName()
{
  return this->name;
}
```

### Dynamic allocation

```c++
//main function
int main()
{
  Person Mike(24,'M',"Michael");
  
  cout << Mike.getName() << endl;
}
```

`output:`

Constructor got called

Michael

Destructor got called



**Another example:**

![Screen Shot 2019-03-28 at 3.50.57 AM](https://ws2.sinaimg.cn/large/006tKfTcly1g1ik6ei187j30ps0n67ej.jpg)

`output:`

Program started ...

A GPS pointer was being declared but not allocated yet

GPS Constructor

GPS Object was being allocated

GPS Destructor

GPS Object was being deleted



###Design pattern example

```c++
class Singleton
{
public:
  static Singleton& getUniqueInstance()
  {
    static Singleton instance;
    return instance;
  }
  // Add the needed public methods
  void doSomething(){}
private:
  Singleton(){}
  ~Singleton(){}
  Singleton(Singleton &);
  Singleton operator = (Singleton &);
};

int main(){
  Singleton& mySingleton = SIngleton::getUniqueInstance();
  mySingleton.doSomething();
}
```

- The Singleton design pattern provides an example of a case where declaring **a constructor private** makes sense
- **Singleton enforces** that `only one object` of a class can be present during the lifetime of a program