// file_reader.h
#ifndef FILE_READER_H
#define FILE_READER_H

#include "bank_operations.h"
#include <string>
#include <vector>

// ������� ��� ������ ���������� �������� �� �����
std::vector<BankOperation> readBankOperations(const std::string& filename);

#endif // FILE_READER_H