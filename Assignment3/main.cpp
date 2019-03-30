#include <iostream>
#include <exception>
using namespace std;


/* 
-Question 1: 
Research smart pointers provided by the standard library (since C++11). 
List them and explain the difference between them. 

-Answer:
In order to manage dynamic memory safely, smart pointers are used to make sure
  that the object is deleted if it will not be used in the future.
According to cppreference.com, "Smart pointers enable automatic, exception-safe, object lifetime management."
"
Smart pointers provided by the standard library (since C++11):
(1)unique_ptr
    Ensure that only exactly one copy of an object exists. 
    i.e. Unique object ownership
(1)shared_ptr
    Enable many shared pointers can own the same object
    i.e. Shared object ownership
    It can avoid memory leak 
(3)weak_ptr
    weak pointer holds a "weak' reference to an object held by shared_ptr
    It can be converted to shared_ptr easily in order to have the acess to the object
    i.e. Temporary object ownership
(4)auto_ptr
    Manages one object created by new keyword and deletes this object when
      auto_ptr is destroyed. It may cause problems regarding its deletion.
    i.e. Strict object ownership
*/


// Smart Pointer
template <typename T>
class SmartPointer
{
  private:
    T *value;
    int size;

  public:
    //Smart Pointer
    SmartPointer();
    SmartPointer(T value);
    ~SmartPointer();
    T getValue();
    void setValue(T value);

    //Smart Array
    SmartPointer(T value[], int size);
    void setValue(T value, int i);
    void getArray();

    //Overloading operators
    friend SmartPointer operator+(SmartPointer<T> &sp1, SmartPointer<T> &sp2)
    {
        try
        {
            if (sp1.size != sp2.size)
            {
                throw "Size Not Match Exception";
            }
        }
        catch (const char *message)
        {
            cerr << message << endl;
        }
        SmartPointer<T> *sp3 = new SmartPointer<T>(new T[sp1.size], sp1.size);
        for (int i = 0; i < sp1.size; i++)
        {
            sp3->setValue(*(sp1.value + i) + *(sp2.value + i), i);
        }
        return *sp3;
    }
    friend SmartPointer operator-(SmartPointer<T> &sp1, SmartPointer<T> &sp2)
    {
        try
        {
            if (sp1.size != sp2.size)
            {
                throw "Size Not Match Exception";
            }
        }
        catch (const char *message)
        {
            cerr << message << endl;
        }
        SmartPointer<T> *sp3 = new SmartPointer<T>(new T[sp1.size], sp1.size);
        for (int i = 0; i < sp1.size; i++)
        {
            sp3->setValue(*(sp1.value + i) - *(sp2.value + i), i);
        }
        return *sp3;
    }
    friend SmartPointer operator*(SmartPointer<T> &sp1, SmartPointer<T> &sp2)
    {
        try
        {
            if (sp1.size != sp2.size)
            {
                throw "Size Not Match Exception";
            }
        }
        catch (const char *message)
        {
            cerr << message << endl;
        }
        SmartPointer<T> *sp3 = new SmartPointer<T>(new T[sp1.size], sp1.size);
        for (int i = 0; i < sp1.size; i++)
        {
            sp3->setValue(*(sp1.value + i) * *(sp2.value + i), i);
        }
        return *sp3;
    }
};

// default constructor
template <typename T>
SmartPointer<T>::SmartPointer()
{
    this->value = new T(0.00);
    this->size = 1;
}
// constructor with parameters
template <typename T>
SmartPointer<T>::SmartPointer(T value)
{
    this->setValue(value);
    this->size = 1;
}
// destructor
template <typename T>
SmartPointer<T>::~SmartPointer()
{
    // Smart Pointer
    if (this->size == 1)
    {
        delete this->value;
    }
    // Smart Array
    else
    {
        delete[] this->value;
    }
}
// get value method
// alway get the first value
template <typename T>
T SmartPointer<T>::getValue()
{
    return *(this->value);
}
// set value method
template <typename T>
void SmartPointer<T>::setValue(T value)
{
    try
    {
        if (value <= 0)
        {
            throw "Negative Number Exception";
        }
    }
    catch (const char *message)
    {
        cerr << message << endl;
    }

    try
    {
        this->value = new T(value);
    }
    catch (const std::bad_alloc &e)
    {
        cout << "the variable was not being allocated" << e.what() << endl;
    }
}

// Smart array

// default constructor cannot be implemented for Smart Array in this case

// constructor with parameters for Smart Array
template <typename T>
SmartPointer<T>::SmartPointer(T value[], int size)
{
    try
    {
        this->value = new T[size];
    }
    catch (const bad_alloc &e)
    {
        cout << "the variable was not being allocated" << e.what() << endl;
    }

    try
    {
        for (int i = 0; i < size; i++)
        {
            //throw exception when data is negative
            if (value[i] < 0)
            {
                throw "Negative Number Exception";
            }
            *(this->value + i) = value[i];
        }
        this->size = size;
    }
    catch (const char *message)
    {
        cerr << message << endl;
    }
}

// set the value at index i in the array
template <typename T>
void SmartPointer<T>::setValue(T value, int i)
{
    try
    {
        if (i > size)
        {
            throw "out of bound exception";
        }
    }
    catch (const char *message)
    {
        cerr << message << endl;
    }

    *(this->value + i) = value;
}
// Print all the elements of Smart Array
template <typename T>
void SmartPointer<T>::getArray()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << *(this->value + i) << " ";
    }
    cout << "\n";
}

