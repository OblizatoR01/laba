// file_reader.cpp
#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<BankOperation> readBankOperations(const std::string& filename) {
    std::vector<BankOperation> operations;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        BankOperation op;

        // Разбиваем строку на части
        if (!(iss >> op.date >> op.time >> op.type >> op.account >> op.amount >> op.description)) {
            continue; // Пропускаем некорректные строки
        }

        operations.push_back(op);
    }

    file.close();
    return operations;
}