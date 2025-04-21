#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Student {
protected:
    std::string firstName;
    std::string lastName;
    double gpa;
    int graduationYear;
    std::string graduationSemester;
    int enrolledYear;
    std::string enrolledSemester;
    std::string degreeLevel;

public:
    Student() : firstName(""), lastName(""), gpa(0.0), graduationYear(0), 
                graduationSemester(""), enrolledYear(0), enrolledSemester(""), 
                degreeLevel("undergrad") {}

    virtual ~Student() {}

    std::string getName() const { return firstName + " " + lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    double getGPA() const { return gpa; }
    int getGraduationYear() const { return graduationYear; }
    std::string getGraduationSemester() const { return graduationSemester; }
    int getEnrolledYear() const { return enrolledYear; }
    std::string getEnrolledSemester() const { return enrolledSemester; }
    std::string getDegreeLevel() const { return degreeLevel; }

    void setName(const std::string& first, const std::string& last) {
        firstName = first;
        lastName = last;
    }
    void setGPA(double g) { gpa = g; }
    void setGraduationYear(int year) { graduationYear = year; }
    void setGraduationSemester(const std::string& semester) { graduationSemester = semester; }
    void setEnrolledYear(int year) { enrolledYear = year; }
    void setEnrolledSemester(const std::string& semester) { enrolledSemester = semester; }
    void setDegreeLevel(const std::string& level) { degreeLevel = level; }

    virtual void writeToFile(std::ofstream& outfile) const {
        outfile << "Name: " << getName() << "\n";
        outfile << "GPA: " << gpa << "\n";
        outfile << "Enrolled: " << enrolledSemester << " " << enrolledYear << "\n";
        outfile << "Expected Graduation: " << graduationSemester << " " << graduationYear << "\n";
        outfile << "Degree Level: " << degreeLevel << "\n";
    }
};

class Art_Student : public Student {
private:
    std::string artEmphasis;

public:
    Art_Student() : Student(), artEmphasis("Art Studio") {}

    ~Art_Student() override {}

    std::string getArtEmphasis() const { return artEmphasis; }

    void setArtEmphasis(const std::string& emphasis) {
        if (emphasis == "Art Studio" || emphasis == "Art History" || emphasis == "Art Education") {
            artEmphasis = emphasis;
        } else {
            artEmphasis = "Art Studio";
        }
    }

    void writeToFile(std::ofstream& outfile) const override {
        Student::writeToFile(outfile);
        outfile << "Art Emphasis: " << artEmphasis << "\n";
        outfile << "------------------------\n";
    }
};

class Physics_Student : public Student {
private:
    std::string concentration;

public:
    Physics_Student() : Student(), concentration("Biophysics") {}

    ~Physics_Student() override {}

    std::string getConcentration() const { return concentration; }

    void setConcentration(const std::string& conc) {
        if (conc == "Biophysics" || conc == "Earth and Planetary Sciences") {
            concentration = conc;
        } else {
            concentration = "Biophysics";
        }
    }

    void writeToFile(std::ofstream& outfile) const override {
        Student::writeToFile(outfile);
        outfile << "Concentration: " << concentration << "\n";
        outfile << "------------------------\n";
    }
};

