// main.cpp
#include <iostream>
#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"
#include <algorithm>


std::vector<BankOperation> filterIncomeOperations(const std::vector<BankOperation>& operations) {
    std::vector<BankOperation> incomeOps;
    for (const auto& op : operations) {
        if (op.type == "������") {
            incomeOps.push_back(op);
        }
    }
    return incomeOps;
}
std::vector<BankOperation> filterOperationsForNovember2021(const std::vector<BankOperation>& operations) {
    std::vector<BankOperation> novemberOps;
    for (const auto& op : operations) {
        // ��������� ����� � ���
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
        return a.amount > b.amount; // �������� �����
        });
}



int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "������������ ������ �8. GIT\n";
    std::cout << "������� �7. ���������� ��������\n";
    std::cout << "�����: ������ ����\n";
    std::cout << "������: 24����1�\n";

    try {
        // ������ ������ �� �����
        std::vector<BankOperation> operations = readBankOperations("data.txt");

        // 1. ������� ��� ��������� ��������
        std::cout << "��������� ��������:\n";
        std::vector<BankOperation> incomeOps = filterIncomeOperations(operations);
        for (const auto& op : incomeOps) {
            std::cout << "����: " << op.date << ", �����: " << op.time << ", ���: " << op.type
                << ", ����: " << op.account << ", �����: " << op.amount
                << ", ����������: " << op.description << "\n";
        }

        // 2. ������� ��� �������� �� ������ 2021 ����
        std::cout << "\n�������� �� ������ 2021 ����:\n";
        std::vector<BankOperation> novemberOps = filterOperationsForNovember2021(operations);
        for (const auto& op : novemberOps) {
            std::cout << "����: " << op.date << ", �����: " << op.time << ", ���: " << op.type
                << ", ����: " << op.account << ", �����: " << op.amount
                << ", ����������: " << op.description << "\n";
        }

        // 3. ���������� �� ���������� �������
        std::cout << "\n���������� �� ���������� �������:\n";
        std::vector<BankOperation> sortedByName = operations;
        sortByName(sortedByName);
        for (const auto& op : sortedByName) {
            std::cout << "����: " << op.date << ", �����: " << op.time << ", ���: " << op.type
                << ", ����: " << op.account << ", �����: " << op.amount
                << ", ����������: " << op.description << "\n";
        }

        // 4. ���������� �� ������ �����, ���� �������� � �����
        std::cout << "\n���������� �� �����, ���� � �����:\n";
        std::vector<BankOperation> sortedByAccountTypeAmount = operations;
        sortByAccountTypeAmount(sortedByAccountTypeAmount);
        for (const auto& op : sortedByAccountTypeAmount) {
            std::cout << "����: " << op.date << ", �����: " << op.time << ", ���: " << op.type
                << ", ����: " << op.account << ", �����: " << op.amount
                << ", ����������: " << op.description << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }

    return 0;
}