#ifndef OPERATORS_H_INCLUDED
#define OPERATORS_H_INCLUDED

#include "../core/BinaryExpression.h"
#include "../core/UnaryExpression.h"


namespace fuzzy{

	template <class T>
	class And : public core::BinaryExpression<T>{
	};

	template <class T>
	class Or : public core::BinaryExpression<T>{
	};

	template <class T>
	class Then : public core::BinaryExpression<T>{
	};

	template <class T>
	class Agg : public core::BinaryExpression<T>{
	};

	template <class T>
	class Not : public core::UnaryExpression<T>{
	};

	template <class T>
	class Is : public core::UnaryExpression<T>{
	};

	template <class T>
	class MamdadiDefuzz : public core::BinaryExpression<T>{
			public :
				MandaniDefuzz(const T&,const T&,const T&);
				virtual ~MandaniDefuzz();

				virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;


		private:
			T min, max, step, current;
	};

	template <class T>
	class CogDefuzz : public core::BinaryExpression<T>{
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

	template<class T>
	MandaniDefuzz<T>::MandaniDefuzz(const T& _min,const T& _max,const T& _step):
	min(_min),max(_max),step(_step){
	}

	template<class T>
	T MandaniDefuzz<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const{

		}
};

}

#endif // OPERATORS_H_INCLUDED
