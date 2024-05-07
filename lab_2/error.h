#pragma once
#include <iostream>
class Error : public std::exception {
    std::string errorMessage;
public:
    // ����������� ������ ����������
    Error(const std::string& message) : errorMessage(message) {}
    // ��������������� ������ what() ��� �������� �������� ������
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};