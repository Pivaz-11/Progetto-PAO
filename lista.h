#ifndef LISTA_H
#define LISTA_H


template<class T>
class Lista {
private:
    class Nodo {
    public:
        T info;
        Nodo *prev, *next;
        Nodo(const T& t = T(), Nodo* p=nullptr, Nodo* n=nullptr):
            info(t), prev(p), next(n) {}
        ~Nodo() {delete next;}
    };
    Nodo *ultimo, *primo;
    unsigned int dim;

    static Nodo* copy(Nodo* p, Nodo*& l){
        if(p==nullptr) return nullptr;
        Nodo* ris = new Nodo(p->info);
        Nodo* it = ris;
        while(p->next!=nullptr){
            p=p->next;
            it=new Nodo(p->info, it, nullptr);
            (it->prev)->next=it;
        }
        l = it;
        return ris;
    }

public:
    ~Lista() {delete primo;}
    Lista(const Lista& d): primo(copy(d.primo,ultimo)),dim(d.dim) {
    }

    Lista& operator=(const Lista& d) {
        if(this != &d) {
            delete primo;
            primo=copy(d.primo,ultimo);
            dim = d.dim;
        }
        return *this;
    }

    void insertFront(const T& t) {
        primo = new Nodo(t,nullptr,primo);
        if(primo->next==nullptr) {
            ultimo=primo;
        }
        else {
            (primo->next)->prev=primo;
        }
        dim +=1;
    }

    void insertBack(const T& t) {
        ultimo = new Nodo(t,ultimo,nullptr);
        if((ultimo->prev)==nullptr) {
            primo=ultimo;
        }
        else {
            (ultimo->prev)->next=ultimo;
        }
        dim+=1;
    }
    void flush() {
        delete primo;
        dim = 0;
        primo = ultimo = nullptr;
    }
    unsigned int getSize() const{return dim;}
    Lista() : ultimo(nullptr), primo(nullptr), dim(0) {};
    Lista(unsigned int k, const T& t): ultimo(nullptr), primo(nullptr) {
        for(unsigned int i=0; i<k; ++i)
            insertFront(t);
        dim = k;
    }


    class Iterator {
        friend class Lista<T>;
    private:
        Nodo* ptr;
        bool pastTheEnd;
        Iterator(Nodo* p, bool pte=false): ptr(p), pastTheEnd(pte) {}
    public:
        Iterator(): ptr(nullptr), pastTheEnd(false) {}

        T& operator*() const {
            return ptr->info;
        }

        T* operator->() const {
            return &(ptr->info);
        }

        Iterator& operator++() {
            if(ptr!= nullptr) {
                if(!pastTheEnd) {
                    if(ptr->next==nullptr) {++ptr; pastTheEnd=true;}
                    else {ptr=ptr->next;}
                }
            }
            return *this;
        }

        Iterator& operator--() {
            if(ptr!=nullptr) {
                if(pastTheEnd) {--ptr; pastTheEnd=false;}
                else ptr=ptr->prev;
            }
            return *this;
        }

        bool operator==(const Iterator& x) const {
            return ptr==x.ptr;
        }

        bool operator!=(const Iterator& x) const {
            return ptr!=x.ptr;
        }
    };

    Iterator begin() const {
        return Iterator(primo);
    }

    Iterator end() const {
        if(ultimo==nullptr) return nullptr;
        return Iterator(ultimo+1,true);
    }

    void removeItem(Iterator& it){ //elimina il nodo puntato dall'iteratore e impostando il puntatore al nodo precedente
        if(it.ptr == nullptr) return;
        if(!it.pastTheEnd){
            if(it.ptr->next == it.ptr->prev){
                delete it.ptr;
                it.ptr=nullptr;
                dim--;
                ultimo = primo = nullptr;
                return;
            }
            if(it.ptr->prev == nullptr){
                primo = it.ptr->next;
                primo->prev = nullptr;
                it.ptr->next = nullptr;
                delete it.ptr;
                dim--;
                it.ptr = nullptr;
                return;
            }else{
                if(it.ptr->next == nullptr){
                    ultimo = ultimo->prev;
                    ultimo ->next = nullptr;
                    delete it.ptr;
                    dim--;
                    it.ptr = ultimo;
                    return;
                }else{
                    if(it.ptr->next != nullptr && it.ptr->next != nullptr){
                        it.ptr = (it.ptr)->prev;
                        (((it.ptr)->next)->next)->prev = it.ptr;
                        Nodo* tmp = (it.ptr)->next;
                        (it.ptr)->next = tmp->next;
                        tmp->next = nullptr;
                        delete tmp;
                        dim--;
                    }}
            }
        }
    }
};

#endif
