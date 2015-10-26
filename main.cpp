#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    int age;
    string birthDate;
    string name;
    string lastName;

public:
    Person() {
    }
    Person(int age, string birthDate, string name, string lastName) {
        this->age = age;
        this->birthDate = birthDate;
        this->name = name;
        this->lastName = lastName;
    }
    ~Person() {
    }
};

class Lecture : public Person
{

public:
    string subject;
    string cafedr;
Lecture() {}
Lecture(int age, string birthDate, string name, string lastName, string subject, string cafedr) : Person( age, birthDate, name, lastName)
{
    this->subject = subject;
    this->cafedr = cafedr;
}
~Lecture(){}


};

class Student : public Person
{

public:
    string course;
    int group;
Student() {}
Student(int age, string birthDate, string name, string lastName, string course, int group) : Person(age, birthDate, name, lastName)
{
    this->course = course;
    this->group = group;
}
~Student(){}

};


class DataBase
{
    vector<Lecture> lectures;
    vector<Student> students;
public:
    void addStudent(int age, string birthDate, string name, string lastName, string course, int group);
    void addLecture(int age, string birthDate, string name, string lastName, string subject, string cafedr);
    void getStudentNum(int num);
    void getLectureNum(int num);
    void getAllStudents();
    void getAllLectures();
    void getAll();
};

void DataBase::addLecture(int age, string birthDate, string name, string lastName, string subject, string cafedr)
{
    Lecture *lecture = new Lecture(age, birthDate, name, lastName, subject, cafedr);
    lectures.push_back(*lecture);
    delete lecture;
}

void DataBase::addStudent(int age, string birthDate, string name, string lastName, string course, int group)
{
    Student *student = new Student(age, birthDate, name, lastName, course, group);
    students.push_back(*student);
    delete student;
}

void DataBase::getStudentNum(int num)
{
    cout << "Cтудент №" << num << endl;
    cout << "Имя: " << students[num - 1].name << endl;
    cout << "Фамилия: " << students[num - 1].lastName << endl;
    cout << "Возраст: " << students[num - 1].age << endl;
    cout << "Дата рождения: " << students[num - 1].birthDate << endl;
    cout << "Направление обучения: " << students[num - 1].course << endl;
    cout << "Группа: " << students[num - 1].group << endl;
}

void DataBase:: getLectureNum(int num)
{
    cout << "Преподаватель №" << num << endl;
    cout << "Имя: " << lectures[num - 1].name << endl;
    cout << "Фамилия: " << lectures[num - 1].lastName << endl;
    cout << "Возраст: " << lectures[num - 1].age << endl;
    cout << "Дата рождения: " << lectures[num - 1].birthDate << endl;
    cout << "Предмет: " << lectures[num - 1].subject << endl;
    cout << "Кафедра: " << lectures[num - 1].cafedr << endl;
}

void DataBase:: getAllLectures()
{
    for (unsigned int i = 0; i< lectures.size(); i++)
    {
        getLectureNum(i+1);
    }
}

void DataBase::getAllStudents()
{
    for (unsigned int i = 0; i< students.size(); i++)
    {
        getStudentNum(i+1);
    }
}

void DataBase::getAll()
{
    getAllLectures();
    cout << endl;
    getAllStudents();
}

int main()
{
    DataBase base;
    int command;
    string name;
    string lastName;
    string birthDate;
    int age;
    string course;
    int group;
    string subject;
    string cafedr;
    int num;

    cout << "Введите команду для работы с базой данных (число)" << endl;
    cout << "1: Добавление студента в базу" << endl;
    cout << "2: Добавление преподавателя в базу" << endl;
    cout << "3: Получение информации о студенте " << endl;
    cout << "4: Получение информации о преподавателе " << endl;
    cout << "5: Получение информации о всех студентах " << endl;
    cout << "6: Получение информации о всех преподавателях " << endl;
    cout << "7: Получение информации о всех в базе " << endl;
    cout << "0: выход" << endl;
    cin >> command;
    while(command)
    {

        switch (command)
        {
        case 1:
            cout << "Введите имя:" << endl;
            cin >> name;
            cout  << "Введите фамилию:" << endl;
            cin >> lastName;
            cout  << "Введите возраст: " << endl;
            cin >> age;
            cout  << "Введите дату рождения: " << endl;
            cin >> birthDate;
            cout  << "Введите направление обучения: " << endl;
            cin >> course;
            cout  << "Введите группу: " << endl;
            cin >> group;
            base.addStudent(age,birthDate,name,lastName,course,group);

            break;
        case 2:
            cout << "Введите имя:" << endl;
            cin >> name;
            cout  << "Введите фамилию:" << endl;
            cin >> lastName;
            cout  << "Введите возраст: " << endl;
            cin >> age;
            cout  << "Введите дату рождения: " << endl;
            cin >> birthDate;
            cout  << "Введите предмет: " << endl;
            cin >> subject;
            cout  << "Введите кафедру: " << endl;
            cin >> cafedr;
            base.addLecture(age,birthDate,name,lastName,subject,cafedr);
            break;
        case 3:
            cout << "Введите номер:" << endl;
            cin >> num;
            base.getStudentNum(num);

            break;
        case 4:
            cout << "Введите номер:" << endl;
            cin >> num;
            base.getLectureNum(num);
            break;
        case 5:
            base.getAllStudents();
            break;
        case 6:
            base.getAllLectures();
            break;
        case 7:
            base.getAll();
            break;
        }


        cout << "Введите команду для работы с базой данных (число)" << endl;
        cout << "1: Добавление студента в базу" << endl;
        cout << "2: Добавление преподавателя в базу" << endl;
        cout << "3: Получение информации о студенте " << endl;
        cout << "4: Получение информации о преподавателе " << endl;
        cout << "5: Получение информации о всех студентах " << endl;
        cout << "6: Получение информации о всех преподавателях " << endl;
        cout << "7: Получение информации о всех в базе " << endl;
        cout << "0: выход" << endl;
        cin >> command;
    }

    return 0;
}

