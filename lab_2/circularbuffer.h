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

    //геттеры для итератора
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
    //конструктор итератора
    Iterator(const CircularBuffer<T>& circularBuffer);

    //начать перебор элементов
    void start();

    //перейти к следующему элементу
    void next();

    //проверка, все ли проитерировано
    bool finish() const;

    //получить очередной элемент очереди
    T getValue();
};

#include "circularbuffer.ipp"