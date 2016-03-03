#ifndef THENMIN_H_INCLUDED
#define THENMIN_H_INCLUDED

namespace fuzzy{

	template <class T>
	class ThenMin : public fuzzy::Then<T>{


		public:
			ThenMin();
			~ThenMin();


			T evaluate(core::Expression<T>*, core::Expression<T>*);

	};


	template <class T>
	ThenMin<T>::ThenMin(){
	}

	template <class T>
	ThenMin<T>::~ThenMin(){
	}

	template <class T>
	T  ThenMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right){
		T l = left->evaluate();
		T r = right->evaluate();
		return (l < r)? l : r;
	}

}

#endif // THENMIN_H_INCLUDED
