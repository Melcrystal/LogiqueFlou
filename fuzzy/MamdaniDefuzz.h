#ifndef MAMDANIDEFUZZ_H_INCLUDED
#define MAMDANIDEFUZZ_H_INCLUDED

#include "../core/BinaryExpression.h"

namespace fuzzy{

	template <class T>
		class MandaniDefuzz:public BinaryExpression<T>{

		public :
			MandaniDefuzz(const T&,const T&,const T&);
			virtual ~MandaniDefuzz();

			virtual T evaluate(Expression<T>*,Expression<T>*) const;


		private:
			T min, max, step, current;
		};

		template<class T>
		MandaniDefuzz<T>::MandaniDefuzz(const T& _min,const T& _max,const T& _step):
		min(_min),max(_max),step(_step){
		}

		template<class T>
		T MandaniDefuzz<T>::evaluate(Expression<T>* l,Expression<T>* r) const{

		}

}

#endif // MAMDANIDEFUZZ_H_INCLUDED
