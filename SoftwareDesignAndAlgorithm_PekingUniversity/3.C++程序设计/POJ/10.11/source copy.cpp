
template<class _Kty,
class _Ty,
class _Pr = less<_Kty>,
class _Alloc = allocator<pair<const _Kty, _Ty> > >

class MyMultimap :public multimap<_Kty, _Ty, _Pr, _Alloc >
{
	//template<class _Kty, class _Ty>
public:
	void Set( _Kty x, _Ty y)
	{

	}
	friend ostream& operator<< (ostream &os, MyMultimap &st) 
	{
		return os; 
	}
};

