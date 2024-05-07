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
    //конструктор
    CircularBuffer(size_t sizeArr);

    //деструктор
    ~CircularBuffer();

    //добавить элемент в конец очереди
    void enqueue(const T& value);

    //взять элемент в начале очереди
    T dequeue();

    //получить элемент в начале очереди (без его изъятия)
    T peek() const;

    //размер очереди
    size_t size() const;

    //сделать очередь пустой
    void clear();

    //проверка очереди на пустоту
    bool isEmpty() const;
};

#include "circularbuffer.ipp"