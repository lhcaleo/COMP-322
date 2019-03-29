# Lecture 7 (Classes and Inheritance)

[TOC]

## Outline

- Friendship
- Inheritance
- Construction/destruction order
- Types of inheritance
- Is-a VS Has-a
- Virtual methods
- Abstract classes

##Classes - Behind the scenes

```c++
class SomeAwesomeClass
{
};
```

- How many methods does the following class have?

- Answer is 4

- The compiler will actually provide 4 methods for you unless you explicitly define them yourself:

  1. Default Constructor
  2. Default Destructor
  3. Copy Constructor
  4. Copy Assignment Operator

  

```c++
class SomeAwesomeClass
{
};
int main(){
  SomeAwesomeClass sac1;
  SomeAwesomeClass sac2 = sac1;
  SomeAwesomeClass sac3(sac2);
  SomeAwesomeClass sac4;
  sac4 = sac1;
}
```



### Copy Constructor

[Constructor vs. Copy Assignment Operator](https://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/)

- **SomeAwesomeClass(const SomeAwesomeClass &obj);**
  - <u>Instantiate and initialize an object from another object having the same type</u>
  - In Java, we obtain similar behaviour by simply inheriting from "Cloneable" (however the way Cloneable works is very different from C++ copy constructor)

###Copy Assignment Operator

- SomeAwesomeClass& operator = (const SomeAwesomeClass &obj);
  - Assign an object from another object having the same type



**Copy Constructor vs Copy Assignment Operator****

- Copy constructor is called when a new object is created from an existing object, as a copy of the existing object.
-  And assignment operator is called when an already initialized object is assigned a new value from another existing object.



### Friends

- Functions and classes can be declared "friends" using the **<u>friend keyword.</u>**
- A friend function or class can have access to a class's private and protected members

```c++
class GPS{
  public:
  	GPS(double altitude, double longitude, double latitude):
  		altitude(altitude),
  		longitude(longitude),
  		latitude(latitude)
    {
     	cout << "GPS Constructor" << endl;   
    }
  	
  	~GPS(){
    	cout << "GPS Destructor" << endl;
  	}
  
  	friend void setLongitude(GPS& gos);
  
  private:
  	double altitude;
  	double longitude;
  	double latitude;
};

void setLongitude(GPS& gps){
  gps.longitude = 42;
}

```



### Class inheritance

- Capability of a class to inherit (or extend) the members (data and methods) of another class
- Reuse of functionalities and characteristics of a base class by a derived class
- Multiple classes can derive from the same base class
- One class may derive from **multiple base classes** (unlike Java)
- Derived classes inherit all the accessible members of their base classes: public and protected members
- Derived classes can extend the inherited members by adding their own members
- Base class cannot access extended members defined within inherited classes

#### Example

```c++
class Aircraft{
  public:
  	Aircraft(){cout << "Aircraft ctor" << endl;}
  	~Aircraft(){cout << "Aircraft ~dtor" << endl;}
  	
  	void setCapacity(int i){capacity = i;}
  	void fly() {cout << "Aircraft flying: " << capacity << endl;}
  	// ...
  protected:
  	int capacity; // number of pass
};

class Boeing: public Aircraft{
  public:
  	Boeing(){cout << "Boeing ctor" << endl;}
  	~Boeing){cout << "Boeing ~dtor" << endl;}
}
//Main function
int main(){
  Aircraft a;
  a.setCapacity(50);
  a.fly();
  
  Boeing b;
  b.setCapacity(100);
  b.fly();
}
```

Output:

```
Aircraft ctor
Aircraft flying: 50
Boeing ctor
Aircraft flying: 100
Boeing ~dtor
Aircraft ~dtor
Aircraft ~dtor
```



###Construction/Destruction call order

- Construction
  - Base class constructor is called first then the constructor of the derived(衍生的) class
  - Whenever any constructor of a derived class (either default or with parameters) is called, the default constructor of the base class is called automatically and executed fisrt
- Destruction
  - It works in exactly the opposite order of construction
  - Derived class destructor is called first then the destructor of the base class

####Example 1

```java
class Aircraft{
  public:
  	Aircraft(){cout << "Aircraft ctor" << endl;}
    
    Aircraft(int i)
    {
      capacity = i;
      cout << "Aircraft ctor with parameters" << endl;
    }
  
  	~Aircraft(){cout << "Aircraft ~dtor" << endl;}
  	
  	void setCapacity(int i){capacity = i;}
  	void fly() {cout << "Aircraft flying: " << capacity << endl;}
  protected:
  	int capacity; // number of pass
};

class Boeing: public Aircraft{
  public:
  	Boeing(){cout << "Default Boeing ctor" << endl;}
  	Boeing(int i)
    {
      capacity = i;
      cout << "Boeing ctor with parameters" << endl;
    }
  	~Boeing){cout << "Boeing ~dtor" << endl;}
}
//Main function
int main(){
  Boeing b(300);
  b.fly();
}
```

Output:

```
Default Aircraft ctor
Boeing ctor with parameters
Aircraft flying: 300
Boeing ~dtor
Aircraft ~dtor
```

#### Example 2

```c++
class Aircraft{
  public:
  	Aircraft(){cout << "Aircraft ctor" << endl;}
    
    Aircraft(int i)
    {
      capacity = i;
      cout << "Aircraft ctor with parameters" << endl;
    }
  
  	~Aircraft(){cout << "Aircraft ~dtor" << endl;}
  	
  	void setCapacity(int i){capacity = i;}
  	void fly() {cout << "Aircraft flying: " << capacity << endl;}
  protected:
  	int capacity; // number of pass
};

class Boeing: public Aircraft{
  public:
  	Boeing(){cout << "Default Boeing ctor" << endl;}
  	Boeing(int i):Aircraft(i)
    {
      capacity = i;
      cout << "Boeing ctor with parameters" << endl;
    }
  	~Boeing){cout << "Boeing ~dtor" << endl;}
}
//Main function
int main(){
  Boeing b(300);
  b.fly();
}
```

Output:

```
Aircraft ctor with parameters
Boeing ctor with parameters
Aircraft flying: 300
Boeing ~dtor
Aircraft ~dtor
```

#### Types of Inheritance

- Derived classes can inherit a base class in 3 different ways
  1. Public
     - Derived class keeps the same access rights to the inherited members
     - Public members in base class remain public in derived class
     - Protected members in base class remain protected in derived class
  2. Private
     - Derived class changes the accessibility rights to the inherited members
     - Public and protected members in base class become private in derived class
  3. Protected
     - Derived class changes the accessibility rights to the inherited members
     - Public and protected members in base class become protected in derived class

###Architecture Dilemma: is-a VS has-a

- When designing the classes of a software you should define carefully the relationship between those classes
  - Should `class A`  inherit from `class B` or should it contain a pointer to class B?
  - Should class `Aircraft` inherit from class `Engine` sicne every aircraft has an engine.
- **If A is B,** then A should <u>inherit</u> from B
- **If A has B as one of its components**, then A should contain B and <u>not inherit</u> from it.



#### Polymorphism: Having different forms

```c++
class Aircraft{
  public:
  	Aircraft(){cout << "Default Aircraft ctor" << endl;}
    
    Aircraft(int i)
    {
      capacity = i;
      cout << "Aircraft ctor with parameters" << endl;
    }
  
  	~Aircraft(){cout << "Aircraft ~dtor" << endl;}
  	
  	void setCapacity(int i){capacity = i;}
  	void fly() {cout << "Aircraft flying: " << capacity << endl;}
  protected:
  	int capacity; // number of pass
};

class Boeing: public Aircraft
{
  public:
  	Boeing(){cout << "Default Boeing ctor" << endl;}
  	
  	Boeing(int i):Aircraft(i)
    {
      capacity = i;
      cout << "Boeing ctor with parameters" << endl;
    }
  	~Boeing){cout << "Boeing ~dtor" << endl;}
  	
  	void fly(){cout << "Boeing flying: "} << capacity << endl;
}
//Main function
int main(){
	Aircraft* af;
	af = new Boeing(300);
  af->fly();
  delete af;
}
```

Output:

```
Aircraft ctor with parameters
Boeing ctor with parameters
Aircraft flying: 300
Aircrafy ~dtor
```

- 2 Main problems
  1. Boeing::fly method is not being executed (Aircraft::fly was being called instead)
  2. Boeing destructor was not being called at all (potential memory leak)

#### Polymorphism: Virtual Methods

Here `fly()` method is polymorphic

```c++
class Aircraft{
  public:
  	Aircraft(){cout << "Default Aircraft ctor" << endl;}
    
    Aircraft(int i)
    {
      capacity = i;
      cout << "Aircraft ctor with parameters" << endl;
    }
  
  	~Aircraft(){cout << "Aircraft ~dtor" << endl;}
  	
  	void setCapacity(int i){capacity = i;}
  	void fly() {cout << "Aircraft flying: " << capacity << endl;}
  protected:
  	int capacity; // number of pass
};

class Boeing: public Aircraft
{
  public:
  	Boeing(){cout << "Default Boeing ctor" << endl;}
  	
  	Boeing(int i):Aircraft(i)
    {
      capacity = i;
      cout << "Boeing ctor with parameters" << endl;
    }
  	~Boeing){cout << "Boeing ~dtor" << endl;}
  	//Virtual here!
  	virtual void fly(){cout << "Boeing flying: "} << capacity << endl;
}
//Main function
int main(){
	Aircraft* af;
	af = new Boeing(300);
  af->fly();
  delete af;
}
```

Output:

```
Aircraft ctor with parameters
Boeing ctor with parameters
Boeing flying: 300
Boeing ~dtor
Aircraft ~dtor
```

- Always mark destructor virtual if the class is meant to be inherited
- You only need to **mark the destructor of the base class** ==virtual==. By doing so, the compiler will automatically consider all subclasses' destructors as virtual as well.
- You only need to **mark the polymorphic methods in the base class as ==virtual==.**
- However, it is common to mark them virtual in the derived classes as well for readability
- C++11 introduced the keyword "`override`" to enhance the readability of the polymorphic methods.



#### Virtual methods VS Pure Virtual methods

- <u>Virtual method</u> has an implementation in the base class and can be overriden by a derived class to obtain polymorphic behaviour
- <u>Pure virtual methods</u> does not have an implementation in the base class and should necessarily be implemented in the derived classes
  - $$\textcolor{blue}{virtual\, void\, fly() = 0;}​$$
- Class that does have at least one pure virtual method is called <u>an abstract base class</u> (Similar to Java's interface classes)
- Abstract base classes cannot be instantiated. Only derived classes can.

#### Few words about Multiple inheritance

- C++ allows a class to inherit from multiple other classes

  - ```c++
    class FighterJet: public Aircraft, public Fighter
    ```

- Order of construction follows the same order of declaration

  - `Aircraft` ctor then `Fighter` actor, then `FighterJet` ctor

- Beware the diamond problem

  - Use virtual inheritance to avoid the headache





#Lecture 8 (Operator Overloading)

## Outline

- Function overloading
- Class Polymorphism
- Operator overloading

##Recap 

### Function Overloading

![Screen Shot 2019-03-28 at 10.57.31 PM](https://ws3.sinaimg.cn/large/006tKfTcly1g1jhfg7oldj30kz0ax3zv.jpg)

### Class polymorphism

![Screen Shot 2019-03-28 at 10.57.38 PM](https://ws3.sinaimg.cn/large/006tKfTcly1g1jhgjg3t5j30l70b6wha.jpg)

##Virtual methods VS Pure Virtual methods

- <u>Virtual method</u></u> has an implementation in the base class and can be overriden by a derived class to obtain polymorphic behaviour
- <u>Pure virtual methods</u> does not have an implementation in the base class and should necessarily be implemented in the derived classes
  - $$\textcolor{blue}{virtual\, void\, fly() = 0;}$$
- Class that does have at least one pure virtual method is called <u>an abstract base class</u> (Similar to Java's interface classes)
- Abstract base classes cannot be instantiated. Only derived classes can.

---

- Abstact base classes (ABC) cannot be instantiated
- If you try to instantiate an ABC you'll get compilation error:
  - error: cannot declare variable `a` to be of abstract type `Aircraft`
- We still don't have an implementation for the method `fly()`

```c++
class Aircraft
{
  public:
  	Aircraft();
  	virtual ~Aircraft();
  	virtual void fly() = 0;
};
int main(){
  Aircraft a; // problem
}
```



___



- Abstact base classes (ABC) cannot be instantiated
- If you try to instantiate a derived class you'll get compilation error:
  - error: cannot declare variable `b` to be of abstract type `Boeing`
- We still don't have an implementation for the method `fly()`

```c++
class Aircraft
{
  public:
  	Aircraft();
  	virtual ~Aircraft();
  	virtual void fly() = 0;
};
class Boeing: public Aircraft
{
  public:
  	Boeing();
  	virtual ~Boeing();
}
int main(){
  Boeing b; // problem
}
```

- Now we can define an object of type `Boeing`

- This becomes not abstract

- ```c++
  class Aircraft
  {
    public:
    	Aircraft(){};
    	virtual ~Aircraft(){};
    	virtual void fly() = 0;
  };
  class Boeing: public Aircraft
  {
    public:
    	Boeing();
    	virtual ~Boeing(){};
    	void fly()
      {
      	// I believe I can fly
      	// I believe I can touch the sky
      }
  }
  int main(){
    Boeing b; // problem
  }
  ```

  

## Operator Overloading

- The ability to re-implement (overload) most of the <u>built in operators</u>
  - The only non-overloadable operators are:
    - :: 
    - .
    - ?:
    - .*
- **Why overloading built in operators?**
  - To be able to use them with <u>user defined types</u>
  - a + b is more natural than add(a,b)
- Java doesn't provide operator overloading mechanism.

### Oprator overloading: example

```c++
class myVector
{
  public:
  	myVector():
  		x(0),y(0),z(0){}
    myVector(int a,int b,int c):
    	x(a),y(b),z(c){}
    	
    void display()
    {
      cout << x << "," << y << ", " << z << endl;
    }
  private:
  	int x,y,z;
}

int main(){
  myVector v1(2,4,6);
  myVector v2(3,5,7);
  v1.display();
  v2.display();
}
```

Output: 

2,4,6

3,5,7

###Operator overloading: example. How to add two vectors?

```c++

int main(){
  myVector v1(2,4,6);
  myVector v2(3,5,7);
  
  myVector v3 = v1 + v2;
  v3.display
}
```

Output: 5,9,13

###Operator overloading: example. Overloading << operator

- Let's replace `display()` method by overloading the ostream operator `<<`
- To be able to use cout to display a vector like any other built-in type
- Two options
  1. Member method
  2. Friend method

```c++
class myVector
{
  public:
  	myVector():
  		x(0),y(0),z(0){}
    myVector(int a,int b,int c):
    	x(a),y(b),z(c){}
    	
    void display()
    {
      cout << x << "," << y << ", " << z << endl;
    }
    
    myVector operator+ (const myVector& vec){
      myVector result;
      result.x = this->x + vec.x;
      result.y = this->y + vec.y;
      result.z = this->z + vec.z;
      return result;
    }
    
  private:
  	int x,y,z;
}
```

---

#### Overloading << operator (member method)

```c++
class myVector
{
  public:
  	myVector():
  		x(0),y(0),z(0){}
    myVector(int a,int b,int c):
    	x(a),y(b),z(c){}
    	
    void display()
    {
      cout << x << "," << y << ", " << z << endl;
    }
    
    ostream& operator<<(ostream& os){
    	 os << this->x << ", " << this->y << ", " << this->z;
     	 return os
    }
    
  private:
  	int x,y,z;
};
int main(){
  myVector v1(2,4,6);
  v1 << cout;
}
Output is : 2,4,6
```

- Notice that the syntax is a bit confusing
  - `v1 << cout`    instead of `cout << v1`
- Stream operator << is being called on `v1` object and **not** on cout object
- It is recommended to use a friend method to avoid this confusion

---

####Overloading << operator (friend method)

```c++
class myVector
{
  public:
  	myVector():
  		x(0),y(0),z(0){}
    myVector(int a,int b,int c):
    	x(a),y(b),z(c){}
    	
    void display()
    {
      cout << x << "," << y << ", " << z << endl;
    }
    
    friend ostream& operator<<(ostream& os, const myVector& vec);
    
  private:
  	int x,y,z;
};
```



```c++
// Actual code of friend method
ostream& operator<<(ostream& os, const myVector& vec){
   os << vec.x << ", " << vec.y << ", " << vec.z;
   return os
}
```

Note: cout is from ostream

```c++
int main(){
  myVector v1(2,4,6);
  cout << v1;                // Look up the friend method, os is cout, vec is v1
}
Output is : 2,4,6
```

