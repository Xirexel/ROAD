#ifndef MEMORYDEFINE
#define MEMORYDEFINE

#include <memory>
#include "platformdependencies.h"

namespace PlatformDependencies
{

    template<typename T>
    class UniqueMassive_ptr: private std::unique_ptr<T, void(*)(T*)>
    {
        ROADSize _length;

     public:
        UniqueMassive_ptr(T* aPtrData, ROADSize aLength):
            _length(aLength),
            std::unique_ptr<T, void(*)(T*)>(aPtrData, [](T* aPtrData){delete[] aPtrData;}){}

        ROADSize length() const noexcept
        {
            return _length;
        }

        typename std::add_lvalue_reference<T>::type
        operator[](size_t __i) const noexcept
        {
            return this->get()[__i];
        }

        operator T*()
        {
            return this->get();
        }

    };

    template<typename T>
    class Unique_ptr: private std::unique_ptr<T>
    {
     public:
        Unique_ptr(T* aPtrData):
            std::unique_ptr<T>(aPtrData){}

        Unique_ptr(){}

        void
        reset(T* __p) noexcept
        {
            std::unique_ptr<T>::reset(__p);
        }

        T* release() noexcept
        {
            return std::unique_ptr<T>::release();
        }

        T* operator->() const noexcept
        {
            return std::unique_ptr<T>::get();
        }

        T*
        get() const noexcept
        {
            return std::unique_ptr<T>::get();
        }

        /// Return @c true if the stored pointer is not null.
        explicit operator bool() const noexcept
        {
            return std::unique_ptr<T>::operator bool();
        }
    };

    template<typename T>
    class SharedMassive_ptr: private std::shared_ptr<T>
    {
        ROADSize _length;

     public:
        SharedMassive_ptr(T* aPtrData, ROADSize aLength):
            _length(aLength),
            std::shared_ptr<T>(aPtrData,
                            [](T* aPtrData){delete[] aPtrData;}){}

        SharedMassive_ptr(){}

        void reset(T* aPtrData, ROADSize aLength)
        {
            std::shared_ptr<T>::reset(aPtrData, [](T* aPtrData){delete[] aPtrData;});

            _length = aLength;
        }

        T* get() const noexcept
        {
            return std::shared_ptr<T>::get();
        }

        ROADSize length() const noexcept
        {
            return _length;
        }

        typename std::add_lvalue_reference<T>::type
        operator[](size_t __i) const
        {
            _GLIBCXX_DEBUG_ASSERT(get() != pointer());
            return std::shared_ptr<T>::get()[__i];
        }

    };

    template<typename T>
    class Shared_ptr: private std::shared_ptr<T>
    {
     public:
        Shared_ptr(T* aPtrData):
            std::shared_ptr<T>(aPtrData){}

        Shared_ptr(){}

        void reset(T* aPtrData)
        {
            std::shared_ptr<T>::reset(aPtrData);
        }

        T* get() const noexcept
        {
            return std::shared_ptr<T>::get();
        }

        T* operator->() const noexcept
        {
            return std::shared_ptr<T>::get();
        }
    };

}
#endif // MEMORYDEFINE

