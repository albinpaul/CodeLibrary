#ifndef TIPS_HPP
#define TIPS_HPP
namespace tips{
	template<class T>
	void print(const T& container ,const char* text=0,const char* element_seperator=" "){
		const char* text_seperator=": ";
		if(text!=0){
			std::cout<<text<<text_seperator;
		}
		typename T::const_iterator container_end=container.end();
		for(typename T::const_iterator i=container.begin();i!=container.end();i++){
			std::cout<<*i<<element_seperator;
		}
		std::cout<<"\n";
	}
}
#endif