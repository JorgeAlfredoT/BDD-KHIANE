#ifndef INDEX_H
#define INDEX_H

template<typename type>
class Index{
protected:
     type index;
     int position;
public:
     Index();
     ~Index(){}

     type getIndex()const;
     int getPosition()const;

     void setIndex(const type);
     void setPosition(const int);
};

#endif
