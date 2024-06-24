#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

unordered_map<string, Course> courses;

bool loadDataFromFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream stream(line);
        string courseNumber, courseName, prerequisite;
        getline(stream, courseNumber, ',');
        getline(stream, courseName, ',');

        Course course;
        course.courseNumber = courseNumber;
        course.courseName = courseName;

        while (getline(stream, prerequisite, ',')) {
            course.prerequisites.push_back(prerequisite);
        }

        courses[courseNumber] = course;
    }

    file.close();
    return true;
}

void printCourseList() {
    vector<string> courseNumbers;
    for (const auto& pair : courses) {
        courseNumbers.push_back(pair.first);
    }

    sort(courseNumbers.begin(), courseNumbers.end());

    cout << "Here is a sample schedule:" << endl;
    for (const string& courseNumber : courseNumbers) {
        const Course& course = courses[courseNumber];
        cout << course.courseNumber << ", " << course.courseName << endl;
    }
}

void printCourseInfo(string courseNumber) {
    if (courses.find(courseNumber) == courses.end()) {
        cout << "Course not found." << endl;
        return;
    }

    const Course& course = courses[courseNumber];
    cout << course.courseNumber << ", " << course.courseName << endl;
    if (course.prerequisites.empty()) {
        cout << "No prerequisites." << endl;
    }
    else {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void displayMenu() {
    cout << "Welcome to the course planner." << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
}

int main() {
    int choice;
    string filename;
    string courseNumber;

    do {
        displayMenu();
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the file name to load: ";
            cin >> filename;
            if (loadDataFromFile(filename)) {
                cout << "Data loaded successfully." << endl;
            }
            else {
                cout << "Failed to load data." << endl;
            }
            break;

        case 2:
            printCourseList();
            break;

        case 3:
            cout << "What course do you want to know about? ";
            cin >> courseNumber;
            printCourseInfo(courseNumber);
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
        }

    } while (choice != 9);

    return 0;
}
