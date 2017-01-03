#include"index.h"

//////////////////////////////////////////////////
//        DESARROLLO DE LA CLASE INDEX          //
//////////////////////////////////////////////////

template<typename type>
Index<type>::Index(){
     index = 0;
     position = 0;
}

template<typename type>
type Index<type>::getIndex()const{
     return index;
}

template<typename type>
int Index<type>::getPosition()const{
     return position;
}

template<typename type>
void Index<type>::setIndex(const type newindex){
     index = newindex;
}

template<typename type>
void Index<type>::setPosition(const int newposition){
     position = newposition;
}
