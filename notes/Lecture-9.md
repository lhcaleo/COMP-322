# Lecture 9 (Exception Handling)

[TOC]

## Outline

- What are exceptions
- Try catch
- Layers of exceptions



**Q: What do they have in common**

- The bigfoot
- Software developer providing error free code
- Little green alien from Mars

<u>A: They all have fans believing in their existence</u>



## What is an exception?

- Exception is an unexpected behaviour
- Exceptions are not necessarily error(bugs), they are more about forgetting to handle errors
- Called exceptions because they deal with exceptional circumstances that may arise during runtime
- Exceptions are raised when there is no logical way for a method to continue its execution 
- Object oriented way of implementing "error codes" used in plain C language

### Examplles

- What if malloc or new failed to provide the demanded memory block?

  - Remember that a system has a limited memory that may run out

- What if your code reads a file that is supposed to be present (and you as a programmer are taking for granted that it is always present). One sunny day, someone deleted that file ...

- What if your code reads a feed from a website, then one rainy day the site's server went down.

  

___



##Try …  catch … throw

- Exceptions should be caught when they occur

  - Using a ==try and catch== blocks
  - Portion of code to be monitored for exceptions should be enclosed within the try block (using ==try== keyword)
  - Exception handling is done within the catch block (Using the ==catch== keyword)
  - To signal an exception or to propagate it to an outer code level, we use the ==throw== keyword.
  - Unlike Java, C++ does **Not** support a "finally" block. Whatever code that "finally" must have, should be done in the destructor.

  ###Try Catch  Syntax

  ```c++
  int main()
  {
    try {
      // Portion of code to be monitored for exceptions
    } catch(...) {
      // Exception handling is done here
    }
  }
  ```

  ### Try … catch .. throw: Example

  ```c++
  double getRatio(double a,double b)
  {
    return a/b;
  }
  int main()
  {
    double ratio1 = getRatio(5,25);
    double ratio2 = getRatio(5,0);
  }
  ```

  - `getRatio` should *throw* an exception **if provided with zero value for b**

  - **Catch argument type should match the throw argument type**

  - In our example, the type is **const char*** because this is exactly the type of the message that we sent using **throw**

  - ```c++
    double getRatio(double a,double b)
    {
      if(b == 0){
        throw "Warning: Division by Zero";
      }
      return a/b;
    }
    int main()
    {
      try{
         double ratio1 = getRatio(5,25);
     		 double ratio2 = getRatio(5,0);
      } catch (const char* message){
       	 cout << message << endl;
      }
    }
    ```

- We can use string as well

- ```c++
  double getRatio(double a,double b)
  {
    if(b == 0){
    	string msg = "Warning: Division by Zero";
      throw msg;
    }
    return a/b;
  }
  int main()
  {
    try{
       double ratio1 = getRatio(5,25);
   		 double ratio2 = getRatio(5,0);
    } catch (string& message){
     	 cout << message << endl;
    }
  }
  ```

###C++ standard exceptions

- \#include <exception>
- C++ standard library offers <u>a list of exceptions</u>
  - std::bad_alloc
  - Std::out_of_range
  - ...
- C++ offers also a base class to create user defined "object" exceptions
  - Define new exceptions by inheriting from the base class **`std::exception`**

### Inheriting from class exception: Example

- `std::exception` has a virtual member method called `what()` that can be reimplemented in derived classes to **personalize a user message about the cause of the exception**
- `const throw()` is part of the declaration of the `what()` method
  - `const`: the method will not alter the state of the class
  - `throw()`: for C++ 98 means that this method is guaranteed not to throw exceptions
    - Replaced by `noexcept` since C++11

```c++
class ZeroException: public exception
{
  virtual const char* what() const throw(){
   	 return "Warning: Division by Zero";
  }
};

ZeroException divideByZeroException;

double getRatio(double a, double b)
{
  if(b == 0)
  {
    	throw divideByZeroException;
  }
  return a/b;
}

int main()
{
  try{
     double ratio1 = getRatio(5,25);
 		 double ratio2 = getRatio(5,0);
  } catch (exception& e){
   	 cout << e.what() << endl;
  }
}
```

