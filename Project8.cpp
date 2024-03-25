#include <iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    // Конструктор
    BankAccount(int accountNum, double initBalance) {
        accountNumber = accountNum;
        balance = initBalance;
        interestRate = 0.0;
    }

    // Внести средства на счет
    void deposit(double amount) {
        balance += amount;
    }

    // Снять средства со счета
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            std::cout << "Ошибка: недостаточно средств на счете!" << std::endl;
        }
    }

    // Получить текущий баланс
    double getBalance() {
        return balance;
    }

    // Рассчитать и вернуть сумму процентов
    double getInterest() {
        return balance * interestRate * (1.0 / 12.0);
    }

    // Обновить процентную ставку
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Получить номер банковского счёта
    int getAccountNumber() {
        return accountNumber;
    }

    // Дружественная функция для перевода средств между счетами
    friend bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount);
};

// Функция для перевода средств между счетами
bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
    if (amount <= fromAccount.balance) {
        fromAccount.balance -= amount;
        toAccount.balance += amount;
        return true;
    }
    else {
        std::cout << "Ошибка: недостаточно средств на счете для перевода!" << std::endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объектов счетов
    BankAccount account1(12345, 1000.0);
    BankAccount account2(67890, 2000.0);

    int choice;
    double amount;

    do {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Внести средства на счет" << std::endl;
        std::cout << "2. Снять средства со счета" << std::endl;
        std::cout << "3. Перевести средства на другой счет" << std::endl;
        std::cout << "4. Проверить баланс" << std::endl;
        std::cout << "0. Выйти" << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите сумму, которую желаете внести: ";
            std::cin >> amount;
            account1.deposit(amount);
            std::cout << "Средства успешно внесены на счет" << std::endl;
            break;
        case 2:
            std::cout << "Введите сумму, которую желаете снять: ";
            std::cin >> amount;
            account1.withdraw(amount);
            std::cout << "Средства успешно сняты со счета" << std::endl;
            break;
        case 3:
            std::cout << "Введите сумму для перевода: ";
            std::cin >> amount;
            if (transfer(account1, account2, amount)) {
                std::cout << "Перевод успешно выполнен" << std::endl;
            }
            break;
        case 4:
            std::cout << "Баланс на счете: " << account1.getBalance() << std::endl;
            break;
        case 0:
            std::cout << "До свидания!" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, повторите попытку" << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}