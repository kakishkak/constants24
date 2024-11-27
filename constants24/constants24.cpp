#include <iostream>

using namespace std;



class User {
    string name;
    string surname;
    int age;
public:
    User() {
        name = "super";
        surname = "puper";
        age = 69;
    }

    User(string name, string surname, int age) {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    void AssingValues(const string name, const string surname, int age) {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    string getName() {
        return name;
    }

    string getSurname() {
        return surname;
    }

    int getAge() {
        return age;
    }
};

class Group {
    User* users;
public:
    static int amountOfUsers;

    Group() {
        users = new User[amountOfUsers];
    }
    void Adder(User user) {
        User* tempArrOfStudents = new User[amountOfUsers];

        for (int i = 0; i < amountOfUsers; i++) {
           tempArrOfStudents[i].AssingValues(
               users[i].getName(),
               users[i].getSurname(),
               users[i].getAge());
        }

        delete[] users;
        users = nullptr;

        IncrementAmountOfPoints(1);

        users = new User[amountOfUsers];

        for (int i = 0; i < amountOfUsers - 1; i++) {
            users[i].AssingValues(
                tempArrOfStudents[i].getName(),
                tempArrOfStudents[i].getSurname(),
                tempArrOfStudents[i].getAge());
        }

        delete[] tempArrOfStudents;
        tempArrOfStudents = nullptr;

        users[amountOfUsers - 1].AssingValues(
            user.getName(),
            user.getSurname(),
            user.getAge());
    }

    void Deleter(int indexToDelete) {
        if (indexToDelete < 0 || indexToDelete >= amountOfUsers) {
            cout << "Invalid index!" << endl;
            return;
        }
        User* tempArrOfStudents = new User[amountOfUsers - 1];
        int tempIndex = 0;

        for (int i = 0; i < amountOfUsers; i++) {
            if (i != indexToDelete - 1) {
                tempArrOfStudents[tempIndex].AssingValues(          
                    users[i].getName(),
                    users[i].getSurname(),
                    users[i].getAge()
                );
                tempIndex++;
            }
        }


        DincrementAmountOfPoints(1);


        delete[] users;
        users = tempArrOfStudents;
    }

    void Rename(int indexToRename, string name, string surname,int age) {
        User* tempArrOfStudents = new User[amountOfUsers];

        for (int i = 0; i < amountOfUsers; i++) {
            tempArrOfStudents[i].AssingValues(
                users[i].getName(),
                users[i].getSurname(),
                users[i].getAge());
        }

        delete[] users;
        users = nullptr;

        users = new User[amountOfUsers];
        
        for (int i = 0; i < amountOfUsers; i++) {
            if (i == indexToRename) {
                tempArrOfStudents[i].AssingValues(name, surname, age);
            }
            else {
                tempArrOfStudents[i].AssingValues(
                    users[i].getName(),
                    users[i].getSurname(),
                    users[i].getAge());
            }
        }

    }

    static void IncrementAmountOfPoints(int x) {
        amountOfUsers += x;
    }
    static void DincrementAmountOfPoints(int x) {
        amountOfUsers += x;
    }
};

int Group::amountOfUsers = 0;

int main() {
    Group obj;
    cout << Group::amountOfUsers << endl;
    Group obj1;
    cout << Group::amountOfUsers << endl;
    Group obj2;
    cout << Group::amountOfUsers << endl;
}
