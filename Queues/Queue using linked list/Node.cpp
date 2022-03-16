template <typename T>

class Node {

    public:
    Node<T> *next;
    T data;

    Node(T d) {

        data = d;
        next = NULL;
    }
};