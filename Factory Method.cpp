/*****************************************************************

Factory Method - Define an interface for creating an object, but let subclasses decide which class to instantiate.


Factory Method lets a class defer instantiation to subclasses. To name the method more descriptively, it can be named as Factory and Product Method or Virtual Constructor. The Factory Method is closely related to Abstract Factory and Prototype patterns.

In Factory Method, client knows about abstract base class but not concrete subclass. Client wants to create an object from abstract class. But the subclass decides which class to instantiate. This allows us to defer the creation to the subclass. Again, the client doesn't know which subclass or concrete class is used to create the object. The creation is deferred to run-time.

Client knows about abstract base class but not concrete subclass.
1. Run-time creation of objects.
2. Subclasses create objects.
3.Actually, the factory method is a way of circumventing following limitations of C++ constructor:

No return type
A constructor cannot return a result, which means that we cannot signal an error during object initialization. The only way of doing it is to throw an exception from a constructor.
Naming
A constructor should have the same name as the class, which means we cannot have two constructors that both take a single argument.
Compile time bound
At the time when we create an object, we must specify the name of a concrete class which is known at compile time. There is no way of dynamic binding constructors at run time.
There is no virtual constructor
We cannot declare a virtual constructor. We should specify the exact type of the object at compile time, so that the compiler can allocate memory for that specific type. If we are constructing derived object, the compiler calls the base class constructor first, and the derived class hasn't been initialized yet. This is the reason why we cannot call virtual methods from the constructor.


In general, we can apply this pattern to the cases:

When the client doesn't know the actual class from which subclass to create the object.
When the client wants to delegate the decision of choosing the concrete class to create the object to one of the subclasses.
When the client wants the subclass to specify the concrete class name from which to create an object.

***********************************************************************************************************************************************/

#include <iostream>

class Button {
public:
	virtual void paint() = 0;
};
 
class OSXButton: public Button {
public:
	void paint() {
		std::cout << "OSX button \n";
	}
};
 
class WindowsButton: public Button  {
public:
	void paint() {
		std::cout << "Windows button \n";
	}
};
 
class iPhoneButton: public Button {
public:
	void paint() {
		std::cout << "iPhone button \n";
	}
};

class GUIFactory {
public:
	virtual Button *createButton(char *type) {
		if(strcmp(type,"Windows") == 0) {
			return new WindowsButton;
		}
		else if(strcmp(type,"OSX") == 0) {
			return new OSXButton;
		}
		return NULL;
	}
};

class Factory: public GUIFactory {
		Button *createButton(char *type) {
		if(strcmp(type,"Windows") == 0) {
			return new WindowsButton;
		}
		else if(strcmp(type,"OSX") == 0) {
			return new OSXButton;
		}
		else if(strcmp(type,"iPhone") == 0) {
			return new iPhoneButton;
		}
	}
};

int main()
{
	GUIFactory* guiFactory;
	Button *btn;

	guiFactory = new Factory;

	btn = guiFactory->createButton("OSX");
	btn -> paint();
	btn = guiFactory->createButton("Windows");
	btn -> paint();
	btn = guiFactory->createButton("iPhone");
	btn -> paint();

	return 0;
}