int main()
{

    // For SmartPointer class
    cout << "\n----Testing SmartPointer class----\n"
         << endl;

    // Testing Constructors
    cout << "Creating a SmartPointer of type int with value 11" << endl;
    SmartPointer<int> SmartIntPointer1(11);
    cout << "SmartIntPointer1 = " << SmartIntPointer1.getValue() << endl;

    cout << "\nCreating a SmartPointer of type int with value -1" << endl;
    SmartPointer<int> SmartIntPointer(-1);

    cout << "\nCreating a SmartPointer of type int with no value provided" << endl;
    SmartPointer<int> SmartIntPointer2;
    cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

    // Testing Setter & Getter
    cout << "\nSetting value of SmartIntPointer2 to 5" << endl;
    SmartIntPointer2.setValue(5);
    cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

    cout << "\nCreating a SmartPointer of type float with no value provided" << endl;
    SmartPointer<float> SmartFloatPointer1;
    cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

    cout << "\nSetting value of SmartFloatPointer1 to 1.5" << endl;
    SmartFloatPointer1.setValue(1.5);
    cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

    cout << "\nCreating a SmartPointer of type float with no value provided" << endl;
    SmartPointer<float> SmartFloatPointer2;
    cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

    cout << "\nSetting value of SmartFloatPointer2 to 2.5" << endl;
    SmartFloatPointer2.setValue(2.5);
    cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

    SmartPointer<float> SmartFloatPointer3 = SmartFloatPointer1 + SmartFloatPointer2;
    cout << "\nSmartFloatPointer1 + SmartFloatPointer2 = " << SmartFloatPointer3.getValue() << endl;

    SmartPointer<float> SmartFloatPointer4 = SmartFloatPointer2 - SmartFloatPointer1;
    cout << "\nSmartFloatPointer2 - SmartFloatPointer1 = " << SmartFloatPointer4.getValue() << endl;

    SmartPointer<float> SmartFloatPointer5 = SmartFloatPointer1 * SmartFloatPointer2;
    cout << "\nSmartFloatPointer1 * SmartFloatPointer2 = " << SmartFloatPointer5.getValue() << endl;

    // For handling arrays
    cout << "\n----Testing arrays----" << endl;

    //
    // add the needed code that shows how you use your class to create an array of multiple elements of a certain type.
    // provide all the necessary test code that shows the different use cases of your code
    // For SmartPointer class

    // Testing Constructors
    int testArray_1[3] = {1, 2, 3};
    cout << "\nCreating a SmartArray of type int with value 1,2,3" << endl;
    SmartPointer<int> SmartIntPointer11(testArray_1, 3);
    cout << "SmartIntArray11 = ";
    SmartIntPointer11.getArray();

    int testArray_2[3] = {-1, -2, -3};
    cout << "\nCreating a SmartArray of type int with value -1,-2,-3" << endl;
    SmartPointer<int> SmartIntPointer22(testArray_2, 3);

    // Testing Setter & Getter
    cout << "\nSetting value of SmartIntArray11 to 11,22,33" << endl;
    SmartIntPointer11.setValue(11, 0);
    SmartIntPointer11.setValue(22, 1);
    SmartIntPointer11.setValue(33, 2);
    cout << "SmartIntArray11 = ";
    SmartIntPointer11.getArray();

    float testArray_3[3] = {1.5, 2.5, 3.5};
    cout << "\nCreating a SmartArray of type float with value 1.5,2.5,3.5" << endl;
    SmartPointer<float> SmartFloatPointer33(testArray_3, 3);
    cout << "SmartFloatArray33 = ";
    SmartFloatPointer33.getArray();

    cout << "\nSetting value of SmartFloatArray33 to 0.5,1.5,2.5" << endl;
    SmartFloatPointer33.setValue(0.5, 0);
    SmartFloatPointer33.setValue(1.5, 1);
    SmartFloatPointer33.setValue(2.5, 2);
    cout << "SmartFloatArray33 = ";
    SmartFloatPointer33.getArray();

    float testArray_4[3] = {0.5, 2.1, 4.0};
    cout << "\nCreating a SmartArray of type float with value 0.5,2.1,4.0" << endl;
    SmartPointer<float> SmartFloatPointer44(testArray_4, 3);
    cout << "SmartFloatArray44 = ";
    SmartFloatPointer44.getArray();

    SmartPointer<float> SmartFloatPointer55 = SmartFloatPointer33 + SmartFloatPointer44;
    cout << "\nSmartFloatArray33 + SmartFloatArray44 = ";
    SmartFloatPointer55.getArray();

    SmartPointer<float> SmartFloatPointer66 = SmartFloatPointer44 - SmartFloatPointer33;
    cout << "\nSmartFloatArray44 - SmartFloatArray33 = ";
    SmartFloatPointer66.getArray();

    SmartPointer<float> SmartFloatPointer77 = SmartFloatPointer33 * SmartFloatPointer44;
    cout << "\nSmartFloatArray33 * SmartFloatArray44 = ";
    SmartFloatPointer77.getArray();

    cout << "\n--Test operation with different array size--\n"
         << endl;
    float testArray_5[2] = {1.5, 1.5};
    cout << "Creating a SmartArray of type float with value 1.5,1.5" << endl;
    SmartPointer<float> SmartFloatPointer88(testArray_5, 2);
    cout << "SmartFloatArray88 = ";
    SmartFloatPointer88.getArray();

    cout << "\nSmartFloatArray33 + SmartFloatArray88 = \n";
    SmartPointer<float> SmartFloatPointer99 = SmartFloatPointer33 + SmartFloatPointer88;
    cout << "\n";
}
