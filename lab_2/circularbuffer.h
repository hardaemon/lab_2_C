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

    //������� ��� ���������
    T* getBuffer() const;
    size_t getFront() const;
    size_t getRear() const;
    size_t getSizeArr() const;
};

template <typename T>
class Iterator {
private:
    const CircularBuffer<T>& circularBuffer;
    size_t current;
public:
    //����������� ���������
    Iterator(const CircularBuffer<T>& circularBuffer);

    //������ ������� ���������
    void start();

    //������� � ���������� ��������
    void next();

    //��������, ��� �� ��������������
    bool finish() const;

    //�������� ��������� ������� �������
    T getValue();
};

#include "circularbuffer.ipp"