#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    T *data;
    size_t size;
    size_t capacity;

public:
    // Constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    // Destructor
    ~Vector()
    {
        delete[] data;
    }

    // insert() function
    void insert(size_t position, const T &value)
    {
        // check valid position
        if (position > size)
        {
            std::cerr << "Error: Invalid insertion position." << std::endl;
            return;
        }

        // check capacity
        if (size == capacity)
        {
            // allocate new memory
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T *newData = new T[capacity];

            // copy data from old memorty to new memory
            for (size_t i = 0; i < position; ++i)
            {
                newData[i] = data[i];
            }

            // insert element at position
            newData[position] = value;

            // copy data from old memorty to new memory
            for (size_t i = position; i < size; ++i)
            {
                newData[i + 1] = data[i];
            }

            // deallocate old memory
            delete[] data;

            // update pointer, to point to new memory
            data = newData;
        }
        else
        {
            // Move elements to the right to make space for the new element
            for (size_t i = size; i > position; --i)
            {
                data[i] = data[i - 1];
            }

            // insert element at position
            data[position] = value;
        }

        ++size;
    }

    // Hiển thị các phần tử của vector
    void display() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    bool find(const T &value) const
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] == value)
            {
                cout << "Found at index " << i << ": " << value << endl;
                return true; 
            }
        }

        cout << "Not found: " << value << endl;
        return false; 
    }
};

int main()
{
    Vector<int> vector;
    vector.insert(0, 10); // size = 1, capacity = 2
    vector.insert(1, 20); // size = 2, capacity = 2
    vector.insert(2, 50); // size = 3, capacity = 4
    vector.insert(3, 40); // size = 4, capacity = 4
    vector.insert(4, 50); // size = 5, capacity = 8
 
    vector.insert(2, 90);

    vector.display();
    // cout << vector.find(10) << endl;
    vector.find(50);

    return 0;
}
