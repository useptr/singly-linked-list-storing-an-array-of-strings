#include "List.h"
//template <class T> Str<T>::Str() : str_{ nullptr }, size_{ 0 } {}
//template<typename T> ostream& operator<<(ostream& os, Str<T>& obj) {
//    os << obj.str_ << endl;
//    return os;
//}
//template <class T> Str<T>::Str() : str_{ nullptr }, size_{0} {}
//template <class T> Str<T>::Str(T* str, unsigned int size) : size_{ size } {
//	str_ = new T[size];
//	strcpy(str_, str);
//}
//template <class T> Str<T>::~Str() {
//	if (str_ != nullptr) {
//		delete[] str_;
//	}
//}
//template <class T> void Str<T>::setCh(T ch, unsigned int i) {
//    if (i < size_) {
//        str_[i] = ch;
//    }
//}
//template <class T> void Str<T>::resize() {
//    T* reStr;
//    reStr = new T[size_ * 2];
//    for (int i = 0; i < size_; i++) {
//        reStr[i] = str_[i];
//    }      
//    delete[] str_;
//    str_ = reStr;
//    size_ *= 2;
//}
//template <class T> istream& operator>>(istream& in, Str<T>& obj) {
//    T ch; unsigned int counter = 0;
//    while (ch != '\n') {
//        in >> ch;
//        obj->setCh(ch, counter);
//        counter++;
//    }
//    return in;
//}
//template <class T> T* Str<T>::getStr() const {
//    return str_;
//}
//template <class T> ostream& operator<< (ostream& out, Str<T>& obj) {
//    //out << "str_: " << obj.str_ << endl;
//    return out;
//}
//template class Str<char>;