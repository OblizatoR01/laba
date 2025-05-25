// bank_operations.h
#ifndef BANK_OPERATIONS_H
#define BANK_OPERATIONS_H

#include <string>

struct BankOperation {
    std::string date;        // дата в формате dd.mm.yy
    std::string time;        // время в формате hh:mm:ss
    std::string type;        // вид операции (приход/расход)
    std::string account;     // номер счёта
    double amount = 0.0;     // сумма операции (инициализация по умолчанию)
    std::string description; // назначение платежа
};

#endif // BANK_OPERATIONS_H