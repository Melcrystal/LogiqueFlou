#ifndef ISBELL_H_INCLUDED
#define ISBELL_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{

	template <class T>
	class IsBell : public Is<T>{

		public :
			IsBell(const T&, const T&, const T&);
			~IsBell();

            T getMin();
            T getMid();
            T getCenter();

            void setMin(T&);
            void setMid(T&);
            void setCenter(T&);

			T evaluate(core::Expression<T>*);

		private:
			T min_;
			T mid;
			T center;

	};

	template <class T>
	IsBell<T>::IsBell(const T& _min, const T& _mid, const T& _center):
		min_(_min),mid(_mid),center(_center){
	}

	template <class T>
	IsBell<T>::~IsBell(){
	}

	template <class T>
	T IsBell<T>::evaluate(core::Expression<T>* e){
		T ev=e->evaluate();
		return 1/(1+(pow((abs((ev-center)/min_)),(2*mid))));
	}



	template <class T>
	T IsBell<T>::getMin(){
		return min_;
	}

	template <class T>
	T IsBell<T>::getMid(){
		return mid;
	}

	template <class T>
	T IsBell<T>::getCenter(){
		return center;
	}


	template <class T>
	void IsBell<T>::setMin(T& _min){
		min_ = _min;
	}

	template <class T>
	void IsBell<T>::setMid(T& _mid){
		mid= _mid;
	}

	template <class T>
	void IsBell<T>::setCenter(T& _center){
		center = _center;
	}

}

#endif // ISBELL_H_INCLUDED
