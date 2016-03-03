#ifndef ISGAUSSIAN_H_INCLUDED
#define ISGAUSSIAN_H_INCLUDED

#include "../core/Expression.h"
#include "operators.h"

namespace fuzzy {

	template <class T>
	class IsGaussian : public Is<T>{

		public:
			IsGaussian(const T&, const T&);
			~IsGaussian();

			T evaluate(core::Expression<T>*);

			T getMax();
            T getSig();

            void setMax(T&);
            void setSig(T&);

		private :
			T max;
			T sig;

	};

	template <class T>
	IsGaussian<T>::IsGaussian(const T& _max, const T& _sig):
		max(_max),sig(_sig){
	}

	template <class T>
    IsGaussian<T>::~IsGaussian(){
    }

	template <class T>
	T IsGaussian<T>::evaluate(core::Expression<T>* e){
		T ev=e->evaluate();
		return exp((-pow(ev-max,2))/(2*pow(sig,2)));
	}

	template <class T>
	T IsGaussian<T>::getMax(){
		return max;
	}

	template <class T>
	T IsGaussian<T>::getSig(){
		return sig;
	}

	template <class T>
	void IsGaussian<T>::setMax(T& _max){
		max = _max;
	}

	template <class T>
	void IsGaussian<T>::setSig(T& _sig){
		sig = _sig;
	}


}

#endif // ISGAUSSIAN_H_INCLUDED
