#ifndef ISTRAPEZE_H_INCLUDED
#define ISTRAPEZE_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy{

	template <class T>
	class IsTrapeze : public Is<T>{

	public:
		IsTrapeze(const T&, const T&, const T&, const T&);
		~IsTrapeze();

		T evaluate(core::Expression<T>*);

		T getMax();
		T getMidA();
		T getMidB();
		T getMin();

		void setMax(T&);
		void setMidA(T&);
		void setMin(T&);
		void setMidB(T&);


	private:
		T min, max, midA, midB;
	};

	template <class T>
	IsTrapeze<T>::IsTrapeze(const T& min_, const T& midA_, const T& midB_, const T& max_) :
		min(min_), max(max_), midA(midA_), midB(midB_) {
	}

	template <class T>
	IsTrapeze<T>::~IsTrapeze(){
	}

	template <class T>
	T IsTrapeze<T>::evaluate(core::Expression<T>* e){
		T ev = e->evaluate();

		if (ev <= min || ev >= max) return 0;
		return (ev <= mid) ? 1 : ((ev - min) / (mid - min));
	}

	template <class T>
	T IsTrapeze<T>::getMin(){
		return min;
	}

	template <class T>
	T IsTrapeze<T>::getMax(){
		return max;
	}

	template <class T>
	T IsTrapeze<T>::getMidA(){
		return midA;
	}

	template <class T>
	T IsTrapeze<T>::getMidB(){
		return midB;
	}

	template <class T>
	void IsTrapeze<T>::setMax(T& _max){
		max = _max;
	}

	template <class T>
	void IsTrapeze<T>::setMin(T& _min){
		min = _min;
	}

	template <class T>
	void IsTrapeze<T>::setMidA(T& _mid){
		midA = _mid;
	}

	template <class T>
	void IsTrapeze<T>::setMidB(T& _mid){
		midB = _mid;
	}

}

#endif // ISTRAPEZE_H_INCLUDED
