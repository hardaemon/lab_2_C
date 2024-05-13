//�����������
template <typename T>
CircularBuffer<T>::CircularBuffer(size_t sizeArr) : buffer(new T[sizeArr]), sizeArr(sizeArr), front(0), rear(0), count(0) {}

//����������
template <typename T>
CircularBuffer<T>::~CircularBuffer() { delete[] buffer; }

//�������� ������� � ����� �������
template <typename T>
void CircularBuffer<T>::enqueue(const T& value) {
    if (count == sizeArr) { throw Error("������� ������"); }
    buffer[rear] = value;
    rear = (rear + 1) % sizeArr; //�����������
    count++;
}

//����� ������� � ������ �������
template <typename T>
T CircularBuffer<T>::dequeue() {
    if (isEmpty()) { throw Error("������� ������"); }
    T& value = buffer[front];
    front = (front + 1) % sizeArr; //�����������
    count--;
    return value;
}

//�������� ������� � ������ ������� (��� ��� �������)
template <typename T>
T CircularBuffer<T>::peek() const {
    if (isEmpty()) { throw Error("������� ������"); }
    return buffer[front];
}

//������ �������
template <typename T>
size_t CircularBuffer<T>::size() const {
    // return rear > front ? rear - front : sizeArr - front + rear;
    return count; }

//������� ������� ������
template <typename T>
void CircularBuffer<T>::clear() {
    front = rear = count = 0;
    for (int i = 0; i < sizeArr; ++i) { buffer[i] = 0; }
}

//�������� ������� �� �������
template <typename T>
bool CircularBuffer<T>::isEmpty() const { return count == 0; }

//������� ��� ���������
template <typename T>
T* CircularBuffer<T>::getBuffer() const { return buffer; }
template <typename T>
size_t CircularBuffer<T>::getFront() const { return front; }
template <typename T>
size_t CircularBuffer<T>::getRear() const { return rear; }
template <typename T>
size_t CircularBuffer<T>::getSizeArr() const { return sizeArr; }

//����������� ���������
template <typename T>
Iterator<T>::Iterator(const CircularBuffer<T>& circularBuffer) : circularBuffer(circularBuffer), current(circularBuffer.getFront()) {}

//������ ������� ���������
template <typename T>
void Iterator<T>::start() { current = circularBuffer.getFront(); }

//������� � ���������� ��������
template <typename T>
void Iterator<T>::next() { current = (current + 1) % circularBuffer.getSizeArr(); }

//��������, ��� �� ��������������
template <typename T>
bool Iterator<T>::finish() const { return current == circularBuffer.getRear() % circularBuffer.getSizeArr(); }

//�������� ��������� ������� �������
template <typename T>
T Iterator<T>::getValue() { return circularBuffer.getBuffer()[current]; }