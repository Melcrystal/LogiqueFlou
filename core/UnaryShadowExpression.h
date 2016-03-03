#ifndef UNARYSHADOWEXPRESSION_H_INCLUDED
#define UNARYSHADOWEXPRESSION_H_INCLUDED

namespace core{

	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T>{

		public:
			UnaryShadowExpression(UnaryExpression<T>*);
			~UnaryShadowExpression(){};

			T evaluate(Expression<T>*);
			void setTarget(UnaryExpression<T>*);

		private:
			UnaryExpression<T>* target;
	};

		template <class T>
		UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* e):
			target(e){
		}

		template <class T>
		T UnaryShadowExpression<T>::evaluate(Expression<T>* o){
			if(target != NULL)
				return target->evaluate(o);
		}

}

#endif // UNARYSHADOWEXPRESSION_H_INCLUDED
