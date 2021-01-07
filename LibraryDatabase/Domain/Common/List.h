#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
private:
    struct elementPointer{
        T* data;
        elementPointer* next;
    };
    elementPointer* start;
public:
    List<T>();
    ~List<T>();
    void Add(T* item);
    void Remove(T* item);
    template<typename Function> List<T> Where(Function predicate);
    template<typename Function> T FirstOrDefault(Function predicate);
};

#endif // LIST_H
