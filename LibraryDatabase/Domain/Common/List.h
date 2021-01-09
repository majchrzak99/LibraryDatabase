#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
private:
    struct elementPointer{
        T data;
        elementPointer* next;
    };
    elementPointer* start;
public:
    List()
    {
        this->start= nullptr;
    }
    ~List()
    {
        while(this->start != nullptr){
            elementPointer* tmp = this->start->next;
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
            this->start->next = nullptr;
        }
        else
        {
            elementPointer* p = this->start;

            //szukam ostatniego elementu
            while(p->next != nullptr)
            {
                p = p->next;
            }
            p->next = new elementPointer();
            p->data = item;
            p->next = nullptr;
        }
    }
    void Remove(T* item)
    {
        //przeszukać listę i dla każdego elementu porównać referencję(adresy) z przkazanym parametrem
        elementPointer* tmp = this->start;

        while(tmp != nullptr)
        {
            if(&(tmp->data) == item)
            {
                elementPointer* tmp = this->start->next;
                delete this->start;
                this->start = tmp;
                return;
            }
            else
            {
                tmp = tmp->next;
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
                tmp = tmp->next;
            }
        }

        return nullptr;
        //koniec przeszukiwania
    }

};

#endif // LIST_H
