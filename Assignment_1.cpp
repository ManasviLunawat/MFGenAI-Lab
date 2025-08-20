/* SET OPERATIONS
Write a program to implement set operations to manage membership in
school clubs.
A school has two clubs: the Drama Club and the Science Club.
Set A={students in the Drama Club}
Set B={students in the Science Club}
Perform following tasks :
1.Find Students in at least one club.
2. Find Students in both clubs.
3. Find students in the Drama Club but not in the Science Club.
4. Find Students in the Science Club but not in the Drama Club.
5. If a student is not a member of any club */

#include<iostream>
using namespace std;

int main() {
    int i, j, x, y, z;
    
    //Take input for total number of students from user
    cout<<"Enter the total number of students: ";
    cin>>x;
    int setu[x];
    
    //Input for Roll no.s of total students
    cout<<"\nEnter the roll numbers of total students:\n";
    for (i = 0; i<x; i++) {
        cin>>setu[i];
    }
    
    //Take input for number of students in Drama club from user
    cout<<"\nEnter the number of students in Drama Club: ";
    cin>>y;
    int setA[y];
    
    //Input for Roll no.s of Drama club students
    cout<<"\nEnter the roll numbers of students in Drama Club:\n";
    for (i = 0; i<y; i++) {
        cin>>setA[i];
    }
    
    //Take input for number of students in Science club from user
    cout<<"\nEnter the number of students in Science Club: ";
    cin>>z;
    int setB[z];
    
    //Input for Roll no.s of Science club students
    cout<<"\nEnter the roll numbers of students in Science Club:\n";
    for (i = 0; i<z; i++) {
        cin>>setB[i];
    }

    //Display all sets
    cout<<"\nDisplaying the Sets";
    cout<<"\nSet U (Total Students): \n";
    for (i = 0; i<x; i++) {
        cout<<setu[i]<<"\t";
    }
    
    cout<<"\nSet A (Drama Club): \n";
    for (i = 0; i<y; i++) {
        cout<<setA[i]<<"\t";
    }

    cout<<"\nSet B (Science Club): \n";
    for (i = 0; i<z; i++) {
        cout<<setB[i]<<"\t";
    }
    
    //Students in at least one club (Union)
    cout<<"\n\nStudents in at least one club (Union):\n";
    //Print Drama Club students
    for (i = 0; i < y; i++) {
        cout << setA[i] << "\t";
    }
    //Print Science Club students that are not in Drama Club
    for (i = 0; i < z; i++) {
        bool found = false;
        for (j = 0; j < y; j++) {
            if (setB[i] == setA[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << setB[i] << "\t";
        }
    }
    
    //Students in both clubs (Intersection)
    cout<<"\n\nStudents in both clubs (Intersection):\n";
    for (i = 0; i<y; i++) {
        for (j = 0; j<z; j++) {
            if (setA[i] == setB[j]) {
                cout<<setA[i] << "\t";
                break;
            }
        }
    }

    //Students in Drama Club but not in Science Club
    cout<<"\n\nStudents in Drama Club but not in Science Club:\n";
    for (i = 0; i < y; i++) {
        bool found = false;
        for (j = 0; j< z; j++) {
            if (setA[i] == setB[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout<<setA[i] << "\t";
        }
    }

    //Students in Science Club but not in Drama Club
    cout<<"\n\nStudents in Science Club but not in Drama Club:\n";
    for (i = 0; i < z; i++) {
        bool found = false;
        for (j = 0; j < y; j++) {
            if (setB[i] == setA[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout<<setB[i] << "\t";
        }
    }

    // Students not in any club
    cout<<"\n\nStudents not in any club:\n";
    //First step compute union into a temporary array
    int unionAB[x];
    int unionCount = 0;
    
    //Add Drama Club students to the union
    for (i = 0; i < y; i++) {
        unionAB[unionCount++] = setA[i];
    }

    //Add Science Club students to the union if not already there
    for (i = 0; i < z; i++) {
        bool found = false;
        for (j = 0; j < y; j++) {
            if (setB[i] == setA[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unionAB[unionCount++] = setB[i];
        }
    }

    //Print students who are in total but not in the union
    for (i = 0; i < x; i++) {
        bool found = false;
        for (j = 0; j<unionCount; j++) {
            if (setu[i] == unionAB[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << setu[i] << "\t";
        }
    }
    
    cout<<endl;
    return 0;
}
