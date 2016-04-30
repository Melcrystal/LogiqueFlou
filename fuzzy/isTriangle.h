#ifndef ISTRIANGLE_H_INCLUDED
#define ISTRIANGLE_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{

	template <class T>
	class isTriangle : public Is<T>{

		public :
			isTriangle(T&, T&, T&);
			~isTriangle();

			T evaluate(core::Expression<T>*);

			T getMax();
			T getMid();
			T getMin();

			void setMax(T&);
			void setMid(T&);
			void setMin(T&);
			


		private:
			T min, mid, max;

	};

    template <class T>
    isTriangle<T>::isTriangle(T& min_, T& mid_, T& max_):
    	min(min_),mid(mid_),max(max_){
    }

	template <class T>
	isTriangle<T>::~isTriangle(){
	}

	template <class T>
	T isTriangle<T>::evaluate(core::Expression<T>* e){
        T ev = e->evaluate();
        if (ev <= min || ev >= max)
			return 0;
		return (ev <= mid)? (ev - min)/(mid - min) : (ev - max)/(mid - max) ;

	}

    template <class T>
    T isTriangle<T>::getMax(){
		return max;
    }

    template <class T>
	T isTriangle<T>::getMid(){
		return mid;
	}

	template <class T>
	T isTriangle<T>::getMin(){
		return min;
	}

	template <class T>
	void isTriangle<T>::setMax(T& _max){
		max = _max;
	}

	template <class T>
	void isTriangle<T>::setMid(T& _mid){
		mid = _mid;
	}

	template <class T>
	void isTriangle<T>::setMin(T& _min){
		min = _min;
	}

}


#endif // ISTRIANGLE_H_INCLUDED
