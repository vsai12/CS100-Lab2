#ifndef __PERSONLIST_H__
#define __PERSONLIST_H__
#include "person.h"

class PersonList{
    private:
      Person **theList; // array of pointers to person objects
      int numPeople; // current number of people in theList
      int capacity; // capacity of theList array

    public:
        PersonList();
        ~PersonList();
        void addPerson(string child_name, string father_name, string mother_name); //name changed to string
        void insertIntoList(Person *newPerson);
        void printLineage(string personName); //changed to string
};
#endif // __PERSONLIST_H__
