#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Znak {
    string firstName;
    string lastName;
    vector<int> dateOfB;
    string znak;

public:
    const vector<string> ZNAKI = { "dafault", "�������","�������","����","����","�����","��������",
                                  "���","���","����","����","��������","�������" };

    Znak(string firstName, string lastName, vector<int> dateOfB, int znakId) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->dateOfB = dateOfB;
        this->znak = ZNAKI[znakId];
    }

    [[nodiscard]] string getFirstName() const noexcept { return this->firstName; }
    [[nodiscard]] string getLastName() const noexcept { return this->lastName; }
    [[nodiscard]] string getZnak() const noexcept { return this->znak; }
    [[nodiscard]] vector<int> getdateOfB() const noexcept { return this->dateOfB; }

    void setFirstName(string value) { this->firstName = value; }
    void setLastName(string value) { this->lastName = value; }
    void setZnak(int value) { this->znak = ZNAKI[value]; }
    void setdateOfB(vector<int> array) { this->dateOfB = array; }

};


void getUserData(int id, vector<Znak>& arr) {

    string firstName;
    string lastName;
    int znak_id;
    vector<int> dateOfB;
    int int_value;
    std::cout << "������� ���: ";
    std::cin >> firstName;
    arr[id].setFirstName(firstName);
    std::cout << "������� �������: ";
    std::cin >> lastName;
    arr[id].setLastName(lastName);
    std::cout << "������� ����� ����� �������: ";
    std::cin >> znak_id;
    arr[id].setZnak(znak_id);
    std::cout << "���� ��������: ";
    std::cin >> int_value;
    dateOfB.push_back(int_value);
    std::cout << "����� ��������: ";
    std::cin >> int_value;
    dateOfB.push_back(int_value);
    std::cout << "��� ��������: ";
    std::cin >> int_value;
    dateOfB.push_back(int_value);
    arr[id].setdateOfB(dateOfB);
}


int main() {
    setlocale(LC_ALL, "Russian");
    vector<Znak> users;
    while (true) {
        std::cout << "��� �� ������ �������?"
            "\n1: �������� ������������."
            "\n2: ������������� ������������."
            "\n3: �����."
            "\n�����: ";

        int answer;
        std::cin >> answer;
        if (answer == 3) break;
        if (answer == 2) {
            if (users.size() == 0) {
                std::cout << "������������ ��� �� ���� ���������!\n";
            }
            else {
                for (int i = 0; i < users.size(); ++i) {
                    std::cout << "USER �" << i << '\n';
                    std::cout << "����: " << users[i].getZnak() << '\n';
                    std::cout << "��� � �������: " << users[i].getFirstName() << " " << users[i].getLastName() << '\n';
                    vector <int> date = users[i].getdateOfB();
                    std::cout << "���� ��������: " << date[0] << " " << date[1] << " " << date[2] << '\n';
                }
                int answerId;
                std::cout << "������ ������������ ������ �������������? (������� ��� �����): ";
                std::cin >> answerId;
                getUserData(answerId, users);
                /*string value;
                int int_value;
                vector<int> newDate;

                std::cout << "������� ���: ";
                std::cin >> value;
                users[answerId].setFirstName(value);
                std::cout << "������� �������: ";
                std::cin >> value;
                users[answerId].setLastName(value);
                std::cout << "������� ����� ����� �������: ";
                std::cin >> int_value;
                users[answerId].setZnak(int_value);
                std::cout << "���� ��������: ";
                std::cin >> int_value;
                newDate.push_back(int_value);
                std::cout << "����� ��������: ";
                std::cin >> int_value;
                newDate.push_back(int_value);
                std::cout << "��� ��������: ";
                std::cin >> int_value;
                newDate.push_back(int_value);
                users[answerId].setdateOfB(newDate);*/
            }
        }
        if (answer == 1) {
            vector<int> dateOfB = { 0, 0, 0 };
            Znak newUser("default", "default", dateOfB, 0);
            users.push_back(newUser);
            getUserData(users.size() - 1, users);
            // string firstName;
            // string lastName;
            // int znak_id;
            // vector<int> dateOfB;
            // int int_value;
            // std::cout << "������� ���: ";
            // std::cin >> firstName;
            //// users[answerId].setFirstName(value);
            // std::cout << "������� �������: ";
            // std::cin >> lastName;
            // //users[answerId].setLastName(value);
            // std::cout << "������� ����� ����� �������: ";
            // std::cin >> znak_id;
            // //users[answerId].setZnak(int_value);
            // std::cout << "���� ��������: ";
            // std::cin >> int_value;
            // dateOfB.push_back(int_value);
            // std::cout << "����� ��������: ";
            // std::cin >> int_value;
            // dateOfB.push_back(int_value);
            // std::cout << "��� ��������: ";
            // std::cin >> int_value;
            // dateOfB.push_back(int_value);
            // //users[answerId].setdateOfB(newDate);
        }
    }

    system("pause");
    return 0;
}
