#include <iostream>
#include <vector>

class Student {
public:
    Student(std::string name, int score) : name_(name), score_(score) {}

    // Accessors
    std::string GetName() const { return name_; }
    int GetScore() const { return score_; }

private:
    std::string name_;
    int score_;
};

class Classroom {
private:
    std::vector<Student> students_;

public:
    void AddStudent(const Student& student) {
        students_.push_back(student);
    }

    double CalculateAverageScore() const {
        int sum = 0;
        for (const auto& student : students_) {
            sum += student.GetScore();
        }
        return static_cast<double>(sum) / students_.size();
    }

    Student FindTopStudent() const {
        if (students_.empty()) {
            return Student("", -1); // Suppose -1 signifies no student
        }
        Student topStudent = students_[0];
        for (const auto& student : students_) {
            if (student.GetScore() > topStudent.GetScore()) {
                topStudent = student;
            }
        }
        return topStudent;
    }
};

int main() {
    Classroom classroom;
    classroom.AddStudent(Student("John", 85));
    classroom.AddStudent(Student("Jane", 92));
    classroom.AddStudent(Student("Doe", 76));

    std::cout << "Average Score: " << classroom.CalculateAverageScore() << std::endl;

    Student topStudent = classroom.FindTopStudent();
    std::cout << "Top Student: " << topStudent.GetName() << " with score " << topStudent.GetScore() << std::endl;

    return 0;
}
