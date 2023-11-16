#include <iostream>
#include <vector>

template <class TypeK, class TypeV>
class UnorderMap
{
private:
    struct Entry
    {
        TypeK key;
        TypeV value;
        Entry *next;
    };

    int size;
    int capacity;

    std::vector<Entry *> bucket;

    // Hash function
    size_t hash(const TypeK &key) const
    {
        // You can use a better hash function depending on the key type
        return 1; // std::hash<TypeK>{}(key) % capacity;  //INDEX
    }

public:
    UnorderMap(int initialCapacity = 10) : size(0), capacity(initialCapacity)
    {
        bucket.resize(capacity, nullptr); // 10 cin tro, deu tro toi null
    }

    void insert(const TypeK &key, const TypeV &value)
    {

        size_t index = hash(key);

        // Check if the key already exists in the bucket
        Entry *current = bucket[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                // Key already exists, update the value
                current->value = value;
                return;
            }
            current = current->next;
        }

        // Key doesn't exist, create a new entry
        Entry *newEntry = new Entry{key, value, nullptr}; // node moi

        // Insert the new entry at the beginning of the bucket's linked list
        // newEntry->next =  null//bucket[index];
        //current->next = newEntry; //

        // Increase the size
        size++;
    }

    void display() const
    {
        std::cout << "{\n";
        for (size_t i = 0; i < capacity; ++i)
        {
            Entry *current = bucket[i];
            while (current != nullptr)
            {
                std::cout << "  " << current->key << ": " << current->value << "\n";
                current = current->next;
            }
        }
        std::cout << "}\n";
    }
};

int main()
{
    UnorderMap<std::string, int> myMap;
    myMap.insert("One", 1);
    // myMap.insert("Two", 2);
    //  myMap.insert("Three", 3);
    //   myMap.insert("Three",4);
    myMap.display();

    return 0;
}