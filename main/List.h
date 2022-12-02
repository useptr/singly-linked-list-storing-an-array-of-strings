#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <conio.h>
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
    template<class T> friend bool operator< (const Str<T>&, const Str<T>&);
    template<class T> friend bool operator> (const Str<T>&, const Str<T>&);
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
template<class T> bool operator< (const Str<T>& lhs, const Str<T>& rhs) {
    if (strcmp(lhs.str_, rhs.str_) < 0) {
        return true;
    }
    return false;
}
template<class T> bool operator> (const Str<T>& lhs, const Str<T>& rhs) {
    if (strcmp(lhs.str_, rhs.str_) > 0) {
        return true;
    }
    return false;
}
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
        /*if (in.peek() == '\n' && counter > 0) {
            break;
        }*/
        if (!in) {
            obj.str_[counter-1] = '\n';
            break;
        }
        in.get(ch);
        if (ch == '\n') {
            obj.str_[counter] = ch;
            break;
        }
        //in >> ch;        
        if (counter + 3 > obj.size_) {
            obj.resize();
        }
        obj.str_[counter] = ch;
        counter++;
    }
    //obj.str_[counter] = '\n';
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

template <class T> class List // CLASS LIST CLASS LIST CLASS LIST CLASS LIST CLASS LIST CLASS LIST
{
	Node<T>* first_;
	Node<T>* last_;
public:
    List();
    void insertAtEnd();
    void insertAtEnd(Str<T>*);
    void insertWithOrder();
    void show();
    void delLast();
    void redFIle();
    void writeFIle();
    void writeBinFIle();
    void readBinFIle();
    void sort();
};
template <class T> List<T>::List() : first_{ nullptr }, last_{ nullptr } {}
//template <class T> List<T>::List() : first_{nullptr}, last_{ nullptr } {}
template <class T> void List<T>::insertWithOrder() {
    int character = 0;
    cout << "После выполнения все элементы будут отсортированы, если не хотите продолжать нажмите - Esc, чтобы продолжить любую другую клавишу" << endl;
    character = _getch();
    if (character == 27) {
        return;
    }
    insertAtEnd();
    sort();
}
template <class T> void List<T>::insertAtEnd(Str<T>* nStr) {
    if (first_ == nullptr) {
        Node<T>* newNode = new Node<T>;
        /*cout << "Введите строку: ";
        newNode->cinStr(0);*/
        newNode->setStr(nStr, 0);
        first_ = newNode;
        last_ = newNode;
        return;
    }
    Node<T>* tmp = first_;
    while (tmp != nullptr) {
        for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
            Str<T>* tmpStr = tmp->getStr(i);
            if (tmpStr->getString() == nullptr) {
                /*cout << "Введите строку: ";
                tmp->cinStr(i);*/
                tmp->setStr(nStr, i);
                //tmpStr = nStr;
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
    /*cout << "Введите строку: ";
    newNode->cinStr(ListVariable::ARR_SIZE / 2);*/
    newNode->setStr(nStr, ListVariable::ARR_SIZE / 2);
    last_->setNext(newNode);
    last_ = newNode;
}
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

template <class T> void List<T>::redFIle() {
    string fileName;
    cout << "Введие имя файла: ";
    //fileName += "1.txt";
    getline(cin, fileName);
    //cin >> fileName; // 
    ifstream fin(fileName);
    if (!fin)
    {
        cout << "Файл не может быть открыт или создан" << endl;
        return;
    }
    while (!fin.eof()) {
        Str<T>* nStr = new Str<T>; nStr->resize();
        fin >> *nStr;
        insertAtEnd(nStr);
        fin.peek();
    }
    fin.close();
}

template <class T> void List<T>::writeFIle() {
    if (first_ == nullptr) {
        cout << "Нечего сохранять в файл" << endl;
        return;
    }
    string fileName;
    cout << "Введие имя файла: ";
    getline(cin, fileName);
    ofstream fout(fileName);
    if (!fout)
    {
        cout << "Файл не может быть открыт или создан" << endl;
        return;
    }

    Node<T>* tmp = first_;
    unsigned int id = 0;
    while (tmp != nullptr) {
        for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
            Str<T>* tmpStr = tmp->getStr(i);
            /*if (tmpStr == nullptr) { continue; }*/
            if (tmpStr->getString() != nullptr) {
                fout << *tmpStr;
            }
        }
        tmp = tmp->getNext();
    }
    fout.close();
}
template <class T> void List<T>::readBinFIle() {
    string fileName;
    cout << "Введие имя файла: ";
    //fileName += "1.txt";
    getline(cin, fileName);
    //cin >> fileName; // 
    ifstream bin(fileName, ios::in | ios::binary);
    if (!bin)
    {
        cout << "Файл не может быть открыт или создан" << endl;
        return;
    }
    while (!bin.eof()) {
        Str<T>* nStr = new Str<T>; //nStr->resize();
        //bin >> *nStr;        
        size_t len = 0;
        bin.read((char*)& len, sizeof(len));
        T* tmpString = new T[len];
        bin.read(tmpString, len);
        nStr->setString(tmpString); nStr->setSize(len);
        insertAtEnd(nStr);
        bin.peek();
    }
    bin.close();
}
template <class T> void List<T>::writeBinFIle() {
    string fileName;
    cout << "Введие имя файла: ";
    getline(cin, fileName);
    ofstream bout(fileName, ios::out | ios::binary);
    if (!bout)
    {
        cout << "Файл не может быть открыт или создан" << endl;
        return;
    }
    Node<T>* tmp = first_;
    unsigned int id = 0;
    while (tmp != nullptr) {
        for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
            Str<T>* tmpStr = tmp->getStr(i);
            /*if (tmpStr == nullptr) { continue; }*/
            if (tmpStr->getString() != nullptr) {
                //fout << *tmpStr;
                T* tmpString = tmpStr->getString();
                size_t len = strlen(tmpString);
                bout.write((char*)&len, sizeof(len));
                bout.write(tmpString, len);
            }
        }
        tmp = tmp->getNext();
    }
    bout.close();    
}
template <class T> void List<T>::sort() {
    if (first_ == nullptr) {
        cout << "Структура пуста" << endl;
    }
    Node<T>* tmp = first_;
    unsigned int id = 0;
    while (tmp != nullptr) {
        for (int i = 0; i < ListVariable::ARR_SIZE; i++) {
            Str<T>* tmpStr = tmp->getStr(i);

            Node<T>* tmp2 = tmp;
            bool hit = true;
            if (i == ListVariable::ARR_SIZE - 1) { // если следуюзий элемент не в текущемм массиве
                tmp2 = tmp->getNext();
                hit = false;
            }                        
            while (tmp2 != nullptr) {
                int j = 0;
                if (hit) { // первый раз следующий элемент может быть в том же массиве
                    j = i + 1;
                    hit = false;
                }
                for (; j < ListVariable::ARR_SIZE; j++) {
                    Str<T>* tmpStr2 = tmp2->getStr(j);
                    if (tmpStr->getString() == nullptr || tmpStr2->getString() == nullptr) {
                        continue;
                    }
                    if (*tmpStr > *tmpStr2) {
                        Str<T>* copy = new Str<T>; copy->copyString(tmpStr);
                        tmpStr->copyString(tmpStr2);
                        tmpStr2->copyString(copy);
                        delete copy;

                        /*Str<T>* StrOld = last_->getStr(i);
                        Str<T>* StrNew = newNode->getStr(j);
                        StrNew->copyString(StrOld);
                        StrOld->setString(nullptr); StrOld->setSize(0);*/
                    }
                }
                tmp2 = tmp2->getNext();
            }
        }
        tmp = tmp->getNext();
    }
}