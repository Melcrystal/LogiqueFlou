#ifndef COQDEFUZZ_H_INCLUDED
#define COQDEFUZZ_H_INCLUDED

#include "MamdaniDefuzz.h"

namespace fuzzy{

	template <class T>
	class CogDefuzz:public MandaniDefuzz<T>{
	public :
		CogDefuzz(const T&,const T&,const T&);

		T evaluate(Expression<T>*,Expression<T>*);

	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min,const T& _max,const T& _step):
		MandaniDefuzz<T>(_min,_max,_step){
	}

	template <class T>
	T CogDefuzz<T>::evaluate(Expression<T>* l,Expression<T>* r){
	}

}

#endif // COQDEFUZZ_H_INCLUDED