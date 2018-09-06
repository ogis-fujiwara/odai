#include <iostream>

void my_memmove(char* dest, char const* src, size_t size) {
#if 0
    std::memmove(dest, src, size);
#else
    // your implementation here
    if (src < dest && dest < src+size) {
        for (size_t i = size; i > 0; i--) {
            dest[i-1] = src[i-1];
        }
    }
    else {
        for (size_t i = 0; i < size; i++) {
            dest[i] = src[i];
        }
    }
#endif
}

int main() {
    {
        char buf[] = "0123456789";
        my_memmove(buf, buf + 2, 4);
        std::cout << buf << std::endl;
    }
    {
        char buf[] = "0123456789";
        my_memmove(buf + 2, buf, 4);
        std::cout << buf << std::endl;
    }
    {
        char buf[] = "0123456789";
        my_memmove(buf, buf + 5, 4);
        std::cout << buf << std::endl;
    }
    {
        char buf[] = "0123456789";
        my_memmove(buf, buf, 4);
        std::cout << buf << std::endl;
    }
}