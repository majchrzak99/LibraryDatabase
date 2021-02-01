#ifndef LIST_H
#define LIST_H

template <class T> class List
{
private:
    class elementPointer{
    private:
        T data;
        elementPointer* nextElement;
    public:
        elementPointer* next(){
            return this->nextElement;
        }
    };
    elementPointer* start;
    elementPointer* back;
public:
    elementPointer* begin(){
        return this->start;
    }
    elementPointer* end(){
        return this->start;
    }
    List()
    {
        this->start= nullptr;
    }
    ~List()
    {
        while(this->start != nullptr){
            elementPointer* tmp = this->start->nextElement;
            delete this->start;
            this->start = tmp;
        }
    }
    void Add(T item)
    {

        if(this->start == nullptr)
        {
            this->start = new elementPointer;
            this->start->data = item;
            this->start->nextElement = nullptr;
            this->back = start;
        }
        else
        {
            elementPointer* p = this->start;

            //szukam ostatniego elementu
            while(p->nextElement != nullptr)
            {
                p = p->nextElement;
            }
            p->nextElement = new elementPointer();
            p->data = item;
            p->nextElement = nullptr;
        }
    }
    void Remove(T* item)
    {
        //przeszukać listę i dla każdego elementu porównać referencję(adresy) z przkazanym parametrem
        elementPointer** tmp = &(this->start);

        while(*tmp != nullptr)
        {
            if(&((*tmp)->data) == item)
            {
                elementPointer* t = (*tmp)->nextElement;
                delete *tmp;
                *tmp = &t;
                return;
            }
            else
            {
                tmp = &(tmp->next);
            }
        }
        return;
    }
    template<typename Function> List<T> Where(Function predicate)
    {
        List<T> returnList;
        //dla każdego elementu w liście
        T element;
        if(predicate(element))
        {
            returnList.Add(element);
        }

        //koniec przeszukiwania
        return returnList;
    }
    template<typename Function> T* FirstOrDefault(Function predicate)
    {
        //zacznij przeszukiwać listę
        elementPointer* tmp = this->start;
        while(tmp != nullptr)
        {
            if(predicate(tmp->data))
            {
                return &(tmp->data);
            }
            else
            {
                tmp = tmp->nextElement;
            }
        }

        return nullptr;
        //koniec przeszukiwania
    }

};
template <class T>
class List
{

};

#endif // LIST_H
