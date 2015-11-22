#ifndef HASH_H_
#define HASH_H_ 

#include "15_11_HashFn.h"
#include <map>
#include <stdexcept>

template<
 typename KEY, //キーの型
 typename VALUE, //扱う値の型
 typename HASH_FN = HashFn<KEY> //ハッシュ関数
>

class Hash
{
private:
	typedef std::map<KEY,VALUE> Map;
	typedef typename Map::const_iterator CIterator;
public:
	//キーに対応する値を取得
	VALUE& operator[](const KEY& key){
		size_t hashValue = HASH_FN::Get(key); //ハッシュ値
		return m_hashTable[hashValue][key];
	}
	//キーに対応する値を取得
	//キーが見つからなければout_of_rangeを投げる
	const VALUE& operator[](const KEY& key) const{
		size_t hashValue = HASH_FN::Get(key);//ハッシュ値
		const Map& map = m_hashTable[hashValue];
		CIterator it = map.find(key);
		if(it == map.end()){
			throw std::out_of_range("見つかりませんでした");
		}
		return it->second;
	}
private:
	Map m_hashTable[HASH_FN::SIZE];//ハッシュ表

};

#endif