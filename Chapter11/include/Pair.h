//
// Created by tkhle on 18.07.2023.
//

#ifndef CHAPTER11_PAIR_H
#define CHAPTER11_PAIR_H

// We use "=" with the second typename, so that we can specify pairs with a single typename instead of defining it twice
// e.g. Pair<int> instead of Pair<int, int>
template <typename T, typename U=T>
class Pair {
    T f;
    U s;
public:
    Pair(const T& first, const U& second) : f(first), s(second) {}

    T first() const {
        return f;
    }

    U second() const {
        return s;
    }

    bool operator==(Pair<T, U>& other) const {
        return f == other.f && s == other.s;
    }
};

template <typename T, typename U = T>
bool comparePairs(Pair<T, U>& p1, Pair<T, U>& p2) {
    return p1.first() == p2.first() && p1.second() == p2.second();
}

#endif //CHAPTER11_PAIR_H
