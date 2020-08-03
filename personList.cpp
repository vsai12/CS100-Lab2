#include "personList.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

PersonList::PersonList(){
    capacity = 2;
    numPeople = 0;
    theList = new Person*[capacity];
}

PersonList::~PersonList(){
    //delete[] theList;
    int i = 0;
    while(i < numPeople) {
        delete theList[i];
        i++;
    }
}

void PersonList::addPerson(string child_name, string father_name, string mother_name){ //name changed to string
    Person *father = 0;
    Person *mother = 0;
    
    // try to find the three names in the theList
    for(int i = 0; i < numPeople; i++){
        if(theList[i]->getName() == child_name){ //change strcmp to reg comparison with str
            cout << "ERROR: " << child_name << " already has parents!!!";
            return;
        } else if(theList[i]->getName() == father_name) { //change strcmp to reg comparison with str
            father = theList[i];
        } else if(theList[i]->getName() == mother_name) { //change strcmp to reg comparison with str
            mother = theList[i];
        }
    }
   
    if(father == 0){
      // father_name is not in the theList so create a new person
      father = new Person(father_name, 0, 0);
      insertIntoList(father);
    }
    if(mother == 0){
      // mother_name is not in the theList so create a new person
      mother = new Person(mother_name, 0, 0);
      insertIntoList(mother);
    }
    Person *newChild = new Person(child_name, father, mother);
    insertIntoList(newChild);
    father->addChild(newChild);
    mother->addChild(newChild);
}

void PersonList::insertIntoList(Person *newPerson){
    if(numPeople == capacity) expand(&theList, capacity);

    theList[numPeople++] = newPerson;
}

void PersonList::printLineage(string personName){ //change to string too
    for(int i = 0; i < numPeople; i++) {
        if(theList[i]->getName() == personName){ //edited to str compare to find the person and print lineage
            theList[i]->printAncestors();
            theList[i]->printDecendents();
            return;
        }
    }
    cout << endl << personName << " is not in the list!" << endl;
}
