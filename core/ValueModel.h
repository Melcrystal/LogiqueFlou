#ifndef VALUEMODEL_H_INCLUDED
#define VALUEMODEL_H_INCLUDED

#include "Expression.h"

namespace core{

	template <class T>
	class ValueModel : public Expression<T> {

		public :
			ValueModel();
			ValueModel(const T&);
			virtual ~ValueModel() {};

			virtual T evaluate();

			virtual void setValue(T);
			virtual T getValue();

		private :
			T value;

	};

	template <class T>
    ValueModel<T>::ValueModel():
    	value(0){
	}

	template <class T>
	ValueModel<T>::ValueModel(const T& v):
		value(v){
	}

	template <class T>
	T ValueModel<T>::evaluate(){
		return value;
	}

	template <class T>
	void ValueModel<T>::setValue(T v){
		value = v;
	}

	template <class T>
	T ValueModel<T>::getValue(){
		return value;
	}

}
#endif // VALUEMODEL_H_INCLUDED
