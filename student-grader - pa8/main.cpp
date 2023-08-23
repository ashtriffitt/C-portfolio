#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// student struct
struct Student {
string name;
vector<int> grades;
};

int main() {

  // original version of gradebook container
  vector<pair<string, vector<int>>> grades = 
  {{"Ashton", {50, 23, 55, 0, 33, 45, 32}},
  {"Libby", {0, 0, 0, 43, 50, 52, 45}},
  {"Gus", {50, 52, 47, 35, 46, 23, 45}}};

  // prints first gradebook container
  for (pair<string, vector<int>> students : grades) {
    cout << "Name: " << students.first << " Grades: ";
    for (int i = 0; i < students.second.size(); i++) {
      cout << students.second.at(i) << " ";
    }
    cout << "\n";
  }

  // Gets assignment averages and prints them
  for (int i = 0; i < 7; i++) {
    cout << "Assignment" << i << " average: ";
    int running_total = 0;
    for (int j = 0; j < grades.size(); j++) {
      running_total += grades[j].second.at(i);
    }
    cout << running_total / grades.size() << "\n";
  }

  // Gets student averages and adds them to a vector.
  vector<double> student_averages;
  for (int i = 0; i < grades.size(); i++) {
    double avg;
    int running_total = 0;
    for (int j = 0; j < grades[i].second.size(); j++) {
      running_total += grades[i].second.at(j);
    }
    avg = running_total / 7;
    student_averages.push_back(avg);
  }

  // Initializes students and new container.
  vector<pair<Student, double>> grades_averages;
  Student student1 = {"Ashton", {50, 23, 55, 0, 33, 45, 32}};
  Student student2 = {"Libby", {0, 0, 0, 43, 50, 52, 45}};
  Student student3 = {"Gus", {50, 52, 47, 35, 46, 23, 45}};

  grades_averages.push_back({student1, student_averages[0]});
  grades_averages.push_back({student2, student_averages[1]});
  grades_averages.push_back({student3, student_averages[2]});

  // SOrts the studetns by average in descending order
  sort(grades_averages.begin(), grades_averages.end(), [](const pair<Student, double> &left, const pair<Student, double> &right)   
  {return left.second > right.second; }); 

  // Prints final container.
  for (pair<Student, double> students : grades_averages) {
    cout << "Name: " << students.first.name << " Grades: ";
    for (int i = 0; i < students.first.grades.size(); i++) {
      cout << students.first.grades.at(i) << " ";
    }
    cout << "Average: " << students.second;
    cout << "\n";
  }
  
}