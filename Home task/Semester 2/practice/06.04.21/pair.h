template < typename T,  typename V >
class pair
{
	private:
		struct store
		{
			T first;
			V second;
			store();
			store(T data1, V data2);
		};
		store* data;

	public:
		pair();
		pair(T data1, V data2); 
		pair(pair<T, V>& p);  
		~pair();	

		pair<T, V>& operator=(pair<T, V> &p);

		T first();
		V second();
		void set_first(T val);
		void set_second(V val);

};


template < typename T,  typename V >
pair< T, V>::store::store()
{
	first = NULL;
	second = NULL;
}


template < typename T,  typename V >
pair< T, V>::store::store(T data1, V data2)
{
	first = data1;
	second = data2;
}


template < typename T,  typename V >
pair<T, V>::pair()
{
	data = new store(NULL, NULL);
}


template < typename T,  typename V >
pair<T, V>::pair(T data1, V data2)
{
	data = new store(data1, data2);
}


template < typename T,  typename V >
pair<T, V>::pair(pair<T, V>& p)
{
	data = new store(p.first(), p.second());
}


template < typename T,  typename V >
pair<T, V>::~pair()
{
	delete data;
}


template < typename T,  typename V >
pair<T, V>& pair<T, V>::operator=(pair<T, V> &p)
{
	
	data->first = p.first();
	data->second = p.second();  

	return *this;
}


template < typename T,  typename V >
T pair<T, V>::first()
{
	return data->first;
}


template < typename T,  typename V >
V pair<T, V>::second()
{
	return data->second;
}


template < typename T,  typename V >
void pair<T, V>::set_first(T val)
{
	data->first = val;
}


template < typename T,  typename V >
void pair<T, V>::set_second(V val)
{
	data->second = val;
}


template < typename T,  typename V >
pair<T, V>& make_pair(T data1, V data2)
{
	pair<T, V>* temp = new pair<T, V>(data1, data2); 
	return *temp;
}

