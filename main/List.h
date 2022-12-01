#pragma once
#include <iostream>
using namespace std;
namespace ListVariable {
    inline unsigned int ARR_SIZE = 4;
}

template<class T> class Str {
    T* str_;
    unsigned int size_;
    //template <class T> ostream& operator>>(ostream&, const Node<T>*);
    //template<class T> friend ostream& operator<<(ostream&, Str<T>*);
    //template<class T> friend istream& operator>>(istream&, Str<T>*);
    template<class T> friend ostream& operator<<(ostream&, Str<T>&);
    template<class T> friend istream& operator>>(istream&, Str<T>&);    
public:
    Str();
    ~Str();
    void resize();
    T* getString();
    unsigned int getSize();
    void copyString(Str*);
    void setString(T*);
    void setSize(unsigned int);
    //template <class T> Str<T>& operator=(const Str<T>& obj);
    /*template <class U> Str<T>& operator=(const Str<U>& obj) {
        size_ = obj.size_;
        if (str_ == nullptr) {
            str_ = new T[size_];
        } else {
            delete[] str_;
            str_ = new T[size_];
        }
        unsigned int i = 0;
        while (obj.str_[i] != '\n') {
            str_[i] = obj.str_[i];
            i++;
        }
        str_[i] = obj.str_[i];
        return *this;
    }*/
};
//template <class U> Str<T>& Str<T>::operator=(const Str<U>& obj) {
//    return *this;
//}
//template <class T> Str<T>& Str<T>::operator=(const Str<T>& obj) {
//    //size_ = obj.size_;
//    return *this;
//}
template <class T> Str<T>::Str() : str_{ nullptr }, size_{ 0 } {}
template <class T> Str<T>::~Str() {
    if (str_ != nullptr) {
        delete[] str_;
    }
}
template <class T> T* Str<T>::getString() {
    return str_;
}
template <class T> unsigned int Str<T>::getSize() {
    return size_;
}
template <class T> void Str<T>::copyString(Str<T>* str) {
    size_ = str->getSize();
    if (str_ == nullptr) {
        str_ = new T[size_];
    }
    else {
        delete[] str_;
        str_ = new T[size_];
    }
    unsigned int i = 0;
    T* tmp = str->getString();
    while (tmp[i] != '\n') {
        str_[i] = tmp[i];
        i++;
    }
    str_[i] = tmp[i];
}
template <class T> void Str<T>::setString(T* str) {
    str_ = str;
}
template <class T> void Str<T>::setSize(unsigned int size) {
    size_ = size;
}
template <class T> void Str<T>::resize() {
    T* reStr;
    if (size_ == 0) {
        size_ = 128;
        str_ = new T[size_];
        return;
    }
    reStr = new T[size_ * 2];      
    for (int i = 0; i < size_; i++) {
        reStr[i] = str_[i];
    }      
    delete[] str_;
    str_ = reStr;
    size_ *= 2;
}
//template<class T> ostream& operator<<(ostream&, Str<T>*) {
//    if (obj->str_ != nullptr) {
//        unsigned int i = 0;
//        while (obj->str_[i] != '\n') {
//            os << obj->str_[i];
//            i++;
//        }
//        os << endl;
//    }
//    else {
//        os << "nullptr" << endl;
//    }
//    return os;
//
//}
//template<class T> istream& operator>>(istream& in, Str<T>* obj) {
//    T ch = 'n'; unsigned int counter = 0;
//    if ((*obj).size_ == 0) {
//        (*obj).resize();
//    }
//    while (true) {
//        if (cin->peek() == '\n' && counter > 0) {
//            break;
//        }
//        in >> ch;
//        if (counter + 2 > obj->size_) {
//            (*obj).resize();
//        }
//        (*obj).str_[counter] = ch;
//        counter++;
//    }
//    
//    (*obj).str_[counter] = '\n';
//    return in;
//}
template<class T> ostream& operator<<(ostream& os, Str<T>& obj) {
    if (obj.str_ != nullptr) {
        unsigned int i = 0;
        while (obj.str_[i] != '\n') {
            os << obj.str_[i];
            i++;
        }
        os << endl;
    }
    else {
        os << "nullptr" << endl;
    }
    return os;
}
template <class T> istream& operator>>(istream& in, Str<T>& obj) {
    T ch='n'; unsigned int counter = 0;
    if (obj.size_ == 0) {
        obj.resize();
    }
    while (true) {
        if (cin.peek() == '\n' && counter > 0) {
            break;
        }
        in >> ch;        
        if (counter + 2 > obj.size_) {
            obj.resize();
        }
        obj.str_[counter] = ch;
        counter++;
    }
    obj.str_[counter] = '\n';
    return in;
}
//template <class T> class Str {	
//private:
//	T* str_;
//	unsigned int size_;	
//	
//	/*template <class T> friend ostream& operator>>(istream&, Str<T>&);*/
//public:
//	Str();
//	/*Str(T*, unsigned int);*/
//	~Str();
//	/*void resize();
//	void setCh(T, unsigned int);
//	T* getStr() const;*/
//	friend ostream& operator<< <>(ostream&, Str<T>&);
//};
template <class T> class Node
{
    //Str<T> data_[ListVar::SIZE]={};
    Str<T>** arr_;// = new Str<T>[ListVariable::ARR_SIZE];
	Node* next_;    
    /*template<class T> friend ostream& operator<<(ostream&, Node<T>&);
    template<class T> friend istream& operator>>(istream&, Node<T>&);*/
public:
    Node();
    ~Node();
    Node* getNext();
    void setNext(Node*);
    void cinStr(unsigned int i);
    void setStr(Str<T>*, unsigned int i);
    Str<T>* getStr(unsigned int i);
    //void eraseStr(unsigned int i);
};
template <class T> Node<T>::Node() : next_{nullptr} {
    arr_ = new Str<T>*[ListVariable::ARR_SIZE];
    for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
         arr_[i] = new Str<T>;
    }
}
template <class T> Node<T>::~Node() {
    for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
        delete arr_[i];
    }
    delete[] arr_;
}
//template<class T> ostream& operator<<(ostream& os, Node<T>& obj) {
//    os << obj.data_;
//    return os;
//}
//template <class T> istream& operator>>(istream& in, Node<T>& obj) {
//    in >> obj.data_;
//    return in;
//}
template <class T> Node<T>* Node<T>::getNext() {
    return next_;
}
template <class T> Str<T>* Node<T>::getStr(unsigned int i) {
    return arr_[i];
}
template <class T> void Node<T>::setStr(Str<T>* str, unsigned int i) {
    arr_[i] = str;
}
template <class T> void Node<T>::setNext(Node<T>* next) {
    next_ = next;
}
template <class T> void Node<T>::cinStr(unsigned int i) {
    cin >> *arr_[i];
}
template <class T> class List
{
	Node<T>* first_;
	Node<T>* last_;
public:
    List();
    void insertAtEnd();
    void show();
    void delLast();
};
template <class T> List<T>::List() : first_{ nullptr }, last_{ nullptr } {}
//template <class T> List<T>::List() : first_{nullptr}, last_{ nullptr } {}
template <class T> void List<T>::insertAtEnd() {
    if (first_ == nullptr) {
        Node<T>* newNode = new Node<T>;
        cout << "Введите строку: ";
        newNode->cinStr(0);
        first_ = newNode;
        last_ = newNode;
        //last_ = first;
        return;
    }
    Node<T>* tmp = first_;
    while (tmp!= nullptr) {
        for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
            Str<T>* tmpStr = tmp->getStr(i);
            /*if (tmpStr == nullptr) { 
                tmpStr = new Str<T>;
            }*/
            if (tmpStr->getString() == nullptr) {
                cout << "Введите строку: ";
                tmp->cinStr(i);
                return;
            }
        }
        tmp = tmp->getNext();
    }
    // если нет места в массивах, создаём новый переписывая в него половину последнего
    Node<T>* newNode = new Node<T>;
    for (int i = ListVariable::ARR_SIZE / 2, j = 0; i < ListVariable::ARR_SIZE; i++, j++) {
        Str<T>* StrOld = last_->getStr(i);
        Str<T>* StrNew = newNode->getStr(j);
        StrNew->copyString(StrOld);
        StrOld->setString(nullptr); StrOld->setSize(0); // обнуление текущего элемнта
    }

    cout << "Введите строку: ";
    newNode->cinStr(ListVariable::ARR_SIZE/2);    
    last_->setNext(newNode);
    last_ = newNode;
}
template <class T> void List<T>::delLast() {
    if (first_ == nullptr) {
        cout << "Нечего удалять" << endl;
        return;
    }
    Node<T>* prevLast = first_;
    if (first_ != last_) { // если больше одного элемента ищем предпоследний
        while (prevLast->getNext() != last_) {
            prevLast = prevLast->getNext();
        }
    }
    
    for (int i = ListVariable::ARR_SIZE-1; i >= 0; i--) {
        Str<T>* tmpStr = last_->getStr(i);
        if (tmpStr->getString() != nullptr) {
            if (i == 0) {
                prevLast->setNext(nullptr);
                delete last_;
                if (first_ != last_) {
                    last_ = prevLast;
                } else {
                    first_ = nullptr;
                }
                return;
            }
            tmpStr->setString(nullptr); tmpStr->setSize(0);
            return;
        }        
        
    }
}
template <class T> void List<T>::show() {
    if (first_ == nullptr) {
        cout << "Структура пуста" << endl;
    }
    Node<T>* tmp = first_;
    unsigned int id = 0;
    while (tmp != nullptr) {
        for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
            Str<T>* tmpStr = tmp->getStr(i);
            /*if (tmpStr == nullptr) { continue; }*/
            if (tmpStr->getString() != nullptr) {
                cout << "Номер " << id << endl;
                cout << *tmpStr;
                id++;
            }            
        }
        tmp = tmp->getNext();
        cout << endl;
    }
}
