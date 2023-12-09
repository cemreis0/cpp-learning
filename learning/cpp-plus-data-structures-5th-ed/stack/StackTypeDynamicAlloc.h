// cpp-plus-data-structures-5th-ed/stack/StackTypeDynamicAlloc.h

class StackTypeDynamicAlloc
{
    public:
        StackTypeDynamicAlloc(int max);
        ~StackTypeDynamicAlloc();
        // rest
    private:
        int maxStack;
        int top;
        char* items;
};