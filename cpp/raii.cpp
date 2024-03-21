#include <iostream>
#include <memory>
using namespace std;

class MyClass {
  public:
  MyClass() {
    cout << "My class constructor called" << endl;
  }

  ~MyClass() {
    cout << "My class destructor called" << endl;
  }
};

int main() {
  // create a smart pointer to a MyClass object
  unique_ptr<MyClass> myClass(new MyClass());

  // use the Myclass object
  cout << "Using the MyClass Object" << endl;

  // The smart pointer will automatically delete the object when it goes out of scope
  return 0;
}