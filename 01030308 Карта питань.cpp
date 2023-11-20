#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

class Question {
private:
    string question;
    string answer;

public:
    Question() : question(""), answer("") {}

    Question(string q, string a) : question(q), answer(a) {}

    string getQuestion() const {
        return question;
    }

    string getAnswer() const {
        return answer;
    }
};

int main() {
    system("chcp 1251>null");
    map<int, Question> questionsMap;
    questionsMap[1] = Question("Її використовують, щоб орієнтуватися на місцевості", "Карта");
    questionsMap[2] = Question("Перекладіть слово 'map' з англійської мови", "Карта");
    questionsMap[3] = Question("Без чого не знайти піратський скарб?", "Карта");
    questionsMap[4] = Question("Є зображенням земної поверхні в певній проєкції", "Карта");
    questionsMap[5] = Question("Заповніть пробіл: компактний електронний носій інформації - ... пам'яті", "Карта");

    int points = 0;
    const int timeLimit = 60;

    cout << "Дайте відповідь на запитання за 60 секунд і натисніть 'Enter'." << endl;
    cout << endl;

    for (const auto& pair : questionsMap) {
        cout << "Питання " << pair.first << ". " << pair.second.getQuestion() << endl;

        auto start = steady_clock::now();
        auto end = steady_clock::now();
        auto duration = duration_cast<seconds>(end - start);

        string userAnswer;
        cout << "Відповідь: ";
        getline(cin, userAnswer);
        cout << endl;

        end = steady_clock::now();
        duration = duration_cast<seconds>(end - start);

        if (duration.count() >= timeLimit) {
            cout << "";
        }
        else {
            if (userAnswer == pair.second.getAnswer()) {
                points += (5 - pair.first + 1);
            }
        }
    }

    cout << "Загальна кількість балів: " << points << endl;
    cout << endl;
    cout << "Правильні відповіді:" << endl;

    for (const auto& pair : questionsMap) {
        cout << "Питання " << pair.first << ". " << pair.second.getQuestion() << ": " << pair.second.getAnswer() << endl;
    }

    return 0;
}
