/*

Composite Pattern

Compose objects into tree structures to represent whole-part hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.
Recursive composition
"Directories contain entries, each of which could be a directory."
1-to-many "has a" up the "is a" hierarchy

Problem:
Application needs to manipulate a hierarchical collection 
of "primitive" and "composite" objects. Processing of a primitive object 
is handled one way, and processing of a composite object is handled differently. 
Having to query the "type" of each object before attempting to process it 
is not desirable.

Identify the scalar/primitive classes and vector/container classes
Create an "interface" (lowest common denominator) that can make all concrete classes "interchangeable"
All concrete classes declare an "is a" relationship to the interface
All "container" classes couple themselves to the interface (recursive composition, Composite "has a" set of children up the "is a" hierarchy)
"Container" classes use polymorphism as they delegate to their children

*/

#include <iostream>
#include <vector>
using namespace std;

// 2. Create an "interface" (lowest common denominator)
class Component
{
  public:
    virtual void traverse() = 0;
};

class Leaf: public Component
{
    // 1. Scalar class   3. "isa" relationship
    int value;
  public:
    Leaf(int val)
    {
        value = val;
    }
    void traverse()
    {
        cout << value << ' ';
    }
};

class Composite: public Component
{
    // 1. Vector class   3. "isa" relationship
    vector < Component * > children; // 4. "container" coupled to the interface
  public:
    // 4. "container" class coupled to the interface
    void add(Component *ele)
    {
        children.push_back(ele);
    }
    void traverse()
    {
        for (int i = 0; i < children.size(); i++)
        // 5. Use polymorphism to delegate to children
          children[i]->traverse();
    }
};

int main()
{
  Composite containers[4];

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      containers[i].add(new Leaf(i *3+j));

  for (i = 1; i < 4; i++)
    containers[0].add(&(containers[i]));

  for (i = 0; i < 4; i++)
  {
    containers[i].traverse();
    cout << endl;
  }
}

/*
OUTPUT:

0 1 2 3 4 5 6 7 8 9 10 11
3 4 5
6 7 8
9 10 11

*/