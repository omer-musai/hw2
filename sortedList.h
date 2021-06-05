
typedef int T; //remember to delete

template<class T>
class SortedList
{
    private:
        typedef struct node_t
        {
            T data;
            struct node_t* next;
           
        } *Node;

        Node list;
         
        Node findPreviousElementPosition(Node current, T element);
    public:
        SortedList(); 
        ~SortedList();
        SortedList(const SortedList& list);
        SortedList& operator=(const SortedList& list);
        void insert(T element);
        
        int length();

        SortedList filter(bool function(T type)); //need to use another template for this 1

        SortedList apply(T function(T type)); //need to use another template for this 1


        class const_iterator;
        
        const_iterator begin() const;
        const_iterator end() const;   

        void remove(const_iterator iterator);

};


//class of the iterator
template<class T>
class SortedList<T>::const_iterator
{
    private:
        Node current;
        
        //user doesn't have access to the standard constructor  NOT SURE IF WE ASKED TO IMPLEMENT OR JUST USE THE "const_iterator();"
        const_iterator(Node current);

    public:
                
        const_iterator(const const_iterator& iterator);
        const_iterator& operator=(const const_iterator& iterator);
        ~const_iterator();
        void operator++(); //throw out_of_range if iterator points to end of list
        bool operator==(const const_iterator& iterator);
        const Node& operator*();
};
       






template<class T>
SortedList<T>::SortedList()
{
   list = NULL;
}

template<class T>
SortedList<T>::~SortedList()
{
    while (list != NULL)
    {
        Node next_node = list->next;
        
        //FIGURE OUT WHAT EXACTLY TO WRITE HERE AFTER IMPLEMENTATION OF INSERT AND REMOVE
        destroy(list->data);
        destroy(list);
        list = next_node;
    }
}

template<class T>
SortedList<T>::SortedList(const SortedList<T>& sorted_list)
{   
    //NOT SURE IF WE SHOULD USE INSERT SINCE THE GIVEN LIST IS ALREADY SORTED
    while(sorted_list.list != NULL)
    { 
        this->insert(sorted_list.list->data);

        sorted_list.list = sorted_list.list->next;
    }
}

template<class T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& sorted_list)
{   
    if(this == &sorted_list)
    {
        return *this;
    }

    while(sorted_list.list != NULL)
    { 
        this->insert(sorted_list.list->data);

        sorted_list.list = sorted_list.list->next;
    }

    return *this;
}



template<class T>
void SortedList<T>::insert(T element)
{
    Node new_node = new Node;
    
    new_node->data = element;
    new_node->next = NULL;

    Node previous = findPreviousElementPosition(this->list, element);

    if(previous == NULL)//there is no previous
    {
        new_node->next = this->list;
        
        this->list = new_node;
        return;
    }

    new_node->next = previous->next;
    previous->next = new_node;
    
        
}

template<class T>
void SortedList<T>::remove(const_iterator iterator)
{

}

template<class T>
int SortedList<T>::length()
{
    int len =0;
    
    while(list != NULL)
    { 
        ++len;
        list = list->next;
    }
    return len;
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
SortedList<T>::const_iterator::const_iterator(const const_iterator& iterator) : current(iterator.current)
{
}

template<class T>
SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const const_iterator& iterator)
{
    if(this == &iterator)
    {
        return *this;
    }

    this->current = iterator->current;
    return *this;
}

template<class T>
SortedList<T>::const_iterator::~const_iterator()
{
  
}

template<class T>
void SortedList<T>::const_iterator::operator++()
{
    if(current->next == NULL)
    {
        throw std::out_of_range;
    }
    current = current->next;
}                

template<class T>             
bool SortedList<T>::const_iterator::operator==(const const_iterator& iterator)
{
    return (this->current == iterator->current)
}

template<class T>
const SortedList<T>::Node& SortedList<T>::const_iterator::operator*()
{
    const Node tmp = *current;

    return &tmp;
}

template<class T>
SortedList<T>::Node SortedList<T>::findPreviousElementPosition(Node current, T element)
{
    if(current->data > element)//element need to be first
    {
        return NULL;
    }

    while(current->next != NULL)
    {
        if(current->next->data > element)
        {
            return current;
        }

        current->next = current->next->next;
    }

    return current;
}