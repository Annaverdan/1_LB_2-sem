#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 100; // Максимальное количество студентов

struct Student {
    string full_name_FIO;
    string gender;
    string number_group;
    int number_list;
    int exam_grades[3];
    int test_grades[5];
    float getGender(int b) {
        int a;
        float t = 3.14;
        return t;
    }
};

Student students[MAX_STUDENTS];
int student_count = 0;

void new_entry_student() {
    if (student_count >= MAX_STUDENTS) {
        cout << "Достигнуто максимальное количество студентов!" << endl;
        return;
    }
    Student newStudent;
    cout << "Введите ФИО студента: ";
    cin.ignore();
    getline(cin, newStudent.full_name_FIO);
    cout << "Введите пол (М/F): ";
    cin >> newStudent.gender;
    cout << "Введите номер группы: ";
    cin >> newStudent.number_group;
    cout << "Введите номер в списке группы: ";
    cin >> newStudent.number_list;
    cout << "Введите оценки за экзамены (3 оценки): ";
    for (int i = 0; i < 3; ++i) {
        cin >> newStudent.exam_grades[i];
    }
    cout << "Введите оценки за дифференцированные зачеты (5 оценок): ";
    for (int i = 0; i < 5; ++i) {
        cin >> newStudent.test_grades[i];
    }
    students[student_count++] = newStudent;
}

void change_student() {
    int listNumber;
    cout << "Введите номер в списке группы студента для редактирования: ";
    cin >> listNumber;
    for (int i = 0; i < student_count; ++i) {
        if (students[i].number_list == listNumber) {
            cout << "Редактирование информации о студенте: " << students[i].full_name_FIO << endl;
            cout << "Введите новое ФИО студента: ";
            cin.ignore();
            getline(cin, students[i].full_name_FIO);
            cout << "Введите новый пол (М/F): ";
            cin >> students[i].gender;
            cout << "Введите новый номер группы: ";
            cin >> students[i].number_group;
            cout << "Введите новые оценки за экзамены (3 оценки): ";
            for (int j = 0; j < 3; ++j) {
                cin >> students[i].exam_grades[j];
            }
            cout << "Введите новые оценки за дифференцированные зачеты (5 оценок): ";
            for (int j = 0; j < 5; ++j) {
                cin >> students[i].test_grades[j];
            }
            return;
        }
    }
    cout << "Студент с номером в списке " << listNumber << " не найден." << endl;
}

void all_data_students() {
    for (int i = 0; i < student_count; ++i) {
        cout << "ФИО: " << students[i].full_name_FIO << endl;
        cout << "Пол: " << students[i].gender << endl;
        cout << "Группа: " << students[i].number_group << endl;
        cout << "Номер в списке группы: " << students[i].number_list << endl;
        cout << "Оценки за экзамены: ";
        for (int j = 0; j < 3; ++j) {
            cout << students[i].exam_grades[j] << " ";
        }
        cout << endl;
        cout << "Оценки за дифференцированные зачеты: ";
        for (int j = 0; j < 5; ++j) {
            cout << students[i].test_grades[j] << " ";
        }
        cout << endl;
    }
}

void inf_on_group_students_N() {
    string groupNumber;
    cout << "Введите номер группы: ";
    cin >> groupNumber;
    for (int i = 0; i < student_count; ++i) {
        if (students[i].number_group == groupNumber) {
            cout << "ФИО: " << students[i].full_name_FIO << endl;
            cout << "Пол: " << students[i].gender << endl;
            cout << "Номер в списке группы: " << students[i].number_list << endl;
            cout << "Оценки за экзамены: ";
            for (int j = 0; j < 3; ++j) {
                cout << students[i].exam_grades[j] << " ";
            }
            cout << endl;
            cout << "Оценки за дифференцированные зачеты: ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].test_grades[j] << " ";
            }
            cout << endl;
        }
    }
}

