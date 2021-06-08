// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>


template <typename T>
Array <T>::Array(void)
{
    this->data_ = new T[0];;
    this->cur_size_ = 0;
    this->max_size_ = 0;
}

template <typename T>
Array <T>::Array (size_t length)
{
    this->data_ = new T[length];
    this->cur_size_ = length;
    this->max_size_ = length;
    

    for (int i = 0; i < length; i++) {
        data_[i] = '\0';
    }
}

template <typename T>
Array<T>::Array (size_t length, T fill)
{
   this->data_ = new T[length];

    this->data_[0] = fill;
    this->cur_size_ = length;
    this->max_size_ = length;
    
    for (int i = 1; i < length; i++) {
        data_[i] = '\0';
    }
}

template <typename T>
Array<T>::Array (const Array & array){

    this->data_ = array.data_;
    this->cur_size_ = array.cur_size_;
    this->max_size_ = array.max_size_;
}

template <typename T>
Array<T>::~Array (void)
{  
    this->cur_size_ = 0;
    this->max_size_ = 0;
    this->data_= 0;   
    
}

template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    this->data_ = rhs.data_;
    this->cur_size_ = rhs.cur_size_;
    this->max_size_ = rhs.max_size_;
    return *this;
}

template <typename T>
T & Array <T>::operator [] (size_t index)
{
    if (index >= this->cur_size_) {
        throw std::out_of_range("ex");
    }
    else {
        return this->data_[index];
    }
}

template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    if (index > this->cur_size_) {
        throw std::out_of_range("ex");
    }
    else {
        const T temp = data_[index];
        return temp;
    }
}

template <typename T>
T Array <T>::get (size_t index) const
{
    if (index >= cur_size_) {
        throw std::out_of_range("ex");
    }
    else {
        return data_[index];
    }
}

template <typename T>
void Array <T>::set (size_t index, T value)
{
    if (index >= cur_size_) {
        throw std::out_of_range("ex");
    }
    else {
       data_[index] = value;
    }
}

template <typename T>
void Array <T>::resize (size_t new_size)
{
    size_t newSize = new_size;

    T temp[sizeof(data_)];
   
    if (cur_size_ > new_size) {
        for (int i = new_size; i < cur_size_; i++) {
            data_[i] = 0;
        }
    }

    if (cur_size_ < new_size) {
        if (new_size > max_size_) max_size_ = new_size;
        for (int j = cur_size_; j < new_size; j++) {
            data_[j] = 0;
        }
    } 
    cur_size_ = new_size;
}

template <typename T>
int Array <T>::find (T value) const
{
    for (int i = 0; i < cur_size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
int Array <T>::find (T value, size_t start) const
{
    if (start > cur_size_) {
        throw std::out_of_range("ex");
    }

    for (size_t i = start; i < cur_size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{ 
    
    for (int i = 0; i < cur_size_; i++) {
        if (this->data_[i] != rhs.data_[i]) {
            return false;
        }
    }
    
    
    if (this->cur_size_ == rhs.cur_size_) {
        if (this->max_size_ == rhs.max_size_) {
            return true;
        }
   }
    return false;
}

template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
    if (this->data_ != rhs.data_) {
        return true;
    }
    else if (this->cur_size_ != rhs.cur_size_) {
        return true;
    }
    else if (this->max_size_ != rhs.max_size_) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void Array <T>::fill(T value)
{
    for (int i = 0; i < cur_size_; i++) {
        if (data_[i] == 0) {
            data_[i] = (T)value;
            break;
        }
        else if (i == cur_size_-1) {
            break;
        }
    }

}

template <typename T>
void Array <T>::shrink (void)
{
    size_t tCount = 0;
    size_t freeCount = 0;

    for (int i = 0; i < cur_size_; i++) {
        if (data_[i] != 0) {
            tCount++;
        }
        else {
            freeCount++;
        }
   }

    if (tCount != cur_size_) {
        for (int j = tCount; j < cur_size_; j++) {
            this->data_[j] = '\0';
        }
        cur_size_ = tCount;
    }
}

template <typename T>
void Array <T>::reverse (void)
{
    size_t end = cur_size_-1;

    for (int i = 0; i < end; i++) {
        T temp = data_[i];
        data_[i] = data_[end];
        data_[end] = temp;
        end--;
    }
}

template <class T>
Array <T> Array <T>::slice (size_t begin) const
{
    Array arr; 
    size_t newSize = cur_size_ - begin;
    size_t start = 0;
    arr.data_ = new T[newSize];
    for (int i = begin; i < cur_size_; i++) {
        arr.data_[start] = data_[i];
        start++;
    }

    arr.cur_size_ = newSize;
    arr.max_size_ = newSize;

    return arr;
}

template <class T>
Array <T> Array <T>::slice (size_t begin, size_t end) const
{
    Array arr;
    size_t newSize = end - begin;
    size_t start = 0;

    arr.data_ = new T[newSize];
    
    for (int i = begin; i < end; i++) {
        arr.data_[start] = data_[i];
        start++;
    }

    arr.cur_size_ = newSize;
    arr.max_size_ = newSize;
    
    return arr;
}

