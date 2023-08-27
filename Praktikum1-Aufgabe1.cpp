#include <iostream>

using namespace std;

struct student
{

    int m_nr;
    int year;
    string name;
    string surname;
    string email;
    string degree;
    bool taskPassed[6];

};


void set_data(student &student1)
{


    student1.m_nr = 3117193;
    student1.year = 2019;
    student1.name = "Alara";
    student1.surname = "Ciyrak";
    student1.email = "alara.ciyrak@stud.uni-due.de";
    student1.degree = "Computer Enginnering";
    student1.taskPassed[6];

    int n;
    for (n=0; n<6; n++)
        if (n = 0)
            student1.taskPassed[n] = 1;
        else
            student1.taskPassed[n] = 0;


}

void input_email_address(student &student1)
{

    cout << "Please enter email address: " << ends;
    cin >> student1.email;

}

void set_task_passed(student &student1)
{
    student1.taskPassed[0]= true;


}


void output(student &student1)

{


    cout << "M. Nummer: " << student1.m_nr << endl;
    cout << "Name: " << student1.name << " " << student1.surname << endl;
    cout << "Email Address: " << student1.email << endl;
    cout << "Course of Studies: " << student1.degree << endl;
    cout << "Start of Studies: " << student1.year << endl;
    cout << "Tasks Passed: " ;
    int a;
    for(a=1; a<7; a++)
        {cout << a <<" " ;
        if (student1.taskPassed[a-1] == 0)
            cout << "False " ;
        else
            cout << "True " ;
        }


}


int main(void)

{
    student student1;
    output(student1);
    set_data(student1);
    input_email_address(student1);
    set_task_passed(student1);
    output(student1);


    return 0;


}