void top_students() {
    double maxAverage = -1.0;

    // Находим максимальный средний балл
    for (int i = 0; i < student_count; ++i) {
        double totalGrades = 0.0;
        for (int j = 0; j < 3; ++j) {
            totalGrades += students[i].exam_grades[j];
        }
        for (int j = 0; j < 5; ++j) {
            totalGrades += students[i].test_grades[j];
        }
        double average = totalGrades / 8;
        if (average > maxAverage) {
            maxAverage = average;
        }
    }
    // Выводим студентов с максимальным средним баллом
    cout << "Топ студентов с наивысшим средним баллом:" << endl;
    for (int i = 0; i < student_count; ++i) {
        double totalGrades = 0.0;
        for (int j = 0; j < 3; ++j) {
            totalGrades += students[i].exam_grades[j];
        }
        for (int j = 0; j < 5; ++j) {
            totalGrades += students[i].test_grades[j];
        }
        double average = totalGrades / 8;
        if (average == maxAverage) {
            cout << "ФИО: " << students[i].full_name_FIO << ", Средний балл: " << fixed << setprecision(2) << average << endl;
        }
    }
}

void count_gender_student() {
    int man_count = 0, woman_count = 0;
    for (int i = 0; i < student_count; ++i) {
        if (students[i].gender == "M") {
            man_count++;
        }
        else if (students[i].gender == "F") {
            woman_count++;
        }
    }
    cout << "Количество студентов мужского пола: " << man_count << endl;
    cout << "Количество студентов женского пола: " << woman_count << endl;
}

void scholarship_students() {
    cout << "Студенты, которые не получают стипендию:" << endl;
    for (int i = 0; i < student_count; ++i) {
        bool hasScholarship = false;
        for (int j = 0; j < 3; ++j) {
            if (students[i].exam_grades[j] < 4) { // Если есть оценка ниже 4
                hasScholarship = true;
                break;
            }
        }
        for (int j = 0; j < 5 && !hasScholarship; ++j) {
            if (students[i].test_grades[j] < 4) {
                hasScholarship = true;
                break;
            }
        }
        if (!hasScholarship) { // Если все оценки >= 4
            cout << students[i].full_name_FIO << endl;
        }
    }

    cout << "Студенты, которые учатся только на «хорошо» и «отлично»:" << endl;
    for (int i = 0; i < student_count; ++i) {
        bool only_good_and_great = true;
        for (int j = 0; j < 3; ++j) {
            if (students[i].exam_grades[j] < 4) { // Оценка ниже 4
                only_good_and_great = false;
                break;
            }
        }
        for (int j = 0; j < 5 && only_good_and_great; ++j) {
            if (students[i].test_grades[j] < 4) {
                only_good_and_great = false;
                break;
            }
        }
        if (only_good_and_great) {
            cout << students[i].full_name_FIO << endl;
        }
    }

    cout << "Студенты, учатся только на 'отлично':" << endl;
    for (int i = 0; i < student_count; ++i) {
        bool only_great = true;
        for (int j = 0; j < 3; ++j) {
            if (students[i].exam_grades[j] != 5) { // Оценка не равна 5
                only_great = false;
                break;
            }
        }
        for (int j = 0; j < 5 && only_great; ++j) {
            if (students[i].test_grades[j] != 5) {
                only_great = false;
                break;
            }
        }
        if (only_great) {
            cout << students[i].full_name_FIO << endl;
        }
    }
}