int main() {
    std::vector<Art_Student*> art_students;
    std::vector<Physics_Student*> physics_students;

    Art_Student* art1 = new Art_Student();
    art1->setName("Jonathan", "Tessema");
    art1->setGPA(3.8);
    art1->setEnrolledYear(2020);
    art1->setEnrolledSemester("Fall");
    art1->setGraduationYear(2024);
    art1->setGraduationSemester("Spring");
    art1->setDegreeLevel("undergrad");
    art1->setArtEmphasis("Art Studio");
    art_students.push_back(art1);

    Art_Student* art2 = new Art_Student();
    art2->setName("Lebron", "James");
    art2->setGPA(3.5);
    art2->setEnrolledYear(2019);
    art2->setEnrolledSemester("Spring");
    art2->setGraduationYear(2023);
    art2->setGraduationSemester("Fall");
    art2->setDegreeLevel("grad");
    art2->setArtEmphasis("Art History");
    art_students.push_back(art2);

    Art_Student* art3 = new Art_Student();
    art3->setName("Cristiano", "Ronaldo");
    art3->setGPA(3.9);
    art3->setEnrolledYear(2021);
    art3->setEnrolledSemester("Fall");
    art3->setGraduationYear(2025);
    art3->setGraduationSemester("Spring");
    art3->setDegreeLevel("undergrad");
    art3->setArtEmphasis("Art Education");
    art_students.push_back(art3);

    Art_Student* art4 = new Art_Student();
    art4->setName("Lionel", "Messi");
    art4->setGPA(3.2);
    art4->setEnrolledYear(2020);
    art4->setEnrolledSemester("Summer");
    art4->setGraduationYear(2024);
    art4->setGraduationSemester("Spring");
    art4->setDegreeLevel("grad");
    art4->setArtEmphasis("Art Studio");
    art_students.push_back(art4);

    Art_Student* art5 = new Art_Student();
    art5->setName("Declan", "Rice");
    art5->setGPA(4.0);
    art5->setEnrolledYear(2022);
    art5->setEnrolledSemester("Spring");
    art5->setGraduationYear(2026);
    art5->setGraduationSemester("Spring");
    art5->setDegreeLevel("undergrad");
    art5->setArtEmphasis("Art History");
    art_students.push_back(art5);

    Physics_Student* phys1 = new Physics_Student();
    phys1->setName("Thomas", "Muller");
    phys1->setGPA(3.7);
    phys1->setEnrolledYear(2018);
    phys1->setEnrolledSemester("Fall");
    phys1->setGraduationYear(2022);
    phys1->setGraduationSemester("Spring");
    phys1->setDegreeLevel("grad");
    phys1->setConcentration("Biophysics");
    physics_students.push_back(phys1);

    Physics_Student* phys2 = new Physics_Student();
    phys2->setName("Suni", "Lee");
    phys2->setGPA(3.9);
    phys2->setEnrolledYear(2020);
    phys2->setEnrolledSemester("Fall");
    phys2->setGraduationYear(2024);
    phys2->setGraduationSemester("Spring");
    phys2->setDegreeLevel("undergrad");
    phys2->setConcentration("Earth and Planetary Sciences");
    physics_students.push_back(phys2);

    Physics_Student* phys3 = new Physics_Student();
    phys3->setName("Tony", "Stark");
    phys3->setGPA(3.4);
    phys3->setEnrolledYear(2021);
    phys3->setEnrolledSemester("Spring");
    phys3->setGraduationYear(2025);
    phys3->setGraduationSemester("Spring");
    phys3->setDegreeLevel("grad");
    phys3->setConcentration("Biophysics");
    physics_students.push_back(phys3);

    Physics_Student* phys4 = new Physics_Student();
    phys4->setName("Barack", "Obama");
    phys4->setGPA(3.6);
    phys4->setEnrolledYear(2019);
    phys4->setEnrolledSemester("Fall");
    phys4->setGraduationYear(2023);
    phys4->setGraduationSemester("Fall");
    phys4->setDegreeLevel("grad");
    phys4->setConcentration("Earth and Planetary Sciences");
    physics_students.push_back(phys4);

    Physics_Student* phys5 = new Physics_Student();
    phys5->setName("Cole", "Palmer");
    phys5->setGPA(3.1);
    phys5->setEnrolledYear(2022);
    phys5->setEnrolledSemester("Spring");
    phys5->setGraduationYear(2026);
    phys5->setGraduationSemester("Spring");
    phys5->setDegreeLevel("undergrad");
    phys5->setConcentration("Biophysics");
    physics_students.push_back(phys5);

    std::ofstream outfile("student_info.dat");
    if (outfile.is_open()) {
        outfile << "ART STUDENTS\n========================\n";
        for (const auto& student : art_students) {
            student->writeToFile(outfile);
        }

        outfile << "\nPHYSICS STUDENTS\n========================\n";
        for (const auto& student : physics_students) {
            student->writeToFile(outfile);
        }

        outfile.close();
        std::cout << "Student information written to student_info.dat\n";
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }

    for (auto student : art_students) {
        delete student;
    }
    for (auto student : physics_students) {
        delete student;
    }

    return 0;
}