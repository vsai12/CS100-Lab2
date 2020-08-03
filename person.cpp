#include "person.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Person::Person(string name, Person* father, Person* mother){
    this->name = name;  //changing the char functions to suit string
    this->father = father;
    this->mother = mother;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}


Person::~Person(){
    delete[] children;
}

void Person::addChild(Person *newChild){
    if(numChildren == capacity) expand(&children, capacity);
    children[numChildren++] = newChild;
}

void Person::printAncestors(){
    cout << endl << "Ancestors of " << name << endl;
    printLineage('u', 0);
}

void Person::printDecendents(){
    cout << endl << "Decendents of " << name << endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level){
    string temp = compute_relation(level);

    if(dir == 'd'){
        for(int i = 0; i < numChildren; i++){
            cout << temp << "child: " << children[i]->getName() << endl;
            children[i]->printLineage(dir, level + 1);
        }
    } else {
        if(mother){
            cout << temp << "mother: " << mother->getName() << endl;
            mother->printLineage(dir, level + 1);
        }
        if(father){
            cout << temp << "father: " << father->getName() << endl;
            father->printLineage(dir, level + 1);
        }
    }
}

/* helper function to compute the lineage
* if level = 0 then returns the empty string
* if level >= 1 then returns ("great ")^(level - 1) + "grand "
*/
//changed to string since the new chars weren't being deleted
string Person::compute_relation(int level){
    if(level == 0) return "";

    string temp = "grand ";

    for(int i = 2; i <= level; i++){
        string temp2 = "great ";
        temp2 += temp;
        temp = temp2;
    }
    return temp;
}

/* non-member function which doubles the size of t
 * NOTE: t's type will be a pointer to an array of pointers
 */
//add delete temp
void expand(Person ***t, int& MAX){
  Person **temp = new Person*[2 * MAX];
  memcpy(temp, *t, MAX * sizeof(**t));
  delete[] *t;
  *t = temp;
  MAX *= 2;
}
