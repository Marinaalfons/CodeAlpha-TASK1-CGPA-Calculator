#include <iostream>
#include <cstdlib>

using namespace std;

void processSemester(int number_of_courses, char grade[], int credit_hours[],string name[]
,double grade_points[],double& total_credits, double& total_grade_points) {
	
for(int n = 0; n < number_of_courses; n++) {
cout << "please enter the name of course " << n + 1 << " :";
cin >> name[n];
cout << "please enter the grade (A/B/C/D/f) for course " << name[n] << " :";
cin >> grade[n];

while(grade[n] != 'A' && grade[n] != 'a' &&grade[n] != 'B' && grade[n] != 'b' 
&&grade[n] != 'C' && grade[n] != 'c' &&grade[n] != 'D' && grade[n] != 'd' &&grade[n] != 'F' && grade[n] != 'f') {
	
cout << "please enter the correct grade (A/B/C/D/F) for course " << n << " :";
cin >> grade[n]; }
 
switch(grade[n]) {
case 'A': case 'a': grade_points[n] = 4.0; break;
case 'B': case 'b': grade_points[n] = 3.0; break;
case 'C': case 'c': grade_points[n] = 2.0; break;
case 'D': case 'd': grade_points[n] = 1.0; break;
case 'F': case 'f': grade_points[n] = 0.0; break; }

cout << "please enter credit hours for course " << name[n] << " :";
cin >> credit_hours[n];

while (credit_hours[n] <= 0) {
cout << "please enter correct credit hours for course " << name[n] << " :";
cin >> credit_hours[n];}
cout << "-------------------------------------------------------------" << endl;

total_credits += credit_hours[n];
total_grade_points += (credit_hours[n] * grade_points[n]);}
}

int main() {
int number_of_courses, number_of_courses_2;
double total_credits = 0, total_grade_points = 0;
double total_credits_2 = 0, total_grade_points_2 = 0;
double GPA, GPA_2, CGPA;

//semester1
cout << "please enter the number of courses (semester 1)  =  " ;
cin >> number_of_courses;
cout << "_____________________________________________________________" << endl;

char grade[number_of_courses];
int credit_hours[number_of_courses];
string name[number_of_courses];
double grade_points[number_of_courses];
processSemester(number_of_courses, grade, credit_hours, name, grade_points, total_credits, total_grade_points);

//semester2
cout << "*************************************************************" << endl;
cout << "please enter the number of courses (semester 2)  =  " ;
cin >> number_of_courses_2;
cout << "_____________________________________________________________" << endl;

char grade_2[number_of_courses_2];
int credit_hours_2[number_of_courses_2];
string name_2[number_of_courses_2];
double grade_points_2[number_of_courses_2];
processSemester(number_of_courses_2, grade_2, credit_hours_2, name_2, grade_points_2, total_credits_2, total_grade_points_2);

GPA = total_grade_points / total_credits;
GPA_2 = total_grade_points_2 / total_credits_2;
CGPA = (total_grade_points + total_grade_points_2) / (total_credits + total_credits_2);


system("cls");

cout << "\nCourses - Semester 1:\n";
for (int n = 0; n < number_of_courses; n++) {cout << "- " << name[n] << " | Grade: " << grade[n] 
<< " | Credit Hours: " << credit_hours[n]<< " | Grade Points: " << grade_points[n] << endl;}

cout << "\nCourses - Semester 2:\n";
for (int i = 0; i < number_of_courses_2; i++) {cout << "- " << name_2[i] << " | Grade: " << grade_2[i]
<< " | Credit Hours: " << credit_hours_2[i]<< " | Grade Points: " << grade_points_2[i] << endl;}

cout << "\nGPA for Semester 1: " << GPA<< "\nGPA for Semester 2: " << GPA_2;
cout << "\nFinal Cumulative GPA (CGPA): " << CGPA << endl;

return 0;}
