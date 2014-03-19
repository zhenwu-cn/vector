#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_
#include <iostream>
namespace qh
{
    template<class T>
    class vector {
    public:
        //ctor
        vector()
            : data_(NULL), size_(0), capacity_(0)
        {
        }

        explicit vector( size_t n, const T& value = T())
        {
            data_ = new T[n];
            for (size_t i = 0; i < n; i++)
            {
                data_[i] = value;
            }
            size_ = n;
            capacity_ = n;
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
            data_ = rhs.data_;
            size_ = rhs.size_;
            capacity_ = rhs.capacity_;
            return *this;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        // set & get
        T& operator[](size_t index)
        {
            return data_[index];
        }

        // set
        void push_back(const T& element)
        {
            if(size_ == capacity_)
                reserve(2 * capacity_ + 1);
            data_[size_++] = element;
        }

        void pop_back()
        {
            if(size_ == 0)
                return;
            size_ --;
        }

        void resize(size_t new_size_)
        {
            if(new_size_ < size_)
                return;
            else if(new_size_ <= capacity_)
                size_ = new_size_;
            else
                reserve(2 * capacity_ + 1);
        }

        void reserve(size_t new_capacity_)
        {
            T* olddata_ = data_;
            data_ = new T[new_capacity_];
            for(size_t i = 0; i < size_; i++)
            {
                data_[i] = olddata_[i];
            }
            capacity_ = new_capacity_;
            delete []olddata_;
        }

        T begin()
        {
            return data_[0];
        }

        T end()
        {
            return data_[size_ - 1];
        }

        void clear()
        {
            delete []data_;
            size_ = 0;
            capacity_ = 0;
        }

        bool empty()
        {
            if(size() == 0){
                // std::cout<<"vector is empty"<<std::endl;
                return true;
            }
            else
                return false;
        }

    private:
        T*      data_;
        size_t  size_;
        size_t  capacity_;
    };
}

#endif

