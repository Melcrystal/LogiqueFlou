#ifndef THENMULT_H_INCLUDED
#define THENMULT_H_INCLUDED

namespace fuzzy{

	template <class T>
		class ThenMult : public Then<T>{

			public :
				ThenMult();
				~ThenMult();

				T evaluate(core::Expression<T>*, core::Expression<T>*);

		};


		template <class T>
		ThenMult<T>::ThenMult(){
		}

		template <class T>
		ThenMult<T>::~ThenMult(){
		}

		template <class T>
		T ThenMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right ){
			T l = left->evaluate();
			T r = right->evaluate();
			return (l *r);
		}

}

#endif // THENMULT_H_INCLUDED
