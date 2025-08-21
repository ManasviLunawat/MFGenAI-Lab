/* INCLUSION AND EXCLUSION PRINCIPLE
Write a program to implement principle of Inclusion and
Exclusion for finding student participation in Sports Club and Music Club in a university
survey.The university has 200 students, and the data collected from the survey is as follows:
● 120 students are members of the Sports Club.
● 90 students are members of the Music Club.
● 50 students are members of both the Sports Club and the Music Club.
Using the Inclusion-Exclusion Principle, Perform following tasks :
● The total number of students who are members of at least one of the clubs (either Sports
Club, Music Club, or both).
● The number of students who are only members of the Sports Club.
● The number of students who are only members of the Music Club.
● The number of students who are members of neither of the two clubs.
*/

#include <iostream>
using namespace std;
int main() {
    int total, sportsClub, musicClub, bothClubs;

    //Take Inputs
    cout<<"Enter the total number of students: ";
    cin>>total;

    cout<<"Enter the number of students in Sports Club: ";
    cin>>sportsClub;

    cout<<"Enter the number of students in Music Club: ";
    cin >>musicClub;

    cout<<"Enter the number of students in BOTH clubs: ";
    cin>>bothClubs;

    //Applying Inclusion-Exclusion Principle
    int atleastOne = sportsClub + musicClub - bothClubs;    // Students in Sports or Music
    int onlySports = sportsClub - bothClubs;                         // Only Sports club members
    int onlyMusic = musicClub - bothClubs;                          // Only Music club members
    int neither = total - atleastOne;                                      // Students in none of the clubs

    //Displaying final results
    cout<<"\n=== Survey Result ===\n";
    cout<<"1) Students in at least one club : "<< atleastOne<<endl;
    cout<<"2) Students only in Sports Club  : "<< onlySports<<endl;
    cout<<"3) Students only in Music Club   : "<< onlyMusic<<endl;
    cout<<"4) Students in neither club      : "<< neither<<endl;

    return 0;
}
