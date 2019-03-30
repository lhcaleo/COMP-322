#include <iostream>
using namespace std;
int main()
{

    // For SmartPointer class
    cout << "Testing SmartPointer class" << endl;

    // Testing Constructors
    cout << "Creating a SmartPointer of type int with value 11" << endl;
    SmartPointer<int> SmartIntPointer1(11);
    cout << "SmartIntPointer1 = " << SmartIntPointer1.getValue() << endl;

    cout << "Creating a SmartPointer of type int with value -1" << endl;
    SmartPointer<int> SmartIntPointer(-1);

    cout << "Creating a SmartPointer of type int with no value provided" << endl;
    SmartPointer<int> SmartIntPointer2;
    cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

    // Testing Setter & Getter
    cout << "Setting value of SmartIntPointer2 to 5" << endl;
    SmartIntPointer2.setValue(5);
    cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

    cout << "Creating a SmartPointer of type float with no value provided" << endl;
    SmartPointer<float> SmartFloatPointer1;
    cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

    cout << "Setting value of SmartFloatPointer1 to 1.5" << endl;
    SmartFloatPointer1.setValue(1.5);
    cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

    cout << "Creating a SmartPointer of type float with no value provided" << endl;
    SmartPointer<float> SmartFloatPointer2;
    cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

    cout << "Setting value of SmartFloatPointer2 to 2.5" << endl;
    SmartFloatPointer2.setValue(2.5);
    cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

    SmartPointer<float> SmartFloatPointer3 = SmartFloatPointer1 + SmartFloatPointer2;
    cout << "SmartFloatPointer1 + SmartFloatPointer2 = " << SmartFloatPointer3.getValue() << endl;

    SmartPointer<float> SmartFloatPointer4 = SmartFloatPointer2 - SmartFloatPointer1;
    cout << "SmartFloatPointer2 - SmartFloatPointer1 = " << SmartFloatPointer4.getValue() << endl;

    SmartPointer<float> SmartFloatPointer5 = SmartFloatPointer1 * SmartFloatPointer2;
    cout << "SmartFloatPointer1 * SmartFloatPointer2 = " << SmartFloatPointer5.getValue() << endl;

    // For handling arrays
    cout << "Testing arrays" << endl;

    //
    // add the needed code that shows how you use your class to create an array of multiple elements of a certain type.
    // provide all the necessary test code that shows the different use cases of your code
}
//implements generic programming
template <typename T>
class SmartPointer
{
  private:
    T *value;

  public:
    SmartPointer();
    SmartPointer(T value);
    T getValue();
    void setValue(T value);
};

// default constructor
template <typename T>
SmartPointer<T>::SmartPointer()
{
    this->value = new T(0);
}
// constructor with parameters
template <typename T>
SmartPointer<T>::SmartPointer(T value)
{
    this->value = new T(value);
}
// get value method
template <typename T>
T SmartPointer<T>::getValue()
{
    return *this->value;
}
// set value method
template <typename T>
void SmartPointer<T>::setValue(T value)
{
    *this->value = new T(value);
}