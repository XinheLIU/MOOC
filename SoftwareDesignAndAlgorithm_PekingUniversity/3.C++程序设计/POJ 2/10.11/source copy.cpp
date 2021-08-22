
template <class T>
struct myGreater {
    bool operator() (const T& x, const T& y) const { return x>y; }
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};
template<typename K, typename V, class Pred = myGreater<K> >
class MyMultimap{
public:
    typedef std::multimap<K, V, Pred>  myType;
    typedef typename std::multimap<K, V>::iterator iterator;
    myType myMap;
    void insert(std::pair<K, V> _p){
        myMap.insert(_p);
    }
    iterator find(K k){
        return myMap.find(k);
    }
    iterator begin(){
        return myMap.begin();
    }
    iterator end(){
        return myMap.end();
    }
    void Set(K k, V v){
        //修改multimap的pair的second值，利用equal_range函数
        iterator ending = myMap.equal_range(k).second;
        iterator starting = myMap.equal_range(k).first;
        while (starting != ending){
            starting->second = v;
            starting++;
        }
    }//这个函数可以缓缓
    void clear(){
        myMap.clear();
    }
};
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, typename std::pair<const T1, T2> _p){
    std::cout << "(" << _p.first << "," << _p.second << ")";
    return o;
}