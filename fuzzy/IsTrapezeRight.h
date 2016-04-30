#ifndef ISTRAPEZERIGHT_H_INCLUDED
#define ISTRAPEZERIGHT_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{

	template <class T>
	class IsTrapezeRight : public Is<T>{

	public:
		IsTrapezeRight(const T&, const T&, const T&);
		~IsTrapezeRight();

		T evaluate(core::Expression<T>*);

		T getMin();
		T getMax();
		T getMid();

		void setMax(T&);
		void setMin(T&);
		void setMid(T&);

	private:
		T min, max, mid;
	};

	template <class T>
	IsTrapezeRight<T>::IsTrapezeRight(const T& min_, const T& mid_, const T& max_) :
		min(min_), max(max_), mid(mid_) {
	}

	template <class T>
	IsTrapezeRight<T>::~IsTrapezeRight(){
	}

	template <class T>
	T IsTrapezeRight<T>::evaluate(core::Expression<T>* e){
		T ev = e->evaluate();

		if (ev <= min) return 0;
		return (ev <= mid) ? 1 : ((ev - min) / (mid - min));
	}

	template <class T>
	T IsTrapezeRight<T>::getMin(){
		return min;
	}

	template <class T>
	T IsTrapezeRight<T>::getMax(){
		return max;
	}

	template <class T>
	T IsTrapezeRight<T>::getMid(){
		return mid;
	}

	template <class T>
	void IsTrapezeRight<T>::setMax(T& _max){
		max = _max;
	}

	template <class T>
	void IsTrapezeRight<T>::setMin(T& _min){
		min = _min;
	}

	template <class T>
	void IsTrapezeRight<T>::setMid(T& _mid){
		mid = _mid;
	}

}

#endif // ISTRAPEZERIGHT_H_INCLUDED
