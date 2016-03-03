#ifndef ANDMIN_H_INCLUDED
#define ANDMIN_H_INCLUDED


namespace fuzzy{

	template <class T>
	class AndMin : public fuzzy::And<T>{


		public:
			AndMin();
			~AndMin();


			T evaluate(core::Expression<T>*, core::Expression<T>*);

	};


	template <class T>
	AndMin<T>::AndMin(){
	}

	template <class T>
	AndMin<T>::~AndMin(){
	}

	template <class T>
	T  AndMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right){
		T l = left->evaluate();
		T r = right->evaluate();
		return (l <= r)? l : r;
	}

}
#endif // ANDMIN_H_INCLUDED
