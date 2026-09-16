#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// pre-release definition 
//#define PRE_RELEASE

#ifdef PRE_RELEASE
typedef struct studentData {
    string firstName;
    string lastName;
    string email;
} STUDENT_DATA;
#else
typedef struct studentData {
    string firstName;
    string lastName;

} STUDENT_DATA;
#endif



int main()
{
#ifdef PRE_RELEASE
    cout << "Application Running Pre-release Source Code\n" << endl;
    ifstream inFile("StudentData_Emails.txt");
#else 
    cout << "Application Running Standard Source Code\n" << endl;
    ifstream inFile("StudentData.txt");

#endif 



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
#ifdef PRE_RELEASE
        getline(ss, student.email, ',');
#endif
        
        students.push_back(student);
    }


    #ifdef _DEBUG
    #ifdef PRE_RELEASE 
        for (const STUDENT_DATA& s : students) {
        cout << s.firstName << " " << s.lastName << " " << s.email << endl;
        }
#else
    for (const STUDENT_DATA& s : students) {
        cout << s.firstName << " " << s.lastName <<  endl;
    }
#endif
    #endif


    return 0;
}
