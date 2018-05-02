#include <iostream>
#include <stdlib>

using namespace std;

class IVisitor;

// Element
class {

public:
  virtual void accept(IVisitor*) = 0
};

// Concrete Element
class {
public:
  void accept(IVisitor* visitor);
};
// Concrete Element
class {
public:
  void accept(IVisitor* visitor);
};

// Interface
class IVisitor {
  public:
    // virtual void visit('El concrete element') = 0;
    // virtual void visit() = 0;
};

// Concrete Visitor
class LaserVisitor : public IVisitor {
  void visit() {

  }
};

// Concrete Visitor
class Inyeccion : public IVisitor {
  void visit() {

  }
};

// Concrete Visitor
class PDF : public IVisitor {
  void visit() {

  }
};
// Concrete Visitor
class Postsrcipt : public IVisitor {
  void visit() {

  }
};


int main(){
    return 0;
}

class Main {
public:
    void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters){
      for (int i = 0; i < countDocs; i++){
        for (int j = 0; j < countPrinters; j++){
          d[i].printOn(p[i]);
        }
      }
    }
}
