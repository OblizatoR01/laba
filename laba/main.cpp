// main.cpp
#include <iostream>
#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"
#include <algorithm>


std::vector<BankOperation> filterIncomeOperations(const std::vector<BankOperation>& operations) {
    std::vector<BankOperation> incomeOps;
    for (const auto& op : operations) {
        if (op.type == "приход") {
            incomeOps.push_back(op);
        }
    }
    return incomeOps;
}
std::vector<BankOperation> filterOperationsForNovember2021(const std::vector<BankOperation>& operations) {
    std::vector<BankOperation> novemberOps;
    for (const auto& op : operations) {
        // Проверяем месяц и год
        if (op.date.substr(3, 2) == "11" && op.date.substr(6, 2) == "21") {
            novemberOps.push_back(op);
        }
    }
    return novemberOps;
}
void sortByName(std::vector<BankOperation>& operations) {
    std::sort(operations.begin(), operations.end(), [](const BankOperation& a, const BankOperation& b) {
        return a.description < b.description;
        });
}

void sortByAccountTypeAmount(std::vector<BankOperation>& operations) {
    std::sort(operations.begin(), operations.end(), [](const BankOperation& a, const BankOperation& b) {
        if (a.account != b.account) {
            return a.account < b.account;
        }
        if (a.type != b.type) {
            return a.type < b.type;
        }
        return a.amount > b.amount; // Убывание суммы
        });
}



int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Лабораторная работа №8. GIT\n";
    std::cout << "Вариант №7. Банковские операции\n";
    std::cout << "Автор: Ловчик Юрий\n";
    std::cout << "Группа: 24ИСИТ1д\n";

    try {
        // Чтение данных из файла
        std::vector<BankOperation> operations = readBankOperations("data.txt");

        // 1. Вывести все приходные операции
        std::cout << "Приходные операции:\n";
        std::vector<BankOperation> incomeOps = filterIncomeOperations(operations);
        for (const auto& op : incomeOps) {
            std::cout << "Дата: " << op.date << ", Время: " << op.time << ", Вид: " << op.type
                << ", Счёт: " << op.account << ", Сумма: " << op.amount
                << ", Назначение: " << op.description << "\n";
        }

        // 2. Вывести все операции за ноябрь 2021 года
        std::cout << "\nОперации за ноябрь 2021 года:\n";
        std::vector<BankOperation> novemberOps = filterOperationsForNovember2021(operations);
        for (const auto& op : novemberOps) {
            std::cout << "Дата: " << op.date << ", Время: " << op.time << ", Вид: " << op.type
                << ", Счёт: " << op.account << ", Сумма: " << op.amount
                << ", Назначение: " << op.description << "\n";
        }

        // 3. Сортировка по назначению платежа
        std::cout << "\nСортировка по назначению платежа:\n";
        std::vector<BankOperation> sortedByName = operations;
        sortByName(sortedByName);
        for (const auto& op : sortedByName) {
            std::cout << "Дата: " << op.date << ", Время: " << op.time << ", Вид: " << op.type
                << ", Счёт: " << op.account << ", Сумма: " << op.amount
                << ", Назначение: " << op.description << "\n";
        }

        // 4. Сортировка по номеру счёта, виду операции и сумме
        std::cout << "\nСортировка по счёту, виду и сумме:\n";
        std::vector<BankOperation> sortedByAccountTypeAmount = operations;
        sortByAccountTypeAmount(sortedByAccountTypeAmount);
        for (const auto& op : sortedByAccountTypeAmount) {
            std::cout << "Дата: " << op.date << ", Время: " << op.time << ", Вид: " << op.type
                << ", Счёт: " << op.account << ", Сумма: " << op.amount
                << ", Назначение: " << op.description << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}