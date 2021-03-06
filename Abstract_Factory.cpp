/********************************************

Abstract Factory 
Provide an interface for creating families of related or dependent objects without specifying their concrete classes.
Factories and products are the key elements to Abstract Factory pattern. 
Also the word families used in the definition distinguishes Abstract Factory pattern from other creational patterns, which involve only one kind of object.

********************************************/

#include <iostream>

class Button
{
public:
	virtual void paint() = 0;
};
 
class WinButton : public Button 
{
public:
	void paint (){
		std::cout << " Window Button \n";
       }
};
 
class MacButton : public Button 
{
public:
	void paint (){
		std::cout << " Mac Button \n";
       }
};

class iPhoneButton : public Button 
{
public:
	void paint (){
		std::cout << " iPhone Button \n";
       }
};

class ScrollBar 
{
public:
	virtual void paint() = 0;
};
 
class WinScrollBar : public ScrollBar 
{
public:
	void paint (){
		std::cout << " Window ScrollBar \n";
       }
};
 
class MacScrollBar : public ScrollBar 
{
public:
	void paint (){
		std::cout << " Mac ScrollBar \n";
       }
};

class iPhoneScrollBar : public ScrollBar
{
public:
	void paint (){
		std::cout << " iPhone ScrollBar \n";
       }
};


class GUIFactory 
{
public:
	virtual Button* createButton () = 0;
	virtual ScrollBar* createScrollBar () = 0;
};
 
class WinFactory : public GUIFactory 
{
public:
	Button* createButton (){
		return new WinButton;
	}
	ScrollBar* createScrollBar (){
		return new WinScrollBar;
	}
};
 
class MacFactory : public GUIFactory 
{
public:
	Button* createButton (){
		return new MacButton;
	}
	ScrollBar* createScrollBar (){
		return new MacScrollBar;
	}
};
 
class iPhoneFactory : public GUIFactory 
{
public:
	Button* createButton (){
		return new iPhoneButton;
	}
	ScrollBar* createScrollBar (){
		return new iPhoneScrollBar;
	}
};

int main()
{
	GUIFactory* guiFactory;
	Button *btn;
	ScrollBar *sb;

	guiFactory = new MacFactory;
	btn = guiFactory->createButton();
	btn -> paint();
	sb = guiFactory->createScrollBar();
	sb -> paint();

	guiFactory = new WinFactory;
	btn = guiFactory->createButton();
	btn -> paint();
	sb = guiFactory->createScrollBar();
	sb -> paint();

	guiFactory = new iPhoneFactory;
	btn = guiFactory->createButton();
	btn -> paint();
	sb = guiFactory->createScrollBar();
	sb -> paint();

	return 0;
}

/****************************

Abstract Factory Pattern vs Factory Method
What's the difference between Abstract Factory Pattern and Factory Method?

Abstract Factory design pattern creates Factory.
Factory design pattern creates Products.

**************************************************/