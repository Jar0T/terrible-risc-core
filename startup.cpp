typedef void (*func_ptr)();

extern func_ptr __ctors_start[];
extern func_ptr __ctors_end[];

extern "C" void callConstructors()
{
    for (func_ptr *ctor = __ctors_start; ctor < __ctors_end; ++ctor)
    {
        (*ctor)(); // Call each constructor
    }
}
