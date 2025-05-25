// bank_operations.h
#ifndef BANK_OPERATIONS_H
#define BANK_OPERATIONS_H

#include <string>

struct BankOperation {
    std::string date;        // ���� � ������� dd.mm.yy
    std::string time;        // ����� � ������� hh:mm:ss
    std::string type;        // ��� �������� (������/������)
    std::string account;     // ����� �����
    double amount = 0.0;     // ����� �������� (������������� �� ���������)
    std::string description; // ���������� �������
};

#endif // BANK_OPERATIONS_H