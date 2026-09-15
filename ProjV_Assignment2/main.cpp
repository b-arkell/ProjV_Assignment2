#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



typedef struct studentData {
    string firstName;
    string lastName;

} STUDENT_DATA;


int main()
{
    ifstream inFile("StudentData.txt");

    if (!inFile.is_open()) {
        cout << "The file did not open properly..."  << endl;
        return 0;
    }
    vector<STUDENT_DATA> students;

    string line;

    while (getline(inFile, line)) {

        stringstream ss(line);
        string field;   

        STUDENT_DATA student;

        getline(ss, student.firstName, ',');
        getline(ss, student.lastName, ',');
        
        students.push_back(student);

    }


    #ifdef _DEBUG
    for (const STUDENT_DATA& s : students) {
        cout << s.firstName << " " << s.lastName << endl;
        }
    #endif


    return 0;
}
