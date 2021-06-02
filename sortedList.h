
typedef int T; //remember to delete

template<class T>
class SortedList
{
    private:
        class Node
        {
            private:
                T value;
                Node* next;
           
            public: 
                Node(); //need to implement
                ~Node();
                Node(const Node& Node);
     
        };

        
    public:
        SortedList(); 
        ~SortedList();
        SortedList(const SortedList& list);
        SortedList& operator=(const SortedList& list);
        void insert(T element);
        
        int length();

        SortedList filter(bool function(T type)); //need to use another template for this 1

        SortedList apply(T function(T type)); //need to use another template for this 1


        class const_iterator
        {
            private:
            
            public:
                //user doesn't have access to the standard constructor
                const_iterator() = delete;

                const_iterator(const const_iterator& iterator);
                const_iterator& operator=(const const_iterator& iterator);
                ~const_iterator();
                void operator++(); //throw out_of_range if iterator points to end of list
                bool operator==(const const_iterator& iterator);
                const const_iterator& operator*();
        };
        
        const_iterator begin() const;
        const_iterator end() const;   

        void remove(const_iterator iterator);

};


template<class T>
SortedList<T>::SortedList()
{
   
}

template<class T>
SortedList<T>::~SortedList()
{

}

template<class T>
SortedList<T>::SortedList(const SortedList<T>& list)
{

}

template<class T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& list)
{

}

template<class T>
void SortedList<T>::insert(T element)
{

}

template<class T>
void SortedList<T>::remove(const_iterator iterator)
{

}

template<class T>
int SortedList<T>::length()
{

}

template<class T>
SortedList<T> SortedList<T>::filter(bool function(T type)) //need to use another template for this 1
{

}

template<class T>
SortedList<T> SortedList<T>::apply(T function(T type)) //need to use another template for this 1
{

}

template<class T>
SortedList<T>::const_iterator::const_iterator(const const_iterator& iterator)
{

}

template<class T>
SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const const_iterator& iterator)
{

}

template<class T>
SortedList<T>::const_iterator::~const_iterator()
{

}

template<class T>
void SortedList<T>::const_iterator::operator++() //throw out_of_range if iterator points to end of list
{

}                

template<class T>             
bool SortedList<T>::const_iterator::operator==(const const_iterator& iterator)
{

}

template<class T>
const SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator*()
{

}