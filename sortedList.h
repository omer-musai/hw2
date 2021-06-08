#include <stdexcept>

template<class T>
class SortedList
{
    private:
        struct Node{
            T data;
            struct Node* next;

            explicit Node(T data) : data(data), next(nullptr)
            {}
        };

        Node* list;

        Node* findPreviousElementPosition(const T element) const;
        static void freeList(Node* list);
        static Node* copyList(Node* list);
    public:
        SortedList(); 
        ~SortedList();
        SortedList(const SortedList& list);
        SortedList& operator=(const SortedList& list);
        void insert(const T element);
        
        int length() const;

        template<class C>
        SortedList filter(C condition);

        template<class A>
        SortedList apply(A action);


        class const_iterator;

        const_iterator begin() const;
        const_iterator end() const;   

        void remove(const_iterator& iterator);

};


//class of the iterator
template<class T>
class SortedList<T>::const_iterator
{
    private:
        Node* current;
        
        //user doesn't have access to the standard constructor  NOT SURE IF WE ASKED TO IMPLEMENT OR JUST USE THE "const_iterator();"
        const_iterator(Node* current);
        friend class SortedList;
    public:
        const_iterator() = delete;
        const_iterator(const const_iterator& iterator);
        const_iterator& operator=(const const_iterator& iterator);
        ~const_iterator() = default;
        void operator++(); //throw out_of_range if iterator points to end of list
        bool operator==(const const_iterator& iterator);
        const T& operator*();
};
       


template<class T>
SortedList<T>::SortedList() : list(nullptr) {}


template<class T>
SortedList<T>::~SortedList()
{
   freeList(list);
}

template<class T>
SortedList<T>::SortedList(const SortedList<T>& sorted_list)
{   
    this->list = copyList(sorted_list.list);
}


template<class T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& sorted_list)
{   
    if(this == &sorted_list)
    {
        return *this;
    }

    Node* new_list = copyList(sorted_list.list);
    freeList(this->list);
    this->list = new_list;
    
    return *this;
}



template<class T>
void SortedList<T>::insert(const T element)
{
    Node* new_node = new Node(element);

    Node* previous = findPreviousElementPosition(element);

    if(previous == nullptr)//there is no previous
    {
        new_node->next = this->list;
        
        this->list = new_node;
        return;
    }

    new_node->next = previous->next;
    previous->next = new_node;
    
}


template<class T>
void SortedList<T>::remove(const_iterator& iterator)
{
    if(iterator == end())
    {
        throw std::out_of_range("Attempted to remove after reaching the end of the list.");
    }

    Node *previous = findPreviousElementPosition(*iterator);
    if (previous == nullptr) //First element.
    {
        Node *newHead = list->next;
        delete list;
        list = newHead;
        return;
    }
    previous->next = iterator.current->next;
    delete iterator.current;
}

template<class T>
int SortedList<T>::length() const
{
    int len =0;
    Node* current = list;

    while(current != nullptr)
    { 
        ++len;
        current = current->next;
    }
    return len;
}

template<class T>
template<class C>
SortedList<T> SortedList<T>::filter(C condition)
{
    SortedList<T> new_list = SortedList<T>();
    for (SortedList<T>::const_iterator i = this->begin(); !(i == this->end()); ++i)
    {
        if (condition(*i))
        {
            new_list.insert(*i);
        }
    }

    return new_list;
}

template<class T>
template<class A>
SortedList<T> SortedList<T>::apply(A action)
{
    SortedList<T> new_list = SortedList<T>();
    for (SortedList<T>::const_iterator i = this->begin(); !(i == this->end()); ++i)
    {
        new_list.insert(action((*i)));
    }

    return new_list;
}

template<class T>
SortedList<T>::const_iterator::const_iterator(Node* current) : current(current) {}



template<class T>
SortedList<T>::const_iterator::const_iterator(const const_iterator& iterator) : current(iterator.current) {}


template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const const_iterator& iterator)
{
    if(this == &iterator)
    {
        return *this;
    }

    this->current = iterator.current;
    return *this;
}

template<class T>
void SortedList<T>::const_iterator::operator++()
{
    if(current == nullptr)
    {
        throw std::out_of_range("Reached the end of the list.");
    }
    current = current->next;
}                

template<class T>             
bool SortedList<T>::const_iterator::operator==(const const_iterator& iterator)
{
    return (this->current == iterator.current);
}

template<class T>
const T& SortedList<T>::const_iterator::operator*()
{
    return current->data;
}

template<class T>
typename SortedList<T>::Node* SortedList<T>::findPreviousElementPosition(const T element) const
{
    if (list == nullptr)
    {
        return nullptr;
    }

    if(list->data >= element)//element need to be first
    {
        return nullptr;
    }

    Node *current = list->next, *previous = list;

    while(current != nullptr)
    {
        if(current->data >= element)
        {
            return previous;
        }

        previous = current;
        current = current->next;
    }

    return previous;
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const
{
    return const_iterator(this->list);
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const
{
     
    return const_iterator(nullptr);
}

template<class T>
void SortedList<T>::freeList(Node* list)
{
    while (list != nullptr)
    {
        Node* tmp = list->next;
        delete list;
        list = tmp;
    }
}

template<class T>
typename SortedList<T>::Node* SortedList<T>::copyList(typename SortedList<T>::Node* list)
{
    SortedList<T>::Node *new_list = nullptr, *end_ptr, *new_node;

    if (list != nullptr)
    {
        new_list = new SortedList<T>::Node(list->data);
        end_ptr = new_list;
        list = list->next;
    }

    while (list != nullptr)
    {
        try
        {
            new_node = new SortedList<T>::Node(list->data);
            end_ptr->next = new_node;
            end_ptr = new_node;
            list = list->next;
        }
        catch (std::exception& exception)
        {
            SortedList<T>::freeList(new_list);
            throw exception;
        }
    }

    return new_list;
}
