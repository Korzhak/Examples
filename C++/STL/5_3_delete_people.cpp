#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Person {
    string Name;
    bool Sex; // 0 - male, 1 - female
    int Age;
    string Email;

public: 
    Person(string name, bool sex, int age, string email) {
        SetName(name);
        SetAge(age);
        SetSex(sex);
        SetEmail(email);
    }

    void SetName(string name) {
        this->Name = name;
    }
    void SetAge(uint8_t age) {
        this->Age = age;
    } 
    void SetEmail(string email) {
        this->Email = email;
    }
    void SetSex(bool sex) {
        this->Sex = sex;
    }

    string GetName() {
        return this->Name;
    }
    int GetAge() {
        return this->Age;
    }
   
    string GetEmail() {
        return this->Email;
    }
    bool GetSex() {
        return this->Sex;
    }
   
};

void ShowPeople(vector<Person> people, bool print_delineathor) {
    for (auto person : people) {
        cout << "name:\t" << person.GetName() << "\tsex:\t" << (person.GetSex() ? "female" : "male");
        cout <<  "\tage:\t" << person.GetAge() << "\temail\t" << person.GetEmail() << endl; 
    }
    if (print_delineathor) 
        cout << "---------------" << endl;
}

void ShowPerson(Person person, bool print_delineathor) {
    cout << "name:\t" << person.GetName() << "\tsex:\t" << (person.GetSex() ? "female" : "male");
    cout <<  "\tage:\t" << person.GetAge() << "\temail\t" << person.GetEmail() << endl; 
    if (print_delineathor) 
        cout << "---------------" << endl;
}


int main() {
    vector<Person> people = {
        Person("Ivan", 0, 18, "ivan@mail.com"),
        Person("Maria", 1, 25, "maria@mail.com"),
        Person("Sofia", 1, 18, "sofia@mail.com"),
        Person("Kolya", 0, 29, "kolya@mail.com"),
        Person("Valeriy", 0, 34, "valeriy@mail.com"),
        Person("Misha", 0, 19, "mykhailo@mail.com"),
        Person("Bohdan", 0, 14, "bohdan@mail.com"),
        Person("Taras", 0, 42, "taras1@mail.com"),
        Person("Taras", 0, 21, "taras2000@mail.com"),
        
    };    

    
    auto new_iter = remove_if(people.begin(), people.end(), [](Person p) {
        return p.GetAge() < 21;
    });

    people.erase(new_iter, people.end());

    ShowPeople(people, true);


    return 0;
}