#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    std::size_t maxSize;

public:
    LinkedList(std::size_t sizeLimit) : head(nullptr), maxSize(sizeLimit) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    std::size_t getSize() const {
        std::size_t size = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            size++; //1
            current = current->next; //con tro next cua current tro den 1 vung null  --> con tro current cung tro toi vung null do --> thoat vong lap
        }
        return size;
    }

    void insert(const T& value, int position) {
        if (getSize() >= maxSize) {
            std::cout << "Danh sach da dat toi kich thuoc toi da. Khong the chen them phan tu." << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        if (position == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head; // chi co 1 nut duy nhat --> current->next chi toi null (con tro next cua current tro toi null)
            for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
                current = current->next; // con tro current tro toi node tiep theo, vong lap nay dung khi con tro tro toi node truoc vi tri chen
            }
            newNode->next = current->next; //current->next la con tro next cua node current (current dang dung truoc vi tri can chen), con tro next nay dang tro vao node sau vi tri can chen. Con tro next cua node can chen se tro toi node sau node can chen
            current->next = newNode; // con tro next cua nut current tro vao node can chen (newNode)
        }
    }

    Node<T>* find(const T& value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Không tìm thấy giá trị trong danh sách
    }


    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Hàm in địa chỉ của nút và địa chỉ của biến data trong nút
    void printNodeAddresses() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << "Dia chi cua nut: " << current << std::endl;
            std::cout << "Dia chi cua bien data trong nut: " << &(current->data) << std::endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList<int> myList(3);

    myList.insert(15, 0);
    myList.insert(10, 1);
    myList.insert(15, 0);

    myList.printList();
    
    int searchValue = 15;
    Node<int>* foundNode = myList.find(searchValue);

    if (foundNode != nullptr) {
        std::cout << "Gia tri " << searchValue << " tim thay tai dia chi: " << foundNode << std::endl;
    } else {
        std::cout << "Gia tri " << searchValue << " khong tim thay trong danh sach." << std::endl;
    }

    //myList.printNodeAddresses();  // In địa chỉ của nút và địa chỉ của biến data trong nút

    return 0;
}
