#pragma once
#include "error.h"

template <typename T>
class CircularBuffer {
private:
    T* buffer;
    size_t front;
    size_t rear;
    size_t count;
    size_t sizeArr;
public:
    //�����������
    CircularBuffer(size_t sizeArr);

    //����������
    ~CircularBuffer();

    //�������� ������� � ����� �������
    void enqueue(const T& value);

    //����� ������� � ������ �������
    T dequeue();

    //�������� ������� � ������ ������� (��� ��� �������)
    T peek() const;

    //������ �������
    size_t size() const;

    //������� ������� ������
    void clear();

    //�������� ������� �� �������
    bool isEmpty() const;
};

#include "circularbuffer.ipp"