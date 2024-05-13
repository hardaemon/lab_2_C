//конструктор
template <typename T>
CircularBuffer<T>::CircularBuffer(size_t sizeArr) : buffer(new T[sizeArr]), sizeArr(sizeArr), front(0), rear(0), count(0) {}

//деструктор
template <typename T>
CircularBuffer<T>::~CircularBuffer() { delete[] buffer; }

//добавить элемент в конец очереди
template <typename T>
void CircularBuffer<T>::enqueue(const T& value) {
    if (count == sizeArr) { throw Error("ќчередь полна€"); }
    buffer[rear] = value;
    rear = (rear + 1) % sizeArr; //зацикливаем
    count++;
}

//вз€ть элемент в начале очереди
template <typename T>
T CircularBuffer<T>::dequeue() {
    if (isEmpty()) { throw Error("ќчередь пуста€"); }
    T& value = buffer[front];
    front = (front + 1) % sizeArr; //зацикливаем
    count--;
    return value;
}

//получить элемент в начале очереди (без его изъ€ти€)
template <typename T>
T CircularBuffer<T>::peek() const {
    if (isEmpty()) { throw Error("ќчередь пуста€"); }
    return buffer[front];
}

//размер очереди
template <typename T>
size_t CircularBuffer<T>::size() const {
    // return rear > front ? rear - front : sizeArr - front + rear;
    return count; }

//сделать очередь пустой
template <typename T>
void CircularBuffer<T>::clear() {
    front = rear = count = 0;
    for (int i = 0; i < sizeArr; ++i) { buffer[i] = 0; }
}

//проверка очереди на пустоту
template <typename T>
bool CircularBuffer<T>::isEmpty() const { return count == 0; }

//геттеры дл€ итератора
template <typename T>
T* CircularBuffer<T>::getBuffer() const { return buffer; }
template <typename T>
size_t CircularBuffer<T>::getFront() const { return front; }
template <typename T>
size_t CircularBuffer<T>::getRear() const { return rear; }
template <typename T>
size_t CircularBuffer<T>::getSizeArr() const { return sizeArr; }

//конструктор итератора
template <typename T>
Iterator<T>::Iterator(const CircularBuffer<T>& circularBuffer) : circularBuffer(circularBuffer), current(circularBuffer.getFront()) {}

//начать перебор элементов
template <typename T>
void Iterator<T>::start() { current = circularBuffer.getFront(); }

//перейти к следующему элементу
template <typename T>
void Iterator<T>::next() { current = (current + 1) % circularBuffer.getSizeArr(); }

//проверка, все ли проитерировано
template <typename T>
bool Iterator<T>::finish() const { return current == circularBuffer.getRear() % circularBuffer.getSizeArr(); }

//получить очередной элемент очереди
template <typename T>
T Iterator<T>::getValue() { return circularBuffer.getBuffer()[current]; }