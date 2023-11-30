#pragma once

template<typename T>
struct node {
    T data;
    node<T>* prev;
    node<T>* next;
    node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

