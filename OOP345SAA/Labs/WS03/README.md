# Templates

## Learning Outcomes
- design and code a class template
- template a class variable
- specialize a class template for a particular type
- instantiate a template class
- specialize a member function of a class template to process a particular type
- derivate a template class from another template class

### Designing and coding a class template + template a class variable

```cpp
template <class T> 
class Array { 
private: 
    T *ptr; 
    int size; 
public: 
    Array(T arr[], int s);
    {
      ptr = new T[s]; 
      size = s; 
      for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
    }
    void print()
    {
      for (int i = 0; i < size; i++) 
        cout<<" "<<*(ptr + i); 
      cout<<endl;
    }
};
```