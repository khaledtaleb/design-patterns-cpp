/*
 * C++ Design Patterns: Decorator
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>

/*
 * Component
 * defines an interface for objects that can have responsibilities
 * added to them dynamically
 */
class Component {
public:
  virtual void operation() = 0;
  virtual ~Component(){}
  // ...
};

/*
 * Concrete Component
 * defines an object to which additional responsibilities
 * can be attached
 */
class ConcreteComponent : public Component {
public:
  void operation() {
    std::cout << "Concrete Component operation" << std::endl;
  }
  // ...
};

/*
 * Decorator
 * maintains a reference to a Component object and defines an interface
 * that conforms to Component's interface
 */
class Decorator : public Component {
public:
  Decorator(Component *c)
    : component(c) {}

  virtual void operation() {
    component->operation();
  }
  
  ~Decorator() {
    delete component;
  }
  // ...

private:
  Component *component;
};

/*
 * Concrete Decorators
 * add responsibilities to the component (can extend the state
 * of the component)
 */
class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(Component *c)
    : Decorator(c) {}

  void operation() {
    Decorator::operation();
    std::cout << "Decorator A" << std::endl;
  }
  // ...
};

class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(Component *c)
    : Decorator(c) {}

  void operation() {
    Decorator::operation();
    std::cout << "Decorator B" << std::endl;
  }
  // ...
};


int main()
{
  Component *component = new ConcreteDecoratorA(
              new ConcreteDecoratorB(new ConcreteComponent));

  component->operation();
  delete component;

  return 0;
}
