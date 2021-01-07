#include "list.h"

template <class T> List<T>::List(){

}

template <class T> List<T>::~List(){

}

template <class T> void List<T>::Add(T* item){

}

template <class T> void List<T>::Remove(T* item){

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