### Catching multiple exceptions

```c++
try{
  //code that might through some exceptions
} 
catch(ZeroException& e)
{
  // handling divison by zero exception
}
catch(SomeOtherCostumException& e)
{
  // handling some other user defined exception
}
catch(const std::exception& e)
{
  // handling all other standard exceptions
}
catch(...)
{
  // handling non defined unexcepted exceptions
}
```

- We can manage different type of exceptions separately
- **Respect the order of catching**
  - Derived classes first, then base classes
  - (…) at the end

###Try catch blocks can be nested - 1

```c++
class ZeroException: public exception
{
  virtual const char* what() const throw(){
   	 return "Warning: Division by Zero";
  }
};
ZeroException divideByZeroException;

class SomeOtherException: public exception
{
  public:
  	virtual const char* what() const throw()
  	{
      return "Some Other Exception";
  	}
};
SomeOtherException otherException;

double getRatio(double a, double b)
{
  if(b == 0)
  {
    	throw divideByZeroException;
  }
  return a/b;
}
```



```c++
int main()
{
  try
  {
  	try
  	{
     double ratio1 = getRatio(5,25);
 		 double ratio2 = getRatio(5,0);
		} 
		catch (ZeroException& e)
		{
   	 		cout << e.what() << endl;
   	 		throw otherException;
  	}
	}
	catch(exception& e)
	{
    	cout<<"Outer catch: " << e.what() << endl;
	}
}
```

Output:

```
Warning: Division by Zero
Outer catch: Some Other Exception
```

### Catch me if you can ;) - take 1

```c++
int main()
{
  try
  {
  	try
  	{
     	double ratio1 = getRatio(5,25);
 			double ratio2 = getRatio(5,0);
		} 
		catch (SomeOtherException& e)
		{
   	 		cout << "Inner catch: " << e.what() << endl;
  	}
	}
	catch(exception& e)
	{
    	cout<<"Outer catch: " << e.what() << endl;
	}
}
```

- Which catch will catch the ZeroException?
  - The outer catch. Exceptions propagate to the outer blocks

### Catch me if you can ;) - take 2

```c++
int main()
{
  try
  {
  	try
  	{
     	double ratio1 = getRatio(5,25);
		} 
		catch (SomeOtherException& e)
		{
   	 		cout << "Inner catch: " << e.what() << endl;
  	}
	}
	catch(exception& e)
	{
    	cout<<"Outer catch: " << e.what() << endl;
	}
}
```

- Which catch will catch the ZeroException?
  - None of them ;)

###Catch me if you can ;) - take 3

```c++
int main()
{
  try
  {
  	try
  	{
     	double ratio1 = getRatio(5,25);
		} 
		catch (ZeroException& e)
		{
   	 		cout << "Inner catch: " << e.what() << endl;
  	}
	}
	catch(exception& e)
	{
    	cout<<"Outer catch: " << e.what() << endl;
    	throw divideByZeroException;
	}
}
```

- Which catch will catch the ZeroException? (Assuming that the outer catch caught an exception and it threw divideByZeroException)
  - Non of them. Exceptions do not propagate to the inner blocks.

###Catch me if you can ;) - take 4

```c++
int main()
{
  try
  {
  	try
  	{
     	double ratio1 = getRatio(5,25);
     	double ratio2 = getRatio(5,0);
		} 
		catch (ZeroException& e)
		{
   	 		cout << "Inner catch: " << e.what() << endl;
   	 		throw divideByZeroException;
  	}
	}
	catch(exception& e)
	{
    	cout<<"Outer catch: " << e.what() << endl;
	}
}
```

- **Which catch will catch the ZeroException?** 
  - getRatio(5,0) will trigger the inner catch
  - Throw divideByZeroException will trigger the outer catch





##Exception handling and control transfer

- When a program throws an exception the execution control is transferred to the catch block and never returns to the block that threw the exception
- If an exception occur and the program does not provide exception handlers or if it does provide one but the catch block exception declaration is not of the same type as the thrown object, the program will abort.(中止)
- When the control is transferred from a throw-point to a handler, destructors are invoked for all automatic objects constructed since the try block was entered