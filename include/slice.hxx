#ifndef __HEAD_SLICE
#define __HEAD_SLICE

template <typename T>
class slice{
public:
    class();
    class(int len = 0, int cap = 0);
private:
    int len;
    int cap;
    T* ptr;
};

#endif