void student_num_list_K() {
    int listNumber;
    cout << "Введите номер в списке группы студента: ";
    cin >> listNumber;

    for (int i = 0; i < student_count; ++i) {
        if (students[i].number_list == listNumber) {
            cout << "ФИО: " << students[i].full_name_FIO << endl;
            cout << "Пол:  " << students[i].gender << endl;
            cout << "Группа: " << students[i].number_group << endl;
            cout << "Номер в списке группы: " << students[i].number_list << endl;
            cout << "Оценки за экзамены: ";
            for (int j = 0; j < 3; ++j) {
                cout << students[i].exam_grades[j] << " ";
            }
            cout << "Оценки за дифференцированные зачеты: ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].test_grades[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Студент с номером в списке не найден." << endl;
}

// idz
struct IdzStudent {
    string full_name;
    char gender;
    int age;
    char clothing_size;  // Размер одежды (например, 'S', 'M', 'L', 'XL')
    bool voll_category;  // Наличие разряда (true - есть, false - нет)
    int number_course;
};

void IdzStudents_has_voll_category(IdzStudent IdzStudents[], int count) {
    cout << "Студенты с разрядом по волейболу:\n";
    for (int i = 0; i < count; ++i) {
        if (IdzStudents[i].voll_category) {
            cout << IdzStudents[i].full_name << "\n";
        }
    }
}

void women_team(IdzStudent IdzStudents[], int count) {
    cout << "Женская сборная волейбольной секции:\n";
    for (int i = 0; i < count; ++i) {
        if (IdzStudents[i].gender == 'F') {
            cout << IdzStudents[i].full_name << "\n";
        }
    }
}

void course_IdzStudents(IdzStudent IdzStudents[], int count, int course) {
    cout << "Студенты " << course << " курса:\n";
    for (int i = 0; i < count; ++i) {
        if (IdzStudents[i].number_course == course) {
            cout << IdzStudents[i].full_name << "\n";
        }
    }
}

void man_IdzStudents_with_a_larger_size(IdzStudent IdzStudents[], int count, char size) {
    cout << "Мужские студенты с размером одежды больше чем S " << size << ":\n";
    for (int i = 0; i < count; ++i) {
        if (IdzStudents[i].gender == 'M' && IdzStudents[i].clothing_size > size) {
            cout << IdzStudents[i].full_name << "\n";
        }
    }
}

int launch_idz() {
    const int IdzStudent_count = 5;
    IdzStudent IdzStudents[IdzStudent_count] = {
        {"Шашичев Никита Дмитриевич", 'M', 20, 'M', true, 2},
        {"Павлова Елизавета Витальевна", 'W', 19, 'S', false, 1},
        {"Кузнецов Алексей Сидорович", 'M', 21, 'L', true, 3},
        {"Петрова Анна Сергеевна", 'W', 22, 'M', true, 2},
        {"Михайлов Сергей Павлович", 'M', 20, 'L', false, 1}
    };

    IdzStudents_has_voll_category(IdzStudents, IdzStudent_count);
    women_team(IdzStudents, IdzStudent_count);
    course_IdzStudents(IdzStudents, IdzStudent_count, 2);
    man_IdzStudents_with_a_larger_size(IdzStudents, IdzStudent_count, 'S');
    return 0;
}


int main() {
    cout << sizeof (Student);
    setlocale(LC_ALL, "Russian");
    while (true) {
        int choice;
        cout << "Выберите действие:" << endl;
        cout << "1. Создание новой записи о студенте." << endl;
        cout << "2. Внесение изменений в уже имеющуюся запись." << endl;
        cout << "3. Вывод всех данных о студентах." << endl;
        cout << "4. Вывод информации обо всех студентах группы N" << endl;
        cout << "5. Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию." << endl;
        cout << "6. Вывод количества студентов мужского и женского пола." << endl;
        cout << "7. Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»;" << endl;
        cout << "8. Вывод данных о студентах, имеющих номер в списке – k." << endl;
        cout << "9. ИДЗ" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            new_entry_student();
            break;
        case 2:
            change_student();
            break;
        case 3:
            all_data_students();
            break;
        case 4:
            inf_on_group_students_N();
            break;
        case 5:
            top_students();
            break;
        case 6:
            count_gender_student();
            break;
        case 7:
            scholarship_students();
            break;
        case 8:
            student_num_list_K();
            break;
        case 9:
            launch_idz();
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }
    }
    return 0;
}
