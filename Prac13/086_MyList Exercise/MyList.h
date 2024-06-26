//
// Created by codjs on 2024-06-06.
//

#ifndef   MYLIST_H
#define   MYLIST_H
#include <cstddef>
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>

template<typename T, size_t N>
class MyList {
public:
    MyList(): size(N) {
        _data = new T[N];
        pos = 0;
    };
    MyList(const MyList& rhs) noexcept {
        size = rhs.size;
        pos = rhs.pos;
        _data = new T[size];
        for ( int i = 0; i < size ; i++){
            _data[i] = rhs._data[i];
        }
    };
    MyList& operator=(const MyList& rhs){
        size = rhs.size;
        pos = rhs.pos;
        _data = new T[size];
        for ( int i = 0; i < size ; i++){
            _data[i] = rhs._data[i];
        }
        return *this;
    };
    ~MyList() noexcept {
        delete [] _data;
        //소멸자 선언.. 해줘야하나 봐..
    };
    void add(T& data){
        _data[pos++] = data;

    };
    void remove(T& data){
        auto it = std::find(begin(),end(),data);
        // 요소가 리스트 내에 존재하는 경우
        if (it != end()) {
            // 'it + 1'부터 'end()'까지의 요소들을 'it' 위치로 이동
            std::move(it + 1, end(), it); // move는 iterator 로 작동함
            _data[size-1] = T(); // reset the last element
            pos--;

        }
    };
    const T* begin() const {return _data;}
    const T* end() const {return _data + N;}

    T* begin() {return _data;}
    T* end() {return _data + N;}

private:
    T* _data= nullptr;
    int size = 0;
    int pos = 0;
};
#endif //  MYLIST_H
