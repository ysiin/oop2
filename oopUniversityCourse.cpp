#include <iostream>
#include <vector>
using namespace std;


class Student
{
private:
    string name;
    int studentID;

public:
    Student(string name, int studentID)
    {
        this->name = name;
        this->studentID = studentID;
    }

    string getName()
    {
        return name;
    }
    int getID()
    {
        return studentID;
    }
};

class Course
{
private:
    string courseName;
    int max;
    vector<Student> listStudent;

public:
    Course(string courseName, int limit)
    {
        this->courseName = courseName;
        this->max = limit;
    }

    
    bool enroll(Student mahasiswa)
    {
        if (listStudent.size() < max)
        {
            listStudent.push_back(mahasiswa);
            cout << mahasiswa.getName() << " berhasil mendaftar di kelas " << courseName << endl;
            return true;
        }
        cout << "Pendaftaran gagal: kelas " << courseName << " sudah penuh" << endl;
        cout << endl;
        return false;
    }


    bool drop(Student mahasiswa)
    {
        for (auto it = listStudent.begin(); it != listStudent.end(); ++it)
        {
            if (it->getID() == mahasiswa.getID())
            {
                listStudent.erase(it);
                cout << mahasiswa.getName() << " telah keluar dari kelas " << courseName << endl;
                cout << endl;
                return true;
            }
        }
        cout << "Penghapusan gagal: " << mahasiswa.getName() << " tidak terdaftar di kelas " << courseName << endl;
        return false;
    }

    void getEnrolledStudents()
    {
        cout << "Mahasiswa terdaftar di kelas " << courseName << ":" << endl;
        for (auto &mhs : listStudent)
        {
            cout << "- " << mhs.getName() << endl;
        }
    }
};

int main()
{
    Course OOP("Information Security", 2);

    Student aden("Deden", 1234);
    Student yasin("Yaa Siin", 122345);
    Student opal("Opal", 123456);

    OOP.enroll(aden);
    OOP.enroll(yasin);
    OOP.enroll(opal);

    OOP.getEnrolledStudents();

    OOP.drop(aden);
    OOP.getEnrolledStudents();

    return 0;
}