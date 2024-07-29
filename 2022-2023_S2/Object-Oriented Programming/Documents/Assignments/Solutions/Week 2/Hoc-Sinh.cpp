#include <bits/stdc++.h>
using namespace std;
struct Student
{
    string name;
    double gradeMath, gradeLiterature;
};
void inputStudent(Student &student);
void averageStudent(Student student);
int main()
{
    Student student;
    inputStudent(student);
    averageStudent(student);
    return 0;
}
void inputStudent(Student &student)
{
    cout << "Nhap ho va ten: ";
    getline(cin,student.name);
    cout << "Nhap diem toan: ";
    cin >> student.gradeMath;
    cout << "Nhap diem van: ";
    cin >> student.gradeLiterature;
}
void averageStudent(Student student)
{
    double average=(student.gradeLiterature+student.gradeMath)/2;
    cout << "Diem trung binh la: " << average;
}