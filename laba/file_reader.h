// file_reader.h
#ifndef FILE_READER_H
#define FILE_READER_H

#include "bank_operations.h"
#include <string>
#include <vector>

// Функция для чтения банковских операций из файла
std::vector<BankOperation> readBankOperations(const std::string& filename);

#endif // FILE_READER_H