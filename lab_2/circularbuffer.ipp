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