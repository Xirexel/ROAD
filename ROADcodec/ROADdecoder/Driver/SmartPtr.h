#ifndef SMARTPTR_H
#define SMARTPTR_H

namespace ROADdecoder
{
    namespace Driver
    {

    template <class T>
    class SmartPtr
    {
    public:

        SmartPtr()
            :element(nullptr)
        {
        }

        virtual ~SmartPtr()
        {
            Release();
        }

        T* Detach()
        {
            auto lOutPtr = element;

            element = nullptr;

            return lOutPtr;
        }

        void Release()
        {
            if (element == nullptr)
                return;

            element->Release();

            element = nullptr;
        }

        SmartPtr& operator = (T *pElement)
        {
            Release();

            if (pElement == nullptr)
            {
                element = nullptr;
            }
            else
            {
                pElement->AddRef();

                element = pElement;
            }

            return *this;
        }

        T* operator->()
        {
            return element;
        }

        operator T*()
        {
            return element;
        }

        operator T*() const
        {
            return element;
        }

        T* get()
        {
            return element;
        }

        T** operator &()
        {
            return &element;
        }

        bool operator !()
        {
            return element == nullptr;
        }

        bool operator == (const T *pElement)
        {
            return element == pElement;
        }


        SmartPtr(const SmartPtr&) = delete;

        SmartPtr& operator = (const SmartPtr&) = delete;

    private:

        T* element;
    };

    }
}

#endif // SMARTPTR_H
