#ifndef COQDEFUZZ_H_INCLUDED
#define COQDEFUZZ_H_INCLUDED

#include "MamdaniDefuzz.h"

namespace fuzzy{

	template <class T>           // BORDEL DE MERDE CA, CA VA DANS OPERATORS.H S'IL TE PLAIT
	class CogDefuzz:public fuzzy::MandaniDefuzz<T>{
	public :
		CogDefuzz(const T&,const T&,const T&);

		T evaluate(core::Expression<T>*,core::Expression<T>*);

	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min,const T& _max,const T& _step):
		MandaniDefuzz<T>(_min,_max,_step){
	}

	template <class T>
	T CogDefuzz<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r){
	}

}

#endif // COQDEFUZZ_H_INCLUDED
