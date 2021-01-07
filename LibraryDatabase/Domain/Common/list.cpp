#include "list.h"

template <class T> List<T>::List(){
    this->start == nullptr;
}

template <class T> List<T>::~List(){
    while(this->start != nullptr){
        elementPointer* tmp = this->start->next;
        delete this->start;
        this->start = tmp;
    }
}

template <class T> void List<T>::Add(T* item){

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

template <class T> void List<T>::Remove(T* item)
{
    //przeszukać listę i dla każdego elementu porównać referencję(adresy) z przkazanym parametrem
}

template <class T> template<typename Function> List<T> List<T>::Where(Function predicate)
{
    List<T> returnList;
    //dla każdego elementu w liście
    T* element;
    if(predicate(element))
    {
        returnList.Add(element);
    }

    //koniec przeszukiwania
    return returnList;
}

template <class T> template<typename Function> T List<T>::FirstOrDefault(Function predicate)
{
    //zacznij przeszukiwać listę
    T* element;
    if(predicate(element))
    {
        return *element;
    }

    //koniec przeszukiwania
}
