#include <iostream>


using namespace std;

template< class T>
class Vector
{
 private:
    T* _data;
    int _Size,_Capacity;


 public:
     // declaration the default constructor.
    Vector(){
        _Capacity = _Size = 0;
        _data = NULL;
    } // end the default constructor.


    // declaration copy constructor.
    Vector(const Vector<T>& vec) {  clone(vec); }



    Vector &operator=(const Vector&vec) {

        delete [] _data;
        clone(vec);
        return *this;

        }



    // declaration another constructor to set the capacity and default value to  vector.
   explicit Vector(int sz,T defaultValue = T()) {


        _data = allocateMemory(sz);
        for(int i = 0;i<sz;++i)
            _data[i] = defaultValue;

         _Capacity =_Size = sz;
    } // end constructor


    // overloading [] operator;
    T& operator[](int index) {
           return _data[index];

    } //end overloading [] operator function.



    int Size() {return _Size;}
    // postcondition: return the size of Vector;


    int Capacity() { return _Capacity;}
    //postcondition :return the capacity  of vector.



    //precondition: vector must have at least one element;
    void Pop_back() {--_Size;}
    // postcondition: delete one element from the last of vector.


    //precondition:vector must have at least one element.
    void Clear() {_Size = 0;}
    //postcondition: delete all elements from vector.


    // precondition: vector must have at least one element.
    T& Back() {return _data[_Size-1];}
    // postcondition: return last element in vector.

    //precondition: vector must have at least one element.
    T& Front() {return _data[0];}
    // postcondition:return front element in vector.

// declaration push_back function.
    void Push_back( const T& value) {

       if(_Size == _Capacity)
       {
          _Capacity ==0?_Capacity = 1:_Capacity*=2;
          T* temp = new T[_Capacity];
          for(int i =0;i<_Size;i++)
          {

              temp[i] = _data[i];
          }
          delete _data;
          _data = temp;

          _data[_Size] = value;

       }
       else {

           _data[_Size] = value;

       }
      _Size++;
    } // end Push_back function.
    //postcondition:push one element in the end of function.

    // precondition the Vector has at least one element.
    void Erase(int index)
    {
        if(index<_Size)
        {
            for(int i =index;i<_Size-1;i++)
            {
                _data[i] =_data[i+1];
            }
              --_Size;
        }

    } // postcondition: delete one element at specific position in


    // declaration insert function.

    void Insert(int index,const T&val)
    {
        Push_back(val);

        for(int i =_Size-1;i>=index;--i)
        {
            _data[i] = _data[i-1];
        }
        _data[index] = val;
    }

   // declaration Empty function.
   bool Empty() { return _Size ==0;}
   // postcondition: return true if the vector


   ~Vector() {
       delete [] _data;
   }

 private:
     // this helper function to allocate memory
    T* allocateMemory(int sz) {
        return new T[sz];
    } // end allocateMemory function.

    // declaration clone function to copy constructor.
    void clone(const Vector<T>&vec)
    {
        _Capacity = _Size = vec._Size;
        _data = allocateMemory(_Size);
        for(int i =0;i<vec._Size;++i)
        {

            _data[i]= vec._data[i];
        }
    } // end clone vector.

}; // end Vector class.

int main()
{


    return 0;
}
