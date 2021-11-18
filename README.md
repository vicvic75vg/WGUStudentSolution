# WGUStudentSolution
### A student roster command-line program written in C++ for C867 - Scripting and Programming at Western Governors University
In this course, I use pointers and an array of pointers to demonstrate the use of effective object-oriented programming by creating a student roster command-line application. The application is able to take in an array of strings of the following: Student ID, first name, last name, email address, age, days remaining in each course, and an enumerated value that represents the course of study.

### How It Works
The program iterates over the array of strings and separates each value by comma using the `Stringstream` type and the `getline()` method to parse the data. Each student is assigned a `Student` object whose pointer is stored in an array of pointers, `classRosterArray`.

The program also implements a `remove()` method that takes in a string of the `studentID` and removes that student from the array of pointers. Other class methods such as `printAverageDaysInCourse(string studentID)`, `printByDegreeProgram(Degree degree)`, `getCurrentRosterSize()`, and `printInvalidEmails()` which uses regular expressions to validate. 

Feel free to look around and tell me what you think!
